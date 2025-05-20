//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXELS 1000
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    int width;
    int height;
    char *pixels;
} Image;

Image loadImage(char *filename)
{
    FILE *fp;
    int width, height, i, j;
    char header[54];
    Image img;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fread(header, 1, 54, fp);

    if (memcmp(header, "BM", 2)!= 0) {
        printf("Error: File is not a valid BMP image\n");
        exit(1);
    }

    width = *(int *)&header[18];
    height = *(int *)&header[22];

    img.width = width;
    img.height = height;
    img.pixels = malloc(3 * width * height);

    fseek(fp, 54, SEEK_SET);

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fread(&img.pixels[3 * (i * width + j)], 1, 3, fp);
        }
    }

    fclose(fp);

    return img;
}

void saveAsciiArt(Image img, char *filename)
{
    FILE *fp;
    int i, j;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    for (i = 0; i < img.height; i++) {
        for (j = 0; j < img.width; j++) {
            int r = img.pixels[3 * (i * img.width + j)];
            int g = img.pixels[3 * (i * img.width + j) + 1];
            int b = img.pixels[3 * (i * img.width + j) + 2];

            int avg = (r + g + b) / 3;

            if (avg < 128) {
                fprintf(fp, " ");
            } else {
                fprintf(fp, "*");
            }
        }

        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char *argv[])
{
    if (argc!= 3) {
        printf("Usage: %s input.bmp output.txt\n", argv[0]);
        exit(1);
    }

    Image img = loadImage(argv[1]);
    saveAsciiArt(img, argv[2]);

    free(img.pixels);

    return 0;
}