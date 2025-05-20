//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// Our trusty image classification system!
typedef struct {
    uint8_t* data;
    int width, height, channels;
} Image;

// Load an image from a file. Returns NULL on error.
Image* load_image(const char* filename) {
    FILE* f = fopen(filename, "rb");
    if (!f) return NULL;

    // Read header
    uint16_t magic, width, height, channels;
    if (fread(&magic, 2, 1, f) != 1 || magic != 0x424d) {
        fclose(f);
        return NULL;
    }
    if (fread(&width, 4, 1, f) != 1 || fread(&height, 4, 1, f) != 1 || fread(&channels, 4, 1, f) != 1) {
        fclose(f);
        return NULL;
    }

    // Read data
    Image* image = malloc(sizeof(Image));
    image->data = malloc(width * height * channels);
    if (fread(image->data, width * height * channels, 1, f) != 1) {
        free(image->data);
        free(image);
        fclose(f);
        return NULL;
    }

    // Close file
    fclose(f);

    // Set fields
    image->width = width;
    image->height = height;
    image->channels = channels;

    return image;
}

// Free an image.
void free_image(Image* image) {
    free(image->data);
    free(image);
}

// Classify an image using our advanced AI technology.
int classify_image(Image* image) {
    // Here comes the magic! We employ a revolutionary algorithm that involves...

    // ...calculating the mean pixel value.
    double mean = 0;
    for (int i = 0; i < image->width * image->height * image->channels; i++) {
        mean += image->data[i];
    }
    mean /= image->width * image->height * image->channels;

    // ...and comparing it to a threshold.
    double threshold = 128;
    if (mean > threshold) {
        return 1;  // Bright image
    } else {
        return 0;  // Dark image
    }
}

int main() {
    // Load an image
    Image* image = load_image("image.bmp");
    if (!image) {
        printf("Error loading image.\n");
        return 1;
    }

    // Classify it
    int classification = classify_image(image);

    // Announce the result
    if (classification == 1) {
        printf("The image is bright.\n");
    } else {
        printf("The image is dark.\n");
    }

    // Clean up
    free_image(image);

    return 0;
}