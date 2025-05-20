//FormAI DATASET v1.0 Category: Image compression ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    printf("Welcome to our image compression program!\n");

    // Open the input file
    FILE *input_file = fopen("input.bmp", "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file!\n");
        return 1;
    }

    // Allocate memory for input image data
    uint8_t *input_data = (uint8_t *)malloc(sizeof(uint8_t) * 1024 * 1024);
    if (input_data == NULL) {
        printf("Error: Could not allocate memory for input image!\n");
        return 1;
    }

    // Read the input image data
    size_t input_size = fread(input_data, sizeof(uint8_t), 1024 * 1024, input_file);
    if (input_size == 0) {
        printf("Error: Could not read input file!\n");
        return 1;
    }

    // Close the input file
    fclose(input_file);

    // Compress the input image data
    for (int i = 0; i < input_size; i++) {
        input_data[i] /= 2;
    }

    // Open the output file
    FILE *output_file = fopen("output.bmp", "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file!\n");
        return 1;
    }

    // Write the compressed image data
    size_t output_size = fwrite(input_data, sizeof(uint8_t), input_size, output_file);
    if (output_size == 0) {
        printf("Error: Could not write output file!\n");
        return 1;
    }

    // Close the output file
    fclose(output_file);

    printf("Compression successful! Compressed image saved as output.bmp\n");
    free(input_data);
    return 0;
}