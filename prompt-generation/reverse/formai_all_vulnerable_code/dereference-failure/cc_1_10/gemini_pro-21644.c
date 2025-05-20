//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;
typedef unsigned int uint32;

// Read a 32-bit little-endian integer from a file
uint32 read_uint32(FILE *fp) {
    byte buf[4];
    fread(buf, 1, 4, fp);
    return buf[0] | (buf[1] << 8) | (buf[2] << 16) | (buf[3] << 24);
}

// Write a 32-bit little-endian integer to a file
void write_uint32(FILE *fp, uint32 value) {
    byte buf[4];
    buf[0] = value & 0xff;
    buf[1] = (value >> 8) & 0xff;
    buf[2] = (value >> 16) & 0xff;
    buf[3] = (value >> 24) & 0xff;
    fwrite(buf, 1, 4, fp);
}

// Encode a message into an image
void encode_image(char *image_file, char *message_file, char *output_file) {
    FILE *image_fp = fopen(image_file, "rb");
    if (image_fp == NULL) {
        perror("Could not open image file");
        exit(1);
    }

    FILE *message_fp = fopen(message_file, "rb");
    if (message_fp == NULL) {
        perror("Could not open message file");
        exit(1);
    }

    FILE *output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        perror("Could not open output file");
        exit(1);
    }

    // Read the header of the image
    uint32 width = read_uint32(image_fp);
    uint32 height = read_uint32(image_fp);

    // Check if the image is large enough to hold the message
    uint32 message_size = ftell(message_fp);
    if (message_size > width * height * 3) {
        fprintf(stderr, "Error: Message is too large for image\n");
        exit(1);
    }

    // Copy the header of the image to the output file
    fwrite(&width, 1, 4, output_fp);
    fwrite(&height, 1, 4, output_fp);

    // Read the message into a buffer
    char *message = malloc(message_size);
    fread(message, 1, message_size, message_fp);

    // Encode the message into the image
    uint32 message_index = 0;
    for (uint32 i = 0; i < width * height; i++) {
        // Read the next pixel from the image
        byte pixel[3];
        fread(pixel, 1, 3, image_fp);

        // Encode the next character of the message into the pixel
        pixel[message_index % 3] &= 0xfe;
        pixel[message_index % 3] |= message[message_index / 3] & 0x01;
        message_index++;

        // Write the modified pixel to the output file
        fwrite(pixel, 1, 3, output_fp);
    }

    // Close the files
    fclose(image_fp);
    fclose(message_fp);
    fclose(output_fp);
    free(message);
}

// Decode a message from an image
void decode_image(char *image_file, char *output_file) {
    FILE *image_fp = fopen(image_file, "rb");
    if (image_fp == NULL) {
        perror("Could not open image file");
        exit(1);
    }

    FILE *output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        perror("Could not open output file");
        exit(1);
    }

    // Read the header of the image
    uint32 width = read_uint32(image_fp);
    uint32 height = read_uint32(image_fp);

    // Decode the message from the image
    uint32 message_index = 0;
    for (uint32 i = 0; i < width * height; i++) {
        // Read the next pixel from the image
        byte pixel[3];
        fread(pixel, 1, 3, image_fp);

        // Decode the next character of the message from the pixel
        if (message_index % 3 == 0) {
            fwrite(&pixel[message_index % 3], 1, 1, output_fp);
        }
        message_index++;
    }

    // Close the files
    fclose(image_fp);
    fclose(output_fp);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <image file> <message file> <output file> <encode/decode>\n", argv[0]);
        exit(1);
    }

    char *image_file = argv[1];
    char *message_file = argv[2];
    char *output_file = argv[3];
    char *mode = argv[4];

    if (!strcmp(mode, "encode")) {
        encode_image(image_file, message_file, output_file);
    } else if (!strcmp(mode, "decode")) {
        decode_image(image_file, output_file);
    } else {
        fprintf(stderr, "Error: Invalid mode\n");
        exit(1);
    }

    return 0;
}