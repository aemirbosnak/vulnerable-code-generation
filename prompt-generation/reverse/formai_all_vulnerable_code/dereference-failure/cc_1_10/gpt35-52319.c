//FormAI DATASET v1.0 Category: Image Steganography ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BYTES_PER_PIXEL 3

// Helper function to read an image file as binary data
uint8_t *read_image(const char *filename, uint32_t *width, uint32_t *height) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        printf("Could not open file %s!\n", filename);
        return NULL;
    }

    // Read BMP header info
    uint8_t header_data[54];
    fread(header_data, 1, 54, f);

    // Extract vital information
    *width = *(uint32_t *)(header_data + 18);
    *height = *(uint32_t *)(header_data + 22);
    uint32_t data_offset = *(uint32_t *)(header_data + 10);
    uint32_t image_size = *(uint32_t *)(header_data + 34);

    // Allocate memory for raw image data
    uint8_t *image_data = malloc(image_size);
    if (!image_data) {
        printf("Failed to allocate memory for image data!\n");
        return NULL;
    }

    // Read raw image data
    fseek(f, data_offset, SEEK_SET);
    fread(image_data, 1, image_size, f);

    fclose(f);
    return image_data;
}

// Helper function to write image data back to file
void write_image(const char *filename, uint8_t *image_data, uint32_t width, uint32_t height) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        printf("Could not open file %s!\n", filename);
        return;
    }

    // BMP header info
    uint8_t header_data[54] = {
        0x42, 0x4D, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
        0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x1E, 0x00, 0x00, 0x13, 0x0B, 0x00, 0x00,
        0x13, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    // Update header with width, height, and image size
    *(uint32_t *)(header_data + 18) = width;
    *(uint32_t *)(header_data + 22) = height;
    *(uint32_t *)(header_data + 34) = width * height * BYTES_PER_PIXEL;

    // Write header and image data to file
    fwrite(header_data, 1, 54, f);
    fwrite(image_data, 1, width * height * BYTES_PER_PIXEL, f);

    fclose(f);
}

// Function to hide a secret message within an image
void hide_message(uint8_t *image_data, uint32_t image_size, const char *message) {
    // Calculate maximum length of message that can be hidden
    uint32_t max_length = (image_size * BYTES_PER_PIXEL) / 8;

    // Determine actual length of message
    uint32_t length = 0;
    while (message[length] != '\0') {
        length++;
    }

    // Check if message can be hidden within the image
    if (length > max_length) {
        printf("The message is too long to be hidden within the image!\n");
        return;
    }

    // Hide message within image data
    uint32_t byte_index = 0;
    uint8_t bit_index = 0;
    for (uint32_t i = 0; i < length; i++) {
        uint8_t bit_value = message[i] & (1 << bit_index++);
        image_data[byte_index] = (image_data[byte_index] & 0xFE) | bit_value;

        if (bit_index == 8) {
            bit_index = 0;
            byte_index++;
        }
    }

    // Append null terminator at the end to mark end of message
    image_data[byte_index] = (image_data[byte_index] & 0xFE) | 0x01;
    image_data[++byte_index] = '\0';
}

// Function to reveal a secret message from an image
char *reveal_message(uint8_t *image_data, uint32_t image_size) {
    // Calculate maximum possible length of message that can be revealed
    uint32_t max_length = (image_size * BYTES_PER_PIXEL) / 8;

    // Iterate through image data to find message
    uint32_t byte_index = 0;
    uint8_t bit_index = 0;
    uint32_t length = 0;
    while (byte_index < max_length) {
        uint8_t bit_value = image_data[byte_index] & 0x01;
        length |= bit_value << bit_index++;

        if (bit_index == 8) {
            bit_index = 0;
            byte_index++;
        }

        if (length && (byte_index >= (length / 8))) {
            break;
        }
    }

    // Extract message from image data
    char *message = malloc(length + 1);
    if (!message) {
        printf("Failed to allocate memory to extract message!\n");
        return NULL;
    }

    byte_index = 0;
    bit_index = 0;
    for (uint32_t i = 0; i < length; i++) {
        uint8_t bit_value = image_data[byte_index] & 0x01;
        message[i] = (message[i] & ~(1 << bit_index)) | (bit_value << bit_index++);

        if (bit_index == 8) {
            bit_index = 0;
            byte_index++;
        }
    }

    message[length] = '\0';
    return message;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s [encode|decode] input_image output_image\n", argv[0]);
        return 0;
    }

    const char *mode = argv[1];
    const char *input_image = argv[2];
    const char *output_image = argv[3];

    uint32_t width, height;
    uint8_t *image_data = read_image(input_image, &width, &height);
    if (!image_data) {
        printf("Failed to read image data!\n");
        return 1;
    }

    // Hide message within the image data
    if (strcmp(mode, "encode") == 0) {
        const char *message = "This is a secret message hidden within the image!";
        hide_message(image_data, width * height * BYTES_PER_PIXEL, message);
        write_image(output_image, image_data, width, height);
        printf("Message successfully hidden within the image!\n");
    }
    // Reveal the message hidden within the image data
    else if (strcmp(mode, "decode") == 0) {
        char *message = reveal_message(image_data, width * height * BYTES_PER_PIXEL);
        printf("The hidden message within the image is: %s\n", message);
        free(message);
    }
    else {
        printf("Invalid mode specified! Use \"encode\" or \"decode\".\n");
    }

    free(image_data);
    return 0;
}