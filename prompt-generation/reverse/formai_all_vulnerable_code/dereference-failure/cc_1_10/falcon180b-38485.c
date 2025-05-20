//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    int width;
    int height;
    char *data;
} image_t;

typedef struct {
    int x;
    int y;
    char c;
    int color;
} pixel_t;

void load_image(image_t *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    rewind(fp);

    img->data = malloc(size);
    if (img->data == NULL) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }

    fread(img->data, 1, size, fp);
    fclose(fp);

    img->width = atoi(strtok(filename, "."));
    img->height = atoi(strtok(NULL, "."));
}

void free_image(image_t *img) {
    free(img->data);
}

int get_pixel(image_t *img, int x, int y) {
    return (int)img->data[y * img->width + x];
}

void set_pixel(image_t *img, int x, int y, int color) {
    int index = y * img->width + x;
    img->data[index] = color;
}

void print_ascii_art(image_t *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int color = get_pixel(img, x, y);
            int ascii_char = (color / 16) + 33;

            printf("%c", ascii_char);
        }
        printf("\n");
    }
}

int main() {
    image_t img;
    load_image(&img, "example.bmp");

    print_ascii_art(&img);

    free_image(&img);

    return 0;
}