//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to digitally watermark an image
void digital_watermark(const char* input_file, const char* output_file) {
    // Open the input image file for reading
    FILE* input_file_ptr = fopen(input_file, "rb");
    if (input_file_ptr == NULL) {
        fprintf(stderr, "Error: Unable to open input file.\n");
        return;
    }
    
    // Open the output image file for writing
    FILE* output_file_ptr = fopen(output_file, "wb");
    if (output_file_ptr == NULL) {
        fprintf(stderr, "Error: Unable to open output file.\n");
        fclose(input_file_ptr);
        return;
    }
    
    // Read the image data from the input file
    unsigned char* image_data = (unsigned char*)malloc(1024 * 1024); // Allocate memory for 1MB of image data
    size_t bytes_read = fread(image_data, 1, 1024 * 1024, input_file_ptr);
    if (bytes_read!= 1024 * 1024) {
        fprintf(stderr, "Error: Unable to read entire image file.\n");
        fclose(input_file_ptr);
        fclose(output_file_ptr);
        free(image_data);
        return;
    }
    
    // Modify the least significant bits of each pixel in the image data
    for (int y = 0; y < 1024; y++) {
        for (int x = 0; x < 1024; x++) {
            unsigned char* pixel = &image_data[y * 1024 + x];
            unsigned char lsb = pixel[0];
            pixel[0] = (pixel[0] & 0b11000000) | (lsb + 1); // Modify the LSB by adding 1
            pixel[1] = (pixel[1] & 0b11000000) | (lsb + 2); // Modify the LSB by adding 2
            pixel[2] = (pixel[2] & 0b11000000) | (lsb + 3); // Modify the LSB by adding 3
            pixel[3] = (pixel[3] & 0b11000000) | (lsb + 4); // Modify the LSB by adding 4
        }
    }
    
    // Write the modified image data to the output file
    fwrite(image_data, 1, 1024 * 1024, output_file_ptr);
    fclose(output_file_ptr);
    free(image_data);
}

// Main function
int main() {
    const char* input_file = "input.jpg";
    const char* output_file = "output.jpg";
    digital_watermark(input_file, output_file);
    return 0;
}