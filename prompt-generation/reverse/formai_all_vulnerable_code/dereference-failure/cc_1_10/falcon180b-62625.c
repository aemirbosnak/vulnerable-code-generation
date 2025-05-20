//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

typedef struct {
    char *data;
    int width;
    int height;
} Image;

void load_image(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open image file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    rewind(fp);

    img->data = malloc(filesize);
    if (img->data == NULL) {
        printf("Error: could not allocate memory for image data.\n");
        exit(1);
    }

    fread(img->data, filesize, 1, fp);
    fclose(fp);

    img->width = WIDTH;
    img->height = HEIGHT;
}

void print_ascii_art(const Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int index = (y * img->width + x) * 3;
            int r = img->data[index];
            int g = img->data[index + 1];
            int b = img->data[index + 2];

            int brightness = (r + g + b) / 3;
            if (brightness < 128) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int main() {
    Image img;
    load_image(&img, "image.bmp");
    print_ascii_art(&img);

    free(img.data);
    return 0;
}