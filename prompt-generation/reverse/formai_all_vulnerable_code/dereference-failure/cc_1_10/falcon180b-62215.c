//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct QRCode {
    int width;
    int height;
    int **data;
};

int getQRCode(int **data, int x, int y) {
    int color = data[y][x];
    if (color == 0) {
        return 0;
    }
    return 1 + getQRCode(data, x, y + 1) + getQRCode(data, x + 1, y + 1) + getQRCode(data, x + 1, y);
}

void printQRCode(int **data, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%d ", data[y][x]);
        }
        printf("\n");
    }
}

struct QRCode readQRCode(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *buffer = (char *) malloc(size + 1);
    fread(buffer, size, 1, fp);
    fclose(fp);
    int width = strlen(buffer) / 2;
    int height = strlen(buffer);
    int **data = (int **) malloc(height * sizeof(int *));
    for (int y = 0; y < height; y++) {
        data[y] = (int *) malloc(width * sizeof(int));
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            data[y][x] = buffer[y * 2 + x] - '0';
        }
    }
    return (struct QRCode) {.width = width,.height = height,.data = data};
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    struct QRCode qrcode = readQRCode(argv[1]);
    printf("Width: %d\n", qrcode.width);
    printf("Height: %d\n", qrcode.height);
    printQRCode(qrcode.data, qrcode.width, qrcode.height);
    for (int y = 0; y < qrcode.height; y++) {
        free(qrcode.data[y]);
    }
    free(qrcode.data);
    return 0;
}