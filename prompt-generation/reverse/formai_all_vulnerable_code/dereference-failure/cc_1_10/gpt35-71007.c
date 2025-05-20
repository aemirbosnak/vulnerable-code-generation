//FormAI DATASET v1.0 Category: Image Editor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store RGB values of a pixel
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

// Function to read image file and return Pixel array
Pixel* readImage(char* filename, int* width, int* height) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }

    // Read header information
    char header[54];
    fread(header, sizeof(char), 54, fp);
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];

    // Allocate memory for Pixel array
    Pixel* img = (Pixel*) malloc(sizeof(Pixel) * (*width) * (*height));

    // Read image pixel data
    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            Pixel pixel;
            fread(&pixel.blue, sizeof(unsigned char), 1, fp);
            fread(&pixel.green, sizeof(unsigned char), 1, fp);
            fread(&pixel.red, sizeof(unsigned char), 1, fp);
            img[i * (*width) + j] = pixel;
        }
    }

    fclose(fp);
    return img;
}

// Function to write Pixel array to image file
void writeImage(char* filename, Pixel* img, int width, int height) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Unable to write to file!\n");
        exit(1);
    }

    // Write header information
    char header[54];
    memset(header, 0, 54);
    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = 54 + 3 * width * height;
    *(int*)&header[10] = 54;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;
    *(short*)&header[26] = 1;
    *(short*)&header[28] = 24;
    *(int*)&header[34] = 3 * width * height;
    fwrite(header, sizeof(char), 54, fp);

    // Write image pixel data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Pixel pixel = img[i * width + j];
            fwrite(&pixel.blue, sizeof(unsigned char), 1, fp);
            fwrite(&pixel.green, sizeof(unsigned char), 1, fp);
            fwrite(&pixel.red, sizeof(unsigned char), 1, fp);
        }
    }

    fclose(fp);
}

// Function to apply sepia filter to image
void sepiaFilter(Pixel* img, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Pixel* pixel = &img[i * width + j];

            // Calculate new RGB values using sepia formula
            int outputRed = (int) ((pixel->red * .393) + (pixel->green *.769) + (pixel->blue *.189));
            int outputGreen = (int) ((pixel->red * .349) + (pixel->green *.686) + (pixel->blue *.168));
            int outputBlue = (int) ((pixel->red * .272) + (pixel->green *.534) + (pixel->blue *.131));

            // Cap RGB values at 255
            if (outputRed > 255) outputRed = 255;
            if (outputGreen > 255) outputGreen = 255;
            if (outputBlue > 255) outputBlue = 255;

            // Update pixel's RGB values with sepia filter
            pixel->red = (unsigned char) outputRed;
            pixel->green = (unsigned char) outputGreen;
            pixel->blue = (unsigned char) outputBlue;
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    int width, height;
    Pixel* img = readImage(argv[1], &width, &height);

    sepiaFilter(img, width, height);

    writeImage(argv[2], img, width, height);

    free(img);

    return 0;
}