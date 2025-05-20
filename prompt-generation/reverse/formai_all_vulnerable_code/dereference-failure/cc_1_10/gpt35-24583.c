//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define the watermark as a string
#define WATERMARK "my watermark"

// Define the size of the watermark in bits
#define WATERMARK_SIZE 128

// Define the image width and height
#define IMG_WIDTH 640
#define IMG_HEIGHT 480

// Define the image data structure
typedef struct {
    uint8_t *data;
    int width;
    int height;
} Image;

// Apply the watermark to the image
void apply_watermark(Image *img) {
    // Calculate the number of pixels required to store the watermark
    int num_pixels = (WATERMARK_SIZE + 7) / 8;

    // Allocate memory for the watermark data
    uint8_t *watermark = (uint8_t *) malloc(num_pixels);

    // Convert the watermark string to binary form
    memset(watermark, 0, num_pixels);
    for (int i = 0; i < strlen(WATERMARK); i++) {
        int byte_index = i / 8;
        int bit_index = i % 8;
        watermark[byte_index] |= (WATERMARK[i] & 1) << bit_index;
    }

    // Embed the watermark in the image data
    for (int i = 0; i < num_pixels; i++) {
        int bit_offset = i * 8;
        for (int j = 0; j < 8; j++) {
            int pixel_index = bit_offset + j;
            int pixel_value = img->data[pixel_index];
            int watermark_bit = (watermark[i] >> j) & 1;
            int new_pixel = (pixel_value & 0xfe) | watermark_bit;
            img->data[pixel_index] = new_pixel;
        }
    }

    // Free the watermark memory
    free(watermark);
}

int main() {
    // Create a test image
    Image img;
    img.width = IMG_WIDTH;
    img.height = IMG_HEIGHT;
    img.data = (uint8_t *) malloc(img.width * img.height);

    // Apply the watermark
    apply_watermark(&img);

    // Save the image to file
    FILE *fp = fopen("watermarked_image.raw", "wb");
    fwrite(img.data, img.width * img.height, 1, fp);
    fclose(fp);

    // Free the image memory
    free(img.data);

    return 0;
}