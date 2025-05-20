//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

void embed_message(const char *image_path, const char *message, const char *output_path) {
    FILE *image = fopen(image_path, "rb");
    if (image == NULL) {
        perror("Could not open input image");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;

    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, image);
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, image);

    // Check if it's a valid BMP file
    if (bmpFileHeader.bfType != 0x4D42) {
        fclose(image);
        fprintf(stderr, "Not a valid BMP file.\n");
        exit(EXIT_FAILURE);
    }

    // Calculate the size of the message
    int message_length = strlen(message);
    if (message_length > (bmpInfoHeader.biWidth * bmpInfoHeader.biHeight * (bmpInfoHeader.biBitCount / 8)) - 54) {
        fclose(image);
        fprintf(stderr, "Message is too large to embed.\n");
        exit(EXIT_FAILURE);
    }

    // Create output image
    FILE *output_image = fopen(output_path, "wb");
    if (output_image == NULL) {
        fclose(image);
        perror("Could not open output image");
        exit(EXIT_FAILURE);
    }

    fwrite(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, output_image);
    fwrite(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, output_image);

    // Read the pixel data
    int padding = (4 - (bmpInfoHeader.biWidth * (bmpInfoHeader.biBitCount / 8)) % 4) % 4;
    uint8_t *pixel_data = malloc(bmpInfoHeader.biSizeImage);
    if (pixel_data == NULL) {
        fclose(image);
        fclose(output_image);
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    fread(pixel_data, bmpInfoHeader.biSizeImage, 1, image);
    fclose(image);

    // Embed the message into the pixel data
    int message_index = 0;
    for (int i = 0; i < bmpInfoHeader.biHeight; i++) {
        for (int j = 0; j < bmpInfoHeader.biWidth; j++) {
            for (int k = 0; k < (bmpInfoHeader.biBitCount / 8); k++) {
                // Check if we still have a message to embed
                if (message_index < message_length) {
                    // Modify the least significant bit (LSB) of the pixel
                    pixel_data[(i * bmpInfoHeader.biWidth + j) * (bmpInfoHeader.biBitCount / 8) + k] &= ~1;
                    pixel_data[(i * bmpInfoHeader.biWidth + j) * (bmpInfoHeader.biBitCount / 8) + k] |= (message[message_index] >> k) & 1;
                    message_index++;
                }
            }
            // Add padding
            if (j == bmpInfoHeader.biWidth - 1) {
                for (int p = 0; p < padding; p++) {
                    fgetc(image); // Skip padding bytes
                }
            }
        }
    }

    // Write the modified pixel data to the output image
    fwrite(pixel_data, bmpInfoHeader.biSizeImage, 1, output_image);

    // Clean up
    free(pixel_data);
    fclose(output_image);
    printf("Message embedded successfully in %s\n", output_path);
}

void extract_message(const char *image_path) {
    FILE *image = fopen(image_path, "rb");
    if (image == NULL) {
        perror("Could not open image");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;

    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, image);
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, image);

    if (bmpFileHeader.bfType != 0x4D42) {
        fclose(image);
        fprintf(stderr, "Not a valid BMP file.\n");
        exit(EXIT_FAILURE);
    }

    int padding = (4 - (bmpInfoHeader.biWidth * (bmpInfoHeader.biBitCount / 8)) % 4) % 4;
    uint8_t *pixel_data = malloc(bmpInfoHeader.biSizeImage);
    if (pixel_data == NULL) {
        fclose(image);
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    fread(pixel_data, bmpInfoHeader.biSizeImage, 1, image);
    fclose(image);

    // Extract the message
    char message[256];
    int message_index = 0;
    for (int i = 0; i < bmpInfoHeader.biHeight; i++) {
        for (int j = 0; j < bmpInfoHeader.biWidth; j++) {
            for (int k = 0; k < (bmpInfoHeader.biBitCount / 8); k++) {
                if (message_index < sizeof(message) - 1) {
                    message[message_index] |= (pixel_data[(i * bmpInfoHeader.biWidth + j) * (bmpInfoHeader.biBitCount / 8) + k] & 1) << k;
                    if ((j * (bmpInfoHeader.biBitCount / 8) + k) % 8 == 7) {
                        message_index++;
                    }
                }
            }
            if (j == bmpInfoHeader.biWidth - 1) {
                for (int p = 0; p < padding; p++) {
                    fgetc(image); // Skip padding bytes
                }
            }
        }
    }

    message[message_index] = '\0'; // Null-terminate
    printf("Extracted message: \"%s\"\n", message);
    free(pixel_data);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s -e|-d <image> <message/output_image>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "-e") == 0) {
        embed_message(argv[2], argv[3], "output.bmp");
    } else if (strcmp(argv[1], "-d") == 0) {
        extract_message(argv[2]);
    } else {
        fprintf(stderr, "Unknown operation: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}