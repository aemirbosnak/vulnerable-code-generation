//FormAI DATASET v1.0 Category: Image Editor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PIXEL_VALUE 255

// Function to read the image file
void readImageFile(char* filename, int* width, int* height, int** data) {
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        fprintf(stderr, "Error: Could not read file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    // Parse the PGM image header
    char magic[3];
    fscanf(f, "%2s\n", magic);
    if (magic[0] != 'P' || magic[1] != '2') {
        fprintf(stderr, "Error: File '%s' is not a valid PGM image\n", filename);
        exit(EXIT_FAILURE);
    }
    fscanf(f, "%d %d\n", width, height);
    int max_val;
    fscanf(f, "%d\n", &max_val);
    if (max_val != MAX_PIXEL_VALUE) {
        fprintf(stderr, "Error: File '%s' uses unsupported PGM format\n", filename);
        exit(EXIT_FAILURE);
    }

    // Read the image data
    *data = (int*)malloc(*width * *height * sizeof(int));
    for (int i = 0; i < *width * *height; i++) {
        fscanf(f, "%d", *data + i);
    }

    fclose(f);
}

// Function to write the image file
void writeImageFile(char* filename, int width, int height, int* data) {
    FILE* f = fopen(filename, "wb");
    if (f == NULL) {
        fprintf(stderr, "Error: Could not write file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    // Write the PGM image header
    fprintf(f, "P2\n");
    fprintf(f, "%d %d\n", width, height);
    fprintf(f, "%d\n", MAX_PIXEL_VALUE);

    // Write the image data
    for (int i = 0; i < width * height; i++) {
        fprintf(f, "%d ", data[i]);
        if (i % width == width - 1) {
            fprintf(f, "\n");
        }
    }

    fclose(f);
}

// Function that rotates the image by 90 degrees clockwise
void rotateImage90Degrees(int width, int height, int* data) {
    int* newData = (int*)malloc(width * height * sizeof(int));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            newData[j * height + (height - i - 1)] = data[i * width + j];
        }
    }

    for (int i = 0; i < width * height; i++) {
        data[i] = newData[i];
    }

    free(newData);
}

// Function that applies a Gaussian blur filter to the image
void applyGaussianBlur(int width, int height, int* data) {
    float filter[] = {
        1.0 / 16, 1.0 / 8, 1.0 / 16,
        1.0 / 8,  1.0 / 4, 1.0 / 8,
        1.0 / 16, 1.0 / 8, 1.0 / 16,
    };

    int* newData = (int*)malloc(width * height * sizeof(int));
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            float value = 0.0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    value += filter[(k + 1) * 3 + (l + 1)] * data[(i + k) * width + (j + l)];
                }
            }
            newData[i * width + j] = (int)round(value);
        }
    }

    for (int i = 0; i < width * height; i++) {
        data[i] = newData[i];
    }

    free(newData);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int width, height;
    int* data;
    readImageFile(argv[1], &width, &height, &data);

    // Rotate the image by 90 degrees clockwise
    rotateImage90Degrees(width, height, data);

    // Apply a Gaussian blur filter
    applyGaussianBlur(width, height, data);

    // Write the modified image to disk
    writeImageFile(argv[2], width, height, data);

    free(data);
    return EXIT_SUCCESS;
}