//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_LEN 256
#define ASCII_CHARS " .'`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0Zmwqpdbkhao*#MW&8%B@$"
#define CHAR_WIDTH 2
#define CHAR_HEIGHT 1

typedef struct {
    uint8_t r, g, b;
} Color;

typedef struct {
    Color **data;
    int width;
    int height;
} Image;

Image *loadImage(const char *filename);
void freeImage(Image *img);
void printAsciiArt(Image *img);
char getAsciiChar(Color color);
int getBrightness(Color color);
void drawSlice(Image *img, int start_col, int end_col, int y);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = loadImage(argv[1]);
    if (img == NULL) {
        fprintf(stderr, "Error loading image.\n");
        return EXIT_FAILURE;
    }

    printf("Converting image to ASCII art...\n");
    printAsciiArt(img);

    freeImage(img);
    return EXIT_SUCCESS;
}

Image *loadImage(const char *filename) {
    // Placeholder: Implement your image loading logic here
    // For now, we will return a dummy image
    Image *img = malloc(sizeof(Image));
    img->width = 10;
    img->height = 10;
    img->data = malloc(img->height * sizeof(Color *));
    for (int i = 0; i < img->height; i++) {
        img->data[i] = malloc(img->width * sizeof(Color));
        for (int j = 0; j < img->width; j++) {
            img->data[i][j] = (Color){rand() % 256, rand() % 256, rand() % 256}; // Random colors
        }
    }
    return img;
}

void freeImage(Image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->data[i]);
    }
    free(img->data);
    free(img);
}

void printAsciiArt(Image *img) {
    for (int y = 0; y < img->height; y += CHAR_HEIGHT) {
        drawSlice(img, 0, img->width, y);
    }
}

void drawSlice(Image *img, int start_col, int end_col, int y) {
    for (int x = start_col; x < end_col; x += CHAR_WIDTH) {
        if (x < img->width) {
            Color color = img->data[y][x];
            char ascii_char = getAsciiChar(color);
            printf("%c", ascii_char);
        }
    }
    printf("\n");
}

char getAsciiChar(Color color) {
    int brightness = getBrightness(color);
    int index = (brightness * (strlen(ASCII_CHARS) - 1)) / 255;
    return ASCII_CHARS[index];
}

int getBrightness(Color color) {
    return (color.r + color.g + color.b) / 3;
}