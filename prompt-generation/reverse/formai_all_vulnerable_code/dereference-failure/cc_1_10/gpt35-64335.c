//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_RGB_VALUE 255

typedef unsigned char BYTE;
typedef struct {
    BYTE r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

void flip_image(Image *img);
void adjust_brightness(Image *img, int brightness_change);
void adjust_contrast(Image *img, double contrast_factor);
void print_image(Image *img);
void free_image(Image *img);

int main() {
    Image *test_image = malloc(sizeof(Image)); // create a new image
    test_image->width = WIDTH;
    test_image->height = HEIGHT;
    test_image->data = malloc(sizeof(Pixel) * WIDTH * HEIGHT);

    // generate a random image
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            test_image->data[i * WIDTH + j].r = rand() % MAX_RGB_VALUE;
            test_image->data[i * WIDTH + j].g = rand() % MAX_RGB_VALUE;
            test_image->data[i * WIDTH + j].b = rand() % MAX_RGB_VALUE;
        }
    }

    printf("Original image:\n");
    print_image(test_image);

    // flip the image
    flip_image(test_image);
    printf("Flipped image:\n");
    print_image(test_image);

    // change the brightness
    adjust_brightness(test_image, 50);
    printf("Brightened image:\n");
    print_image(test_image);

    // change the contrast
    adjust_contrast(test_image, 2.0);
    printf("High contrast image:\n");
    print_image(test_image);

    // free memory
    free_image(test_image);
    return 0;
}

void flip_image(Image *img) {
    Pixel *temp_row = malloc(sizeof(Pixel) * img->width);

    for (int i = 0; i < img->height / 2; i++) {
        // swap top and bottom rows
        int top_row_index = i * img->width;
        int bottom_row_index = (img->height - 1 - i) * img->width;
        memcpy(temp_row, img->data + top_row_index, sizeof(Pixel) * img->width);
        memcpy(img->data + top_row_index, img->data + bottom_row_index, sizeof(Pixel) * img->width);
        memcpy(img->data + bottom_row_index, temp_row, sizeof(Pixel) * img->width);
    }

    free(temp_row);
}

void adjust_brightness(Image *img, int brightness_change) {
    for (int i = 0; i < img->width * img->height; i++) {
        // adjust each pixel
        img->data[i].r = img->data[i].r + brightness_change > MAX_RGB_VALUE ? MAX_RGB_VALUE : img->data[i].r + brightness_change;
        img->data[i].g = img->data[i].g + brightness_change > MAX_RGB_VALUE ? MAX_RGB_VALUE : img->data[i].g + brightness_change;
        img->data[i].b = img->data[i].b + brightness_change > MAX_RGB_VALUE ? MAX_RGB_VALUE : img->data[i].b + brightness_change;
    }
}

void adjust_contrast(Image *img, double contrast_factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        // adjust each pixel
        img->data[i].r = contrast_factor * (img->data[i].r - MAX_RGB_VALUE / 2) + MAX_RGB_VALUE / 2;
        img->data[i].g = contrast_factor * (img->data[i].g - MAX_RGB_VALUE / 2) + MAX_RGB_VALUE / 2;
        img->data[i].b = contrast_factor * (img->data[i].b - MAX_RGB_VALUE / 2) + MAX_RGB_VALUE / 2;
        // clamp values
        img->data[i].r = img->data[i].r > MAX_RGB_VALUE ? MAX_RGB_VALUE : img->data[i].r;
        img->data[i].g = img->data[i].g > MAX_RGB_VALUE ? MAX_RGB_VALUE : img->data[i].g;
        img->data[i].b = img->data[i].b > MAX_RGB_VALUE ? MAX_RGB_VALUE : img->data[i].b;
        img->data[i].r = img->data[i].r < 0 ? 0 : img->data[i].r;
        img->data[i].g = img->data[i].g < 0 ? 0 : img->data[i].g;
        img->data[i].b = img->data[i].b < 0 ? 0 : img->data[i].b;
    }
}

void print_image(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        if (i % img->width == 0) {
            printf("\n");
        }
        printf("(%d, %d, %d) ", img->data[i].r, img->data[i].g, img->data[i].b);
    }
    printf("\n");
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}