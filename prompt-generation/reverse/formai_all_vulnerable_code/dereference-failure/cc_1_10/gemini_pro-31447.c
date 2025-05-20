//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum size of the image
#define MAX_SIZE 1024

// Define the maximum size of the message
#define MAX_MESSAGE_SIZE 1024

// Define the number of bits per pixel
#define BITS_PER_PIXEL 8

// Define the number of channels per pixel
#define CHANNELS_PER_PIXEL 3

// Define the maximum number of bytes per pixel
#define BYTES_PER_PIXEL (BITS_PER_PIXEL * CHANNELS_PER_PIXEL / 8)

// Define the magic number that identifies the steganographic image
#define MAGIC_NUMBER 0x53455447

// Define the structure of the steganographic image
typedef struct {
    unsigned char magic_number[4];
    unsigned int width;
    unsigned int height;
    unsigned char data[MAX_SIZE * MAX_SIZE * BYTES_PER_PIXEL];
} steganographic_image_t;

// Define the function to encode a message into an image
int encode_message(steganographic_image_t *image, const char *message) {
    // Check if the message is too large
    if (strlen(message) > MAX_MESSAGE_SIZE) {
        return -1;
    }

    // Get the length of the message
    size_t message_length = strlen(message);

    // Convert the message to a bitstream
    unsigned char *bitstream = malloc(message_length * BITS_PER_PIXEL);
    for (size_t i = 0; i < message_length; i++) {
        for (int j = 0; j < BITS_PER_PIXEL; j++) {
            bitstream[i * BITS_PER_PIXEL + j] = (message[i] >> j) & 1;
        }
    }

    // Embed the bitstream into the image
    for (size_t i = 0; i < message_length * BITS_PER_PIXEL; i++) {
        // Get the index of the pixel
        size_t pixel_index = i / BITS_PER_PIXEL;

        // Get the index of the channel
        size_t channel_index = (i % BITS_PER_PIXEL) / 3;

        // Get the value of the pixel
        unsigned char pixel_value = image->data[pixel_index * BYTES_PER_PIXEL + channel_index];

        // Set the least significant bit of the pixel to the bit from the bitstream
        image->data[pixel_index * BYTES_PER_PIXEL + channel_index] = (pixel_value & ~1) | bitstream[i];
    }

    // Free the bitstream
    free(bitstream);

    // Return 0 to indicate success
    return 0;
}

// Define the function to decode a message from an image
int decode_message(steganographic_image_t *image, char *message) {
    // Check if the image is a steganographic image
    if (memcmp(image->magic_number, MAGIC_NUMBER, 4) != 0) {
        return -1;
    }

    // Get the length of the message
    size_t message_length = 0;
    for (size_t i = 0; i < image->width * image->height * BYTES_PER_PIXEL; i++) {
        if ((image->data[i] & 1) == 1) {
            message_length++;
        }
    }

    // Convert the bitstream to a message
    for (size_t i = 0; i < message_length; i++) {
        // Get the index of the pixel
        size_t pixel_index = i / BITS_PER_PIXEL;

        // Get the index of the channel
        size_t channel_index = (i % BITS_PER_PIXEL) / 3;

        // Get the value of the pixel
        unsigned char pixel_value = image->data[pixel_index * BYTES_PER_PIXEL + channel_index];

        // Get the least significant bit of the pixel
        message[i] = (pixel_value & 1) << (i % BITS_PER_PIXEL);
    }

    // Add a null terminator to the message
    message[message_length] = '\0';

    // Return 0 to indicate success
    return 0;
}

// Define the main function
int main(int argc, char **argv) {
    // Check if the user has provided the correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    // Open the input image file
    FILE *input_image_file = fopen(argv[1], "rb");
    if (input_image_file == NULL) {
        fprintf(stderr, "Error: could not open input image file '%s'\n", argv[1]);
        return 1;
    }

    // Open the output image file
    FILE *output_image_file = fopen(argv[2], "wb");
    if (output_image_file == NULL) {
        fprintf(stderr, "Error: could not open output image file '%s'\n", argv[2]);
        return 1;
    }

    // Read the input image file
    steganographic_image_t input_image;
    fread(&input_image, sizeof(steganographic_image_t), 1, input_image_file);

    // Check if the input image is a steganographic image
    if (memcmp(input_image.magic_number, MAGIC_NUMBER, 4) != 0) {
        fprintf(stderr, "Error: input image is not a steganographic image\n");
        return 1;
    }

    // Decode the message from the input image
    char message[MAX_MESSAGE_SIZE];
    int decode_result = decode_message(&input_image, message);
    if (decode_result != 0) {
        fprintf(stderr, "Error: could not decode message from input image\n");
        return 1;
    }

    // Encode the message into the output image
    int encode_result = encode_message(&input_image, message);
    if (encode_result != 0) {
        fprintf(stderr, "Error: could not encode message into output image\n");
        return 1;
    }

    // Write the output image file
    fwrite(&input_image, sizeof(steganographic_image_t), 1, output_image_file);

    // Close the input image file
    fclose(input_image_file);

    // Close the output image file
    fclose(output_image_file);

    // Return 0 to indicate success
    return 0;
}