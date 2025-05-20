//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Function to extract the least significant bit of a byte
uint8_t extract_lsb(uint8_t byte) {
    return byte & 0x01;
}

// Function to embed the least significant bit of a message byte into an image byte
uint8_t embed_lsb(uint8_t image_byte, uint8_t message_bit) {
    return (image_byte & 0xFE) | message_bit;
}

// Function to encode a message into an image
int encode_image(const char *image_file, const char *message_file, const char *output_file) {
    // Open the image file for reading
    FILE *image_fp = fopen(image_file, "rb");
    if (image_fp == NULL) {
        fprintf(stderr, "Error: Could not open image file %s\n", image_file);
        return -1;
    }

    // Open the message file for reading
    FILE *message_fp = fopen(message_file, "rb");
    if (message_fp == NULL) {
        fprintf(stderr, "Error: Could not open message file %s\n", message_file);
        return -1;
    }

    // Open the output file for writing
    FILE *output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        fprintf(stderr, "Error: Could not open output file %s\n", output_file);
        return -1;
    }

    // Read the image header
    uint8_t header[54];
    fread(header, sizeof(header), 1, image_fp);

    // Write the image header to the output file
    fwrite(header, sizeof(header), 1, output_fp);

    // Read the image data
    uint8_t *image_data = malloc(header[18] * header[22] * 3);
    fread(image_data, header[18] * header[22] * 3, 1, image_fp);

    // Read the message data
    uint8_t *message_data = malloc(strlen(message_file));
    fread(message_data, strlen(message_file), 1, message_fp);

    // Encode the message data into the image data
    int message_index = 0;
    for (int i = 0; i < header[18] * header[22] * 3; i++) {
        if (message_index < strlen(message_data)) {
            image_data[i] = embed_lsb(image_data[i], extract_lsb(message_data[message_index]));
            message_index++;
        }
    }

    // Write the encoded image data to the output file
    fwrite(image_data, header[18] * header[22] * 3, 1, output_fp);

    // Free the allocated memory
    free(image_data);
    free(message_data);

    // Close the files
    fclose(image_fp);
    fclose(message_fp);
    fclose(output_fp);

    return 0;
}

// Function to decode a message from an image
int decode_image(const char *image_file, const char *output_file) {
    // Open the image file for reading
    FILE *image_fp = fopen(image_file, "rb");
    if (image_fp == NULL) {
        fprintf(stderr, "Error: Could not open image file %s\n", image_file);
        return -1;
    }

    // Open the output file for writing
    FILE *output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        fprintf(stderr, "Error: Could not open output file %s\n", output_file);
        return -1;
    }

    // Read the image header
    uint8_t header[54];
    fread(header, sizeof(header), 1, image_fp);

    // Read the image data
    uint8_t *image_data = malloc(header[18] * header[22] * 3);
    fread(image_data, header[18] * header[22] * 3, 1, image_fp);

    // Decode the message data from the image data
    char *message_data = malloc(strlen(image_file));
    int message_index = 0;
    for (int i = 0; i < header[18] * header[22] * 3; i++) {
        message_data[message_index] |= extract_lsb(image_data[i]) << message_index;
        message_index++;
    }

    // Write the decoded message data to the output file
    fwrite(message_data, strlen(image_file), 1, output_fp);

    // Free the allocated memory
    free(image_data);
    free(message_data);

    // Close the files
    fclose(image_fp);
    fclose(output_fp);

    return 0;
}

int main() {
    // Encode a message into an image
    int encode_status = encode_image("image.bmp", "message.txt", "output.bmp");
    if (encode_status != 0) {
        fprintf(stderr, "Error: Could not encode message into image\n");
        return -1;
    }

    // Decode the message from the image
    int decode_status = decode_image("output.bmp", "decoded_message.txt");
    if (decode_status != 0) {
        fprintf(stderr, "Error: Could not decode message from image\n");
        return -1;
    }

    return 0;
}