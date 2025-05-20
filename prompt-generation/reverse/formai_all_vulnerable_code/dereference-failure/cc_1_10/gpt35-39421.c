//FormAI DATASET v1.0 Category: Image Editor ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define IMAGE_WIDTH 80
#define IMAGE_HEIGHT 24

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

void draw_pixel(pixel *image, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    int offset = (y * IMAGE_WIDTH) + x;
    image[offset].r = r;
    image[offset].g = g;
    image[offset].b = b;
}

void read_image(pixel *image, char *filename) {
    FILE *fp = fopen(filename, "rb");
    fread(image, sizeof(pixel), IMAGE_WIDTH*IMAGE_HEIGHT, fp);
    fclose(fp);
}

void write_image(pixel *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fwrite(image, sizeof(pixel), IMAGE_WIDTH*IMAGE_HEIGHT, fp);
    fclose(fp);
}

void clear_image(pixel *image) {
    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            draw_pixel(image, x, y, 0, 0, 0);
        }
    }
}

int main() {
    pixel *image = (pixel*) calloc(IMAGE_WIDTH * IMAGE_HEIGHT, sizeof(pixel));
    char filename_in[] = "input.ppm";
    char filename_out[] = "output.ppm";
    read_image(image, filename_in);

    clear_image(image);
    draw_pixel(image, 40, 12, 255, 255, 255);
    write_image(image, filename_out);

    free(image);
    return 0;
}