//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;        // Magic number for BMP files
    uint32_t bfSize;        // Size of the BMP file
    uint16_t bfReserved1;   // Reserved
    uint16_t bfReserved2;   // Reserved
    uint32_t bfOffBits;     // Offset to the start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;         // Size of the DIB header
    int32_t  biWidth;        // Width of the bitmap
    int32_t  biHeight;       // Height of the bitmap
    uint16_t biPlanes;       // Color planes
    uint16_t biBitCount;     // Bits per pixel
    uint32_t biCompression;   // Compression type
    uint32_t biSizeImage;    // Size of the image data
    int32_t  biXPelsPerMeter;  // Horizontal resolution
    int32_t  biYPelsPerMeter;  // Vertical resolution
    uint32_t biClrUsed;       // Colors used
    uint32_t biClrImportant;   // Important colors
} BITMAPINFOHEADER;
#pragma pack(pop)

void encode_message_in_image(const char *image_filename, const char *message, const char *output_filename) {
    FILE *image_file = fopen(image_filename, "rb");
    if (!image_file) {
        perror("Error opening image file");
        return;
    }
    
    BITMAPFILEHEADER bmpHeader;
    fread(&bmpHeader, sizeof(BITMAPFILEHEADER), 1, image_file);

    BITMAPINFOHEADER bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, image_file);

    // Check for 24-bit BMP
    if (bmpInfoHeader.biBitCount != 24) {
        printf("Only 24-bit BMP format is supported.\n");
        fclose(image_file);
        return;
    }

    // Allocate space for pixel data
    int pixel_array_size = bmpHeader.bfSize - bmpHeader.bfOffBits;
    uint8_t *pixel_data = (uint8_t *)malloc(pixel_array_size);
    fseek(image_file, bmpHeader.bfOffBits, SEEK_SET);
    fread(pixel_data, 1, pixel_array_size, image_file);
    fclose(image_file);

    // Embed message into pixel data
    int message_length = strlen(message);
    if (message_length * 8 > pixel_array_size) {
        printf("Message is too long to be hidden in this image.\n");
        free(pixel_data);
        return;
    }

    for (int i = 0; i < message_length; i++) {
        for (int bit = 0; bit < 8; bit++) {
            int pixel_index = i * 8 + bit;
            if (pixel_index < pixel_array_size) {
                // Encode each bit of the message into the least significant bit of the pixel
                pixel_data[pixel_index] = (pixel_data[pixel_index] & ~1) | ((message[i] >> (7 - bit)) & 1);
            }
        }
    }

    // Create and write the new image file
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Error creating output file");
        free(pixel_data);
        return;
    }
    
    fwrite(&bmpHeader, sizeof(BITMAPFILEHEADER), 1, output_file);
    fwrite(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, output_file);
    fseek(output_file, bmpHeader.bfOffBits, SEEK_SET);
    fwrite(pixel_data, 1, pixel_array_size, output_file);
    
    fclose(output_file);
    free(pixel_data);
    printf("Message encoded successfully in %s\n", output_filename);
}

void decode_message_from_image(const char *image_filename) {
    FILE *image_file = fopen(image_filename, "rb");
    if (!image_file) {
        perror("Error opening image file");
        return;
    }
    
    BITMAPFILEHEADER bmpHeader;
    fread(&bmpHeader, sizeof(BITMAPFILEHEADER), 1, image_file);

    BITMAPINFOHEADER bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, image_file);

    if (bmpInfoHeader.biBitCount != 24) {
        printf("Only 24-bit BMP format is supported.\n");
        fclose(image_file);
        return;
    }

    int pixel_array_size = bmpHeader.bfSize - bmpHeader.bfOffBits;
    uint8_t *pixel_data = (uint8_t *)malloc(pixel_array_size);
    fseek(image_file, bmpHeader.bfOffBits, SEEK_SET);
    fread(pixel_data, 1, pixel_array_size, image_file);
    fclose(image_file);

    printf("Decoded message: ");
    for (int i = 0; ; i++) {
        char byte = 0;
        for (int bit = 0; bit < 8; bit++) {
            int pixel_index = i * 8 + bit;
            if (pixel_index >= pixel_array_size) {
                printf("\n");
                free(pixel_data);
                return;
            }
            byte = (byte << 1) | (pixel_data[pixel_index] & 1);
        }
        if (byte == '\0') break; // End of message
        putchar(byte);
    }
    free(pixel_data);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <encode/decode> <image.bmp> <message/output.bmp>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encode") == 0) {
        encode_message_in_image(argv[2], argv[3], "output.bmp");
    } else if (strcmp(argv[1], "decode") == 0) {
        decode_message_from_image(argv[2]);
    } else {
        printf("Unknown action: %s. Use 'encode' or 'decode'.\n", argv[1]);
    }

    return 0;
}