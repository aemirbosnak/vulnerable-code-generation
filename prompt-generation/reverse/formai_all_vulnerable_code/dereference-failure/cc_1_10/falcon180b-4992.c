//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print the ASCII art
void printArt(int width, int height, char *art) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", art[y * width + x]);
        }
        printf("\n");
    }
}

// Function to convert the image to ASCII art
void imageToArt(char *filename, int width, int height, char *art) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    unsigned char *buffer = malloc(fileSize);
    if (buffer == NULL) {
        printf("Error: Could not allocate memory for buffer.\n");
        exit(1);
    }

    fread(buffer, fileSize, 1, file);
    fclose(file);

    int pixelCount = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            int r = buffer[index];
            int g = buffer[index + 1];
            int b = buffer[index + 2];

            int avg = (r + g + b) / 3;
            if (avg < 128) {
                art[pixelCount] = '@';
            } else if (avg < 192) {
                art[pixelCount] = '#';
            } else if (avg < 224) {
                art[pixelCount] = '$';
            } else {
                art[pixelCount] = '%';
            }

            pixelCount++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <width> <height> <filename>\n", argv[0]);
        exit(1);
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);

    char *art = malloc(width * height);
    if (art == NULL) {
        printf("Error: Could not allocate memory for art.\n");
        exit(1);
    }

    imageToArt(argv[3], width, height, art);
    printArt(width, height, art);

    free(art);
    return 0;
}