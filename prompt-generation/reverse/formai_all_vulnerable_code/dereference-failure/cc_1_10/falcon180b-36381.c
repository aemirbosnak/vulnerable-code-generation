//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512

// Function to read image file and store it in a 2D array
void readImage(char* filename, unsigned char image[WIDTH][HEIGHT]) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open image file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp);

    unsigned char* buffer = (unsigned char*) malloc(fileSize);
    fread(buffer, fileSize, 1, fp);
    fclose(fp);

    int x = 0, y = 0;
    for (int i = 0; i < fileSize; i++) {
        if (x == WIDTH) {
            x = 0;
            y++;
        }
        image[y][x] = buffer[i];
        x++;
    }
}

// Function to embed watermark into image
void embedWatermark(unsigned char image[WIDTH][HEIGHT], char* watermark) {
    int watermarkSize = strlen(watermark);
    int x = 0, y = 0;

    for (int i = 0; i < watermarkSize; i++) {
        if (x == WIDTH) {
            x = 0;
            y++;
        }

        if (watermark[i] == '1') {
            image[y][x] ^= 0xff;
        } else {
            image[y][x] ^= 0x00;
        }

        x++;
    }
}

// Function to save image file
void saveImage(char* filename, unsigned char image[WIDTH][HEIGHT]) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open image file for writing.\n");
        exit(1);
    }

    for (int i = 0; i < WIDTH*HEIGHT; i++) {
        fputc(image[i], fp);
    }

    fclose(fp);
}

int main() {
    // Read image file
    unsigned char image[WIDTH][HEIGHT];
    readImage("input.bmp", image);

    // Embed watermark
    char* watermark = "This is a secret message";
    embedWatermark(image, watermark);

    // Save watermarked image
    saveImage("output.bmp", image);

    return 0;
}