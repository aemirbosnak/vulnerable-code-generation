//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define CHAR_SET_SIZE 96
#define CHAR_SET ".:+oxX#*-=+@%"

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image loadImage(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *data = malloc(size);
    if (data == NULL) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }

    fread(data, 1, size, fp);
    fclose(fp);

    Image image;
    image.width = *(int *)data;
    image.height = *(int *)(data + 4);
    image.data = data + 8;

    return image;
}

void saveAsciiArt(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    int maxValue = (int)log((double)CHAR_SET_SIZE) / log(2.0);
    int scale = maxValue - 1;

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int value = *(image->data + y * image->width + x) / (255.0 / maxValue);
            fprintf(fp, "%c", CHAR_SET[value * scale]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input.bmp output.txt\n", argv[0]);
        return 1;
    }

    Image image = loadImage(argv[1]);
    saveAsciiArt(&image, argv[2]);

    free(image.data);
    return 0;
}