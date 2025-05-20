//FormAI DATASET v1.0 Category: Image Editor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// a struct to represent a pixel in the image
typedef struct pixel {
    int red;
    int green;
    int blue;
} Pixel;

// a struct to represent an image
typedef struct image {
    int width;
    int height;
    Pixel* pixels;
} Image;

// function to initialize an image with all black pixels
void init(Image* image) {
    image->pixels = (Pixel*) malloc(sizeof(Pixel) * image->width * image->height);
    for(int i = 0; i < image->width * image->height; i++) {
        image->pixels[i].red = 0;
        image->pixels[i].green = 0;
        image->pixels[i].blue = 0;
    }
}

// function to set a pixel in the image to a specific color
void set_pixel(Image* image, int x, int y, int red, int green, int blue) {
    int index = y * image->width + x;
    image->pixels[index].red = red;
    image->pixels[index].green = green;
    image->pixels[index].blue = blue;
}

// function to get the color of a pixel in the image
void get_pixel(Image* image, int x, int y, int* red, int* green, int* blue) {
    int index = y * image->width + x;
    *red = image->pixels[index].red;
    *green = image->pixels[index].green;
    *blue = image->pixels[index].blue;
}

// function to save the image as a PPM file
void save(Image* image, char* filename) {
    FILE* file = fopen(filename, "w");
    fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);
    for(int y = 0; y < image->height; y++) {
        for(int x = 0; x < image->width; x++) {
            int red, green, blue;
            get_pixel(image, x, y, &red, &green, &blue);
            fprintf(file, "%d %d %d\n", red, green, blue);
        }
    }
    fclose(file);
}

int main() {
    int width = 100;
    int height = 100;
    Image* myImage = (Image*) malloc(sizeof(Image));
    myImage->width = width;
    myImage->height = height;
    init(myImage);
    set_pixel(myImage, 50, 50, 255, 0, 0); // set pixel in the center of the image to red
    save(myImage, "myImage.ppm"); // save the image as a PPM file
    free(myImage->pixels);
    free(myImage);
    return 0;
}