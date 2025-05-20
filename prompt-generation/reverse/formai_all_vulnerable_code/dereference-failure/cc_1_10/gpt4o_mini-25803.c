//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_CHARS "@%#*+=-:. "

typedef struct {
    uint8_t r, g, b;
} Pixel;

void readPPM(const char *filename, Pixel image[MAX_HEIGHT][MAX_WIDTH], int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char header[3];
    fgets(header, sizeof(header), file);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported file format\n");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %d\n", width, height);
    int maxColorValue;
    fscanf(file, "%d\n", &maxColorValue);
    
    for (int y = 0; y < *height; y++) {
        for (int x = 0; x < *width; x++) {
            Pixel p;
            fread(&p, sizeof(Pixel), 1, file);
            image[y][x] = p;
        }
    }

    fclose(file);
}

char getAsciiChar(uint8_t gray) {
    int index = gray * (strlen(ASCII_CHARS) - 1) / 255;
    return ASCII_CHARS[index];
}

void convertToAscii(Pixel image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    printf("\033[0;37m"); // Set color to white
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            uint8_t gray = (image[y][x].r + image[y][x].g + image[y][x].b) / 3;
            char asciiChar = getAsciiChar(gray);
            putchar(asciiChar);
        }
        putchar('\n');
    }
    printf("\033[0m"); // Reset color
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Pixel image[MAX_HEIGHT][MAX_WIDTH];
    int width, height;

    readPPM(argv[1], image, &width, &height);
    
    // Adjust dimensions to not exceed MAX_WIDTH and MAX_HEIGHT
    if (width > MAX_WIDTH) {
        float aspectRatio = (float)height / (float)width;
        height = (int)(MAX_WIDTH * aspectRatio);
        width = MAX_WIDTH;
    }
    if (height > MAX_HEIGHT) {
        float aspectRatio = (float)width / (float)height;
        width = (int)(MAX_HEIGHT * aspectRatio);
        height = MAX_HEIGHT;
    }

    convertToAscii(image, width, height);
    return EXIT_SUCCESS;
}