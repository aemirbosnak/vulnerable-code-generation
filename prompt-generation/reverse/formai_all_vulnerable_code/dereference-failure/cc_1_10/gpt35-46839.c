//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_VALUE 255

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

Image* create_image(int width, int height) {
    Image *img = (Image*) malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = (Pixel*) malloc(sizeof(Pixel) * width * height);
    return img;
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}

void set_pixel(Image *img, int x, int y, Pixel p) {
    img->data[(y * img->width) + x] = p;
}

Pixel get_pixel(Image *img, int x, int y) {
    return img->data[(y * img->width) + x];
}

void flip_horizontally(Image *img) {
    Pixel temp;
    int x, y;
    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width / 2; x++) {
            temp = get_pixel(img, x, y);
            set_pixel(img, x, y, get_pixel(img, img->width - x - 1, y));
            set_pixel(img, img->width - x - 1, y, temp);
        }
    }
}

void change_brightness(Image *img, int brightness) {
    int i;
    for (i = 0; i < img->width * img->height; i++) {
        img->data[i].red += brightness;
        img->data[i].green += brightness;
        img->data[i].blue += brightness;

        if (img->data[i].red > MAX_COLOR_VALUE) {
            img->data[i].red = MAX_COLOR_VALUE;
        }
        if (img->data[i].green > MAX_COLOR_VALUE) {
            img->data[i].green = MAX_COLOR_VALUE;
        }
        if (img->data[i].blue > MAX_COLOR_VALUE) {
            img->data[i].blue = MAX_COLOR_VALUE;
        }

        if (img->data[i].red < 0) {
            img->data[i].red = 0;
        }
        if (img->data[i].green < 0) {
            img->data[i].green = 0;
        }
        if (img->data[i].blue < 0) {
            img->data[i].blue = 0;
        }
    }
}

void change_contrast(Image *img, float contrast) {
    int i;
    for (i = 0; i < img->width * img->height; i++) {
        float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
        
        int r = img->data[i].red - 128;
        int g = img->data[i].green - 128;
        int b = img->data[i].blue - 128;
        
        img->data[i].red = (unsigned char) (factor * r + 128);
        img->data[i].green = (unsigned char) (factor * g + 128);
        img->data[i].blue = (unsigned char) (factor * b + 128);
    }
}

int main() {
    int i;
    Image *img = create_image(5, 5);
    for (i = 0; i < 25; i++) {
        img->data[i].red = i * 10;
        img->data[i].green = i * 10;
        img->data[i].blue = i * 10;
    }

    flip_horizontally(img);
    change_brightness(img, 50);
    change_contrast(img, 75);

    printf("P3\n%d %d\n%d\n", img->width, img->height, MAX_COLOR_VALUE);
    for (i = 0; i < img->width * img->height; i++) {
        printf("%d %d %d ", img->data[i].red, img->data[i].green, img->data[i].blue);
    }

    free_image(img);
    return 0;
}