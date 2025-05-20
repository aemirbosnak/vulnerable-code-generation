//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MAX_PIXEL_VALUE 255

void convertToAscii(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height);

int main() {
    char fileName[100];
    int width, height, maxPixelValue;
    unsigned char image[MAX_HEIGHT][MAX_WIDTH];
    FILE *filePointer;

    printf("Enter the file name of the image you want to convert: ");
    scanf("%s", fileName);

    filePointer = fopen(fileName, "rb");

    if (filePointer == NULL) {
        printf("Could not open file.");
        return 0;
    }

    char buffer[1024];
    fgets(buffer, 1024, filePointer);

    fscanf(filePointer, "%d %d %d", &width, &height, &maxPixelValue);
    fread(image, sizeof(unsigned char), width * height, filePointer);

    fclose(filePointer);

    convertToAscii(image, width, height);

    return 0;
}

void convertToAscii(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    int i, j;
    int charWidth = 6;
    int charHeight = 10;
    int scale = 2;
    int asciiWidth = width / charWidth;
    int asciiHeight = height / charHeight;
    char asciiImage[asciiHeight][asciiWidth];

    for (i = 0; i < asciiHeight; i++) {
        for (j = 0; j < asciiWidth; j++) {
            int x, y;
            float brightness = 0.0;

            for (x = 0; x < charHeight; x++) {
                for (y = 0; y < charWidth; y++) {
                    brightness += image[i * charHeight + x][j * charWidth + y];
                }
            }

            brightness /= (charWidth * charHeight * MAX_PIXEL_VALUE);

            if (brightness > 0.9) {
                asciiImage[i][j] = ' ';
            } else if (brightness > 0.8) {
                asciiImage[i][j] = '.';
            } else if (brightness > 0.7) {
                asciiImage[i][j] = '*';
            } else if (brightness > 0.6) {
                asciiImage[i][j] = ':';
            } else if (brightness > 0.5) {
                asciiImage[i][j] = 'o';
            } else if (brightness > 0.4) {
                asciiImage[i][j] = '&';
            } else if (brightness > 0.3) {
                asciiImage[i][j] = '8';
            } else if (brightness > 0.2) {
                asciiImage[i][j] = '#';
            } else {
                asciiImage[i][j] = '@';
            }
        }
    }

    for (i = 0; i < asciiHeight; i++) {
        for (j = 0; j < asciiWidth; j++) {
            int x, y;

            for (x = 0; x < scale; x++) {
                for (y = 0; y < scale; y++) {
                    printf("%c", asciiImage[i][j]);
                }
            }
        }
        printf("\n");
    }
}