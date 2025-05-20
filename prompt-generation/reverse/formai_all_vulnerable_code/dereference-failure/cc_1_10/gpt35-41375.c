//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct Image {
    Pixel *pixels;
    int width;
    int height;
} Image;

// Function to allocate memory for an Image structure
Image* create_image(int width, int height) {
    Image *im = (Image*) malloc(sizeof(Image));
    im->width = width;
    im->height = height;
    im->pixels = (Pixel*) malloc(sizeof(Pixel) * width * height);
    return im;
}

// Function to flip an image horizontally
void flip_horizontal(Image *image) {
    // Iterate over each row, and swap the pixels horizontally
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width/2; x++) {
            int i = y * image->width + x;
            int j = y * image->width + (image->width - x - 1);
            // Swap the pixels
            Pixel temp = image->pixels[i];
            image->pixels[i] = image->pixels[j];
            image->pixels[j] = temp;
        }
    }
}

int main() {
    // Create a new image
    Image *image = create_image(WIDTH, HEIGHT);

    // Set every pixel to red
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image->pixels[i].red = 255;
        image->pixels[i].green = 0;
        image->pixels[i].blue = 0;
    }

    // Flip the image horizontally
    flip_horizontal(image);

    // Save the image to a file
    FILE *f = fopen("flipped_image.ppm", "w");
    fprintf(f, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->pixels, sizeof(Pixel), image->width*image->height, f);
    fclose(f);

    // Free the memory
    free(image->pixels);
    free(image);

    return 0;
}