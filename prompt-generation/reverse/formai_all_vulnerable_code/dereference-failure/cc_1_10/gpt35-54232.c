//FormAI DATASET v1.0 Category: Image Editor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

// Define pixel structure
struct Pixel {
    int red;
    int green;
    int blue;
};

// Define image structure
struct Image {
    int width;
    int height;
    struct Pixel **pixels;
};

// Function to create a new image
struct Image *createImage(int width, int height) {
    // Allocate memory for image structure
    struct Image *image = malloc(sizeof(struct Image));
    
    // Set image width and height
    image->width = width;
    image->height = height;
    
    // Allocate memory for pixels
    image->pixels = malloc(sizeof(struct Pixel *) * height);
    for (int i = 0; i < height; i++) {
        image->pixels[i] = malloc(sizeof(struct Pixel) * width);
    }
    
    return image;
}

// Function to free memory allocated for image
void freeImage(struct Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

// Function to set pixel value
void setPixel(struct Image *image, int x, int y, int red, int green, int blue) {
    image->pixels[y][x].red = red;
    image->pixels[y][x].green = green;
    image->pixels[y][x].blue = blue;
}

// Function to get pixel value
void getPixel(struct Image *image, int x, int y, int *red, int *green, int *blue) {
    *red = image->pixels[y][x].red;
    *green = image->pixels[y][x].green;
    *blue = image->pixels[y][x].blue;
}

// Function to flip image horizontally
void flipHorizontally(struct Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            // Swap pixels
            struct Pixel temp = image->pixels[y][x];
            image->pixels[y][x] = image->pixels[y][image->width - x - 1];
            image->pixels[y][image->width - x - 1] = temp;
        }
    }
}

// Function to flip image vertically
void flipVertically(struct Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            // Swap pixels
            struct Pixel temp = image->pixels[y][x];
            image->pixels[y][x] = image->pixels[image->height - y - 1][x];
            image->pixels[image->height - y - 1][x] = temp;
        }
    }
}

// Main function
int main() {
    // Create new image
    struct Image *image = createImage(10, 10);
    
    // Set pixel values
    setPixel(image, 0, 0, 255, 0, 0);
    setPixel(image, 9, 0, 0, 255, 0);
    setPixel(image, 0, 9, 0, 0, 255);
    setPixel(image, 9, 9, 255, 255, 255);
    
    // Flip image horizontally
    flipHorizontally(image);
    
    // Flip image vertically
    flipVertically(image);
    
    // Print pixel values
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int red, green, blue;
            getPixel(image, x, y, &red, &green, &blue);
            printf("(%d,%d,%d) ", red, green, blue);
        }
        printf("\n");
    }
    
    // Free memory allocated for image
    freeImage(image);
    
    return 0;
}