//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to embed the digital watermark in the image
void embed_watermark(unsigned char *image, unsigned char *watermark, int image_length, int watermark_length) {
    int watermark_index = 0;
    int watermark_bit_index = 0;
    int i, j;

    // Embed the watermark in each byte of the image
    for (i = 0; i < image_length && watermark_index < watermark_length; ++i) {
        for (j = 0; j < 8 && watermark_index < watermark_length; ++j) {
            int image_bit_index = (i * 8) + j;

            // Get the bit from the image byte and bit from watermark byte
            int image_bit = (image[i] >> j) & 1;
            int watermark_bit = (watermark[watermark_index] >> watermark_bit_index) & 1;

            // If the bit from watermark is 1, then set the LSB of the image byte to 1
            if (watermark_bit == 1) {
                image[i] |= (1 << j);
            }
            // If the bit from watermark is 0 and LSB of image byte is 0, then no change is required
            // If the bit from watermark is 0 and LSB of image byte is 1, then set the LSB of the image byte to 0
            else {
                if (image_bit == 1) {
                    image[i] &= ~(1 << j);
                }
            }

            // Move to the next bit of the watermark
            watermark_bit_index++;

            // If all bits of the watermark byte are processed, move to the next watermark byte
            if (watermark_bit_index >= 8) {
                watermark_index++;
                watermark_bit_index = 0;
            }
        }
    }
}

// Function to extract the digital watermark from the image
void extract_watermark(unsigned char *image, unsigned char *watermark, int image_length, int watermark_length) {
    int watermark_index = 0;
    int watermark_bit_index = 0;
    int i, j;

    // Extract the watermark from each byte of the image
    for (i = 0; i < image_length && watermark_index < watermark_length; ++i) {
        for (j = 0; j < 8 && watermark_index < watermark_length; ++j) {
            int image_bit_index = (i * 8) + j;

            // Get the bit from the image byte
            int image_bit = (image[i] >> j) & 1;

            // If the LSB of the image byte is 1, then the corresponding bit of the watermark is 1
            // If the LSB of the image byte is 0, then the corresponding bit of the watermark is 0
            if (image_bit == 1) {
                watermark[watermark_index] |= (1 << watermark_bit_index);
            }
            else {
                watermark[watermark_index] &= ~(1 << watermark_bit_index);
            }

            // Move to the next bit of the watermark
            watermark_bit_index++;

            // If all bits of the watermark byte are processed, move to the next watermark byte
            if (watermark_bit_index >= 8) {
                watermark_index++;
                watermark_bit_index = 0;
            }
        }
    }
}

int main() {
    // Read the image and the watermark from files
    FILE *image_file = fopen("image.bmp", "rb");
    FILE *watermark_file = fopen("watermark.dat", "rb");

    if (image_file == NULL || watermark_file == NULL) {
        printf("Error: Could not open input files.\n");
        return 1;
    }

    // Read the image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image_file);

    // Get the size of the image
    int image_width = *(int*)&header[18];
    int image_height = *(int*)&header[22];

    // Calculate the length of the image data
    int image_size = image_width * image_height * 3;

    // Allocate memory for the image and watermark buffers
    unsigned char *image = (unsigned char*)malloc(image_size);
    unsigned char *watermark = (unsigned char*)malloc(image_size / 8);

    if (image == NULL || watermark == NULL) {
        printf("Error: Could not allocate memory.\n");
        return 1;
    }

    // Read the image data
    fread(image, sizeof(unsigned char), image_size, image_file);

    // Get the length of the watermark
    fseek(watermark_file, 0L, SEEK_END);
    int watermark_length = ftell(watermark_file);
    rewind(watermark_file);

    // Read the watermark data
    fread(watermark, sizeof(unsigned char), watermark_length, watermark_file);

    // Embed the watermark in the image
    embed_watermark(image, watermark, image_size, watermark_length);

    // Write the watermarked image to file
    FILE *output_file = fopen("watermarked_image.bmp", "wb");

    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    fwrite(header, sizeof(unsigned char), 54, output_file);
    fwrite(image, sizeof(unsigned char), image_size, output_file);

    // Close the files
    fclose(image_file);
    fclose(watermark_file);
    fclose(output_file);

    // Extract the watermark from the watermarked image
    unsigned char *extracted_watermark = (unsigned char*)malloc(image_size / 8);

    if (extracted_watermark == NULL) {
        printf("Error: Could not allocate memory.\n");
        return 1;
    }

    // Read the watermarked image from file
    FILE *input_file = fopen("watermarked_image.bmp", "rb");

    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Read the image header
    unsigned char extracted_header[54];
    fread(extracted_header, sizeof(unsigned char), 54, input_file);

    // Read the watermarked image data
    fread(image, sizeof(unsigned char), image_size, input_file);

    // Extract the watermark from the watermarked image
    extract_watermark(image, extracted_watermark, image_size, watermark_length);

    // Compare the extracted watermark with the original watermark
    if (memcmp(watermark, extracted_watermark, watermark_length) == 0) {
        printf("Watermarking and extraction successful.\n");
    }
    else {
        printf("Watermarking and extraction unsuccessful.\n");
    }

    // Close the files
    fclose(input_file);

    // Free the memory
    free(image);
    free(watermark);
    free(extracted_watermark);

    return 0;
}