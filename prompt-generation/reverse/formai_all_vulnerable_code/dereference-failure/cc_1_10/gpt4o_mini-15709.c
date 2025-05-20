//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;      // Magic number for BMP files
    uint32_t bfSize;      // Size of the BMP file in bytes
    uint16_t bfReserved1; // Reserved; must be zero
    uint16_t bfReserved2; // Reserved; must be zero
    uint32_t bfOffBits;   // Offset to the pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of the DIB header
    int32_t  biWidth;         // Width of the bitmap in pixels
    int32_t  biHeight;        // Height of the bitmap in pixels
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Number of bits per pixel
    uint32_t biCompression;    // Type of compression to use
    uint32_t biSizeImage;     // Size of the image data
    int32_t  biXPelsPerMeter;   // Horizontal resolution
    int32_t  biYPelsPerMeter;   // Vertical resolution
    uint32_t biClrUsed;       // Number of colors in the palette
    uint32_t biClrImportant;   // Important colors
} BITMAPINFOHEADER;
#pragma pack(pop)

void hide_message(const char *input_file, const char *output_file, const char *message) {
    FILE *in = fopen(input_file, "rb");
    FILE *out = fopen(output_file, "wb");
    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    
    if (in == NULL || out == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, in);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, in);
    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, out);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, out);
    
    uint32_t pixels = bih.biWidth * bih.biHeight;
    uint8_t *pixel_data = malloc(pixels * 3); // Assuming 24-bit BMP
    fread(pixel_data, sizeof(uint8_t), pixels * 3, in);

    // Hide message in LSB of pixel data
    size_t message_len = strlen(message);
    for (size_t i = 0; i < message_len; i++) {
        for (int j = 0; j < 8; j++) {
            // Get the current pixel index
            size_t index = (i * 8 + j) * 3; // Assume RGB hence *3
            if (index >= pixels * 3) {
                goto finish; // If we run out of pixels, stop.
            }
            // Set the LSB of the blue channel to the message bit
            pixel_data[index + 2] = (pixel_data[index + 2] & 0xFE) | ((message[i] >> (7 - j)) & 0x01);
        }
    }

finish:
    fwrite(pixel_data, sizeof(uint8_t), pixels * 3, out);
    free(pixel_data);
    fclose(in);
    fclose(out);
    printf("Message hidden successfully!\n");
}

void retrieve_message(const char *input_file, size_t message_length) {
    FILE *in = fopen(input_file, "rb");
    if (in == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, in);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, in);
    
    uint32_t pixels = bih.biWidth * bih.biHeight;
    uint8_t *pixel_data = malloc(pixels * 3);
    fread(pixel_data, sizeof(uint8_t), pixels * 3, in);

    char *message = malloc(message_length + 1);
    message[message_length] = '\0'; // Null-terminate the string

    for (size_t i = 0; i < message_length; i++) {
        char byte = 0;
        for (int j = 0; j < 8; j++) {
            size_t index = (i * 8 + j) * 3; // Assume RGB hence *3
            if (index >= pixels * 3) {
                free(message);
                goto end;
            }
            // Read the LSB of the blue channel
            byte |= (pixel_data[index + 2] & 1) << (7 - j);
        }
        message[i] = byte;
    }

end:
    printf("Retrieved message: %s\n", message);
    free(message);
    free(pixel_data);
    fclose(in);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <hide/retrieve> <input_file> <output_file> <message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "hide") == 0) {
        hide_message(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "retrieve") == 0) {
        size_t message_length = strlen(argv[4]);
        retrieve_message(argv[2], message_length);
    } else {
        printf("Invalid action. Use 'hide' or 'retrieve'.\n");
    }

    return 0;
}