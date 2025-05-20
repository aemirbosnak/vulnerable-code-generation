//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: relaxed
/*
 * This program demonstrates a simple method of digital image watermarking using C.
 * The program accepts an input image and a watermark image and embeds the watermark in the input image.
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the image dimensions
#define IMAGE_WIDTH 256
#define IMAGE_HEIGHT 256
#define IMAGE_SIZE (IMAGE_WIDTH * IMAGE_HEIGHT)

// Define the watermark dimensions
#define WATERMARK_WIDTH 64
#define WATERMARK_HEIGHT 64
#define WATERMARK_SIZE (WATERMARK_WIDTH * WATERMARK_HEIGHT)

// Define the scaling factor for the watermark
#define WATERMARK_SCALE_FACTOR 0.5

// Define the strength of the watermark (0 - 1)
#define WATERMARK_STRENGTH 0.5

// Define the number of bits to use for the watermark
#define WATERMARK_BITS 5

// Define the number of times to iterate the watermarking process
#define WATERMARK_ITERATIONS 5

unsigned char *read_image(char *filename);
void write_image(char *filename, unsigned char *image);
unsigned char *resize_image(unsigned char *image, int width, int height);
unsigned char *generate_watermark(int width, int height);
unsigned char *embed_watermark(unsigned char *image, unsigned char *watermark);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_image> <watermark_image>\n", argv[0]);
        exit(1);
    }

    char *input_filename = argv[1];
    char *watermark_filename = argv[2];

    // Read the input image and watermark image
    unsigned char *input_image = read_image(input_filename);
    unsigned char *watermark_image = read_image(watermark_filename);

    // Resize the watermark image
    watermark_image = resize_image(watermark_image, WATERMARK_WIDTH, WATERMARK_HEIGHT);

    // Generate the final watermark by scaling and quantizing the image
    unsigned char *watermark = generate_watermark(WATERMARK_WIDTH, WATERMARK_HEIGHT);

    // Embed the watermark in the input image
    unsigned char *output_image = embed_watermark(input_image, watermark);

    // Write the output image to disk
    char *output_filename = "watermarked_image.raw";
    write_image(output_filename, output_image);

    // Free memory
    free(input_image);
    free(output_image);
    free(watermark_image);
    free(watermark);

    return 0;
}

/*
 * Reads an image file from disk and returns a pointer to the image data.
 */
unsigned char *read_image(char *filename) {
    FILE *file;
    unsigned char *image;

    // Open the file
    file = fopen(filename, "rb");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // Allocate memory for the image
    image = (unsigned char *) malloc(IMAGE_SIZE);
    if (!image) {
        printf("Error: could not allocate memory for image\n");
        exit(1);
    }

    // Read the image data from the file
    fread(image, sizeof(unsigned char), IMAGE_SIZE, file);

    // Close the file
    fclose(file);

    return image;
}

/*
 * Writes an image file to disk.
 */
void write_image(char *filename, unsigned char *image) {
    FILE *file;

    // Open the file
    file = fopen(filename, "wb");
    if (!file) {
        printf("Error: could not open file %s for writing\n", filename);
        exit(1);
    }

    // Write the image data to the file
    fwrite(image, sizeof(unsigned char), IMAGE_SIZE, file);

    // Close the file
    fclose(file);
}

/*
 * Resizes an image to the specified dimensions using nearest-neighbor interpolation.
 */
unsigned char *resize_image(unsigned char *image, int width, int height) {
    int i, j, x, y, index;
    unsigned char *resized_image;

    // Allocate memory for the resized image
    resized_image = (unsigned char *) malloc(width * height);
    if (!resized_image) {
        printf("Error: could not allocate memory for resized image\n");
        exit(1);
    }

    // Resize the image using nearest-neighbor interpolation
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            x = (int) ((float) j / width * IMAGE_WIDTH);
            y = (int) ((float) i / height * IMAGE_HEIGHT);
            index = y * IMAGE_WIDTH + x;
            resized_image[i * width + j] = image[index];
        }
    }

    return resized_image;
}

/*
 * Generates a watermark by scaling and quantizing the input image.
 */
unsigned char *generate_watermark(int width, int height) {
    int i, j, index;
    float scale_factor = WATERMARK_SCALE_FACTOR;
    unsigned char *watermark_image;
    unsigned char *watermark;

    // Allocate memory for the watermark image
    watermark_image = (unsigned char *) malloc(width * height);
    if (!watermark_image) {
        printf("Error: could not allocate memory for watermark image\n");
        exit(1);
    }

    // Generate the watermark by scaling and quantizing the input image
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            index = i * width + j;
            watermark_image[index] = (unsigned char) floor(scale_factor * (float) (rand() % 256));
        }
    }

    // Allocate memory for the final watermark
    watermark = (unsigned char *) malloc(WATERMARK_SIZE);
    if (!watermark) {
        printf("Error: could not allocate memory for watermark\n");
        exit(1);
    }

    // Quantize the watermark to the specified number of bits
    for (i = 0; i < WATERMARK_SIZE; i++) {
        watermark[i] = watermark_image[i] >> (8 - WATERMARK_BITS);
    }

    // Free memory
    free(watermark_image);

    return watermark;
}

/*
 * Embeds the watermark in the input image.
 */
unsigned char *embed_watermark(unsigned char *input_image, unsigned char *watermark) {
    int i, j, k, index;
    float strength = WATERMARK_STRENGTH;
    unsigned char *output_image;
    unsigned char *temp_image;

    // Allocate memory for the output image
    output_image = (unsigned char *) malloc(IMAGE_SIZE);
    if (!output_image) {
        printf("Error: could not allocate memory for output image\n");
        exit(1);
    }

    // Allocate memory for the temporary image
    temp_image = (unsigned char *) malloc(IMAGE_SIZE);
    if (!temp_image) {
        printf("Error: could not allocate memory for temp image\n");
        exit(1);
    }

    // Copy the input image to the output image
    memcpy(output_image, input_image, IMAGE_SIZE);

    // Iterate the watermarking process
    for (k = 0; k < WATERMARK_ITERATIONS; k++) {
        // Embed the watermark in the image
        for (i = 0; i < IMAGE_HEIGHT; i++) {
            for (j = 0; j < IMAGE_WIDTH; j++) {
                index = i * IMAGE_WIDTH + j;
                output_image[index] = input_image[index] + strength * watermark[index];
            }
        }

        // Reverse the process
        for (i = 0; i < IMAGE_HEIGHT; i++) {
            for (j = 0; j < IMAGE_WIDTH; j++) {
                index = i * IMAGE_WIDTH + j;
                temp_image[index] = output_image[index] - strength * watermark[index];
            }
        }

        // Copy the temporary image to the output image
        memcpy(output_image, temp_image, IMAGE_SIZE);
    }

    // Free memory
    free(temp_image);

    return output_image;
}