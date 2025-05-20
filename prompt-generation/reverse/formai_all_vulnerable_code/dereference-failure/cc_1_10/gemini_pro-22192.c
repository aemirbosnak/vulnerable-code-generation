//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

// This program hides a secret message inside an image.
// The secret message is stored in the least significant bits of the image's pixels.
// The program can also extract the secret message from the image.

// The maximum length of the secret message is 255 characters.
#define MAX_MESSAGE_LENGTH 255

// The number of bits per pixel in the image.
#define BITS_PER_PIXEL 24

// The number of bits to use for the secret message.
#define MESSAGE_BITS_PER_PIXEL 1

// The mask to use to extract the secret message from the image.
#define MESSAGE_MASK 0x01

// The function to hide the secret message in the image.
void hide_message(const char *image_file, const char *secret_message) {
    // Open the image file.
    FILE *image = fopen(image_file, "rb+");
    if (image == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Get the size of the image.
    fseek(image, 0, SEEK_END);
    long image_size = ftell(image);
    rewind(image);

    // Check if the secret message is too long.
    if (strlen(secret_message) > MAX_MESSAGE_LENGTH) {
        fprintf(stderr, "Error: secret message is too long\n");
        exit(1);
    }

    // Get the number of pixels in the image.
    int width, height;
    fread(&width, sizeof(int), 1, image);
    fread(&height, sizeof(int), 1, image);

    // Check if the image is large enough to hold the secret message.
    if (width * height * BITS_PER_PIXEL < strlen(secret_message) * MESSAGE_BITS_PER_PIXEL) {
        fprintf(stderr, "Error: image is too small to hold secret message\n");
        exit(1);
    }

    // Hide the secret message in the image.
    int message_index = 0;
    for (int i = 0; i < image_size; i++) {
        // Read a byte from the image.
        uint8_t byte;
        fread(&byte, sizeof(uint8_t), 1, image);

        // Extract the least significant bit from the byte.
        uint8_t lsb = byte & MESSAGE_MASK;

        // If the message index is less than the length of the secret message,
        // set the least significant bit to the next bit of the secret message.
        if (message_index < strlen(secret_message)) {
            byte &= ~MESSAGE_MASK;
            byte |= (secret_message[message_index] >> (7 - MESSAGE_BITS_PER_PIXEL)) & MESSAGE_MASK;
            message_index++;
        }

        // Write the byte back to the image.
        fseek(image, i, SEEK_SET);
        fwrite(&byte, sizeof(uint8_t), 1, image);
    }

    // Close the image file.
    fclose(image);
}

// The function to extract the secret message from the image.
char *extract_message(const char *image_file) {
    // Open the image file.
    FILE *image = fopen(image_file, "rb");
    if (image == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Get the size of the image.
    fseek(image, 0, SEEK_END);
    long image_size = ftell(image);
    rewind(image);

    // Get the number of pixels in the image.
    int width, height;
    fread(&width, sizeof(int), 1, image);
    fread(&height, sizeof(int), 1, image);

    // Allocate memory for the secret message.
    char *secret_message = malloc(MAX_MESSAGE_LENGTH + 1);
    if (secret_message == NULL) {
        perror("Error allocating memory for secret message");
        exit(1);
    }

    // Extract the secret message from the image.
    int message_index = 0;
    for (int i = 0; i < image_size; i++) {
        // Read a byte from the image.
        uint8_t byte;
        fread(&byte, sizeof(uint8_t), 1, image);

        // Extract the least significant bit from the byte.
        uint8_t lsb = byte & MESSAGE_MASK;

        // Append the least significant bit to the secret message.
        secret_message[message_index] |= lsb << (7 - message_index % MESSAGE_BITS_PER_PIXEL);
        message_index++;

        // If the message index is a multiple of the message bits per pixel,
        // increment the secret message index and reset the secret message byte.
        if (message_index % MESSAGE_BITS_PER_PIXEL == 0) {
            message_index = 0;
            secret_message[message_index] = 0;
        }
    }

    // Close the image file.
    fclose(image);

    // Return the secret message.
    return secret_message;
}

// The main function.
int main(int argc, char **argv) {
    // Check if the user specified the image file and the secret message.
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <image_file> <secret_message>\n", argv[0]);
        exit(1);
    }

    // Get the image file and the secret message from the command line.
    const char *image_file = argv[1];
    const char *secret_message = argv[2];

    // Hide the secret message in the image.
    hide_message(image_file, secret_message);

    // Extract the secret message from the image.
    char *extracted_message = extract_message(image_file);

    // Print the extracted message.
    printf("Extracted message: %s\n", extracted_message);

    // Free the memory allocated for the extracted message.
    free(extracted_message);

    return 0;
}