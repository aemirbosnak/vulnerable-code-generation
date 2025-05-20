//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// The bit size of the watermark.
#define BIT_SIZE 8

// The maximum size of the message.
#define MAX_MSG_SIZE 1000

// The maximum size of the watermark.
#define MAX_WATERMARK_SIZE 100

// The maximum size of the image.
#define MAX_IMAGE_SIZE 1000000

// Function to read an image file.
int read_image(char *filename, unsigned char *image_data) {
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error: Could not open image file.\n");
        return 1;
    }
    // Read the image bytes into memory.
    fread(image_data, sizeof(unsigned char), MAX_IMAGE_SIZE, fp);
    fclose(fp);
    return 0;
}

// Function to write an image file.
int write_image(char *filename, unsigned char *image_data, int image_size) {
    FILE *fp = fopen(filename, "wb");
    if(fp == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }
    // Write the image bytes to the output file.
    fwrite(image_data, sizeof(unsigned char), image_size, fp);
    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
    // Read the image data into memory.
    unsigned char image_data[MAX_IMAGE_SIZE];
    int image_size = read_image("input_image.raw", image_data);
    // Initialize the message and watermark buffers.
    unsigned char message[MAX_MSG_SIZE];
    unsigned char watermark[MAX_WATERMARK_SIZE];
    // Read the message and watermark files into memory.
    FILE *message_file = fopen("message.txt", "r");
    fread(message, sizeof(char), MAX_MSG_SIZE, message_file);
    fclose(message_file);
    FILE *watermark_file = fopen("watermark.txt", "r");
    fread(watermark, sizeof(char), MAX_WATERMARK_SIZE, watermark_file);
    fclose(watermark_file);
    // Calculate the bit size of the message and watermark.
    int message_bit_size = strlen(message) * BIT_SIZE;
    int watermark_bit_size = strlen(watermark) * BIT_SIZE;
    // Compute the LSBs for the message and watermark.
    unsigned char *message_lsb = (unsigned char*) calloc(message_bit_size, sizeof(unsigned char));
    unsigned char *watermark_lsb = (unsigned char*) calloc(watermark_bit_size, sizeof(unsigned char));
    for(int i = 0; i < message_bit_size; i++) {
        message_lsb[i] = (message[i / BIT_SIZE] & (1 << (i % BIT_SIZE))) ? 1 : 0;
    }
    for(int i = 0; i < watermark_bit_size; i++) {
        watermark_lsb[i] = (watermark[i / BIT_SIZE] & (1 << (i % BIT_SIZE))) ? 1 : 0;
    }
    // Embed the watermark bits into the LSBs of the image data.
    int embed_count = 0;
    for(int i = 0; i < image_size; i++) {
        if(embed_count < watermark_bit_size) {
            image_data[i] = (image_data[i] & 0xFE) | watermark_lsb[embed_count++];
        } else {
            break;
        }
    }
    // Embed the message bits into the LSBs of the image data.
    embed_count = 0;
    for(int i = 0; i < image_size; i++) {
        if(embed_count < message_bit_size) {
            image_data[i] = (image_data[i] & 0xFE) | message_lsb[embed_count++];
        } else {
            break;
        }
    }
    // Write the output image file.
    write_image("output_image.raw", image_data, image_size);
    printf("Embedding complete. Output file written to 'output_image.raw'.\n");
    return 0;
}