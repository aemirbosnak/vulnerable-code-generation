//FormAI DATASET v1.0 Category: Image Editor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// Define constants
#define MAX_PIXEL_VALUE 255
#define MAX_INTENSITY_VALUE 100
#define PI 3.14159265

// Define a structure to hold RGB pixel values
typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} RGBPixel;

// Define a structure to hold a 2D array of RGB pixel values
typedef struct {
    RGBPixel **pixels;
    int width;
    int height;
} Image;

// Define function to allocate memory for a new Image object
Image *createImage(int width, int height) {
    // Allocate memory for Image structure
    Image *image = malloc(sizeof(Image));

    // Allocate memory for 2D array of RGB pixels
    image->pixels = malloc(sizeof(RGBPixel*) * height);
    for (int i = 0; i < height; i++) {
        image->pixels[i] = malloc(sizeof(RGBPixel) * width);
    }

    // Set Image width and height
    image->width = width;
    image->height = height;

    return image;
}

// Define function to free memory allocated to an Image object
void destroyImage(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

// Define a function to read an image from a file
Image *readImageFromFile(char *filename) {
    // Open the image file for reading
    FILE *imageFile = fopen(filename, "rb");

    // Read image dimensions
    int width, height;
    fscanf(imageFile, "%d %d", &width, &height);

    // Create a new Image object
    Image *image = createImage(width, height);

    // Read pixel values from file
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBPixel pixel;
            fscanf(imageFile, "%hhu %hhu %hhu", &pixel.r, &pixel.g, &pixel.b);
            image->pixels[i][j] = pixel;
        }
    }

    // Close the image file
    fclose(imageFile);

    return image;
}

// Define a function to write an image to a file
void writeImageToFile(Image *image, char *filename) {
    // Open the output file for writing
    FILE *outFile = fopen(filename, "wb");

    // Write image dimensions
    fprintf(outFile, "%d %d\n", image->width, image->height);

    // Write pixel values to file
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fprintf(outFile, "%hhu %hhu %hhu ", image->pixels[i][j].r,
                                                 image->pixels[i][j].g,
                                                 image->pixels[i][j].b);
        }
        fprintf(outFile, "\n");
    }

    // Close the output file
    fclose(outFile);
}

// Define a function to adjust image brightness
void adjustBrightness(Image *image, int brightness) {
    // Calculate brightness factor
    double brightnessFactor = (double)brightness / MAX_INTENSITY_VALUE;

    // Adjust pixel values based on brightness factor
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            double red = (double)image->pixels[i][j].r / MAX_PIXEL_VALUE;
            double green = (double)image->pixels[i][j].g / MAX_PIXEL_VALUE;
            double blue = (double)image->pixels[i][j].b / MAX_PIXEL_VALUE;

            // Adjust pixel values using brightness factor
            red += brightnessFactor;
            green += brightnessFactor;
            blue += brightnessFactor;

            // Clamp pixel values to range [0, 1]
            red = fmin(1.0, fmax(0.0, red));
            green = fmin(1.0, fmax(0.0, green));
            blue = fmin(1.0, fmax(0.0, blue));

            // Convert pixel values back to 8-bit range
            image->pixels[i][j].r = (uint8_t)(red * MAX_PIXEL_VALUE);
            image->pixels[i][j].g = (uint8_t)(green * MAX_PIXEL_VALUE);
            image->pixels[i][j].b = (uint8_t)(blue * MAX_PIXEL_VALUE);
        }
    }
}

// Define a function to adjust image contrast
void adjustContrast(Image *image, int contrast) {
    // Calculate contrast factor
    double contrastFactor = (double)contrast / MAX_INTENSITY_VALUE;

    // Calculate scaling factor for pixel values
    double multiplier = (MAX_PIXEL_VALUE - (2 * MAX_PIXEL_VALUE * contrastFactor)) / MAX_PIXEL_VALUE;

    // Adjust pixel values based on contrast factor
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            double red = (double)image->pixels[i][j].r / MAX_PIXEL_VALUE;
            double green = (double)image->pixels[i][j].g / MAX_PIXEL_VALUE;
            double blue = (double)image->pixels[i][j].b / MAX_PIXEL_VALUE;

            // Adjust pixel values using scaling factor
            red = ((red - 0.5) * multiplier) + 0.5;
            green = ((green - 0.5) * multiplier) + 0.5;
            blue = ((blue - 0.5) * multiplier) + 0.5;

            // Clamp pixel values to range [0, 1]
            red = fmin(1.0, fmax(0.0, red));
            green = fmin(1.0, fmax(0.0, green));
            blue = fmin(1.0, fmax(0.0, blue));

            // Convert pixel values back to 8-bit range
            image->pixels[i][j].r = (uint8_t)(red * MAX_PIXEL_VALUE);
            image->pixels[i][j].g = (uint8_t)(green * MAX_PIXEL_VALUE);
            image->pixels[i][j].b = (uint8_t)(blue * MAX_PIXEL_VALUE);
        }
    }
}

// Define a function to adjust image saturation
void adjustSaturation(Image *image, int saturation) {
    // Calculate saturation factor
    double saturationFactor = (double)saturation / MAX_INTENSITY_VALUE;

    // Adjust pixel values based on saturation factor
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            double red = (double)image->pixels[i][j].r / MAX_PIXEL_VALUE;
            double green = (double)image->pixels[i][j].g / MAX_PIXEL_VALUE;
            double blue = (double)image->pixels[i][j].b / MAX_PIXEL_VALUE;

            // Calculate luma (perceived brightness)
            double luma = (0.2126 * red) + (0.7152 * green) + (0.0722 * blue);

            // Adjust saturation for each color channel
            red = (red * saturationFactor) + (luma * (1 - saturationFactor));
            green = (green * saturationFactor) + (luma * (1 - saturationFactor));
            blue = (blue * saturationFactor) + (luma * (1 - saturationFactor));

            // Clamp pixel values to range [0, 1]
            red = fmin(1.0, fmax(0.0, red));
            green = fmin(1.0, fmax(0.0, green));
            blue = fmin(1.0, fmax(0.0, blue));

            // Convert pixel values back to 8-bit range
            image->pixels[i][j].r = (uint8_t)(red * MAX_PIXEL_VALUE);
            image->pixels[i][j].g = (uint8_t)(green * MAX_PIXEL_VALUE);
            image->pixels[i][j].b = (uint8_t)(blue * MAX_PIXEL_VALUE);
        }
    }
}

int main(void) {
    // Read original image from file
    Image *image = readImageFromFile("input.ppm");

    // Adjust image brightness, contrast, and saturation
    adjustBrightness(image, 50);
    adjustContrast(image, 50);
    adjustSaturation(image, 50);

    // Write edited image to file
    writeImageToFile(image, "output.ppm");

    // Free memory allocated to Image object
    destroyImage(image);

    return 0;
}