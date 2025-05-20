//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define LSB_MASK 0x1

void encode_image(const char *image_path, const char *message_path, const char *output_path) {
    // Open the image file
    FILE *image_file = fopen(image_path, "rb");
    if (image_file == NULL) {
        fprintf(stderr, "Error opening the image file.\n");
        exit(1);
    }

    // Read the image header
    uint8_t header[54];
    fread(header, 1, 54, image_file);

    // Calculate the image size
    uint32_t width = *(uint32_t *)(header + 18);
    uint32_t height = *(uint32_t *)(header + 22);
    uint32_t image_size = width * height * 3;

    // Read the image data
    uint8_t *image_data = malloc(image_size);
    fread(image_data, 1, image_size, image_file);
    fclose(image_file);

    // Open the message file
    FILE *message_file = fopen(message_path, "rb");
    if (message_file == NULL) {
        fprintf(stderr, "Error opening the message file.\n");
        exit(1);
    }

    // Read the message
    fseek(message_file, 0, SEEK_END);
    uint32_t message_size = ftell(message_file);
    rewind(message_file);

    uint8_t *message = malloc(message_size);
    fread(message, 1, message_size, message_file);
    fclose(message_file);

    // Encode the message into the image
    uint32_t message_index = 0;
    for (uint32_t i = 0; i < image_size; i++) {
        if (message_index < message_size) {
            // Set the LSB of the pixel to the next bit of the message
            image_data[i] = (image_data[i] & ~LSB_MASK) | (message[message_index] & LSB_MASK);
            message_index++;
        }
    }

    // Write the encoded image to the output file
    FILE *output_file = fopen(output_path, "wb");
    fwrite(header, 1, 54, output_file);
    fwrite(image_data, 1, image_size, output_file);
    fclose(output_file);

    // Free the allocated memory
    free(image_data);
    free(message);
}

void decode_image(const char *image_path, const char *output_path) {
    // Open the image file
    FILE *image_file = fopen(image_path, "rb");
    if (image_file == NULL) {
        fprintf(stderr, "Error opening the image file.\n");
        exit(1);
    }

    // Read the image header
    uint8_t header[54];
    fread(header, 1, 54, image_file);

    // Calculate the image size
    uint32_t width = *(uint32_t *)(header + 18);
    uint32_t height = *(uint32_t *)(header + 22);
    uint32_t image_size = width * height * 3;

    // Read the image data
    uint8_t *image_data = malloc(image_size);
    fread(image_data, 1, image_size, image_file);
    fclose(image_file);

    // Decode the message from the image
    uint32_t message_size = 0;
    uint32_t message_index = 0;
    uint8_t message[image_size];

    for (uint32_t i = 0; i < image_size; i++) {
        // Get the LSB of the pixel
        uint8_t bit = image_data[i] & LSB_MASK;

        // Append the bit to the message
        message[message_index] = (message[message_index] << 1) | bit;

        // Increment the message index
        message_index++;

        // If the message index is equal to the message size, then we have reached the end of the message
        if (message_index == message_size) {
            break;
        }
    }

    // Write the decoded message to the output file
    FILE *output_file = fopen(output_path, "wb");
    fwrite(message, 1, message_size, output_file);
    fclose(output_file);

    // Free the allocated memory
    free(image_data);
    free(message);
}

int main() {
    // Encode an image
    encode_image("image.bmp", "message.txt", "encoded_image.bmp");

    // Decode the image
    decode_image("encoded_image.bmp", "decoded_message.txt");

    return 0;
}