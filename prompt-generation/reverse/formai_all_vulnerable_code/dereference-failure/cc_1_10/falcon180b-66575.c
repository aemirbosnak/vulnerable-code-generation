//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int width;
    int height;
    char *data;
} Image;

void create_image(Image *img, int width, int height) {
    img->width = width;
    img->height = height;
    img->data = (char *)malloc(sizeof(char) * width * height);
}

void destroy_image(Image *img) {
    free(img->data);
}

void set_pixel(Image *img, int x, int y, char value) {
    int offset = (y * img->width + x) * 3;
    img->data[offset] = value;
    img->data[offset + 1] = value;
    img->data[offset + 2] = value;
}

void save_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);

    int size = img->width * img->height;
    for (int i = 0; i < size; i++) {
        fputc(img->data[i], fp);
    }

    fclose(fp);
}

int main() {
    Image img;
    create_image(&img, 500, 500);

    for (int x = 0; x < img.width; x++) {
        for (int y = 0; y < img.height; y++) {
            int value = (x + y) % 256;
            set_pixel(&img, x, y, value);
        }
    }

    save_image(&img, "output.png");

    destroy_image(&img);

    return 0;
}