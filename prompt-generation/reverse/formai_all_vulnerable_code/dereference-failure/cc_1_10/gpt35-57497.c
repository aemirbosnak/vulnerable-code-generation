//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define BMP_HEADER_SIZE 54

// Function to read the BMP header from file
void read_bmp_header(FILE *fp, int *width, int *height, int *image_size) {
    // Set file position to 18 bytes in to read the width and height
    fseek(fp, 18, SEEK_SET);
    fread(width, 4, 1, fp);
    fread(height, 4, 1, fp);

    // Set file position to 34 bytes in to read the image size
    fseek(fp, 34, SEEK_SET);
    fread(image_size, 4, 1, fp);
}

// Function to flip the image vertically
void flip_vertical(unsigned char *image_data, int width, int height) {
    // Allocate memory for a row of pixels
    unsigned char *row = (unsigned char*) malloc(width * 3);

    for (int i = 0; i < height/2; i++) {
        // Swap rows i and height-i-1
        memcpy(row, image_data + i * width * 3, width * 3);
        memcpy(image_data + i * width * 3, image_data + (height - i - 1) * width * 3, width * 3);
        memcpy(image_data + (height - i - 1) * width * 3, row, width * 3);
    }

    free(row);
}

// Function to adjust brightness and contrast of the image
void adjust_brightness_contrast(unsigned char *image_data, int width, int height, int brightness, int contrast) {
    int brightness_adjustment = brightness - 128;
    float contrast_adjustment = (contrast + 128) / 128.0;

    for (int i = 0; i < height * width * 3; i += 3) {
        // Adjust brightness
        image_data[i] += brightness_adjustment;
        image_data[i+1] += brightness_adjustment;
        image_data[i+2] += brightness_adjustment;

        // Adjust contrast
        image_data[i] = (image_data[i] - 128) * contrast_adjustment + 128;
        image_data[i+1] = (image_data[i+1] - 128) * contrast_adjustment + 128;
        image_data[i+2] = (image_data[i+2] - 128) * contrast_adjustment + 128;
    }
}

int main(int argc, char *argv[]) {
    // Check for input file name
    if (argc < 2) {
        printf("Usage: %s <input_file_name>\n", argv[0]);
        return 0;
    }

    // Open input file for reading
    FILE *input_fp = fopen(argv[1], "rb");
    if (!input_fp) {
        printf("Error: failed to open input file %s\n", argv[1]);
        return 0;
    }

    // Read BMP header
    int width, height, image_size;
    read_bmp_header(input_fp, &width, &height, &image_size);

    // Allocate memory for the image data
    unsigned char *image_data = (unsigned char*) malloc(image_size);

    // Read image data from file
    fread(image_data, 1, image_size, input_fp);

    // Close input file
    fclose(input_fp);

    // Flip image vertically
    flip_vertical(image_data, width, height);

    // Adjust brightness and contrast
    adjust_brightness_contrast(image_data, width, height, 30, 70);

    // Open output file for writing
    FILE *output_fp = fopen("output.bmp", "wb");
    if (!output_fp) {
        printf("Error: failed to open output file\n");
        return 0;
    }

    // Write BMP header to file
    fwrite(image_data, 1, BMP_HEADER_SIZE, output_fp);

    // Write image data to file
    fwrite(image_data + BMP_HEADER_SIZE, 1, image_size - BMP_HEADER_SIZE, output_fp);

    // Close output file
    fclose(output_fp);

    // Free allocated memory
    free(image_data);

    printf("Done\n");

    return 0;
}