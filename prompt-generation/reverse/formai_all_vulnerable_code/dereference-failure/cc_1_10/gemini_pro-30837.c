//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define IMAGE_WIDTH  512
#define IMAGE_HEIGHT 512

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} pixel_t;

void embed_watermark(pixel_t *image, const char *watermark, int watermark_length) {
    // Convert the watermark to a binary string.
    char *binary_watermark = (char *)malloc(watermark_length * 8 + 1);
    for (int i = 0; i < watermark_length; i++) {
        for (int j = 0; j < 8; j++) {
            binary_watermark[i * 8 + j] = ((watermark[i] >> (7 - j)) & 1) + '0';
        }
    }
    binary_watermark[watermark_length * 8] = '\0';

    // Embed the binary watermark in the image.
    int bit_index = 0;
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            // Embed the least significant bit of the binary watermark in the red channel of the pixel.
            image[i * IMAGE_WIDTH + j].r = (image[i * IMAGE_WIDTH + j].r & 0xFE) | (binary_watermark[bit_index++] - '0');

            // Embed the second least significant bit of the binary watermark in the green channel of the pixel.
            image[i * IMAGE_WIDTH + j].g = (image[i * IMAGE_WIDTH + j].g & 0xFE) | (binary_watermark[bit_index++] - '0');

            // Embed the third least significant bit of the binary watermark in the blue channel of the pixel.
            image[i * IMAGE_WIDTH + j].b = (image[i * IMAGE_WIDTH + j].b & 0xFE) | (binary_watermark[bit_index++] - '0');
        }
    }

    free(binary_watermark);
}

char *extract_watermark(pixel_t *image, int watermark_length) {
    // Extract the binary watermark from the image.
    char *binary_watermark = (char *)malloc(watermark_length * 8 + 1);
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            // Extract the least significant bit of the binary watermark from the red channel of the pixel.
            binary_watermark[i * IMAGE_WIDTH + j] = (image[i * IMAGE_WIDTH + j].r & 1) + '0';

            // Extract the second least significant bit of the binary watermark from the green channel of the pixel.
            binary_watermark[i * IMAGE_WIDTH + j] |= ((image[i * IMAGE_WIDTH + j].g & 1) << 1) + '0';

            // Extract the third least significant bit of the binary watermark from the blue channel of the pixel.
            binary_watermark[i * IMAGE_WIDTH + j] |= ((image[i * IMAGE_WIDTH + j].b & 1) << 2) + '0';
        }
    }

    // Convert the binary watermark to a string.
    char *watermark = (char *)malloc(watermark_length + 1);
    for (int i = 0; i < watermark_length; i++) {
        watermark[i] = (char)strtol(binary_watermark + i * 8, NULL, 2);
    }
    watermark[watermark_length] = '\0';

    free(binary_watermark);
    return watermark;
}

int main() {
    // Load the image from a file.
    FILE *image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        fprintf(stderr, "Error opening image file.\n");
        return 1;
    }
    pixel_t *image = (pixel_t *)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * sizeof(pixel_t));
    fread(image, sizeof(pixel_t), IMAGE_WIDTH * IMAGE_HEIGHT, image_file);
    fclose(image_file);

    // Embed the watermark in the image.
    const char *watermark = "Hello world!";
    embed_watermark(image, watermark, strlen(watermark));

    // Save the watermarked image to a file.
    image_file = fopen("watermarked_image.bmp", "wb");
    if (image_file == NULL) {
        fprintf(stderr, "Error opening watermarked image file.\n");
        return 1;
    }
    fwrite(image, sizeof(pixel_t), IMAGE_WIDTH * IMAGE_HEIGHT, image_file);
    fclose(image_file);

    // Extract the watermark from the image.
    char *extracted_watermark = extract_watermark(image, strlen(watermark));

    // Print the extracted watermark.
    printf("Extracted watermark: %s\n", extracted_watermark);

    free(image);
    free(extracted_watermark);

    return 0;
}