//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define PATTERN_SIZE 8

void embed_watermark(uint8_t *image_data, uint32_t image_size, char *watermark) {
    uint32_t watermark_size = strlen(watermark);

    // Calculate the number of pixels required to embed the whole watermark
    uint32_t pixels_required = watermark_size * PATTERN_SIZE;

    // Calculate the number of pixels needed for the header
    uint32_t header_size = PATTERN_SIZE + 32; // 32 bits for the watermark size

    // Check if there is enough space in the image to embed the watermark
    if ((pixels_required + header_size) > (image_size / 3)) {
        printf("Image too small to embed the watermark.\n");
        return;
    }

    // Embed the watermark size in the first 32 bits of the image data
    uint32_t watermark_size_bits = watermark_size * PATTERN_SIZE;
    uint32_t *header = (uint32_t *) image_data;
    *header = watermark_size_bits;

    // Embed the watermark pattern in the image data
    uint8_t mask = 0x03; // 00000011

    uint32_t i, j;
    for (i = header_size, j = 0; j < watermark_size; i += PATTERN_SIZE, j++) {
        char c = watermark[j];
        uint8_t pattern = (uint8_t) c;
        pattern <<= 2; // Shift the pattern to make room for the mask
        pattern |= mask; // Apply the mask

        image_data[i] = pattern;
        image_data[i+1] = pattern >> 8;
        image_data[i+2] = pattern >> 16;
    }

    printf("Watermark embedded successfully.\n");
}

char *extract_watermark(uint8_t *image_data) {
    // Extract the watermark size from the first 32 bits of the image data
    uint32_t *header = (uint32_t *) image_data;
    uint32_t watermark_size_bits = *header;
    uint32_t watermark_size = watermark_size_bits / PATTERN_SIZE;

    // Extract the watermark pattern from the image data
    char *watermark = (char *) malloc((watermark_size + 1) * sizeof(char));

    uint8_t mask = 0x03; // 00000011

    uint32_t i, j;
    for (i = PATTERN_SIZE + 32, j = 0; j < watermark_size; i += PATTERN_SIZE, j++) {
        uint8_t pattern = image_data[i] | (image_data[i+1] << 8) | (image_data[i+2] << 16);
        pattern &= mask; // Apply the mask
        pattern >>= 2; // Shift the pattern back to get rid of the mask

        watermark[j] = (char) pattern;
    }

    watermark[watermark_size] = '\0';

    return watermark;
}

int main() {
    char *watermark = "Hello, world! This is a test.";

    // Load the image data from a file
    FILE *image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        printf("Failed to open image file.\n");
        return 1;
    }

    fseek(image_file, 0, SEEK_END);
    uint32_t image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    uint8_t *image_data = (uint8_t *) malloc(image_size * sizeof(uint8_t));
    fread(image_data, sizeof(uint8_t), image_size, image_file);

    fclose(image_file);

    // Embed the watermark in the image data
    embed_watermark(image_data, image_size, watermark);

    // Extract the watermark from the image data
    char *extracted_watermark = extract_watermark(image_data);

    printf("Extracted watermark: %s\n", extracted_watermark);

    free(extracted_watermark);
    free(image_data);

    return 0;
}