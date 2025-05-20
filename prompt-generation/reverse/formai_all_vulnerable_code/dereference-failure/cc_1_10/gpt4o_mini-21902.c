//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    Pixel** data;
    int width;
    int height;
} Image;

// Function to allocate memory for the image
Image* create_image(int width, int height) {
    Image* img = (Image*)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = (Pixel**)malloc(height * sizeof(Pixel*));
    
    for (int i = 0; i < height; i++) {
        img->data[i] = (Pixel*)malloc(width * sizeof(Pixel));
    }

    return img;
}

// Function to free the image memory
void free_image(Image* img) {
    for (int i = 0; i < img->height; i++) {
        free(img->data[i]);
    }
    free(img->data);
    free(img);
}

// Function to flip the image vertically
void flip_vertical(Image* img) {
    for (int i = 0; i < img->height / 2; i++) {
        for (int j = 0; j < img->width; j++) {
            Pixel temp = img->data[i][j];
            img->data[i][j] = img->data[img->height - 1 - i][j];
            img->data[img->height - 1 - i][j] = temp;
        }
    }
}

// Function to change brightness
void change_brightness(Image* img, int value) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->data[i][j].r = (img->data[i][j].r + value > 255) ? 255 : (img->data[i][j].r + value < 0) ? 0 : img->data[i][j].r + value;
            img->data[i][j].g = (img->data[i][j].g + value > 255) ? 255 : (img->data[i][j].g + value < 0) ? 0 : img->data[i][j].g + value;
            img->data[i][j].b = (img->data[i][j].b + value > 255) ? 255 : (img->data[i][j].b + value < 0) ? 0 : img->data[i][j].b + value;
        }
    }
}

// Function to change contrast
void change_contrast(Image* img, float factor) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->data[i][j].r = (int)(factor * (img->data[i][j].r - 128) + 128);
            img->data[i][j].g = (int)(factor * (img->data[i][j].g - 128) + 128);
            img->data[i][j].b = (int)(factor * (img->data[i][j].b - 128) + 128);
            img->data[i][j].r = img->data[i][j].r < 0 ? 0 : (img->data[i][j].r > 255 ? 255 : img->data[i][j].r);
            img->data[i][j].g = img->data[i][j].g < 0 ? 0 : (img->data[i][j].g > 255 ? 255 : img->data[i][j].g);
            img->data[i][j].b = img->data[i][j].b < 0 ? 0 : (img->data[i][j].b > 255 ? 255 : img->data[i][j].b);
        }
    }
}

// Function to display the image in a simple manner (for testing)
void display_image(Image* img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("(%d, %d, %d) ", img->data[i][j].r, img->data[i][j].g, img->data[i][j].b);
        }
        printf("\n");
    }
}

int main() {
    int width = 5, height = 5;
    Image* img = create_image(width, height);

    // Initialize image with some data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            img->data[i][j].r = (i + j) % 256;
            img->data[i][j].g = (i * 50 + j * 50) % 256;
            img->data[i][j].b = (i * 100 + j * 100) % 256;
        }
    }

    printf("Original Image:\n");
    display_image(img);

    flip_vertical(img);
    printf("\nFlipped Image:\n");
    display_image(img);

    change_brightness(img, 50);
    printf("\nBrightened Image:\n");
    display_image(img);

    change_contrast(img, 1.5);
    printf("\nContrasted Image:\n");
    display_image(img);

    free_image(img);
    return 0;
}