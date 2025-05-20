//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Structure to represent an image
typedef struct {
    uint32_t width;
    uint32_t height;
    uint8_t *data;
} Image;

// Function to load an image from a file
Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the image header
    Image *image = malloc(sizeof(Image));
    fread(&image->width, sizeof(uint32_t), 1, fp);
    fread(&image->height, sizeof(uint32_t), 1, fp);

    // Allocate memory for the image data
    image->data = malloc(image->width * image->height * 3);
    fread(image->data, image->width * image->height * 3, 1, fp);

    fclose(fp);

    return image;
}

// Function to save an image to a file
void save_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Write the image header
    fwrite(&image->width, sizeof(uint32_t), 1, fp);
    fwrite(&image->height, sizeof(uint32_t), 1, fp);

    // Write the image data
    fwrite(image->data, image->width * image->height * 3, 1, fp);

    fclose(fp);
}

// Function to encode a message in an image
void encode_message(Image *image, const char *message) {
    int message_length = strlen(message);
    int bit_index = 0;

    // Iterate over the image data
    for (int i = 0; i < image->width * image->height * 3; i++) {
        // If we have reached the end of the message, break
        if (bit_index >= message_length * 8) {
            break;
        }

        // Get the current byte
        uint8_t byte = image->data[i];

        // Set the least significant bit of the byte to the next bit of the message
        byte &= 0xFE;
        byte |= (message[bit_index / 8] >> (7 - (bit_index % 8))) & 0x01;

        // Update the byte in the image data
        image->data[i] = byte;

        // Increment the bit index
        bit_index++;
    }
}

// Function to decode a message from an image
char *decode_message(Image *image) {
    int message_length = 0;
    int bit_index = 0;
    char *message = NULL;

    // Iterate over the image data
    for (int i = 0; i < image->width * image->height * 3; i++) {
        // Get the current byte
        uint8_t byte = image->data[i];

        // Get the least significant bit of the byte
        int bit = byte & 0x01;

        // If we have reached the end of the message, break
        if (bit_index >= message_length * 8) {
            break;
        }

        // If this is the first bit of the message, read the message length
        if (bit_index == 0) {
            message_length = bit;
            message = malloc(message_length + 1);
        } else {
            // Store the bit in the message
            message[bit_index / 8] |= bit << (7 - (bit_index % 8));
        }

        // Increment the bit index
        bit_index++;
    }

    // Null-terminate the message
    message[message_length] = '\0';

    return message;
}

// Main function
int main() {
    // Load the image
    Image *image = load_image("image.bmp");

    // Encode a message in the image
    encode_message(image, "Hello, world!");

    // Save the image
    save_image("encoded_image.bmp", image);

    // Decode the message from the image
    char *message = decode_message(image);

    // Print the message
    printf("%s\n", message);

    // Free the message and the image
    free(message);
    free(image->data);
    free(image);

    return 0;
}