//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

// Bitwise operations macros
#define GET_BIT(x, n) ((x) >> (n) & 1)
#define SET_BIT(x, n) ((x) | (1 << (n)))
#define CLEAR_BIT(x, n) ((x) & ~(1 << (n)))
#define TOGGLE_BIT(x, n) ((x) ^ (1 << (n)))

// Image header structure
typedef struct {
    uint16_t type;              // Magic number
    uint32_t size;              // File size in bytes
    uint16_t reserved1;         // Reserved (always 0)
    uint16_t reserved2;         // Reserved (always 0)
    uint32_t offset;            // Offset to image data
} bmp_header;

// Pixel structure
typedef struct {
    uint8_t blue;               // Blue component
    uint8_t green;              // Green component
    uint8_t red;                // Red component
} pixel;

// Embed message into image data
void embed_message(pixel *data, int data_size, const char *message) {
    int message_len = strlen(message);
    int bit_pos = 0;

    for (int i = 0; i < data_size; i++) {
        if (bit_pos >= message_len * 8) {
            break;
        }

        // Set the least significant bit of the blue component to the message bit
        data[i].blue = SET_BIT(data[i].blue, 0);

        // If the message bit is 1, clear the second least significant bit of the blue component
        if (GET_BIT(message[bit_pos / 8], bit_pos % 8)) {
            data[i].blue = CLEAR_BIT(data[i].blue, 1);
        }

        bit_pos++;
    }
}

// Extract message from image data
char *extract_message(pixel *data, int data_size) {
    int bit_pos = 0;
    char *message = malloc(data_size / 8 + 1);

    for (int i = 0; i < data_size; i++) {
        if (bit_pos >= data_size * 8) {
            break;
        }

        // Get the least significant bit of the blue component
        int bit = GET_BIT(data[i].blue, 0);

        // If the second least significant bit of the blue component is 0, set the message bit to 1
        if (!GET_BIT(data[i].blue, 1)) {
            bit = 1;
        }

        message[bit_pos / 8] = SET_BIT(message[bit_pos / 8], bit_pos % 8);

        bit_pos++;
    }

    message[bit_pos / 8] = '\0';

    return message;
}

int main() {
    // Open the input image file
    FILE *input_file = fopen("input.bmp", "rb");
    if (input_file == NULL) {
        printf("Error: Unable to open input image file.\n");
        return 1;
    }

    // Read the BMP header
    bmp_header header;
    fread(&header, sizeof(bmp_header), 1, input_file);

    // Check if the file is a valid BMP file
    if (header.type != 0x4D42) {
        printf("Error: Invalid BMP file.\n");
        fclose(input_file);
        return 1;
    }

    // Get the image data size
    int data_size = header.size - header.offset;

    // Allocate memory for the image data
    pixel *data = malloc(data_size);

    // Read the image data
    fread(data, data_size, 1, input_file);

    // Close the input image file
    fclose(input_file);

    // Get the message to embed
    char *message = "Hello, world!";

    // Embed the message into the image data
    embed_message(data, data_size, message);

    // Open the output image file
    FILE *output_file = fopen("output.bmp", "wb");
    if (output_file == NULL) {
        printf("Error: Unable to open output image file.\n");
        free(data);
        return 1;
    }

    // Write the BMP header to the output file
    fwrite(&header, sizeof(bmp_header), 1, output_file);

    // Write the image data to the output file
    fwrite(data, data_size, 1, output_file);

    // Close the output image file
    fclose(output_file);

    // Free the allocated memory
    free(data);
    free(message);

    // Print a success message
    printf("Message successfully embedded into image.\n");

    return 0;
}