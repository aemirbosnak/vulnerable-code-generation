//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *data;
    int width, height;
} Image;

Image *createImage(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->data = malloc(width * height * sizeof(int));
    image->width = width;
    image->height = height;
    return image;
}

void freeImage(Image *image) {
    free(image->data);
    free(image);
}

void printImage(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%d ", image->data[y * image->width + x]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // Create a 10x10 image
    Image *image = createImage(10, 10);

    // Fill the image with random data
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            image->data[y * image->width + x] = rand() % 256;
        }
    }

    // Print the image
    printf("Original image:\n");
    printImage(image);

    // Create a new image to store the classified data
    Image *classifiedImage = createImage(image->width, image->height);

    // Classify each pixel in the image
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            // Get the pixel value
            int pixelValue = image->data[y * image->width + x];

            // Classify the pixel
            int classification;
            if (pixelValue < 128) {
                classification = 0; // Black
            } else if (pixelValue < 192) {
                classification = 1; // Gray
            } else {
                classification = 2; // White
            }

            // Store the classification in the new image
            classifiedImage->data[y * classifiedImage->width + x] = classification;
        }
    }

    // Print the classified image
    printf("Classified image:\n");
    printImage(classifiedImage);

    // Free the memory
    freeImage(image);
    freeImage(classifiedImage);

    return 0;
}