//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("\nUsage: %s <input file> <output file> <watermark>\n", argv[0]);
        printf("Example: %s input.bmp output.bmp mywatermark\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("\n Failed to open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("\n Failed to open output file.\n");
        return 1;
    }

    char *watermark = argv[3];

    // Read header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_file);

    // Get image size
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int padding = 0;

    // Calculate padding
    while ((width * 3 + padding) % 4 != 0) {
        padding++;
    }

    // Calculate image length
    int image_size = width * height * 3 + height * padding;

    // Allocate memory for image and watermark
    unsigned char *image = (unsigned char*)malloc(sizeof(unsigned char) * image_size);
    unsigned char *new_image = (unsigned char*)malloc(sizeof(unsigned char) * image_size);
    unsigned char *watermark_binary = (unsigned char*)malloc(sizeof(unsigned char) * (strlen(watermark) * 8 + 1));

    // Read image
    fread(image, sizeof(unsigned char), image_size, input_file);

    // Convert watermark to binary
    int i = 0;
    for (i = 0; i < strlen(watermark) * 8; i++) {
        watermark_binary[i] = (watermark[i/8] >> (i%8)) & 1;
    }
    watermark_binary[strlen(watermark) * 8] = '\0';

    // Add watermark to image
    int j = 0;
    for (i = 0; i < image_size; i++) {
        if (i % 3 == 0) {
            int bit = watermark_binary[j];
            j++;

            // Power of 2 coefficient
            int coeff = pow(2, (i/3) % 8);

            // Pixel
            unsigned char pixel = image[i];

            // Change least significant bit
            pixel = ((pixel >> 1) << 1) | bit;

            // Update image
            new_image[i] = pixel;
        } else {
            new_image[i] = image[i];
        }
    }

    // Write header
    fwrite(header, sizeof(unsigned char), 54, output_file);

    // Write new image
    fwrite(new_image, sizeof(unsigned char), image_size, output_file);

    // Free memory
    free(image);
    free(new_image);
    free(watermark_binary);

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}