//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    char *data;
    int width;
    int height;
} Image;

void load_image(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    img->data = malloc(size);
    fread(img->data, size, 1, fp);
    fclose(fp);

    int width, height;
    if (fgetc(fp)!= 0x42 || fgetc(fp)!= 0x4d ||
        fgetc(fp)!= 0x36 || fgetc(fp)!= 0x0a) {
        printf("Error: Invalid BMP file\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET);
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);

    img->width = width;
    img->height = height;
}

void convert_to_ascii(Image *img, char *output) {
    int i, j, k;
    int x, y;
    int r, g, b;

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            x = i * MAX_WIDTH + j;
            if (x >= MAX_WIDTH * MAX_HEIGHT) {
                break;
            }

            r = img->data[i * img->width + j] >> 16 & 0xff;
            g = img->data[i * img->width + j] >> 8 & 0xff;
            b = img->data[i * img->width + j] & 0xff;

            k = (r + g + b) / 3;

            if (k < 0) {
                k = 0;
            } else if (k > 6) {
                k = 6;
            }

            output[x] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[k];
        }
    }

    output[MAX_WIDTH * MAX_HEIGHT - 1] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input.bmp output.txt\n", argv[0]);
        return 1;
    }

    Image img;
    load_image(&img, argv[1]);

    char output[MAX_WIDTH * MAX_HEIGHT];
    convert_to_ascii(&img, output);

    FILE *fp = fopen(argv[2], "wb");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", argv[2]);
        return 1;
    }

    fwrite(output, strlen(output), 1, fp);
    fclose(fp);

    printf("Conversion completed\n");

    return 0;
}