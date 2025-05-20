//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to embed a watermark into an image
void embed_watermark(char *input_image, char *output_image, char *watermark) {
    // Open the input image
    FILE *input_file = fopen(input_image, "rb");
    if (input_file == NULL) {
        perror("Error opening input image");
        exit(1);
    }

    // Open the output image
    FILE *output_file = fopen(output_image, "wb");
    if (output_file == NULL) {
        perror("Error opening output image");
        exit(1);
    }

    // Read the input image
    unsigned char *input_data = malloc(1000000);
    size_t input_size = fread(input_data, 1, 1000000, input_file);
    if (input_size == 0) {
        perror("Error reading input image");
        exit(1);
    }

    // Resize input data to the length of the image
    input_data = realloc(input_data, input_size);

    // Embed the watermark into the input image data
    size_t watermark_length = strlen(watermark);
    for (size_t i = 0; i < watermark_length; i++) {
        input_data[i] = input_data[i] | (1 << watermark[i]);
    }

    // Write the output image
    fwrite(input_data, 1, input_size, output_file);

    // Free the input image data
    free(input_data);

    // Close the input and output images
    fclose(input_file);
    fclose(output_file);

    // Print a success message
    printf("Watermarking the image was a snap! Check out %s to see the results.\n", output_image);
}

// Function to extract a watermark from an image
void extract_watermark(char *input_image, char *output_watermark) {
    // Open the input image
    FILE *input_file = fopen(input_image, "rb");
    if (input_file == NULL) {
        perror("Error opening input image");
        exit(1);
    }

    // Read the input image
    unsigned char *input_data = malloc(1000000);
    size_t input_size = fread(input_data, 1, 1000000, input_file);
    if (input_size == 0) {
        perror("Error reading input image");
        exit(1);
    }

    // Resize input data to the length of the image
    input_data = realloc(input_data, input_size);

    // Extract the watermark from the input image data
    char *watermark = malloc(1000);
    size_t watermark_length = 0;
    for (size_t i = 0; i < input_size; i++) {
        if (input_data[i] & 1) {
            watermark[watermark_length++] = (char) i;
        }
    }
    watermark[watermark_length] = '\0';

    // Write the output watermark
    FILE *output_file = fopen(output_watermark, "w");
    if (output_file == NULL) {
        perror("Error opening output watermark");
        exit(1);
    }
    fwrite(watermark, 1, watermark_length + 1, output_file);

    // Free the input image data and watermark
    free(input_data);
    free(watermark);

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    // Print a success message
    printf("The extracted watermark is: %s\n", output_watermark);
}

// Main function
int main() {
    // Define the input and output images
    char *input_image = "input.jpg";
    char *output_image = "output.jpg";

    // Define the watermark
    char *watermark = "Watermark!";

    // Embed the watermark into the image
    embed_watermark(input_image, output_image, watermark);

    // Extract the watermark from the image
    char *output_watermark = "output.txt";
    extract_watermark(output_image, output_watermark);

    return 0;
}