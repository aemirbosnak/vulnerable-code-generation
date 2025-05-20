//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
    char *data;
    int width;
    int height;
} Image;

void load_image(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Failed to open image file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    img->data = malloc(size);
    if (img->data == NULL) {
        printf("Error: Failed to allocate memory for image data.\n");
        exit(1);
    }

    fread(img->data, 1, size, fp);
    fclose(fp);

    int header_size = 54; // BMP file header size
    if (size < header_size ||
        img->data[0]!= 'B' || img->data[1]!= 'M') {
        printf("Error: Invalid image format.\n");
        exit(1);
    }

    int width = *(int *)(img->data + 18);
    int height = *(int *)(img->data + 22);

    img->width = width;
    img->height = height;
}

void free_image(Image *img) {
    free(img->data);
}

void print_ascii_art(const Image *img) {
    int x, y;
    for (y = 0; y < img->height; ++y) {
        for (x = 0; x < img->width; ++x) {
            int index = (y * img->width + x) * 3;
            int r = img->data[index];
            int g = img->data[index + 1];
            int b = img->data[index + 2];

            int brightness = (r + g + b) / 3;

            if (brightness < 128) {
                printf(" ");
            } else if (brightness < 192) {
                printf(".");
            } else if (brightness < 224) {
                printf(":");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    Image img;
    load_image(&img, argv[1]);
    print_ascii_art(&img);

    free_image(&img);
    return 0;
}