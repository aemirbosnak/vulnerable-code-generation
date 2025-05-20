//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// LSB of a byte
#define LSB_MASK 0x01

// Extract the LSB of a byte
#define GET_LSB(byte) (byte & LSB_MASK)

// Set the LSB of a byte
#define SET_LSB(byte, bit) ((byte & ~LSB_MASK) | (bit & LSB_MASK))

// Embed a bit in the LSB of a byte
#define EMBED_BIT(byte, bit) SET_LSB(byte, bit)

// Extract a bit from the LSB of a byte
#define EXTRACT_BIT(byte) GET_LSB(byte)

// Embed a message in an image
void embed_message(const char *image_path, const char *message_path, const char *output_path) {
    // Read the image
    FILE *image_file = fopen(image_path, "rb");
    fseek(image_file, 0, SEEK_END);
    long image_size = ftell(image_file);
    rewind(image_file);
    uint8_t *image_data = malloc(image_size);
    fread(image_data, 1, image_size, image_file);
    fclose(image_file);

    // Read the message
    FILE *message_file = fopen(message_path, "rb");
    fseek(message_file, 0, SEEK_END);
    long message_size = ftell(message_file);
    rewind(message_file);
    char *message = malloc(message_size);
    fread(message, 1, message_size, message_file);
    fclose(message_file);

    // Embed the message in the image
    int message_index = 0;
    for (long i = 0; i < image_size; i++) {
        if (message_index < message_size) {
            image_data[i] = EMBED_BIT(image_data[i], EXTRACT_BIT(message[message_index]));
            message_index++;
        }
    }

    // Write the output image
    FILE *output_file = fopen(output_path, "wb");
    fwrite(image_data, 1, image_size, output_file);
    fclose(output_file);

    free(image_data);
    free(message);
}

// Extract a message from an image
void extract_message(const char *image_path, const char *output_path) {
    // Read the image
    FILE *image_file = fopen(image_path, "rb");
    fseek(image_file, 0, SEEK_END);
    long image_size = ftell(image_file);
    rewind(image_file);
    uint8_t *image_data = malloc(image_size);
    fread(image_data, 1, image_size, image_file);
    fclose(image_file);

    // Extract the message from the image
    int message_index = 0;
    FILE *output_file = fopen(output_path, "wb");
    for (long i = 0; i < image_size; i++) {
        putc(EXTRACT_BIT(image_data[i]), output_file);
        message_index++;
    }
    fclose(output_file);

    free(image_data);
}

int main() {
    // Embed a message in an image
    embed_message("image.png", "message.txt", "output.png");

    // Extract the message from the image
    extract_message("output.png", "extracted_message.txt");

    return 0;
}