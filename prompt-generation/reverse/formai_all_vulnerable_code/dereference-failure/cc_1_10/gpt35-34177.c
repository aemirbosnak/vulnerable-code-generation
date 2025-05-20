//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

void convertToAsciiArt(char (*ascii)[MAX_WIDTH], int width, int height, int* pixels);
void outputAsciiArt(char (*ascii)[MAX_WIDTH], int width, int height);

int main(int argc, char *argv[]) {

    if(argc < 2) {
        printf("Error: No file provided\n");
        return 1;
    }

    FILE* fp = fopen(argv[1], "rb");
    if(fp == NULL) {
        printf("Error: Unable to open file\n");
        return 1;
    }

    // Get image dimensions
    char buf[10];
    fgets(buf, 10, fp);
    int width = strtol(buf, NULL, 10);
    fgets(buf, 10, fp);
    int height = strtol(buf, NULL, 10);

    if(width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Image too large\n");
        return 1;
    }

    // Read pixel data
    int pixels[MAX_WIDTH * MAX_HEIGHT];
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            fgets(buf, 10, fp);
            pixels[i * width + j] = strtol(buf, NULL, 10);
        }
    }

    // Convert image to ASCII art
    char ascii[MAX_HEIGHT][MAX_WIDTH];
    convertToAsciiArt(ascii, width, height, pixels);

    // Print ASCII art
    outputAsciiArt(ascii, width, height);

    fclose(fp);
    return 0;
}

void convertToAsciiArt(char (*ascii)[MAX_WIDTH], int width, int height, int* pixels) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int pixel = pixels[i * width + j];

            if(pixel < 64) {
                ascii[i][j] = '#';
            } else if(pixel < 128) {
                ascii[i][j] = 'X';
            } else if(pixel < 192) {
                ascii[i][j] = '-';
            } else {
                ascii[i][j] = ' ';
            }
        }
    }
}

void outputAsciiArt(char (*ascii)[MAX_WIDTH], int width, int height) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            printf("%c", ascii[i][j]);
        }
        printf("\n");
    }
}