//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    int width;
    int height;
    char *data;
} Image;

void loadImage(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    img->data = malloc(size);
    fread(img->data, size, 1, fp);

    fclose(fp);

    int width = 0;
    int height = 0;
    while (width < MAX_WIDTH && height < MAX_HEIGHT && img->data[4 * (height * MAX_WIDTH + width) + 0]!= 0xff) {
        width++;
    }
    img->width = width;
    img->height = height;
}

void freeImage(Image *img) {
    free(img->data);
}

void printAsciiArt(Image *img) {
    int x, y;
    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            int pixel = img->data[4 * (y * MAX_WIDTH + x) + 0] & 0xff;
            int red = pixel >> 16 & 0xff;
            int green = pixel >> 8 & 0xff;
            int blue = pixel & 0xff;
            int brightness = (red + green + blue) / 3;
            if (brightness < 128) {
                printf("  ");
            } else if (brightness < 192) {
                printf(".");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    Image img;
    loadImage(&img, argv[1]);

    char *output_filename = argv[2];
    FILE *fp = fopen(output_filename, "w");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", output_filename);
        exit(1);
    }

    printAsciiArt(&img);

    fprintf(fp, "%s", "\n");
    fprintf(fp, "ASCII art generated from image %s\n", argv[1]);
    fprintf(fp, "%s", "\n");

    fclose(fp);

    freeImage(&img);

    return 0;
}