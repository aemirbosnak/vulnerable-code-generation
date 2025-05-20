//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_ART_WIDTH 80
#define ASCII_ART_HEIGHT 24
#define ASCII_ART_CHARS ".:-=+*#@%"

typedef struct {
    int x;
    int y;
    int value;
} Pixel;

typedef struct {
    Pixel *data;
    int width;
    int height;
} Image;

Image *loadImage(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Failed to open %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *data = malloc(filesize);
    if (data == NULL) {
        printf("Error: Failed to allocate memory\n");
        exit(1);
    }

    fread(data, filesize, 1, fp);
    fclose(fp);

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        printf("Error: Failed to allocate memory\n");
        exit(1);
    }

    image->data = malloc(sizeof(Pixel) * ASCII_ART_WIDTH * ASCII_ART_HEIGHT);
    if (image->data == NULL) {
        printf("Error: Failed to allocate memory\n");
        exit(1);
    }

    image->width = ASCII_ART_WIDTH;
    image->height = ASCII_ART_HEIGHT;

    int pixelCount = 0;
    for (int y = 0; y < ASCII_ART_HEIGHT; y++) {
        for (int x = 0; x < ASCII_ART_WIDTH; x++) {
            int index = (y * ASCII_ART_WIDTH + x) * 3;
            int r = data[index];
            int g = data[index + 1];
            int b = data[index + 2];

            int value = (r + g + b) / 3;

            image->data[pixelCount].x = x;
            image->data[pixelCount].y = y;
            image->data[pixelCount].value = value;

            pixelCount++;
        }
    }

    free(data);

    return image;
}

void saveASCIIArt(Image *image, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Failed to open %s\n", filename);
        exit(1);
    }

    for (int y = 0; y < ASCII_ART_HEIGHT; y++) {
        for (int x = 0; x < ASCII_ART_WIDTH; x++) {
            Pixel *pixel = &image->data[y * ASCII_ART_WIDTH + x];

            int asciiChar = ASCII_ART_CHARS[pixel->value / 8];

            fprintf(fp, "%c", asciiChar);
        }

        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input.png output.txt\n", argv[0]);
        return 1;
    }

    Image *image = loadImage(argv[1]);
    if (image == NULL) {
        return 1;
    }

    saveASCIIArt(image, argv[2]);

    free(image->data);
    free(image);

    return 0;
}