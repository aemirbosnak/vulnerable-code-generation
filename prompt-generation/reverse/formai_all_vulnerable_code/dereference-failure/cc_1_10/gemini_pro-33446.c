//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hide a message inside an image using LSB steganography
void hide_message(char *image_file, char *message) {
    // Open the image file
    FILE *image = fopen(image_file, "rb+");
    if (image == NULL) {
        fprintf(stderr, "Error opening image file: %s\n", image_file);
        return;
    }

    // Get the image's dimensions
    int width, height;
    fseek(image, 18, SEEK_SET);
    fread(&width, 4, 1, image);
    fread(&height, 4, 1, image);

    // Calculate the number of pixels in the image
    int num_pixels = width * height;

    // Get the message's length
    int message_length = strlen(message);

    // Check if the message is too long to fit in the image
    if (message_length * 8 > num_pixels * 3) {
        fprintf(stderr, "Error: Message is too long to fit in image.\n");
        fclose(image);
        return;
    }

    // Convert the message to binary
    char binary_message[message_length * 8];
    for (int i = 0; i < message_length; i++) {
        for (int j = 0; j < 8; j++) {
            binary_message[i * 8 + j] = (message[i] >> j) & 1;
        }
    }

    // Hide the message in the image's LSBs
    fseek(image, 54, SEEK_SET);
    for (int i = 0; i < message_length * 8; i++) {
        unsigned char pixel;
        fread(&pixel, 1, 1, image);
        pixel &= 0xFE;
        pixel |= binary_message[i];
        fseek(image, -1, SEEK_CUR);
        fwrite(&pixel, 1, 1, image);
    }

    // Close the image file
    fclose(image);

    printf("Message hidden in image successfully.\n");
}

// Extract a message from an image using LSB steganography
void extract_message(char *image_file) {
    // Open the image file
    FILE *image = fopen(image_file, "rb");
    if (image == NULL) {
        fprintf(stderr, "Error opening image file: %s\n", image_file);
        return;
    }

    // Get the image's dimensions
    int width, height;
    fseek(image, 18, SEEK_SET);
    fread(&width, 4, 1, image);
    fread(&height, 4, 1, image);

    // Calculate the number of pixels in the image
    int num_pixels = width * height;

    // Extract the message from the image's LSBs
    char message[num_pixels / 8 + 1];
    fseek(image, 54, SEEK_SET);
    for (int i = 0; i < num_pixels / 8; i++) {
        unsigned char pixel;
        fread(&pixel, 1, 1, image);
        message[i] = pixel & 1;
    }
    message[num_pixels / 8] = '\0';

    // Print the message
    printf("Extracted message: %s\n", message);

    // Close the image file
    fclose(image);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image_file> <hide/extract> <message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[2], "hide") == 0) {
        hide_message(argv[1], argv[3]);
    } else if (strcmp(argv[2], "extract") == 0) {
        extract_message(argv[1]);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[2]);
        return 1;
    }

    return 0;
}