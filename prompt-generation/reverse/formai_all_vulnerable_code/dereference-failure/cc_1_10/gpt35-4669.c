//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK 12

void printWatermark(char watermark[]) {
    printf("This image is watermarked with: %s\n", watermark);
}

int main() {
    char watermark[WATERMARK] = "Peaceful";
    FILE *imageFile = fopen("image.bmp", "r+b");

    if (imageFile == NULL) {
        printf("Error: Unable to open the image file.\n");
        return 1;
    }

    fseek(imageFile, 0, SEEK_END);
    long int imageSize = ftell(imageFile);
    rewind(imageFile);

    char *imageBuffer = (char*) malloc(sizeof(char) * imageSize);
    fread(imageBuffer, sizeof(char), imageSize, imageFile);

    printWatermark(watermark);

    int watermarkByte = 0;
    int watermarkBit = 0;
    int watermarkSize = strlen(watermark);
    char pixel;
    int i, j;

    for (i = 54; i < imageSize - (WATERMARK * 8); i += 3) {
        pixel = 0;
        for (j = 0; j < 8; j++) {
            if (watermarkByte < watermarkSize) {
                watermarkBit = watermark[watermarkByte] & (1 << j);
            }
            pixel = pixel | (watermarkBit << j);
        }
        imageBuffer[i] = pixel;
        watermarkByte = (watermarkByte + 1) % watermarkSize;
    }

    fwrite(imageBuffer, sizeof(char), imageSize, imageFile);

    fclose(imageFile);
    free(imageBuffer);

    printf("Watermark successfully added to the image!\n");

    return 0;
}