//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* readImage(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return NULL;
    }

    // Read the PPM file header
    char buffer[128];
    fgets(buffer, sizeof(buffer), file);
    if (strncmp(buffer, "P6", 2) != 0) {
        fprintf(stderr, "Unsupported file format\n");
        fclose(file);
        return NULL;
    }

    // Read image dimensions
    fgets(buffer, sizeof(buffer), file);
    int width, height;
    sscanf(buffer, "%d %d", &width, &height);
    
    // Read max color value
    fgets(buffer, sizeof(buffer), file);
    int maxColorValue = atoi(buffer);
    
    // Allocate memory for the image
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(sizeof(Pixel) * width * height);
    
    // Read pixel data
    fread(image->data, sizeof(Pixel), width * height, file);
    fclose(file);
    
    return image;
}

void writeImage(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }

    // Write the PPM file header
    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);

    // Write pixel data
    fwrite(image->data, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

void flipImageHorizontally(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            int oppositeX = image->width - x - 1;
            Pixel temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + oppositeX];
            image->data[y * image->width + oppositeX] = temp;
        }
    }
}

void adjustBrightnessContrast(Image *image, int brightness, float contrast) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i].r = (unsigned char) fmin(fmax((image->data[i].r - 128) * contrast + 128 + brightness, 0), 255);
        image->data[i].g = (unsigned char) fmin(fmax((image->data[i].g - 128) * contrast + 128 + brightness, 0), 255);
        image->data[i].b = (unsigned char) fmin(fmax((image->data[i].b - 128) * contrast + 128 + brightness, 0), 255);
    }
}

void freeImage(Image *image) {
    free(image->data);
    free(image);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <brightness> <contrast>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputFilename = argv[1];
    const char *outputFilename = argv[2];
    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);

    Image *image = readImage(inputFilename);
    if (!image) {
        return EXIT_FAILURE;
    }

    // Flip the image horizontally
    flipImageHorizontally(image);

    // Adjust brightness and contrast
    adjustBrightnessContrast(image, brightness, contrast);

    // Save the modified image
    writeImage(outputFilename, image);

    // Clean up
    freeImage(image);

    printf("Image processing complete. Output saved as %s\n", outputFilename);
    return EXIT_SUCCESS;
}