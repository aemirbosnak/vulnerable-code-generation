//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void embed(char *image, char *watermark, char *output) {
    // Read the image and watermark files
    FILE *fp_image = fopen(image, "rb");
    if (fp_image == NULL) {
        fprintf(stderr, "Error opening image file: %s\n", image);
        exit(1);
    }
    FILE *fp_watermark = fopen(watermark, "rb");
    if (fp_watermark == NULL) {
        fprintf(stderr, "Error opening watermark file: %s\n", watermark);
        exit(1);
    }

    // Check the size of the watermark
    fseek(fp_watermark, 0, SEEK_END);
    int watermark_size = ftell(fp_watermark);
    if (watermark_size > MAX_SIZE) {
        fprintf(stderr, "Watermark size is too large: %d\n", watermark_size);
        exit(1);
    }

    // Read the image data into a buffer
    fseek(fp_image, 0, SEEK_SET);
    unsigned char *image_data = malloc(MAX_SIZE);
    if (image_data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        exit(1);
    }
    fread(image_data, 1, MAX_SIZE, fp_image);

    // Embed the watermark in the image data
    for (int i = 0; i < watermark_size; i++) {
        // Get the watermark bit
        unsigned char watermark_bit = 0;
        fread(&watermark_bit, 1, 1, fp_watermark);

        // Embed the watermark bit in the image data
        image_data[i] ^= watermark_bit;
    }

    // Write the watermarked image data to a file
    FILE *fp_output = fopen(output, "wb");
    if (fp_output == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", output);
        exit(1);
    }
    fwrite(image_data, 1, MAX_SIZE, fp_output);

    // Free the memory
    free(image_data);
    fclose(fp_image);
    fclose(fp_watermark);
    fclose(fp_output);
}

void extract(char *image, char *output) {
    // Read the watermarked image file
    FILE *fp_image = fopen(image, "rb");
    if (fp_image == NULL) {
        fprintf(stderr, "Error opening image file: %s\n", image);
        exit(1);
    }

    // Read the image data into a buffer
    fseek(fp_image, 0, SEEK_SET);
    unsigned char *image_data = malloc(MAX_SIZE);
    if (image_data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        exit(1);
    }
    fread(image_data, 1, MAX_SIZE, fp_image);

    // Extract the watermark from the image data
    char *watermark = malloc(MAX_SIZE);
    if (watermark == NULL) {
        fprintf(stderr, "Error allocating memory for watermark\n");
        exit(1);
    }
    int watermark_index = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        // Get the watermark bit from the image data
        int watermark_bit = image_data[i] & 1;

        // Store the watermark bit in the watermark buffer
        watermark[watermark_index++] = watermark_bit;
    }

    // Write the watermark to a file
    FILE *fp_output = fopen(output, "wb");
    if (fp_output == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", output);
        exit(1);
    }
    fwrite(watermark, 1, watermark_index, fp_output);

    // Free the memory
    free(image_data);
    free(watermark);
    fclose(fp_image);
    fclose(fp_output);
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s embed/extract image watermark output\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "embed") == 0) {
        embed(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extract(argv[2], argv[3]);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[1]);
        exit(1);
    }

    return 0;
}