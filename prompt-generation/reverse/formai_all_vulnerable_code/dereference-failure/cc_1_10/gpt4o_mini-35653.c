//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;

typedef struct {
    BYTE r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

Image* loadImage(const char *filename);
void saveImage(const char *filename, Image *image);
void flipImage(Image *image);
void changeBrightness(Image *image, int value);
void changeContrast(Image *image, float factor);
void freeImage(Image *image);
void printUsage();

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printUsage();
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    const char *operation = argv[3];

    Image *image = loadImage(inputFile);
    if (!image) {
        fprintf(stderr, "Error: Could not load image.\n");
        return EXIT_FAILURE;
    }

    if (strcmp(operation, "flip") == 0) {
        printf("Flipping the image...\n");
        flipImage(image);
    } else if (strcmp(operation, "brightness") == 0) {
        if (argc != 5) {
            fprintf(stderr, "Error: Brightness operation requires a value.\n");
            freeImage(image);
            return EXIT_FAILURE;
        }
        int value = atoi(argv[4]);
        printf("Changing brightness by %d...\n", value);
        changeBrightness(image, value);
    } else if (strcmp(operation, "contrast") == 0) {
        if (argc != 5) {
            fprintf(stderr, "Error: Contrast operation requires a factor.\n");
            freeImage(image);
            return EXIT_FAILURE;
        }
        float factor = atof(argv[4]);
        printf("Changing contrast by a factor of %.2f...\n", factor);
        changeContrast(image, factor);
    } else {
        fprintf(stderr, "Error: Invalid operation '%s'.\n", operation);
        freeImage(image);
        return EXIT_FAILURE;
    }

    saveImage(outputFile, image);
    printf("Image processing completed! Saved to '%s'.\n", outputFile);
    
    freeImage(image);
    return EXIT_SUCCESS;
}

Image* loadImage(const char *filename) {
    // Placeholder for loading image (e.g., BMP, PPM, etc.)
    Image *image = (Image*)malloc(sizeof(Image));
    // Simulated image loading (placeholder)
    image->width = 640;
    image->height = 480;
    image->pixels = (Pixel*)malloc(image->width * image->height * sizeof(Pixel));

    // Just filling with random pixel data for demonstration
    for (int i = 0; i < image->width * image->height; i++) {
        image->pixels[i].r = rand() % 256;
        image->pixels[i].g = rand() % 256;
        image->pixels[i].b = rand() % 256;
    }
    return image;
}

void saveImage(const char *filename, Image *image) {
    // Placeholder for saving image (e.g., BMP, PPM, etc.)
    // This function would implement actual image saving logic
}

void flipImage(Image *image) {
    int width = image->width;
    int height = image->height;
    Pixel *flippedPixels = (Pixel*)malloc(width * height * sizeof(Pixel));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            flippedPixels[(height - 1 - y) * width + x] = image->pixels[y * width + x];
        }
    }

    free(image->pixels);
    image->pixels = flippedPixels;
}

void changeBrightness(Image *image, int value) {
    int width = image->width;
    int height = image->height;

    for (int i = 0; i < width * height; i++) {
        image->pixels[i].r = (BYTE) fmin(fmax(image->pixels[i].r + value, 0), 255);
        image->pixels[i].g = (BYTE) fmin(fmax(image->pixels[i].g + value, 0), 255);
        image->pixels[i].b = (BYTE) fmin(fmax(image->pixels[i].b + value, 0), 255);
    }
}

void changeContrast(Image *image, float factor) {
    int width = image->width;
    int height = image->height;

    for (int i = 0; i < width * height; i++) {
        image->pixels[i].r = (BYTE) fmin(fmax((image->pixels[i].r - 128) * factor + 128, 0), 255);
        image->pixels[i].g = (BYTE) fmin(fmax((image->pixels[i].g - 128) * factor + 128, 0), 255);
        image->pixels[i].b = (BYTE) fmin(fmax((image->pixels[i].b - 128) * factor + 128, 0), 255);
    }
}

void freeImage(Image *image) {
    if (image) {
        free(image->pixels);
        free(image);
    }
}

void printUsage() {
    printf("Image Processing Tool\n");
    printf("Usage: \n");
    printf("  imageproc <input_file> <output_file> <operation> [<value>]\n");
    printf("Operations:\n");
    printf("  flip\n");
    printf("  brightness <value>\n");
    printf("  contrast <factor>\n");
}