//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

unsigned char *bitmap;

void encode(unsigned char *bitmap, unsigned char *data, int size) {
    int i, j, k;
    unsigned char bit;

    for (i = 0, k = 0; i < size && k < MAX_SIZE; i++) {
        for (j = 0; j < 8 && k < MAX_SIZE; j++) {
            bit = (data[i] >> (7 - j)) & 1;
            bitmap[k] = (bitmap[k] & 0xFE) | bit;
            k++;
        }
    }
}

void decode(unsigned char *bitmap, unsigned char *data, int size) {
    int i, j, k;
    unsigned char bit;

    for (i = 0, k = 0; i < size && k < MAX_SIZE; i++) {
        for (j = 0; j < 8 && k < MAX_SIZE; j++) {
            bit = (bitmap[i] >> (7 - j)) & 1;
            data[k] = (data[k] << 1) | bit;
            k++;
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    unsigned char *bitmap, *data;
    int size;

    if (argc != 4) {
        printf("Usage: %s <bitmap file> <data file> <output file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error opening bitmap file.\n");
        return 1;
    }

    bitmap = (unsigned char *)malloc(MAX_SIZE);
    if (bitmap == NULL) {
        printf("Error allocating memory for bitmap.\n");
        return 1;
    }

    fread(bitmap, 1, MAX_SIZE, fp);
    fclose(fp);

    fp = fopen(argv[2], "rb");
    if (fp == NULL) {
        printf("Error opening data file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);

    data = (unsigned char *)malloc(size);
    if (data == NULL) {
        printf("Error allocating memory for data.\n");
        return 1;
    }

    fread(data, 1, size, fp);
    fclose(fp);

    encode(bitmap, data, size);

    fp = fopen(argv[3], "wb");
    if (fp == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    fwrite(bitmap, 1, MAX_SIZE, fp);
    fclose(fp);

    return 0;
}