//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1) // To ensure the correct byte alignment
typedef struct {
    unsigned char bfType[2];
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;

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
} BITMAPINFOHEADER;

void embed_message_in_bmp(const char *bmp_file, const char *message) {
    FILE *file = fopen(bmp_file, "r+b");
    if (!file) {
        perror("Error opening file");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, file);

    size_t message_len = strlen(message);
    size_t total_bits = message_len * 8 + 1; // +1 for the null terminator

    if (total_bits > (bih.biWidth * bih.biHeight * (bih.biBitCount / 8))) {
        fprintf(stderr, "Message is too large to fit in the image.\n");
        fclose(file);
        return;
    }

    fseek(file, bfh.bfOffBits, SEEK_SET);

    for (size_t i = 0; i < total_bits; i++) {
        unsigned char byte;
        fread(&byte, sizeof(unsigned char), 1, file);
        if (i < total_bits - 1) { // For message bits
            byte = (byte & 0xFE) | ((message[i / 8] >> (7 - (i % 8))) & 0x01);
        } else { // For null terminator
            byte = (byte & 0xFE) | 0x01;
        }
        fseek(file, -1, SEEK_CUR);
        fwrite(&byte, sizeof(unsigned char), 1, file);
    }

    fclose(file);
    printf("Message embedded successfully.\n");
}

void extract_message_from_bmp(const char *bmp_file) {
    FILE *file = fopen(bmp_file, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, file);

    size_t message_len = (bih.biWidth * bih.biHeight * (bih.biBitCount / 8)) / 8; // Max size
    char *message = malloc(message_len + 1);
    memset(message, 0, message_len + 1);

    fseek(file, bfh.bfOffBits, SEEK_SET);

    for (size_t i = 0; i < message_len * 8; i++) {
        unsigned char byte;
        fread(&byte, sizeof(unsigned char), 1, file);
        if (byte & 0x01) {
            message[i / 8] |= (1 << (7 - (i % 8)));
        }
        
        // Stop reading if we find the null terminator
        if (i % 8 == 7 && message[i / 8] == 0) {
            break;
        }
    }

    printf("Extracted message: %s\n", message);

    free(message);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <embed/extract> <bmp_file> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embed_message_in_bmp(argv[2], argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extract_message_from_bmp(argv[2]);
    } else {
        fprintf(stderr, "Invalid option. Use 'embed' or 'extract'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}