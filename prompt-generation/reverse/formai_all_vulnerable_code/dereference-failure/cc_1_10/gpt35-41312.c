//FormAI DATASET v1.0 Category: Image Editor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Configurable variables
#define IMAGE_WIDTH 640
#define IMAGE_HEIGHT 480
#define MAX_PIXEL_VALUE 255

// Helper function to convert pixel coordinates to 1-dimensional array index
int pixelToIndex(int x, int y) {
    return y * IMAGE_WIDTH + x;
}

// Main struct to hold image data
typedef struct Image {
    int width;
    int height;
    unsigned char* data;
} Image;

// Helper function to create an empty Image struct with all pixels set to 0
Image* createImageData(int width, int height) {
    Image* image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = calloc(width * height, sizeof(unsigned char));
    return image;
}

// Helper function to free memory allocated for Image struct
void freeImageData(Image* image) {
    free(image->data);
    free(image);
}

// Helper function to read image data from a PGM file
Image* readPGM(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char magicNumber[3];
    fgets(magicNumber, 3, file);
    if (strcmp(magicNumber, "P5\n") != 0) {
        printf("Error: file %s is not a valid PGM file\n", filename);
        exit(1);
    }

    int width, height, maxPixelValue;
    fscanf(file, "%d %d %d\n", &width, &height, &maxPixelValue);

    if (maxPixelValue != MAX_PIXEL_VALUE) {
        printf("Error: this program can only handle PGM files with max pixel value %d\n", MAX_PIXEL_VALUE);
        exit(1);
    }

    Image* image = createImageData(width, height);
    fread(image->data, sizeof(unsigned char), width * height, file);

    fclose(file);
    return image;
}

// Helper function to write image data to a PGM file
void writePGM(const char* filename, Image* image) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: could not open file %s for writing\n", filename);
        exit(1);
    }

    fprintf(file, "P5\n%d %d\n%d\n", image->width, image->height, MAX_PIXEL_VALUE);
    fwrite(image->data, sizeof(unsigned char), image->width * image->height, file);

    fclose(file);
}

// Example image processing function
void invertColors(Image* image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int index = pixelToIndex(x, y);
            image->data[index] = MAX_PIXEL_VALUE - image->data[index];
        }
    }
}

int main() {
    const char* inputFilename = "input.pgm";
    const char* outputFilename = "output.pgm";

    Image* image = readPGM(inputFilename);
    invertColors(image);
    writePGM(outputFilename, image);
    freeImageData(image);

    return 0;
}