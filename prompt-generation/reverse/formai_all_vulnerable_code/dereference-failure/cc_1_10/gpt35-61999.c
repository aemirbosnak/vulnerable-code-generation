//FormAI DATASET v1.0 Category: Image compression ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255

int main() {
    FILE* in_file = fopen("input.jpg", "rb"); // open input file in binary mode
    FILE* out_file = fopen("output.compressed", "wb"); // open output file in binary mode

    if (in_file == NULL || out_file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // read image data from input file
    unsigned char image_data[1024][1024]; // assuming image size to be 1024x1024
    fread(image_data, sizeof(unsigned char), 1024*1024, in_file);

    // calculate average pixel value
    int total_pixels = 1024 * 1024;
    int sum = 0;
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 1024; j++) {
            sum += image_data[i][j];
        }
    }
    int average_pixel_value = sum / total_pixels;

    // compress image data
    unsigned char compressed_data[1024][1024];
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 1024; j++) {
            int pixel_value = image_data[i][j];
            if (pixel_value > average_pixel_value) {
                compressed_data[i][j] = MAX_PIXEL_VALUE - pixel_value;
            } else {
                compressed_data[i][j] = pixel_value;
            }
        }
    }

    // write compressed data to output file
    fwrite(compressed_data, sizeof(unsigned char), 1024*1024, out_file);

    // close files
    fclose(in_file);
    fclose(out_file);

    printf("Image compression successful.\n");

    return 0;
}