//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define IMG_WIDTH 512
#define IMG_HEIGHT 512

// Function to read the image from a file
unsigned char* read_image(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    unsigned char *image_data = malloc(IMG_WIDTH * IMG_HEIGHT * 3);
    fread(image_data, IMG_WIDTH * IMG_HEIGHT * 3, 1, fp);
    fclose(fp);

    return image_data;
}

// Function to write the image to a file
void write_image(char* filename, unsigned char* image_data) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fwrite(image_data, IMG_WIDTH * IMG_HEIGHT * 3, 1, fp);
    fclose(fp);
}

// Function to embed the watermark in the image
void embed_watermark(unsigned char* image_data, char* watermark) {
    // Convert the watermark to a bitstream
    unsigned char* watermark_bits = malloc(strlen(watermark) * 8);
    for (int i = 0; i < strlen(watermark); i++) {
        for (int j = 0; j < 8; j++) {
            watermark_bits[i * 8 + j] = (watermark[i] >> j) & 1;
        }
    }

    // Embed the watermark in the image
    int watermark_index = 0;
    for (int i = 0; i < IMG_WIDTH * IMG_HEIGHT * 3; i++) {
        // Embed the watermark bit in the least significant bit of the pixel
        image_data[i] &= 0xFE;
        image_data[i] |= watermark_bits[watermark_index++];

        // Check if we have reached the end of the watermark
        if (watermark_index == strlen(watermark) * 8) {
            break;
        }
    }

    free(watermark_bits);
}

// Function to extract the watermark from the image
char* extract_watermark(unsigned char* image_data) {
    // Extract the watermark from the image
    unsigned char* watermark_bits = malloc(IMG_WIDTH * IMG_HEIGHT * 3 / 8);
    for (int i = 0; i < IMG_WIDTH * IMG_HEIGHT * 3; i++) {
        // Extract the watermark bit from the least significant bit of the pixel
        watermark_bits[i / 8] |= (image_data[i] & 1) << (7 - (i % 8));
    }

    // Convert the watermark bitstream to a string
    char* watermark = malloc(strlen(watermark_bits) / 8 + 1);
    for (int i = 0; i < strlen(watermark_bits) / 8; i++) {
        watermark[i] = 0;
        for (int j = 0; j < 8; j++) {
            watermark[i] |= watermark_bits[i * 8 + j] << j;
        }
    }
    watermark[strlen(watermark_bits) / 8] = '\0';

    free(watermark_bits);

    return watermark;
}

int main() {
    // Read the image from a file
    unsigned char* image_data = read_image("image.bmp");

    // Embed the watermark in the image
    embed_watermark(image_data, "This is a watermark");

    // Write the watermarked image to a file
    write_image("watermarked_image.bmp", image_data);

    // Extract the watermark from the watermarked image
    char* watermark = extract_watermark(image_data);

    // Print the extracted watermark
    printf("Extracted watermark: %s\n", watermark);

    free(image_data);
    free(watermark);

    return 0;
}