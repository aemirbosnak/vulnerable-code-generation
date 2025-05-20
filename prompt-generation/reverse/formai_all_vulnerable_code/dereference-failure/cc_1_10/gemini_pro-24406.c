//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_SIZE 1024
#define MAX_IMAGE_SIZE 1024 * 1024 * 3

// Elementary, my dear Watson!
int hide_message_in_image(char *image_file, char *message_file, char *output_file) {
    FILE *image_fp = fopen(image_file, "rb");
    if (image_fp == NULL) {
        fprintf(stderr, "Error: Could not open image file.\n");
        return -1;
    }

    FILE *message_fp = fopen(message_file, "rb");
    if (message_fp == NULL) {
        fprintf(stderr, "Error: Could not open message file.\n");
        return -1;
    }

    // Read the image data
    unsigned char *image_data = malloc(MAX_IMAGE_SIZE);
    if (image_data == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for image data.\n");
        return -1;
    }
    size_t image_size = fread(image_data, 1, MAX_IMAGE_SIZE, image_fp);
    fclose(image_fp);

    // Read the message data
    unsigned char *message_data = malloc(MAX_MESSAGE_SIZE);
    if (message_data == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for message data.\n");
        return -1;
    }
    size_t message_size = fread(message_data, 1, MAX_MESSAGE_SIZE, message_fp);
    fclose(message_fp);

    // Check if the message is too large to fit in the image
    if (message_size > image_size) {
        fprintf(stderr, "Error: Message is too large to fit in the image.\n");
        return -1;
    }

    // Hide the message in the image data
    for (size_t i = 0; i < message_size; i++) {
        image_data[i] = image_data[i] & 0xF8 | message_data[i] >> 3;
    }

    // Write the output image
    FILE *output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        fprintf(stderr, "Error: Could not open output file.\n");
        return -1;
    }
    fwrite(image_data, 1, image_size, output_fp);
    fclose(output_fp);

    free(image_data);
    free(message_data);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image_file> <message_file> <output_file>\n", argv[0]);
        return -1;
    }

    hide_message_in_image(argv[1], argv[2], argv[3]);

    return 0;
}