//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX 256

void flip_horizontal(int image[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][size-j-1];
            image[i][size-j-1] = temp;
        }
    }
}

void adjust_contrast(int image[MAX][MAX], int size, int contrast) {
    int factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int pixel = image[i][j];
            int new_pixel = factor * (pixel - 128) + 128;
            if (new_pixel < 0) new_pixel = 0;
            if (new_pixel > 255) new_pixel = 255;
            image[i][j] = new_pixel;
        }
    }
}

int main() {
    FILE *input_file = fopen("image.bmp", "rb");
    if (input_file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    // Read image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_file);

    // Retrieve image dimensions from header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    if (width != height) {
        printf("Error: Image is not square.\n");
        fclose(input_file);
        return 1;
    }

    // Read image data
    unsigned char data[width][height];
    fread(data, sizeof(unsigned char), width*height, input_file);
    fclose(input_file);

    // Convert to 2D integer array
    int image[MAX][MAX];
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            image[i][j] = (int) data[i][j];
        }
    }

    // Flip image horizontally
    flip_horizontal(image, width);

    // Adjust contrast
    int contrast = 50;
    adjust_contrast(image, width, contrast);

    // Convert back to 3D unsigned char array
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            data[i][j] = (unsigned char) image[i][j];
        }
    }

    // Write output file
    FILE *output_file = fopen("output.bmp", "wb");
    fwrite(header, sizeof(unsigned char), 54, output_file);
    fwrite(data, sizeof(unsigned char), width*height, output_file);
    fclose(output_file);

    printf("Image processed and saved to output.bmp.\n");

    return 0;
}