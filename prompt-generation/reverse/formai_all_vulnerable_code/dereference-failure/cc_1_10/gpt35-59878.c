//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to embed the watermark
void embed_watermark(unsigned char *data, unsigned char *watermark, int watermark_size) {
    int i, j;
    unsigned char bit;
    for (i = 0; i < watermark_size; i++) {
        for (j = 0; j < 8; j++) {
            bit = (watermark[i] >> j) & 1;
            data[i] = (data[i] & 0xFE) | bit;
        }
    }
}

// Function to extract the watermark
void extract_watermark(unsigned char *data, unsigned char *watermark, int watermark_size) {
    int i, j;
    unsigned char bit;
    for (i = 0; i < watermark_size; i++) {
        watermark[i] = 0;
        for (j = 0; j < 8; j++) {
            bit = data[i] & 1;
            watermark[i] |= (bit << j);
            data[i] >>= 1;
        }
    }
}

int main() {
    FILE *image_file, *watermark_file, *output_file;
    int image_size, watermark_size, i;
    unsigned char *image_data, *watermark_data, *output_data;

    // Open image file
    image_file = fopen("image.bmp", "rb");
    if (!image_file) {
        printf("Error: Unable to open image file\n");
        return 1;
    }

    // Read image data
    fseek(image_file, 0, SEEK_END);
    image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);
    image_data = (unsigned char *) malloc(image_size);
    fread(image_data, 1, image_size, image_file);

    // Open watermark file
    watermark_file = fopen("watermark.dat", "rb");
    if (!watermark_file) {
        printf("Error: Unable to open watermark file\n");
        return 1;
    }

    // Read watermark data
    fseek(watermark_file, 0, SEEK_END);
    watermark_size = ftell(watermark_file);
    fseek(watermark_file, 0, SEEK_SET);
    watermark_data = (unsigned char *) malloc(watermark_size);
    fread(watermark_data, 1, watermark_size, watermark_file);

    // Embed watermark in image
    embed_watermark(image_data, watermark_data, watermark_size);

    // Open output file
    output_file = fopen("output.bmp", "wb");
    if (!output_file) {
        printf("Error: Unable to create output file\n");
        return 1;
    }

    // Write image data to output file
    fwrite(image_data, 1, image_size, output_file);

    // Close files and free memory
    fclose(image_file);
    fclose(watermark_file);
    fclose(output_file);
    free(image_data);
    free(watermark_data);

    // Extract watermark from image
    image_file = fopen("output.bmp", "rb");
    if (!image_file) {
        printf("Error: Unable to open output file\n");
        return 1;
    }

    // Read output data
    fseek(image_file, 0, SEEK_END);
    image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);
    output_data = (unsigned char *) malloc(image_size);
    fread(output_data, 1, image_size, image_file);

    // Extract watermark from output data
    unsigned char *extracted_watermark = (unsigned char *) malloc(watermark_size);
    extract_watermark(output_data, extracted_watermark, watermark_size);

    // Print extracted watermark
    printf("Extracted Watermark: ");
    for (i = 0; i < watermark_size; i++) {
        printf("%02x ", extracted_watermark[i]);
    }
    printf("\n");

    // Close files and free memory
    fclose(image_file);
    free(extracted_watermark);
    free(output_data);

    return 0;
}