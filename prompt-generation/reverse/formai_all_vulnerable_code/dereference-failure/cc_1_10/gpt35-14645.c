//FormAI DATASET v1.0 Category: Image Editor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for holding the image data
typedef struct Image {
    int width;
    int height;
    unsigned char* data;
} Image;

// Function to load an image from a file
Image* loadImage(char* filename) {
    // Open the file
    FILE* fp = fopen(filename, "rb");
    if(!fp) {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    // Read the header
    char header[54];
    fread(header, 1, 54, fp);

    // Get the image width and height
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Check if the image is 24 bits per pixel
    if(*(int*)&header[28] != 24) {
        printf("Error: Unsupported image format (must be 24 bits per pixel)\n");
        fclose(fp);
        return NULL;
    }

    // Allocate memory for the image data
    unsigned char* data = (unsigned char*)malloc(width * height * 3);

    // Read the data
    fread(data, 1, width * height * 3, fp);

    // Close the file
    fclose(fp);

    // Allocate memory for the image struct
    Image* image = (Image*)malloc(sizeof(Image));

    // Set the image data
    image->width = width;
    image->height = height;
    image->data = data;

    return image;
}

// Function to save an image to a file
void saveImage(char* filename, Image* image) {
    // Open the file
    FILE* fp = fopen(filename, "wb");
    if(!fp) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    // Write the header
    char header[54];
    memset(header, 0, 54);
    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = 54 + image->width * image->height * 3;
    *(int*)&header[10] = 54;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = image->width;
    *(int*)&header[22] = image->height;
    *(short*)&header[26] = 1;
    *(short*)&header[28] = 24;

    fwrite(header, 1, 54, fp);

    // Write the data
    fwrite(image->data, 1, image->width * image->height * 3, fp);

    // Close the file
    fclose(fp);
}

// Function to get a pixel from an image
void getPixel(Image* image, int x, int y, unsigned char* r, unsigned char* g, unsigned char* b) {
    *b = image->data[(y * image->width + x) * 3];
    *g = image->data[(y * image->width + x) * 3 + 1];
    *r = image->data[(y * image->width + x) * 3 + 2];
}

// Function to set a pixel in an image
void setPixel(Image* image, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    image->data[(y * image->width + x) * 3] = b;
    image->data[(y * image->width + x) * 3 + 1] = g;
    image->data[(y * image->width + x) * 3 + 2] = r;
}

// Function to convert an image to grayscale
void grayscale(Image* image) {
    for(int y = 0; y < image->height; y++) {
        for(int x = 0; x < image->width; x++) {
            unsigned char r, g, b;
            getPixel(image, x, y, &r, &g, &b);
            unsigned char gray = (int)(0.299 * r + 0.587 * g + 0.114 * b);
            setPixel(image, x, y, gray, gray, gray);
        }
    }
}

// Function to flip an image horizontally
void flipHorizontally(Image* image) {
    for(int y = 0; y < image->height; y++) {
        for(int x = 0; x < image->width / 2; x++) {
            unsigned char r1, g1, b1, r2, g2, b2;
            getPixel(image, x, y, &r1, &g1, &b1);
            getPixel(image, image->width - x - 1, y, &r2, &g2, &b2);
            setPixel(image, x, y, r2, g2, b2);
            setPixel(image, image->width - x - 1, y, r1, g1, b1);
        }
    }
}

// Function to flip an image vertically
void flipVertically(Image* image) {
    for(int y = 0; y < image->height / 2; y++) {
        for(int x = 0; x < image->width; x++) {
            unsigned char r1, g1, b1, r2, g2, b2;
            getPixel(image, x, y, &r1, &g1, &b1);
            getPixel(image, x, image->height - y - 1, &r2, &g2, &b2);
            setPixel(image, x, y, r2, g2, b2);
            setPixel(image, x, image->height - y - 1, r1, g1, b1);
        }
    }
}

int main(int argc, char* argv[]) {
    if(argc < 3) {
        printf("Usage: %s [input file] [output file]\n", argv[0]);
        return 0;
    }

    // Load the image from the input file
    Image* image = loadImage(argv[1]);
    if(!image) {
        return 0;
    }

    // Apply the filters
    grayscale(image);
    flipHorizontally(image);
    flipVertically(image);

    // Save the image to the output file
    saveImage(argv[2], image);

    // Free the image memory
    free(image->data);
    free(image);

    return 0;
}