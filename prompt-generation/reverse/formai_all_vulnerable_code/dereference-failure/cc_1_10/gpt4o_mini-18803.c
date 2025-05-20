//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent the realm of our pixel
typedef struct {
    unsigned char r, g, b;
} Pixel;

// A structure to represent the image as a canvas of pixels
typedef struct {
    int width, height;
    Pixel *data;
} Image;

// Function to create a new image for our kingdom
Image *create_image(int width, int height) {
    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(Pixel));
    return img;
}

// Function to free the memory of our pixel realm
void free_image(Image *img) {
    free(img->data);
    free(img);
}

// Function to fill the image with a color of royalty
void fill_image(Image *img, unsigned char r, unsigned char g, unsigned char b) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = r;
        img->data[i].g = g;
        img->data[i].b = b;
    }
}

// Function to display the image in the console (medieval scroll)
void display_image(const Image *img) {
    printf("Behold the Image of %dx%d dimension:\n", img->width, img->height);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int index = y * img->width + x;
            printf("(%3u,%3u,%3u) ", img->data[index].r, img->data[index].g, img->data[index].b);
        }
        printf("\n");
    }
}

// Function to blend two colors in a mystical manner
Pixel blend_colors(Pixel a, Pixel b, float alpha) {
    Pixel blended;
    blended.r = (unsigned char)((1 - alpha) * a.r + alpha * b.r);
    blended.g = (unsigned char)((1 - alpha) * a.g + alpha * b.g);
    blended.b = (unsigned char)((1 - alpha) * a.b + alpha * b.b);
    return blended;
}

// Function to apply a magical grayscale filter upon the image
void apply_grayscale(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char gray = (unsigned char)(0.3 * img->data[i].r + 0.59 * img->data[i].g + 0.11 * img->data[i].b);
        img->data[i].r = gray;
        img->data[i].g = gray;
        img->data[i].b = gray;
    }
}

// Heroic main function to guide the creation of our splendid image
int main() {
    // Noble dimensions for our canvas
    int width = 10, height = 5;

    // Summon the new image into existence
    Image *my_image = create_image(width, height);

    // Fill the realm of pixels with royal blue
    fill_image(my_image, 0, 0, 255);

    // Display the canvas before transformation
    display_image(my_image);

    // Bestow the gift of grayscale upon the image
    apply_grayscale(my_image);

    // Display the transformed canvas
    display_image(my_image);

    // Free the canvas to honor the memory of our realm
    free_image(my_image);

    // Let the fable of this image editor dwell forever in the heart of the ages!
    return 0;
}