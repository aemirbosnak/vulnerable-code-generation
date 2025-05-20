//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define the maximum size of the image
#define MAX_IMAGE_SIZE 1000000

// Define the message size
#define MESSAGE_SIZE 100

// Define the number of bits per pixel
#define BITS_PER_PIXEL 8

// Define the bitmask for extracting the LSB
#define LSB_BITMASK 0x01

// Define the bitmask for setting the LSB
#define LSB_SET_BITMASK 0x02

// Function to embed the message into the image
void embed_message(uint8_t *image, uint8_t *message, int image_size, int message_size) {
    // Iterate over the message
    for (int i = 0; i < message_size; i++) {
        // Extract the LSB of the message byte
        uint8_t message_bit = message[i] & LSB_BITMASK;

        // Iterate over the image
        for (int j = 0; j < image_size; j++) {
            // Extract the LSB of the image byte
            uint8_t image_bit = image[j] & LSB_BITMASK;

            // If the message bit is 1, set the LSB of the image byte to 1
            if (message_bit) {
                image[j] |= LSB_SET_BITMASK;
            }

            // Shift the message bit to the right
            message_bit >>= 1;

            // If the message bit is 0, clear the LSB of the image byte
            if (!message_bit) {
                image[j] &= ~LSB_SET_BITMASK;
            }
        }
    }
}

// Function to extract the message from the image
uint8_t *extract_message(uint8_t *image, int image_size, int message_size) {
    // Allocate memory for the message
    uint8_t *message = malloc(message_size);

    // Iterate over the message
    for (int i = 0; i < message_size; i++) {
        // Initialize the message byte to 0
        message[i] = 0;

        // Iterate over the image
        for (int j = 0; j < image_size; j++) {
            // Extract the LSB of the image byte
            uint8_t image_bit = image[j] & LSB_BITMASK;

            // Shift the message byte to the left
            message[i] <<= 1;

            // Set the LSB of the message byte to the image bit
            message[i] |= image_bit;
        }
    }

    // Return the message
    return message;
}

// Main function
int main() {
    // Read the image from a file
    FILE *image_file = fopen("image.png", "rb");
    if (image_file == NULL) {
        perror("Error opening image file");
        return -1;
    }

    // Get the size of the image
    fseek(image_file, 0, SEEK_END);
    int image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    // Read the image into a buffer
    uint8_t *image = malloc(image_size);
    fread(image, 1, image_size, image_file);
    fclose(image_file);

    // Read the message from a file
    FILE *message_file = fopen("message.txt", "rb");
    if (message_file == NULL) {
        perror("Error opening message file");
        return -1;
    }

    // Get the size of the message
    fseek(message_file, 0, SEEK_END);
    int message_size = ftell(message_file);
    fseek(message_file, 0, SEEK_SET);

    // Read the message into a buffer
    uint8_t *message = malloc(message_size);
    fread(message, 1, message_size, message_file);
    fclose(message_file);

    // Embed the message into the image
    embed_message(image, message, image_size, message_size);

    // Write the image to a file
    FILE *output_image_file = fopen("output_image.png", "wb");
    if (output_image_file == NULL) {
        perror("Error opening output image file");
        return -1;
    }

    fwrite(image, 1, image_size, output_image_file);
    fclose(output_image_file);

    // Extract the message from the image
    uint8_t *extracted_message = extract_message(image, image_size, message_size);

    // Write the extracted message to a file
    FILE *extracted_message_file = fopen("extracted_message.txt", "wb");
    if (extracted_message_file == NULL) {
        perror("Error opening extracted message file");
        return -1;
    }

    fwrite(extracted_message, 1, message_size, extracted_message_file);
    fclose(extracted_message_file);

    // Free the allocated memory
    free(image);
    free(message);
    free(extracted_message);

    return 0;
}