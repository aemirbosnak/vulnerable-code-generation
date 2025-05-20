//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL 255

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    Pixel **pixels;
    int width;
    int height;
} Image;

Image* create_image(int width, int height) {
    Image *img = (Image *)malloc(sizeof(Image));
    img->width = width;
    img->height = height;

    img->pixels = (Pixel **)malloc(height * sizeof(Pixel *));
    for (int i = 0; i < height; i++) {
        img->pixels[i] = (Pixel *)malloc(width * sizeof(Pixel));
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

void set_pixel(Image *img, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    img->pixels[y][x].r = r;
    img->pixels[y][x].g = g;
    img->pixels[y][x].b = b;
}

Pixel get_pixel(Image *img, int x, int y) {
    return img->pixels[y][x];
}

void flip_image_horizontal(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            Pixel temp = img->pixels[y][x];
            img->pixels[y][x] = img->pixels[y][img->width - x - 1];
            img->pixels[y][img->width - x - 1] = temp;
        }
    }
}

void adjust_brightness(Image *img, int amount) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            Pixel *p = &img->pixels[y][x];
            p->r = (p->r + amount > MAX_PIXEL) ? MAX_PIXEL : (p->r + amount < 0 ? 0 : p->r + amount);
            p->g = (p->g + amount > MAX_PIXEL) ? MAX_PIXEL : (p->g + amount < 0 ? 0 : p->g + amount);
            p->b = (p->b + amount > MAX_PIXEL) ? MAX_PIXEL : (p->b + amount < 0 ? 0 : p->b + amount);
        }
    }
}

void adjust_contrast(Image *img, float factor) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            Pixel *p = &img->pixels[y][x];
            p->r = (unsigned char)(p->r * factor > MAX_PIXEL ? MAX_PIXEL : p->r * factor);
            p->g = (unsigned char)(p->g * factor > MAX_PIXEL ? MAX_PIXEL : p->g * factor);
            p->b = (unsigned char)(p->b * factor > MAX_PIXEL ? MAX_PIXEL : p->b * factor);
        }
    }
}

void print_image_data(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            Pixel p = get_pixel(img, x, y);
            printf("(%d, %d) -> R: %d, G: %d, B: %d\n", x, y, p.r, p.g, p.b);
        }
    }
}

int main() {
    int width = 5, height = 5;
    Image *myImage = create_image(width, height);
    
    // Initialize image with some colors
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            set_pixel(myImage, x, y, (unsigned char)(x * 50 % 256), (unsigned char)(y * 50 % 256), (unsigned char)((x + y) * 25 % 256));
        }
    }
    
    printf("Original Image Data:\n");
    print_image_data(myImage);

    // Flip and adjust
    flip_image_horizontal(myImage);
    printf("\nFlipped Image Data:\n");
    print_image_data(myImage);

    adjust_brightness(myImage, 20);
    printf("\nBrightened Image Data:\n");
    print_image_data(myImage);

    adjust_contrast(myImage, 1.2);
    printf("\nContrast Adjusted Image Data:\n");
    print_image_data(myImage);

    free_image(myImage);
    return 0;
}