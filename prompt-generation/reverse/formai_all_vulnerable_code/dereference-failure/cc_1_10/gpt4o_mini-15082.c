//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    Pixel **pixels;
    int width, height;
} Image;

Image* create_image(int width, int height) {
    Image *img = (Image*)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = (Pixel**)malloc(height * sizeof(Pixel*));
    for (int i = 0; i < height; i++) {
        img->pixels[i] = (Pixel*)malloc(width * sizeof(Pixel));
    }
    return img;
}

void free_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
}

void flip_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width / 2; j++) {
            Pixel temp = img->pixels[i][j];
            img->pixels[i][j] = img->pixels[i][img->width - j - 1];
            img->pixels[i][img->width - j - 1] = temp;
        }
    }
}

void adjust_brightness(Image *img, int value) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixels[i][j].r = (img->pixels[i][j].r + value > 255) ? 255 : 
                                   (img->pixels[i][j].r + value < 0) ? 0 : img->pixels[i][j].r + value;

            img->pixels[i][j].g = (img->pixels[i][j].g + value > 255) ? 255 : 
                                   (img->pixels[i][j].g + value < 0) ? 0 : img->pixels[i][j].g + value;

            img->pixels[i][j].b = (img->pixels[i][j].b + value > 255) ? 255 : 
                                   (img->pixels[i][j].b + value < 0) ? 0 : img->pixels[i][j].b + value;
        }
    }
}

void print_image(const Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("(%d, %d, %d) ", img->pixels[i][j].r, img->pixels[i][j].g, img->pixels[i][j].b);
        }
        printf("\n");
    }
}

void contrast_image(Image *img, float factor) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixels[i][j].r = (int)( factor * (img->pixels[i][j].r - 128) + 128);
            img->pixels[i][j].g = (int)( factor * (img->pixels[i][j].g - 128) + 128);
            img->pixels[i][j].b = (int)( factor * (img->pixels[i][j].b - 128) + 128);

            // Clamp values to 0-255
            img->pixels[i][j].r = (img->pixels[i][j].r > 255) ? 255 : (img->pixels[i][j].r < 0) ? 0 : img->pixels[i][j].r;
            img->pixels[i][j].g = (img->pixels[i][j].g > 255) ? 255 : (img->pixels[i][j].g < 0) ? 0 : img->pixels[i][j].g;
            img->pixels[i][j].b = (img->pixels[i][j].b > 255) ? 255 : (img->pixels[i][j].b < 0) ? 0 : img->pixels[i][j].b;
        }
    }
}

int main() {
    int width = 5, height = 5;
    Image *img = create_image(width, height);

    // Initializing the image with some sample color data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            img->pixels[i][j].r = (i * 50 + j * 10) % 256;
            img->pixels[i][j].g = (j * 100) % 256;
            img->pixels[i][j].b = (i * 20 + j * 30) % 256;
        }
    }

    printf("Original Image:\n");
    print_image(img);

    printf("\nFlipping Image:\n");
    flip_image(img);
    print_image(img);

    printf("\nAdjusting Brightness (+50):\n");
    adjust_brightness(img, 50);
    print_image(img);

    printf("\nAdjusting Contrast (factor 1.2):\n");
    contrast_image(img, 1.2);
    print_image(img);

    free_image(img);
    return 0;
}