//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_MSG_LEN 1000

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} pixel;

void encode_message(pixel *image, char *message, size_t image_size, size_t msg_len);
void decode_message(pixel *image, size_t image_size);

int main() {
    // Read the image from a file
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        perror("Could not open image file");
        exit(1);
    }

    // Get the image size
    fseek(fp, 2, SEEK_SET);
    uint32_t image_size;
    fread(&image_size, 4, 1, fp);

    // Read the image data
    fseek(fp, 54, SEEK_SET);
    pixel *image = malloc(image_size);
    fread(image, image_size, 1, fp);
    fclose(fp);

    // Read the message from the user
    char message[MAX_MSG_LEN];
    printf("Enter the message to encode: ");
    fgets(message, MAX_MSG_LEN, stdin);

    // Encode the message in the image
    size_t msg_len = strlen(message);
    encode_message(image, message, image_size, msg_len);

    // Write the modified image to a file
    fp = fopen("encoded_image.bmp", "wb");
    if (fp == NULL) {
        perror("Could not open encoded image file");
        exit(1);
    }

    // Write the header
    fseek(fp, 0, SEEK_SET);
    fwrite("BM", 2, 1, fp);
    fwrite(&image_size, 4, 1, fp);
    fseek(fp, 54, SEEK_SET);

    // Write the image data
    fwrite(image, image_size, 1, fp);
    fclose(fp);

    // Decode the message from the image
    decode_message(image, image_size);

    // Free the image data
    free(image);

    return 0;
}

void encode_message(pixel *image, char *message, size_t image_size, size_t msg_len) {
    // Convert the message to a binary string
    char binary_msg[msg_len * 8 + 1];
    for (size_t i = 0; i < msg_len; i++) {
        for (size_t j = 0; j < 8; j++) {
            binary_msg[i * 8 + j] = (message[i] >> (7 - j)) & 1;
        }
    }
    binary_msg[msg_len * 8] = '\0';

    // Encode the message in the image
    size_t index = 0;
    for (size_t i = 0; i < image_size; i++) {
        // Encode the bit in the least significant bit of the blue channel
        image[i].b &= 0xFE;
        image[i].b |= binary_msg[index++];

        // If we have encoded all the bits, stop
        if (index == msg_len * 8) {
            break;
        }
    }
}

void decode_message(pixel *image, size_t image_size) {
    // Decode the message from the image
    char binary_msg[image_size * 8 + 1];
    for (size_t i = 0; i < image_size; i++) {
        // Decode the bit from the least significant bit of the blue channel
        binary_msg[i * 8] = image[i].b & 1;
    }
    binary_msg[image_size * 8] = '\0';

    // Convert the binary string to a message
    char message[image_size + 1];
    for (size_t i = 0; i < image_size; i++) {
        for (size_t j = 0; j < 8; j++) {
            message[i] |= binary_msg[i * 8 + j] << (7 - j);
        }
    }
    message[image_size] = '\0';

    // Print the message
    printf("Decoded message: %s\n", message);
}