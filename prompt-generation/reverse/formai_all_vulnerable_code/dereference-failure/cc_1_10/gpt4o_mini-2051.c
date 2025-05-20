//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define WATERMARK_SIZE 8
#define BLOCK_SIZE 16

typedef struct {
    uint8_t *data;
    size_t width;
    size_t height;
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, Image *image);
void add_watermark(Image *image, const char *watermark);
void extract_watermark(Image *image);
void free_image(Image *image);

int main() {
    char input_file[100];
    char output_file[100];
    char watermark[WATERMARK_SIZE + 1];

    printf("Enter the input image file name: ");
    scanf("%s", input_file);
    printf("Enter the output image file name: ");
    scanf("%s", output_file);
    printf("Enter the watermark (max %d chars): ", WATERMARK_SIZE);
    scanf("%s", watermark);
    
    if (strlen(watermark) > WATERMARK_SIZE) {
        fprintf(stderr, "Watermark exceeds maximum allowed length of %d characters.\n", WATERMARK_SIZE);
        return EXIT_FAILURE;
    }

    Image *image = load_image(input_file);
    if (image == NULL) {
        fprintf(stderr, "Failed to load image.\n");
        return EXIT_FAILURE;
    }

    add_watermark(image, watermark);
    save_image(output_file, image);
    printf("Watermark added successfully to %s\n", output_file);

    // For extraction, we can simply call a function to extract watermark
    // from the saved watermarked image.
    extract_watermark(image);
    
    free_image(image);
    return EXIT_SUCCESS;
}

Image* load_image(const char *filename) {
    // Simulate loading an image (Here we are pretending any file is a dummy image)
    Image *img = malloc(sizeof(Image));
    img->width = 128; // Example dimension
    img->height = 128; // Example dimension
    img->data = malloc(img->width * img->height * 3); // RGB channels

    // Fill image with dummy data.
    for (size_t i = 0; i < img->width * img->height * 3; i++) {
        img->data[i] = rand() % 256;
    }

    return img;
}

void save_image(const char *filename, Image *image) {
    // Simulate saving the image (This would actually save to a real format)
    printf("Saving the image to %s...\n", filename);
}

void add_watermark(Image *image, const char *watermark) {
    // Add watermark into the image's data
    for (size_t i = 0; i < WATERMARK_SIZE; i++) {
        size_t pixel_index = (image->height - 1) * image->width + (i * BLOCK_SIZE); // Insert at bottom row
        image->data[pixel_index * 3 + 0] = (uint8_t) watermark[i]; // Red channel dominance
        image->data[pixel_index * 3 + 1] = (uint8_t) watermark[i]; // Green channel dominance
        image->data[pixel_index * 3 + 2] = (uint8_t) watermark[i]; // Blue channel dominance
    }
}

void extract_watermark(Image *image) {
    char extracted_watermark[WATERMARK_SIZE + 1] = {0};

    for (size_t i = 0; i < WATERMARK_SIZE; i++) {
        size_t pixel_index = (image->height - 1) * image->width + (i * BLOCK_SIZE);
        extracted_watermark[i] = image->data[pixel_index * 3]; // assuming watermarked in red channel
    }

    printf("Extracted Watermark: %s\n", extracted_watermark);
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}