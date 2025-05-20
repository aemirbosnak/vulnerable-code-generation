//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define constants for image size
#define WIDTH 256
#define HEIGHT 256

// Define constants for secret message
#define MESSAGE_LENGTH 32
#define MESSAGE_BYTES (MESSAGE_LENGTH * 8)

// Define the function for encoding the message
void encode(unsigned char *image, unsigned char *message) {
    // Loop through each pixel in the image
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Get the pixel value
            unsigned char pixel = image[y * WIDTH + x];

            // Encode the message bit by bit
            for (int i = 0; i < MESSAGE_BYTES; i++) {
                // Set the bit in the message to the corresponding bit in the pixel
                if (pixel & (1 << i))
                    message[i] = 1;
                else
                    message[i] = 0;
            }
        }
    }
}

// Define the function for decoding the message
void decode(unsigned char *image, unsigned char *message) {
    // Loop through each pixel in the image
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Get the pixel value
            unsigned char pixel = image[y * WIDTH + x];

            // Decode the message bit by bit
            for (int i = 0; i < MESSAGE_BYTES; i++) {
                // Set the bit in the message to the corresponding bit in the pixel
                if (message[i] == 1)
                    pixel |= (1 << i);
                else
                    pixel &= ~(1 << i);
            }
        }
    }
}

// Define the function for printing the image
void print_image(unsigned char *image, int width, int height) {
    // Loop through each row in the image
    for (int y = 0; y < height; y++) {
        // Loop through each column in the image
        for (int x = 0; x < width; x++) {
            // Print the pixel value
            printf("%02X ", image[y * width + x]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments are provided
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    // Open the image file
    FILE *image_file = fopen(argv[1], "rb");
    if (image_file == NULL) {
        fprintf(stderr, "Error opening image file\n");
        return 1;
    }

    // Read the image data into memory
    fseek(image_file, 0, SEEK_END);
    long image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);
    unsigned char *image = malloc(image_size);
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        return 1;
    }
    fread(image, 1, image_size, image_file);
    fclose(image_file);

    // Open the output file for the encoded image
    FILE *encoded_image_file = fopen("encoded.png", "wb");
    if (encoded_image_file == NULL) {
        fprintf(stderr, "Error opening output file\n");
        return 1;
    }

    // Encode the secret message in the image
    unsigned char *message = malloc(MESSAGE_BYTES);
    if (message == NULL) {
        fprintf(stderr, "Error allocating memory for message\n");
        return 1;
    }
    encode(image, message);

    // Write the encoded image data to the output file
    fwrite(image, 1, image_size, encoded_image_file);
    fclose(encoded_image_file);

    // Decode the secret message from the encoded image
    unsigned char *encoded_image = malloc(image_size);
    if (encoded_image == NULL) {
        fprintf(stderr, "Error allocating memory for encoded image\n");
        return 1;
    }
    fread(encoded_image, 1, image_size, encoded_image_file);
    fclose(encoded_image_file);
    decode(encoded_image, message);

    // Print the decoded message
    printf("Decoded message: ");
    for (int i = 0; i < MESSAGE_LENGTH; i++) {
        printf("%c", (char) message[i]);
    }
    printf("\n");

    // Free the memory used for the image and message
    free(image);
    free(message);

    return 0;
}