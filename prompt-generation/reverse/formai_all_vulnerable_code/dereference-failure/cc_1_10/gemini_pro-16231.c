//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512

// Embed a watermark into an image
void embed_watermark(unsigned char *image, unsigned char *watermark, int watermark_width, int watermark_height) {
    // Get the size of the image
    int image_size = IMAGE_WIDTH * IMAGE_HEIGHT * 3;

    // Get the size of the watermark
    int watermark_size = watermark_width * watermark_height;

    // Iterate over the image and embed the watermark
    for (int i = 0; i < image_size; i += 3) {
        // Get the pixel value
        int pixel_value = (image[i] + image[i + 1] + image[i + 2]) / 3;

        // Get the watermark value
        int watermark_value = watermark[i / 3 % watermark_width + (i / 3 / watermark_width) * watermark_height];

        // Embed the watermark
        image[i] = pixel_value + watermark_value;
        image[i + 1] = pixel_value + watermark_value;
        image[i + 2] = pixel_value + watermark_value;
    }
}

// Extract a watermark from an image
void extract_watermark(unsigned char *image, unsigned char *watermark, int watermark_width, int watermark_height) {
    // Get the size of the image
    int image_size = IMAGE_WIDTH * IMAGE_HEIGHT * 3;

    // Get the size of the watermark
    int watermark_size = watermark_width * watermark_height;

    // Iterate over the image and extract the watermark
    for (int i = 0; i < image_size; i += 3) {
        // Get the pixel value
        int pixel_value = (image[i] + image[i + 1] + image[i + 2]) / 3;

        // Get the watermark value
        int watermark_value = pixel_value - (image[i] + image[i + 1] + image[i + 2]) / 3;

        // Extract the watermark
        watermark[i / 3 % watermark_width + (i / 3 / watermark_width) * watermark_height] = watermark_value;
    }
}

// Save an image to a file
void save_image(unsigned char *image, char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "wb");

    // Write the image to the file
    fwrite(image, IMAGE_WIDTH * IMAGE_HEIGHT * 3, 1, fp);

    // Close the file
    fclose(fp);
}

// Load an image from a file
unsigned char *load_image(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "rb");

    // Get the size of the file
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for the image
    unsigned char *image = malloc(file_size);

    // Read the image from the file
    fread(image, file_size, 1, fp);

    // Close the file
    fclose(fp);

    // Return the image
    return image;
}

// Main function
int main(int argc, char *argv[]) {
    // Check the arguments
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input image> <output image> <watermark image> <watermark size>\n", argv[0]);
        return 1;
    }

    // Load the input image
    unsigned char *input_image = load_image(argv[1]);

    // Load the watermark image
    unsigned char *watermark_image = load_image(argv[3]);

    // Get the watermark size
    int watermark_width = atoi(argv[4]);
    int watermark_height = atoi(argv[4]);

    // Embed the watermark
    embed_watermark(input_image, watermark_image, watermark_width, watermark_height);

    // Save the output image
    save_image(input_image, argv[2]);

    // Free the memory
    free(input_image);
    free(watermark_image);

    return 0;
}