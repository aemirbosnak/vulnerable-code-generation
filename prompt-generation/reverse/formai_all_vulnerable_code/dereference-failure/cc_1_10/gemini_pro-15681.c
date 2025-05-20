//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define the steganography function
void steganography(char *image_file, char *message_file, char *output_file) {
    // Open the image file
    FILE *image = fopen(image_file, "rb");
    if (image == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Open the message file
    FILE *message = fopen(message_file, "rb");
    if (message == NULL) {
        perror("Error opening message file");
        exit(1);
    }

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Get the size of the message file
    fseek(message, 0L, SEEK_END);
    long message_size = ftell(message);
    rewind(message);

    // Check if the message is too large to fit in the image
    fseek(image, 0L, SEEK_END);
    long image_size = ftell(image);
    rewind(image);
    if (message_size > image_size) {
        fprintf(stderr, "Error: Message is too large to fit in image\n");
        exit(1);
    }

    // Read the image data into a buffer
    unsigned char *image_data = malloc(image_size);
    if (image_data == NULL) {
        perror("Error allocating memory for image data");
        exit(1);
    }
    fread(image_data, 1, image_size, image);

    // Read the message data into a buffer
    unsigned char *message_data = malloc(message_size);
    if (message_data == NULL) {
        perror("Error allocating memory for message data");
        exit(1);
    }
    fread(message_data, 1, message_size, message);

    // Embed the message data in the image data
    for (int i = 0; i < message_size; i++) {
        image_data[i] = image_data[i] & 0xF0 | message_data[i] & 0x0F;
    }

    // Write the steganographed image data to the output file
    fwrite(image_data, 1, image_size, output);

    // Free the allocated memory
    free(image_data);
    free(message_data);

    // Close the files
    fclose(image);
    fclose(message);
    fclose(output);
}

// Define the main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments were provided
    if (argc != 4) {
        fprintf(stderr, "Usage: %s image_file message_file output_file\n", argv[0]);
        exit(1);
    }

    // Call the steganography function
    steganography(argv[1], argv[2], argv[3]);

    return 0;
}