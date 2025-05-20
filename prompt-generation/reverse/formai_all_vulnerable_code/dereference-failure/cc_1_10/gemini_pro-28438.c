//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Embed the secret message into the image
void embedMessage(char *image, char *message) {
    int i, j, k;
    char *ptr = image;
    int len = strlen(message);

    // Iterate over the image and the message, embedding each character of the message
    // into the least significant bit of each pixel
    for (i = 0; i < len; i++) {
        for (j = 0; j < 8; j++) {
            // Extract the least significant bit of the current pixel
            int bit = *ptr & 1;

            // Replace the least significant bit with the corresponding bit from the secret message
            if ((message[i] >> j) & 1) {
                *ptr |= 1;
            } else {
                *ptr &= ~1;
            }

            ptr++;
        }
    }
}

// Extract the secret message from the image
char *extractMessage(char *image, int len) {
    int i, j, k;
    char *ptr = image;
    char *message = malloc(len + 1);

    // Iterate over the image and extract each character of the message from the least
    // significant bit of each pixel
    for (i = 0; i < len; i++) {
        for (j = 0; j < 8; j++) {
            // Extract the least significant bit of the current pixel
            int bit = *ptr & 1;

            // Append the extracted bit to the secret message
            message[i] |= (bit << (7 - j));

            ptr++;
        }
    }

    message[len] = '\0';
    return message;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <input_image> <secret_message> <output_image>\n", argv[0]);
        return 1;
    }

    // Read the input image and secret message from files
    FILE *image_file = fopen(argv[1], "rb");
    if (image_file == NULL) {
        printf("Error opening input image file\n");
        return 1;
    }
    FILE *message_file = fopen(argv[2], "r");
    if (message_file == NULL) {
        printf("Error opening secret message file\n");
        return 1;
    }

    // Get the image size
    fseek(image_file, 0, SEEK_END);
    long image_size = ftell(image_file);
    rewind(image_file);

    // Get the secret message length
    fseek(message_file, 0, SEEK_END);
    long message_len = ftell(message_file);
    rewind(message_file);

    // Check if the image is large enough to hold the secret message
    if (image_size < message_len * 8) {
        printf("Error: Image is not large enough to hold the secret message\n");
        return 1;
    }

    // Load the input image into memory
    char *image = malloc(image_size);
    if (image == NULL) {
        printf("Error allocating memory for input image\n");
        return 1;
    }
    fread(image, 1, image_size, image_file);

    // Embed the secret message into the image
    embedMessage(image, argv[2]);

    // Save the modified image to a file
    FILE *output_file = fopen(argv[3], "wb");
    if (output_file == NULL) {
        printf("Error opening output image file\n");
        return 1;
    }
    fwrite(image, 1, image_size, output_file);

    // Extract the secret message from the image
    char *extracted_message = extractMessage(image, message_len);

    // Print the extracted message
    printf("Extracted message: %s\n", extracted_message);

    // Free allocated memory
    free(image);
    free(extracted_message);
    fclose(image_file);
    fclose(message_file);
    fclose(output_file);

    return 0;
}