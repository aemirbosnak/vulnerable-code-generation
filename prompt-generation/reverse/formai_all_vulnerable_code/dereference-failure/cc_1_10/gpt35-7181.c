//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 40

char asciiChars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

int getBrightness(int r, int g, int b) {
    return (r + g + b) / 3;
}

char getAsciiChar(int brightness) {
    int charCount = sizeof(asciiChars) / sizeof(asciiChars[0]);
    int brightnessRange = (255 / charCount) + 1;
    int charIndex = brightness / brightnessRange;
    charIndex = charIndex >= charCount ? charCount - 1 : charIndex;
    return asciiChars[charIndex];
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: imageConverter <imagePath>");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        printf("Error reading file");
        return 1;
    }

    char* fileBuffer = (char*)malloc(WIDTH * HEIGHT * 3);
    if (!fileBuffer) {
        printf("Error allocating memory");
        return 1;
    }

    fseek(file, 54, SEEK_SET);
    fread(fileBuffer, WIDTH * HEIGHT * 3, 1, file);
    fclose(file);

    char asciiImage[HEIGHT][WIDTH];
    memset(asciiImage, ' ', HEIGHT * WIDTH);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int pixelIndex = (y * WIDTH + x) * 3;
            int r = fileBuffer[pixelIndex + 2];
            int g = fileBuffer[pixelIndex + 1];
            int b = fileBuffer[pixelIndex];
            int brightness = getBrightness(r, g, b);
            asciiImage[y][x] = getAsciiChar(brightness);
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", asciiImage[y][x]);
        }
        printf("\n");
    }

    free(fileBuffer);
    return 0;
}