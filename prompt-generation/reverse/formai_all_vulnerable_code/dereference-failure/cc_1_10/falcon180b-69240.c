//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_PIXELS (WIDTH * HEIGHT)

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

void init_image(Image *img) {
    img->width = WIDTH;
    img->height = HEIGHT;
    img->pixels = (Pixel *)malloc(MAX_PIXELS * sizeof(Pixel));
    memset(img->pixels, 0, MAX_PIXELS * sizeof(Pixel));
}

void set_pixel(Image *img, int x, int y, int r, int g, int b) {
    int index = (y * WIDTH) + x;
    if (index >= 0 && index < MAX_PIXELS) {
        img->pixels[index].x = x;
        img->pixels[index].y = y;
        img->pixels[index].r = r;
        img->pixels[index].g = g;
        img->pixels[index].b = b;
    }
}

void save_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp!= NULL) {
        fwrite(img->pixels, sizeof(Pixel), MAX_PIXELS, fp);
        fclose(fp);
    }
}

void load_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp!= NULL) {
        fread(img->pixels, sizeof(Pixel), MAX_PIXELS, fp);
        fclose(fp);
    }
}

void print_image(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            Pixel *p = &img->pixels[(y * img->width) + x];
            printf("%d,%d,%d\n", p->x, p->y, p->r);
        }
    }
}

int main() {
    Image image1, image2;
    init_image(&image1);
    init_image(&image2);

    set_pixel(&image1, 0, 0, 255, 0, 0);
    set_pixel(&image1, 0, 1, 0, 255, 0);
    set_pixel(&image1, 0, 2, 0, 0, 255);
    set_pixel(&image1, 0, 3, 255, 255, 255);

    set_pixel(&image2, 0, 0, 0, 0, 0);
    set_pixel(&image2, 0, 1, 0, 0, 0);
    set_pixel(&image2, 0, 2, 0, 0, 0);
    set_pixel(&image2, 0, 3, 0, 0, 0);

    save_image(&image1, "image1.bin");
    save_image(&image2, "image2.bin");

    load_image(&image2, "image1.bin");

    print_image(&image1);
    print_image(&image2);

    return 0;
}