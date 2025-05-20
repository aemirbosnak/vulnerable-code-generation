//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 80 // maximum width of ASCII art
#define HEIGHT 60 // maximum height of ASCII art

typedef struct {
    char *filename; // filename of image
    int width; // width of image
    int height; // height of image
    unsigned char *data; // pixel data
} Image;

void load_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    img->data = malloc(filesize);
    fread(img->data, 1, filesize, fp);
    fclose(fp);

    img->filename = strdup(filename);
    img->width = *(int *)img->data;
    img->height = *(int *)(img->data + 4);
}

void free_image(Image *img) {
    free(img->data);
    free(img->filename);
}

void print_ascii_art(Image *img, int x, int y, int scale) {
    unsigned char *data = img->data + 8; // skip header
    int bytes_per_pixel = 3; // RGB

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int index = (i * img->width + j) * bytes_per_pixel;
            int r = data[index] * 8 / 3;
            int g = data[index + 1] * 8 / 3;
            int b = data[index + 2] * 8 / 3;

            int xpos = x + j * scale;
            int ypos = y + i * scale;

            if (xpos >= 0 && xpos < WIDTH && ypos >= 0 && ypos < HEIGHT) {
                printf("%c", (r << 5) | (g << 2) | b);
            }
        }
    }
}

int main() {
    Image img;
    load_image(&img, "example.bmp");

    int scale = WIDTH / img.width;
    int x = (WIDTH - img.width * scale) / 2;
    int y = (HEIGHT - img.height * scale) / 2;

    print_ascii_art(&img, x, y, scale);

    free_image(&img);

    return 0;
}