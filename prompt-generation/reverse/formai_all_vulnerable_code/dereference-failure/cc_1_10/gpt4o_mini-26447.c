//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;

typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t sizeImage;
    int32_t xPelsPerMeter;
    int32_t yPelsPerMeter;
    uint32_t clrUsed;
    uint32_t clrImportant;
} BMPInfoHeader;

void embedMessage(const char *imgFile, const char *msgFile, const char *outputFile) {
    FILE *img = fopen(imgFile, "rb");
    FILE *msg = fopen(msgFile, "r");
    FILE *out = fopen(outputFile, "wb");

    if (!img || !msg || !out) {
        fprintf(stderr, "Could not open files. Consent to the fates!\n");
        exit(1);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, img);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, img);

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, out);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, out);

    Pixel pixel;
    size_t msgLen = strlen(fgets(malloc(1024), 1024, msg));
    fseek(msg, 0, SEEK_SET);
    char *message = (char *)malloc(msgLen + 1);
    fread(message, 1, msgLen, msg);
    message[msgLen] = '\0';

    for (size_t i = 0; i < msgLen; i++) {
        for (int j = 0; j < 8; j++) {
            fread(&pixel, sizeof(Pixel), 1, img);
            pixel.red = (pixel.red & 0xFE) | ((message[i] >> (7 - j)) & 0x1);
            fwrite(&pixel, sizeof(Pixel), 1, out);
        }
    }

    while (fread(&pixel, sizeof(Pixel), 1, img)) {
        fwrite(&pixel, sizeof(Pixel), 1, out);
    }

    fclose(img);
    fclose(msg);
    fclose(out);
    free(message);
}

void extractMessage(const char *stegoFile) {
    FILE *stego = fopen(stegoFile, "rb");
    if (!stego) {
        fprintf(stderr, "Alas! Could not open the stego image.\n");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, stego);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, stego);

    Pixel pixel;
    char extractedMessage[1024] = {0};
    size_t msgIndex = 0;

    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 8; j++) {
            fread(&pixel, sizeof(Pixel), 1, stego);
            if (msgIndex < 1023) {
                extractedMessage[msgIndex] = (extractedMessage[msgIndex] << 1) | (pixel.red & 0x1);
            }
            if (j == 7) {
                msgIndex++;
            }
        }
    }

    printf("The message is: %s\n", extractedMessage);
    fclose(stego);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "With great passion, use the format: %s <input_image> <message_file> <output_image> <action>\n", argv[0]);
        exit(1);
    }

    char *action = argv[4];

    if (strcmp(action, "embed") == 0) {
        embedMessage(argv[1], argv[2], argv[3]);
        printf("The message has been draped in silence within the canvas of colors.\n");
    } else if (strcmp(action, "extract") == 0) {
        extractMessage(argv[1]);
    } else {
        fprintf(stderr, "Alas, a tragic error! Please use 'embed' or 'extract'.\n");
    }

    return 0;
}