//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: energetic
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

void hide_message(const char *input_image, const char *output_image, const char *message) {
    FILE *infile = fopen(input_image, "rb");
    if (!infile) {
        perror("Cannot open input image");
        return;
    }

    FILE *outfile = fopen(output_image, "wb");
    if (!outfile) {
        perror("Cannot open output image");
        fclose(infile);
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, infile);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, infile);

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, outfile);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, outfile);

    // Move to pixel data
    fseek(infile, bfh.bfOffBits, SEEK_SET);
    fseek(outfile, bfh.bfOffBits, SEEK_SET);

    size_t message_length = strlen(message);
    size_t padded_length = (message_length + 1) * 8;
    uint8_t byte;

    for (size_t i = 0; i < padded_length; i++) {
        fread(&byte, sizeof(uint8_t), 1, infile);
        
        // If we've reached the end of the message, write the end of the message indicator
        if (i < padded_length - 1) {
            byte = (byte & 0xFE) | ((message[i / 8] >> (7 - (i % 8))) & 0x01);
        } else {
            // Indicating end of the message with a null character
            byte = (byte & 0xFE) | 0;
        }
        fwrite(&byte, sizeof(uint8_t), 1, outfile);
    }

    // Copy the rest of the image
    uint8_t buffer;
    while (fread(&buffer, sizeof(uint8_t), 1, infile) == 1) {
        fwrite(&buffer, sizeof(uint8_t), 1, outfile);
    }

    fclose(infile);
    fclose(outfile);
    printf("Message hidden successfully!\n");
}

void reveal_message(const char *input_image) {
    FILE *infile = fopen(input_image, "rb");
    if (!infile) {
        perror("Cannot open input image");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, infile);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, infile);

    fseek(infile, bfh.bfOffBits, SEEK_SET);

    uint8_t byte;
    char message[256] = {0};
    size_t idx = 0;

    while (1) {
        fread(&byte, sizeof(uint8_t), 1, infile);
        if (feof(infile)) break;

        for (int j = 0; j < 8; j++) {
            if (idx < sizeof(message) - 1) {
                message[idx / 8] = (message[idx / 8] << 1) | (byte & 0x01);
                idx++;
            }
            byte >>= 1;
        }

        // Detect end of the message
        if (message[(idx / 8) - 1] == 0) break;
    }

    fclose(infile);
    printf("Revealed message: %s\n", message);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <hide/reveal> <image_file> [message/output_image]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "hide") == 0 && argc == 5) {
        hide_message(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "reveal") == 0) {
        reveal_message(argv[2]);
    } else {
        printf("Invalid command or missing arguments.\n");
    }

    return 0;
}