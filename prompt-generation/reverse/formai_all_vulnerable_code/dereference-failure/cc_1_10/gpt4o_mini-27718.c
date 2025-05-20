//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BMPHeader;

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
#pragma pack(pop)

void embed_message(const char *imagefile, const char *messagefile);
void extract_message(const char *imagefile);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <embed/extract> <image.bmp> <message.txt>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embed_message(argv[2], argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extract_message(argv[2]);
    } else {
        printf("Invalid option. Use 'embed' or 'extract'.\n");
        return 1;
    }

    return 0;
}

void embed_message(const char *imagefile, const char *messagefile) {
    FILE *img = fopen(imagefile, "rb+");
    FILE *msg = fopen(messagefile, "rb");
    if (!img || !msg) {
        perror("Error opening file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, img);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, img);

    fseek(msg, 0, SEEK_END);
    long messageSize = ftell(msg);
    rewind(msg);

    char *message = malloc(messageSize + 1);
    fread(message, 1, messageSize, msg);
    message[messageSize] = '\0';

    fseek(img, bmpHeader.bfOffBits, SEEK_SET);

    for (int i = 0; i < messageSize; i++) {
        char c = message[i];
        for (int j = 0; j < 8; j++) {
            unsigned char pixel[3];
            fread(pixel, 3, 1, img);
            pixel[0] = (pixel[0] & 0xFE) | ((c >> (7 - j)) & 0x01);
            fwrite(pixel, 3, 1, img);
        }
    }

    free(message);
    fclose(img);
    fclose(msg);
    printf("Message embedded successfully.\n");
}

void extract_message(const char *imagefile) {
    FILE *img = fopen(imagefile, "rb");
    if (!img) {
        perror("Error opening file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, img);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, img);

    fseek(img, bmpHeader.bfOffBits, SEEK_SET);

    char c;
    char *message = malloc(1024); // Use a buffer of size 1024 for extracted message
    int idx = 0;

    while (!feof(img)) {
        c = 0;
        for (int j = 0; j < 8; j++) {
            unsigned char pixel[3];
            fread(pixel, 3, 1, img);
            c <<= 1;
            c |= (pixel[0] & 0x01);
        }
        if (c == '\0') break; // Stop if null terminator is hit
        message[idx++] = c;
    }
    message[idx] = '\0';

    printf("Extracted Message: %s\n", message);
    free(message);
    fclose(img);
}