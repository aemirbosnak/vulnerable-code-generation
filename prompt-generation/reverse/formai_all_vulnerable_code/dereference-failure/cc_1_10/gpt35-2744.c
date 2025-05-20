//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void embed_watermark(char image_file_name[], char watermark_file_name[], char output_file_name[]) {
    // Open the image file in binary read mode
    FILE *image_file = fopen(image_file_name, "rb");
    if (image_file == NULL) {
        printf("Error: Image file could not be opened!\n");
        return;
    }

    // Open the watermark file in binary read mode
    FILE *watermark_file = fopen(watermark_file_name, "rb");
    if (watermark_file == NULL) {
        printf("Error: Watermark file could not be opened!\n");
        return;
    }

    // Create a new file to store the output image with watermark
    FILE *output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Error: Output file could not be created!\n");
        return;
    }

    // Read the image file header data
    unsigned char header_data[MAX_SIZE];
    fread(header_data, sizeof(unsigned char), MAX_SIZE, image_file);

    // Write the image file header data to the output file
    fwrite(header_data, sizeof(unsigned char), MAX_SIZE, output_file);

    // Read the watermark file data
    unsigned char watermark_data[MAX_SIZE];
    fread(watermark_data, sizeof(unsigned char), MAX_SIZE, watermark_file);

    // Embed the watermark data into the image data
    unsigned char image_data[MAX_SIZE];
    int watermark_length = strlen(watermark_data);
    int image_length = fread(image_data, sizeof(unsigned char), MAX_SIZE, image_file);
    for (int i = 0; i < watermark_length; i++) {
        // Modify the image data to embed the watermark data
        image_data[i] = ((image_data[i] & 0xFE) | ((watermark_data[i] & 0x01) >> 7));
    }

    // Write the modified image data to the output file
    fwrite(image_data, sizeof(unsigned char), image_length, output_file);

    // Close all the files
    fclose(image_file);
    fclose(watermark_file);
    fclose(output_file);

    printf("Successfully embedded watermark into the image!\n");
}

void extract_watermark(char image_file_name[], char watermark_file_name[]) {
    // Open the image file in binary read mode
    FILE *image_file = fopen(image_file_name, "rb");
    if (image_file == NULL) {
        printf("Error: Image file could not be opened!\n");
        return;
    }

    // Open the watermark file in binary write mode
    FILE *watermark_file = fopen(watermark_file_name, "wb");
    if (watermark_file == NULL) {
        printf("Error: Watermark file could not be opened!\n");
        return;
    }

    // Skip the image file header data
    fseek(image_file, MAX_SIZE, SEEK_SET);

    // Extract the watermark data from the image data
    unsigned char watermark_data[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        unsigned char image_byte;
        fread(&image_byte, sizeof(unsigned char), 1, image_file);
        // Extract the least significant bit from the image byte and store it in the watermark data
        watermark_data[i] = (image_byte & 0x01) << 7;
    }

    // Write the extracted watermark data to the watermark file
    fwrite(watermark_data, sizeof(unsigned char), MAX_SIZE, watermark_file);

    // Close all the files
    fclose(image_file);
    fclose(watermark_file);

    printf("Successfully extracted watermark from the image!\n");
}

int main() {
    char image_file_name[] = "my_image.bmp";
    char watermark_file_name[] = "my_watermark.txt";
    char output_file_name[] = "my_watermarked_image.bmp";

    embed_watermark(image_file_name, watermark_file_name, output_file_name);
    extract_watermark(output_file_name, watermark_file_name);

    return 0;
}