//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the secret message
#define MAX_MESSAGE_SIZE 1024

// Define the maximum size of the image
#define MAX_IMAGE_SIZE 1024 * 1024

// Define the number of bits per pixel
#define BITS_PER_PIXEL 8

// Define the bitmask for the least significant bit
#define LSB_MASK 0x01

// Embed the secret message in the image
void embed_message(char *image, int image_size, char *message, int message_size) {
    // Check if the message is too large for the image
    if (message_size > image_size * BITS_PER_PIXEL) {
        printf("Error: The message is too large for the image.\n");
        return;
    }

    // Convert the message to binary
    char *binary_message = malloc(message_size * 8);
    for (int i = 0; i < message_size; i++) {
        for (int j = 0; j < 8; j++) {
            binary_message[i * 8 + j] = (message[i] >> j) & LSB_MASK;
        }
    }

    // Embed the binary message in the image
    for (int i = 0; i < message_size * 8; i++) {
        image[i / 8] = (image[i / 8] & ~LSB_MASK) | binary_message[i];
    }

    // Free the memory allocated for the binary message
    free(binary_message);
}

// Extract the secret message from the image
char *extract_message(char *image, int image_size) {
    // Allocate memory for the secret message
    char *message = malloc(MAX_MESSAGE_SIZE);

    // Extract the binary message from the image
    char *binary_message = malloc(image_size * BITS_PER_PIXEL);
    for (int i = 0; i < image_size * BITS_PER_PIXEL; i++) {
        binary_message[i] = image[i / 8] & LSB_MASK;
    }

    // Convert the binary message to text
    for (int i = 0; i < image_size * BITS_PER_PIXEL / 8; i++) {
        message[i] = 0;
        for (int j = 0; j < 8; j++) {
            message[i] |= binary_message[i * 8 + j] << j;
        }
    }

    // Free the memory allocated for the binary message
    free(binary_message);

    // Return the secret message
    return message;
}

// Main function
int main() {
    // Open the image file
    FILE *image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        printf("Error: Could not open the image file.\n");
        return 1;
    }

    // Get the size of the image
    fseek(image_file, 0, SEEK_END);
    int image_size = ftell(image_file);
    rewind(image_file);

    // Read the image into memory
    char *image = malloc(image_size);
    fread(image, 1, image_size, image_file);

    // Close the image file
    fclose(image_file);

    // Get the secret message
    char *message = "Hello, world!";
    int message_size = strlen(message);

    // Embed the secret message in the image
    embed_message(image, image_size, message, message_size);

    // Open the steganography image file
    FILE *steganography_image_file = fopen("steganography_image.bmp", "wb");
    if (steganography_image_file == NULL) {
        printf("Error: Could not open the steganography image file.\n");
        return 1;
    }

    // Write the image to the steganography image file
    fwrite(image, 1, image_size, steganography_image_file);

    // Close the steganography image file
    fclose(steganography_image_file);

    // Free the memory allocated for the image
    free(image);

    // Extract the secret message from the steganography image
    char *extracted_message = extract_message(image, image_size);

    // Print the secret message
    printf("The secret message is: %s\n", extracted_message);

    // Free the memory allocated for the secret message
    free(extracted_message);

    return 0;
}