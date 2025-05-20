//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the image data
#define MAX_IMAGE_DATA_SIZE 1024 * 1024

// Define the maximum size of the watermark data
#define MAX_WATERMARK_DATA_SIZE 1024

// Define the number of bits to use for the watermark
#define NUM_BITS_PER_WATERMARK 8

// Function to embed the watermark into the image data
void embed_watermark(unsigned char *image_data, int image_data_size, unsigned char *watermark_data, int watermark_data_size)
{
    // Check if the image data is large enough to hold the watermark data
    if (image_data_size < watermark_data_size * NUM_BITS_PER_WATERMARK) {
        fprintf(stderr, "Error: The image data is not large enough to hold the watermark data.\n");
        exit(EXIT_FAILURE);
    }

    // Embed the watermark data into the image data
    for (int i = 0; i < watermark_data_size; i++) {
        for (int j = 0; j < NUM_BITS_PER_WATERMARK; j++) {
            // Get the bit from the watermark data
            int bit = (watermark_data[i] >> j) & 1;

            // Set the corresponding bit in the image data
            image_data[i * NUM_BITS_PER_WATERMARK + j] = (image_data[i * NUM_BITS_PER_WATERMARK + j] & ~1) | bit;
        }
    }
}

// Function to extract the watermark from the image data
void extract_watermark(unsigned char *image_data, int image_data_size, unsigned char *watermark_data, int watermark_data_size)
{
    // Check if the image data contains the watermark data
    if (image_data_size < watermark_data_size * NUM_BITS_PER_WATERMARK) {
        fprintf(stderr, "Error: The image data does not contain the watermark data.\n");
        exit(EXIT_FAILURE);
    }

    // Extract the watermark data from the image data
    for (int i = 0; i < watermark_data_size; i++) {
        for (int j = 0; j < NUM_BITS_PER_WATERMARK; j++) {
            // Get the bit from the image data
            int bit = image_data[i * NUM_BITS_PER_WATERMARK + j] & 1;

            // Set the corresponding bit in the watermark data
            watermark_data[i] = (watermark_data[i] << 1) | bit;
        }
    }
}

// Main function
int main(int argc, char *argv[])
{
    // Check if the correct number of arguments have been provided
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image> <watermark> <output_image>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Read the input image data from a file
    FILE *input_image_file = fopen(argv[1], "rb");
    if (input_image_file == NULL) {
        fprintf(stderr, "Error: Could not open the input image file.\n");
        exit(EXIT_FAILURE);
    }

    unsigned char *image_data = malloc(MAX_IMAGE_DATA_SIZE);
    int image_data_size = fread(image_data, 1, MAX_IMAGE_DATA_SIZE, input_image_file);
    fclose(input_image_file);

    // Read the watermark data from a file
    FILE *watermark_file = fopen(argv[2], "rb");
    if (watermark_file == NULL) {
        fprintf(stderr, "Error: Could not open the watermark file.\n");
        exit(EXIT_FAILURE);
    }

    unsigned char *watermark_data = malloc(MAX_WATERMARK_DATA_SIZE);
    int watermark_data_size = fread(watermark_data, 1, MAX_WATERMARK_DATA_SIZE, watermark_file);
    fclose(watermark_file);

    // Embed the watermark into the image data
    embed_watermark(image_data, image_data_size, watermark_data, watermark_data_size);
    
    //Free the allocated memory
    free(image_data);
    free(watermark_data);

    // Write the watermarked image data to a file
    FILE *output_image_file = fopen(argv[3], "wb");
    if (output_image_file == NULL) {
        fprintf(stderr, "Error: Could not open the output image file.\n");
        exit(EXIT_FAILURE);
    }

    fwrite(image_data, 1, image_data_size, output_image_file);
    fclose(output_image_file);

    printf("Watermarking successful.\n");

    return EXIT_SUCCESS;
}