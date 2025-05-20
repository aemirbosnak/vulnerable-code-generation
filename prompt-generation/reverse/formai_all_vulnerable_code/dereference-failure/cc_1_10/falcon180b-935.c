//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_QR_SIZE 1000
#define BLACK 0
#define WHITE 1

typedef struct {
    int x, y;
    int color;
} Pixel;

Pixel *readQRCode(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    rewind(fp);

    unsigned char *buffer = (unsigned char *) malloc(filesize);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    fread(buffer, 1, filesize, fp);
    fclose(fp);

    int width = 0, height = 0;
    for (int i = 0; i < filesize; i++) {
        if (buffer[i] == 0xD4) {
            width = buffer[i + 1] * 8 + buffer[i + 2];
            height = buffer[i + 3] * 8 + buffer[i + 4];
            break;
        }
    }

    Pixel *pixels = (Pixel *) malloc(width * height * sizeof(Pixel));
    if (pixels == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    int pos = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char c = buffer[pos++];
            if ((c & 0x80) == 0) {
                pixels[y * width + x].color = BLACK;
            } else {
                pixels[y * width + x].color = WHITE;
            }
        }
    }

    return pixels;
}

void printQRCode(Pixel *pixels, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (pixels[y * width + x].color == BLACK) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    Pixel *pixels = readQRCode(argv[1]);
    printQRCode(pixels, MAX_QR_SIZE, MAX_QR_SIZE);

    free(pixels);
    return 0;
}