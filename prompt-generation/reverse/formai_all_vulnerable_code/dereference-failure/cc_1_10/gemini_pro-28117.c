//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1024
#define MAX_IMAGE_SIZE 1024 * 1024

// LSB (Least Significant Bit) steganography function
void hide_message(unsigned char *image, int image_size, unsigned char *message, int message_length) {
    int i, j, k;
    for (i = 0, k = 0; i < image_size && k < message_length; i++) {
        if (image[i] & 1) {
            image[i] &= ~1;
            image[i] |= (message[k] & 1);
            k++;
        }
    }
}

// Extract message from LSB
unsigned char *extract_message(unsigned char *image, int image_size) {
    int i, k;
    unsigned char *message = malloc(MAX_MESSAGE_LENGTH);
    for (i = 0, k = 0; i < image_size; i++) {
        if (image[i] & 1) {
            message[k] |= 1;
            k++;
        }
        message[k] <<= 1;
    }
    message[k] = '\0';
    return message;
}

int main() {
    unsigned char image[MAX_IMAGE_SIZE];
    int image_size;
    FILE *image_file;

    // Read image from file
    image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        fprintf(stderr, "Error opening image file\n");
        return EXIT_FAILURE;
    }
    image_size = fread(image, 1, MAX_IMAGE_SIZE, image_file);
    fclose(image_file);

    // Get the message to hide
    unsigned char message[MAX_MESSAGE_LENGTH];
    printf("Enter the message to hide (max %d characters): ", MAX_MESSAGE_LENGTH - 1);
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Hide the message in the image
    hide_message(image, image_size, message, strlen(message));

    // Save the steganographed image to file
    image_file = fopen("stego_image.bmp", "wb");
    if (image_file == NULL) {
        fprintf(stderr, "Error opening stego image file\n");
        return EXIT_FAILURE;
    }
    fwrite(image, 1, image_size, image_file);
    fclose(image_file);

    // Extract and display the message from the stego image
    unsigned char *extracted_message;
    image_file = fopen("stego_image.bmp", "rb");
    if (image_file == NULL) {
        fprintf(stderr, "Error opening stego image file\n");
        return EXIT_FAILURE;
    }
    extracted_message = extract_message(image, image_size);
    printf("Extracted message: %s\n", extracted_message);
    free(extracted_message);
    fclose(image_file);

    return EXIT_SUCCESS;
}