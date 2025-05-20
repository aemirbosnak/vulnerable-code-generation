//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t byte;

// Embed a message into an image
void embed(char *image_path, char *message) {
    // Open the image file
    FILE *image = fopen(image_path, "rb+");
    if (image == NULL) {
        fprintf(stderr, "Error opening image file\n");
        exit(1);
    }

    // Get the size of the image file
    fseek(image, 0, SEEK_END);
    long image_size = ftell(image);
    rewind(image);

    // Read the image data into a buffer
    byte *image_data = malloc(image_size);
    fread(image_data, 1, image_size, image);

    // Get the length of the message
    size_t message_length = strlen(message);

    // Check if the message is too long to fit in the image
    if (message_length > (image_size - 1) / 8) {
        fprintf(stderr, "Error: message is too long to fit in the image\n");
        exit(1);
    }

    // Embed the message into the image data
    for (size_t i = 0; i < message_length; i++) {
        // Get the binary representation of the character
        byte character = message[i];
        for (int j = 0; j < 8; j++) {
            // Set the least significant bit of the pixel to the corresponding bit of the character
            image_data[i * 8 + j] &= ~(1 << j);
            image_data[i * 8 + j] |= (character >> j) & 1;
        }
    }

    // Write the modified image data back to the file
    fseek(image, 0, SEEK_SET);
    fwrite(image_data, 1, image_size, image);

    // Close the image file
    fclose(image);

    // Free the image data buffer
    free(image_data);
}

// Extract a message from an image
char *extract(char *image_path) {
    // Open the image file
    FILE *image = fopen(image_path, "rb");
    if (image == NULL) {
        fprintf(stderr, "Error opening image file\n");
        exit(1);
    }

    // Get the size of the image file
    fseek(image, 0, SEEK_END);
    long image_size = ftell(image);
    rewind(image);

    // Read the image data into a buffer
    byte *image_data = malloc(image_size);
    fread(image_data, 1, image_size, image);

    // Get the length of the message
    size_t message_length = (image_size - 1) / 8;

    // Extract the message from the image data
    char *message = malloc(message_length + 1);
    for (size_t i = 0; i < message_length; i++) {
        // Get the least significant bit of each pixel and concatenate them to form the message
        byte character = 0;
        for (int j = 0; j < 8; j++) {
            character |= (image_data[i * 8 + j] & 1) << j;
        }
        message[i] = character;
    }
    message[message_length] = '\0';

    // Close the image file
    fclose(image);

    // Free the image data buffer
    free(image_data);

    // Return the message
    return message;
}

int main() {
    // Embed a message into an image
    embed("image.bmp", "Hello, world!");

    // Extract the message from the image
    char *message = extract("image.bmp");

    // Print the message
    printf("The message is: %s\n", message);

    // Free the message
    free(message);

    return 0;
}