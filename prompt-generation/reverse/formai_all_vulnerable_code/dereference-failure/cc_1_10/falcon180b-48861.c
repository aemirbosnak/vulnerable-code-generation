//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define CHAR_SET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_-=+;:,.?/~"

typedef struct {
    int width;
    int height;
    int max_val;
    int **data;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    int width, height, max_val;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    fread(&max_val, sizeof(int), 1, fp);

    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->max_val = max_val;
    img->data = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        img->data[i] = malloc(width * sizeof(int));
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int val;
            fread(&val, sizeof(int), 1, fp);
            img->data[i][j] = val;
        }
    }

    fclose(fp);
    return img;
}

void free_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->data[i]);
    }
    free(img->data);
    free(img);
}

void print_ascii_art(Image *img, int scale) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int val = img->data[i][j];
            int idx = val * scale / img->max_val;

            printf("%c", CHAR_SET[idx]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s input.bmp scale\n", argv[0]);
        return 1;
    }

    Image *img = read_image(argv[1]);
    int scale = atoi(argv[2]);

    print_ascii_art(img, scale);

    free_image(img);
    return 0;
}