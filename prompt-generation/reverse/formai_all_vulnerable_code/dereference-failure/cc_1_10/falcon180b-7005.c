//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_PIXELS 256
#define WATERMARK_SIZE 8
#define WATERMARK_VALUE 5

int read_image(char* filename, int* pixels) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    rewind(fp);

    if (filesize!= MAX_PIXELS * 3) {
        printf("Error: Invalid image size\n");
        exit(1);
    }

    for (int i = 0; i < MAX_PIXELS; i++) {
        int red, green, blue;
        fread(&red, sizeof(int), 1, fp);
        fread(&green, sizeof(int), 1, fp);
        fread(&blue, sizeof(int), 1, fp);
        pixels[i] = (red + green + blue) / 3;
    }

    fclose(fp);
    return 0;
}

int add_watermark(int* pixels, int watermark_value) {
    for (int i = 0; i < MAX_PIXELS; i++) {
        int x = i % WATERMARK_SIZE;
        int y = i / WATERMARK_SIZE;

        if (x == 0 || x == WATERMARK_SIZE - 1 || y == 0 || y == WATERMARK_SIZE - 1) {
            pixels[i] += watermark_value;
        }
    }

    return 0;
}

int write_image(char* filename, int* pixels) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < MAX_PIXELS; i++) {
        int red = pixels[i] * 255;
        int green = red;
        int blue = red;

        fwrite(&red, sizeof(int), 1, fp);
        fwrite(&green, sizeof(int), 1, fp);
        fwrite(&blue, sizeof(int), 1, fp);
    }

    fclose(fp);
    return 0;
}

int main() {
    int pixels[MAX_PIXELS];

    read_image("image.bmp", pixels);
    add_watermark(pixels, WATERMARK_VALUE);
    write_image("watermarked_image.bmp", pixels);

    return 0;
}