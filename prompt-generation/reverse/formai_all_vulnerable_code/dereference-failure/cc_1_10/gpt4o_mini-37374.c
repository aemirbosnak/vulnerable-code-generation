//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1) // To ensure proper structure packing.

// BMP file header structure
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BMPFileHeader;

// BMP info header structure
typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BMPInfoHeader;

void hideMessage(const char *inputFile, const char *outputFile, const char *message) {
    FILE *input = fopen(inputFile, "rb");
    if (!input) {
        printf("Error: Cannot open input file.\n");
        return;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, input);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, input);

    if (fileHeader.bfType != 0x4D42 || infoHeader.biBitCount != 24) {
        printf("Error: Unsupported BMP format. Only 24-bit BMP files are supported.\n");
        fclose(input);
        return;
    }

    // Prepare the message to hide
    char message_bin[256] = {0};
    int message_length = strlen(message);

    // Encode the message length in 1 byte
    message_bin[0] = (char)message_length;
    for (int i = 0; i < message_length; i++) {
        message_bin[i + 1] = message[i];
    }

    // Modify pixels in the BMP to hide the message
    int pixels_to_modify = message_length * 8; // Each character takes 8 bits
    int padding = (4 - (infoHeader.biWidth * 3) % 4) % 4;

    for (int i = 0; i < infoHeader.biHeight; i++) {
        for (int j = 0; j < infoHeader.biWidth; j++) {
            unsigned char pixel[3];
            fread(pixel, 1, 3, input);

            if (i * infoHeader.biWidth + j < pixels_to_modify) {
                // Get the current bit to hide
                int bit_position = i * infoHeader.biWidth + j - 1;
                int bit = (message_bin[bit_position / 8] >> (7 - (bit_position % 8))) & 1;

                // Hide the bit in the least significant bit of the blue component
                pixel[0] = (pixel[0] & 0xFE) | bit; // Modify blue channel
            }

            fwrite(pixel, 1, 3, stdout);
        }
        fseek(input, padding, SEEK_CUR); // Skip the padding
    }

    fclose(input);
}

void revealMessage(const char *inputFile) {
    FILE *input = fopen(inputFile, "rb");
    if (!input) {
        printf("Error: Cannot open input file.\n");
        return;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, input);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, input);

    if (fileHeader.bfType != 0x4D42 || infoHeader.biBitCount != 24) {
        printf("Error: Unsupported BMP format. Only 24-bit BMP files are supported.\n");
        fclose(input);
        return;
    }

    // Read the hidden message
    char message_bin[256] = {0};
    int pixels_to_read = message_bin[0];

    int padding = (4 - (infoHeader.biWidth * 3) % 4) % 4;

    for (int i = 0; i < infoHeader.biHeight; i++) {
        for (int j = 0; j < infoHeader.biWidth; j++) {
            unsigned char pixel[3];
            fread(pixel, 1, 3, input);

            if (i * infoHeader.biWidth + j < pixels_to_read * 8) {
                // Read the bit from the least significant bit of the blue component
                int bit_position = i * infoHeader.biWidth + j;
                message_bin[bit_position / 8] = (message_bin[bit_position / 8] << 1) | (pixel[0] & 1);
            }
        }
        fseek(input, padding, SEEK_CUR);
    }

    // Print the decoded message
    printf("Hidden Message: ");
    for (int i = 0; i < pixels_to_read; i++) {
        putchar(message_bin[i + 1]);
    }
    putchar('\n');

    fclose(input);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <hide/reveal> <input.bmp> <output.bmp/message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "hide") == 0) {
        hideMessage(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "reveal") == 0) {
        revealMessage(argv[2]);
    } else {
        printf("Invalid option. Use 'hide' or 'reveal'.\n");
    }

    return 0;
}