//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum size of the image
#define MAX_SIZE 1024

// Maximum size of the message
#define MAX_MESSAGE_SIZE 1024

// Function to embed the message into the image
void embed_message(char *image, char *message) {
    // Get the length of the message
    int message_length = strlen(message);

    // Check if the message is too long
    if (message_length > MAX_MESSAGE_SIZE) {
        printf("Error: Message too long.\n");
        return;
    }

    // Get the length of the image
    int image_length = strlen(image);

    // Check if the image is too small
    if (image_length < message_length) {
        printf("Error: Image too small.\n");
        return;
    }

    // Embed the message into the image
    for (int i = 0; i < message_length; i++) {
        // Get the binary representation of the message character
        char binary_message[8];
        for (int j = 0; j < 8; j++) {
            binary_message[j] = (message[i] >> j) & 1;
        }

        // Embed the binary message into the image
        for (int j = 0; j < 8; j++) {
            image[i * 8 + j] = (image[i * 8 + j] & 0xFE) | binary_message[j];
        }
    }

    // Print the modified image
    printf("%s\n", image);
}

// Function to extract the message from the image
void extract_message(char *image) {
    // Get the length of the image
    int image_length = strlen(image);

    // Extract the message from the image
    char message[MAX_MESSAGE_SIZE];
    for (int i = 0; i < image_length; i++) {
        // Get the binary representation of the image character
        char binary_image[8];
        for (int j = 0; j < 8; j++) {
            binary_image[j] = (image[i] >> j) & 1;
        }

        // Extract the message character from the binary image
        message[i] = 0;
        for (int j = 0; j < 8; j++) {
            message[i] |= binary_image[j] << j;
        }
    }

    // Print the extracted message
    printf("%s\n", message);
}

// Main function
int main(int argc, char **argv) {
    // Check if the user has provided the correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <image> <message>\n", argv[0]);
        return -1;
    }

    // Get the image and the message from the user
    char *image = argv[1];
    char *message = argv[2];

    // Embed the message into the image
    embed_message(image, message);

    // Extract the message from the image
    extract_message(image);

    return 0;
}