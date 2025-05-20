//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Function to embed a simple digital watermark into an image
void embed_watermark(uint8_t *image, size_t width, size_t height, const char *watermark) {
    size_t wm_length = strlen(watermark);
    size_t index = 0;

    // Embed the watermark in the least significant bit of the image's pixel values
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            if (index < wm_length) {
                // Embed watermark character into the blue channel of the pixel
                image[(i * width + j) * 3 + 2] = (image[(i * width + j) * 3 + 2] & 0xFE) | ((watermark[index] >> (j % 8)) & 0x01);
                index++;
            } else {
                return; // Stop if the watermark is fully embedded
            }
        }
    }
}

// Function to extract the watermark from the image
void extract_watermark(uint8_t *image, size_t width, size_t height, char *output, size_t output_size) {
    size_t index = 0;

    // Extract bits from the least significant bit of the blue channel
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            if (index < output_size - 1) {
                output[index] = (output[index] << 1) | (image[(i * width + j) * 3 + 2] & 0x01);
                if ((j + 1) % 8 == 0) {
                    index++;
                }
            } else {
                return; // Stop if the output buffer is filled
            }
        }
    }
    output[index] = '\0'; // Null terminate the extracted string
}

// Function to simulate reading an image (for demonstration purposes)
uint8_t *read_image(const char *filename, size_t *width, size_t *height) {
    // Simulate an image of given width and height; replace this with actual image loading
    *width = 10; // Example width
    *height = 10; // Example height
    uint8_t *image = (uint8_t *)malloc(*width * *height * 3);

    // Initialize image with random colors
    for (size_t i = 0; i < *width * *height * 3; ++i) {
        image[i] = rand() % 256;
    }

    return image;
}

// Function to simulate saving an image (for demonstration purposes)
void save_image(const char *filename, uint8_t *image, size_t width, size_t height) {
    printf("Image saved: %s\n", filename);
}

int main() {
    size_t width, height;
    const char *watermark = "secret";
    char extracted_watermark[64] = {0};

    // Simulate reading an image
    uint8_t *image = read_image("input_image.bmp", &width, &height);

    // Embed the watermark
    embed_watermark(image, width, height, watermark);
    printf("Watermark embedded: %s\n", watermark);

    // Save the modified image
    save_image("output_image.bmp", image, width, height);

    // Extract the watermark
    extract_watermark(image, width, height, extracted_watermark, sizeof(extracted_watermark));
    printf("Extracted Watermark: %s\n", extracted_watermark);

    // Clean up
    free(image);
    return 0;
}