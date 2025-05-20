//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPixPerMeter;
    int32_t biYPixPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;

#pragma pack(pop)

// Function to hide a message in the pixel data of the BMP image
void hide_message_in_image(const char *image_path, const char *message, const char *output_path) {
    FILE *image_file = fopen(image_path, "rb");
    FILE *output_file = fopen(output_path, "wb");

    if (!image_file || !output_file) {
        fprintf(stderr, "Could not open files.\n");
        exit(EXIT_FAILURE);
    }

    // Read the BMP headers
    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, image_file);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, image_file);

    // Make sure it's a 24-bit BMP image
    if (bfh.bfType != 0x4D42 || bih.biBitCount != 24) {
        fprintf(stderr, "Unsupported image format. Please use a 24-bit BMP.\n");
        fclose(image_file);
        fclose(output_file);
        exit(EXIT_FAILURE);
    }

    // Calculate the size of the message and create a padded version
    size_t message_len = strlen(message);
    size_t padded_length = message_len + 1; // Account for null terminator
    uint8_t *message_buffer = (uint8_t *)malloc(padded_length);
    memcpy(message_buffer, message, padded_length);

    // Begin hiding the message
    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, output_file);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, output_file);

    // Move to the start of the pixel data
    fseek(image_file, bfh.bfOffBits, SEEK_SET);
    int pixel_count = bih.biWidth * bih.biHeight;

    for (int i = 0; i < pixel_count; i++) {
        uint8_t pixel[3];
        fread(pixel, sizeof(uint8_t), 3, image_file);

        // Hide characters of the message into the least significant bit of the pixel
        if (i < padded_length) {
            pixel[0] = (pixel[0] & ~1) | ((message_buffer[i] >> 0) & 1); // Red component
            pixel[1] = (pixel[1] & ~1) | ((message_buffer[i] >> 1) & 1); // Green component
            pixel[2] = (pixel[2] & ~1) | ((message_buffer[i] >> 2) & 1); // Blue component
        }

        fwrite(pixel, sizeof(uint8_t), 3, output_file);
    }

    free(message_buffer);
    fclose(image_file);
    fclose(output_file);
    printf("Message hidden in image successfully!\n");
}

// Function to extract hidden message from the pixel data
void extract_message_from_image(const char *image_path) {
    FILE *image_file = fopen(image_path, "rb");

    if (!image_file) {
        fprintf(stderr, "Could not open the image file.\n");
        exit(EXIT_FAILURE);
    }

    // Read the BMP headers
    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, image_file);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, image_file);

    // Make sure it's a 24-bit BMP image
    if (bfh.bfType != 0x4D42 || bih.biBitCount != 24) {
        fprintf(stderr, "Unsupported image format. Please use a 24-bit BMP.\n");
        fclose(image_file);
        exit(EXIT_FAILURE);
    }

    // Start extracting message
    fseek(image_file, bfh.bfOffBits, SEEK_SET);
    uint8_t byte = 0;
    size_t bit_count = 0;
    char hidden_message[256];
    size_t message_length = 0;

    // Read pixels until we retrieve a null-terminated string
    for (int i = 0; i < 256 * 8; i++) { // Assuming message won't exceed 256 characters
        uint8_t pixel[3];
        fread(pixel, sizeof(uint8_t), 3, image_file);

        // Read the least significant bits of each color component
        byte |= (pixel[0] & 1) << (bit_count % 8);
        bit_count++;

        if (bit_count % 8 == 0) {
            hidden_message[message_length++] = byte;
            if (byte == '\0') {
                break; // Stop reading if we have reached the null terminator
            }
            byte = 0; // Reset byte for next character
        }
    }

    hidden_message[message_length] = '\0';
    printf("Extracted Message: %s\n", hidden_message);
    fclose(image_file);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <hide/extract> <image.bmp> <message (if hiding)> <output.bmp (if hiding)>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "hide") == 0) {
        hide_message_in_image(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extract_message_from_image(argv[2]);
    } else {
        fprintf(stderr, "Invalid option. Use 'hide' or 'extract'.\n");
    }

    return 0;
}