//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

// Embed the watermark into the image
void embed_watermark(unsigned char *image, int image_len, unsigned char *watermark, int watermark_len) {
    // Check if the watermark fits into the image
    if (watermark_len > image_len) {
        printf("Watermark is too large for the image.\n");
        return;
    }

    // Embed the watermark into the image
    for (int i = 0; i < watermark_len; i++) {
        image[i] = image[i] | watermark[i];
    }
}

// Extract the watermark from the image
void extract_watermark(unsigned char *image, int image_len, unsigned char *watermark, int watermark_len) {
    // Check if the watermark is embedded in the image
    for (int i = 0; i < watermark_len; i++) {
        if ((image[i] & watermark[i]) != watermark[i]) {
            printf("Watermark is not embedded in the image.\n");
            return;
        }
    }

    // Extract the watermark from the image
    for (int i = 0; i < watermark_len; i++) {
        watermark[i] = image[i] & watermark[i];
    }
}

int main(int argc, char **argv) {
    // Check the arguments
    if (argc < 4) {
        printf("Usage: %s <image> <watermark> <output>\n", argv[0]);
        return 1;
    }

    // Read the image
    FILE *image_file = fopen(argv[1], "rb");
    if (image_file == NULL) {
        printf("Error opening the image file.\n");
        return 1;
    }
    unsigned char *image = malloc(MAX_LEN);
    int image_len = fread(image, 1, MAX_LEN, image_file);
    fclose(image_file);

    // Read the watermark
    FILE *watermark_file = fopen(argv[2], "rb");
    if (watermark_file == NULL) {
        printf("Error opening the watermark file.\n");
        return 1;
    }
    unsigned char *watermark = malloc(MAX_LEN);
    int watermark_len = fread(watermark, 1, MAX_LEN, watermark_file);
    fclose(watermark_file);

    // Embed the watermark into the image
    embed_watermark(image, image_len, watermark, watermark_len);

    // Write the watermarked image to the output file
    FILE *output_file = fopen(argv[3], "wb");
    if (output_file == NULL) {
        printf("Error opening the output file.\n");
        return 1;
    }
    fwrite(image, 1, image_len, output_file);
    fclose(output_file);

    // Extract the watermark from the image
    unsigned char *extracted_watermark = malloc(MAX_LEN);
    extract_watermark(image, image_len, extracted_watermark, watermark_len);

    // Check if the extracted watermark matches the original watermark
    if (memcmp(extracted_watermark, watermark, watermark_len) == 0) {
        printf("Watermark successfully embedded and extracted.\n");
    } else {
        printf("Watermark embedding or extraction failed.\n");
    }

    // Free the memory
    free(image);
    free(watermark);
    free(extracted_watermark);

    return 0;
}