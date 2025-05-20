//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WATERMARK_SIZE 16
#define IMAGE_SIZE 512

int main() {

    // Read in image data
    FILE *image_file = fopen("image.png", "rb");
    if (image_file == NULL) {
        printf("Error: Could not open image file.\n");
        exit(1);
    }
    unsigned char *image_data = malloc(IMAGE_SIZE * sizeof(unsigned char));
    fread(image_data, sizeof(unsigned char), IMAGE_SIZE, image_file);
    fclose(image_file);

    // Read in watermark data
    FILE *watermark_file = fopen("watermark.png", "rb");
    if (watermark_file == NULL) {
        printf("Error: Could not open watermark file.\n");
        exit(1);
    }
    unsigned char *watermark_data = malloc(WATERMARK_SIZE * sizeof(unsigned char));
    fread(watermark_data, sizeof(unsigned char), WATERMARK_SIZE, watermark_file);
    fclose(watermark_file);

    // Apply watermark to image
    int image_index = 0;
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        int watermark_value = watermark_data[i];
        int alpha_value = watermark_value >> 4;
        int red_value = (watermark_value & 0x0F) << 4;
        int green_value = (watermark_value & 0xF0) >> 4;
        int blue_value = (watermark_value & 0xFF) >> 8;
        image_data[image_index] = (alpha_value << 4) | (red_value << 2) | (green_value >> 2) | (blue_value >> 6);
        image_index++;
    }

    // Save watermarked image
    FILE *output_file = fopen("watermarked_image.png", "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }
    fwrite(image_data, sizeof(unsigned char), IMAGE_SIZE, output_file);
    fclose(output_file);

    printf("Watermark applied successfully!\n");

    return 0;
}