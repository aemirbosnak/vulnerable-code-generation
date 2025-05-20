//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Elementary, my dear Watson!
int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <input image> <watermark image> <output image>\n", argv[0]);
        return 1;
    }

    // Load the input image
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input image file: %s\n", argv[1]);
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    long input_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    uint8_t *input_image = malloc(input_size);
    if (input_image == NULL) {
        printf("Error allocating memory for input image\n");
        fclose(input_file);
        return 1;
    }

    fread(input_image, 1, input_size, input_file);
    fclose(input_file);

    // Load the watermark image
    FILE *watermark_file = fopen(argv[2], "rb");
    if (watermark_file == NULL) {
        printf("Error opening watermark image file: %s\n", argv[2]);
        free(input_image);
        return 1;
    }

    fseek(watermark_file, 0, SEEK_END);
    long watermark_size = ftell(watermark_file);
    fseek(watermark_file, 0, SEEK_SET);

    uint8_t *watermark_image = malloc(watermark_size);
    if (watermark_image == NULL) {
        printf("Error allocating memory for watermark image\n");
        fclose(watermark_file);
        free(input_image);
        return 1;
    }

    fread(watermark_image, 1, watermark_size, watermark_file);
    fclose(watermark_file);

    // Embed the watermark in the input image
    int watermark_width = 64;
    int watermark_height = 64;

    for (int y = 0; y < watermark_height; y++) {
        for (int x = 0; x < watermark_width; x++) {
            int input_offset = (y * input_size / watermark_height) + (x * 3 / watermark_width);
            int watermark_offset = (y * watermark_size / watermark_height) + (x / watermark_width);

            uint8_t watermark_value = watermark_image[watermark_offset];

            input_image[input_offset] = (input_image[input_offset] & 0xF0) | (watermark_value >> 4);
            input_image[input_offset + 1] = (input_image[input_offset + 1] & 0xF0) | (watermark_value & 0x0F);
            input_image[input_offset + 2] = (input_image[input_offset + 2] & 0xF0) | ((watermark_value >> 6) & 0x03);
        }
    }

    // Save the watermarked image
    FILE *output_file = fopen(argv[3], "wb");
    if (output_file == NULL) {
        printf("Error opening output image file: %s\n", argv[3]);
        free(input_image);
        free(watermark_image);
        return 1;
    }

    fwrite(input_image, 1, input_size, output_file);
    fclose(output_file);

    free(input_image);
    free(watermark_image);

    printf("Watermarking complete! Elementary, my dear Watson.\n");
    return 0;
}