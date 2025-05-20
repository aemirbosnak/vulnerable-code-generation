//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define NUM_COLORS 3
#define BITS_PER_BYTE 8
#define LSB_MASK 0x01

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} pixel_t;

void encodeMessage(pixel_t *image, size_t image_size, const char *message) {
    // Calculate the number of bits in the message
    size_t message_size = strlen(message);
    size_t message_bits = message_size * BITS_PER_BYTE;

    // Calculate the number of bytes in the image
    size_t image_bytes = image_size / NUM_COLORS;

    // Check if the message can fit in the image
    if (message_bits > image_bytes) {
        printf("Error: Message is too large for image\n");
        return;
    }

    // Create a bitmask for the least significant bit
    uint8_t bitmask = LSB_MASK;

    // Iterate over the message and encode each bit into the image
    size_t message_index = 0;
    size_t image_index = 0;
    while (message_index < message_bits) {
        // Get the current bit from the message
        uint8_t bit = (message[message_index / BITS_PER_BYTE] >> (message_index % BITS_PER_BYTE)) & bitmask;

        // Set the least significant bit of the current image pixel to the message bit
        if (bit) {
            image[image_index].r |= bitmask;
            image[image_index].g |= bitmask;
            image[image_index].b |= bitmask;
        } else {
            image[image_index].r &= ~bitmask;
            image[image_index].g &= ~bitmask;
            image[image_index].b &= ~bitmask;
        }

        // Increment the message and image indices
        message_index++;
        image_index++;
    }
}

char *decodeMessage(const pixel_t *image, size_t image_size) {
    // Calculate the number of bytes in the image
    size_t image_bytes = image_size / NUM_COLORS;

    // Calculate the number of bits in the message
    size_t message_bits = image_bytes * BITS_PER_BYTE;

    // Create a string to store the decoded message
    char *message = malloc(message_bits / BITS_PER_BYTE + 1);

    // Create a bitmask for the least significant bit
    uint8_t bitmask = LSB_MASK;

    // Iterate over the image and decode the message
    size_t message_index = 0;
    size_t image_index = 0;
    while (image_index < image_bytes) {
        // Get the least significant bit of the current image pixel
        uint8_t bit = image[image_index].r & bitmask;

        // Set the current bit in the decoded message
        message[message_index / BITS_PER_BYTE] |= (bit << (message_index % BITS_PER_BYTE));

        // Increment the message and image indices
        message_index++;
        image_index++;
    }

    // Terminate the decoded message with a null character
    message[message_bits / BITS_PER_BYTE] = '\0';

    return message;
}

int main() {
    // Load an image from a file
    FILE *image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        printf("Error: Could not open image file\n");
        return EXIT_FAILURE;
    }

    // Read the image header
    uint16_t header[14];
    fread(header, sizeof(uint16_t), 14, image_file);

    // Calculate the width and height of the image
    uint32_t width = header[4];
    uint32_t height = header[5];

    // Calculate the size of the image in bytes
    size_t image_size = width * height * NUM_COLORS;

    // Allocate memory for the image data
    pixel_t *image = malloc(image_size);

    // Read the image data
    fread(image, 1, image_size, image_file);

    // Close the image file
    fclose(image_file);

    // Encode a message into the image
    const char *message = "Hello, world!";
    encodeMessage(image, image_size, message);

    // Save the encoded image to a file
    image_file = fopen("encoded_image.bmp", "wb");
    if (image_file == NULL) {
        printf("Error: Could not open encoded image file\n");
        return EXIT_FAILURE;
    }

    // Write the image header to the file
    fwrite(header, sizeof(uint16_t), 14, image_file);

    // Write the image data to the file
    fwrite(image, 1, image_size, image_file);

    // Close the encoded image file
    fclose(image_file);

    // Decode the message from the encoded image
    char *decoded_message = decodeMessage(image, image_size);

    // Print the decoded message
    printf("Decoded message: %s\n", decoded_message);

    // Free the memory allocated for the decoded message
    free(decoded_message);

    // Free the memory allocated for the image
    free(image);

    return EXIT_SUCCESS;
}