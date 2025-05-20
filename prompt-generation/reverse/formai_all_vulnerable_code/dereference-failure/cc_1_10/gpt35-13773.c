//FormAI DATASET v1.0 Category: Image Editor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Image data structure
typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

// Function to read a bitmap image from file
Image* readImage(char *filename) {
    FILE *file;
    Image *img;

    // Open the file in binary mode
    file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        return NULL;
    }

    // Allocate memory for the image structure
    img = (Image*) malloc(sizeof(Image));

    // Read the header data
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    // Extract the width and height from the header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Allocate memory for the image data
    int imageSize = width * height * 3;
    unsigned char *data = (unsigned char*) malloc(sizeof(unsigned char) * imageSize);

    // Read the image data
    fread(data, sizeof(unsigned char), imageSize, file);

    // Close the file
    fclose(file);

    img->data = data;
    img->width = width;
    img->height = height;

    return img;
}

// Function to write a bitmap image to file
void writeImage(char *filename, Image *img) {
    FILE *file;

    // Open the file in binary mode
    file = fopen(filename, "wb");

    if (file == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        return;
    }

    // Write the header data
    unsigned char header[54] = {
        0x42, 0x4d, 0x36, 0x28, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x36, 0x04, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00,
        0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x28, 0x04, 0x00, 0x00, 0x13,
        0x0b, 0x00, 0x00, 0x13, 0x0b, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    *(int*)&header[18] = img->width;
    *(int*)&header[22] = img->height;
    fwrite(header, sizeof(unsigned char), 54, file);

    // Write the image data
    fwrite(img->data, sizeof(unsigned char), img->width * img->height * 3, file);

    // Close the file
    fclose(file);
}

// Function to flip an image vertically
void flipVertical(Image *img) {
    int width = img->width;
    int height = img->height;
    int rowSize = width * 3;

    for (int y = 0; y < height / 2; y++) {
        int topOffset = y * rowSize;
        int bottomOffset = (height - y - 1) * rowSize;

        for (int x = 0; x < width * 3; x++) {
            unsigned char temp = img->data[topOffset + x];
            img->data[topOffset + x] = img->data[bottomOffset + x];
            img->data[bottomOffset + x] = temp;
        }
    }
}

// Function to apply a grayscale filter to an image
void grayscale(Image *img) {
    int width = img->width;
    int height = img->height;
    int rowSize = width * 3;

    for (int y = 0; y < height; y++) {
        int offset = y * rowSize;

        for (int x = 0; x < width * 3; x += 3) {
            int gray = 0.2989 * img->data[offset + x + 2] + 0.5870 * img->data[offset + x + 1] + 0.1140 * img->data[offset + x];
            img->data[offset + x] = gray;
            img->data[offset + x + 1] = gray;
            img->data[offset + x + 2] = gray;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Error: No input file specified\n");
        return 1;
    }

    char *filename = argv[1];
    Image *img = readImage(filename);

    if (img == NULL) {
        return 1;
    }

    // Flip the image vertically
    flipVertical(img);

    // Apply the grayscale filter to the image
    grayscale(img);

    // Save the modified image to file
    char outFilename[100];
    sprintf(outFilename, "%s_grayscale.bmp", filename);
    writeImage(outFilename, img);

    printf("Grayscale image saved to %s\n", outFilename);

    return 0;
}