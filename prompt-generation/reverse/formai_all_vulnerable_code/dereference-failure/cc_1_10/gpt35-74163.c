//FormAI DATASET v1.0 Category: Image Steganography ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to hide message in image
void hide_message(char *message, char *image_path, char *output_path) {
    // Open image file in read mode
    FILE *input_image = fopen(image_path, "rb");
    if (input_image == NULL) {
        printf("Error opening input image!\n");
        return;
    }

    // Open output file in write mode
    FILE *output_image = fopen(output_path, "wb");
    if (output_image == NULL) {
        printf("Error creating output image!\n");
        return;
    }

    int message_len = strlen(message);
    int image_size, pixel_count, bits_in_last_byte;
    unsigned char *image_bytes, *output_bytes;

    // Get image size
    fseek(input_image, 0, SEEK_END);
    image_size = ftell(input_image);
    fseek(input_image, 0, SEEK_SET);

    // Read image byte data
    image_bytes = (unsigned char *) malloc(sizeof(unsigned char) * image_size);
    fread(image_bytes, sizeof(unsigned char), image_size, input_image);

    // Calculate number of pixels in image
    pixel_count = image_size / 3;

    // Calculate number of bits required to store message
    bits_in_last_byte = message_len % 8;

    // Allocate memory for output byte data
    output_bytes = (unsigned char *) malloc(sizeof(unsigned char) * image_size);

    // Initialize output byte data to the same as input byte data
    memcpy(output_bytes, image_bytes, image_size);

    int bit_index = 0;
    int byte_index = 0;

    // Loop through each pixel in image
    for (int i = 0; i < pixel_count; i++) {
        // Loop through each color component (R, G, B) in pixel
        for (int j = 0; j < 3; j++) {
            // Check if message has been completely hidden
            if (byte_index == message_len) {
                fwrite(output_bytes, sizeof(unsigned char), image_size, output_image);
                fclose(input_image);
                fclose(output_image);
                free(image_bytes);
                free(output_bytes);
                return;
            }

            // Get current color component value
            unsigned char color = image_bytes[i * 3 + j];

            // Get least significant bit of current color component value
            unsigned char lsb = color & 0x1;

            // Get current bit of message to hide
            unsigned char bit_to_hide = (message[byte_index] >> bit_index) & 0x1;

            // Check if current bit of message matches least significant bit of current color component value
            if (lsb != bit_to_hide) {
                // If not, flip least significant bit of current color component value
                color ^= 0x1;
                output_bytes[i * 3 + j] = color;
            }

            // Move to next bit of message
            bit_index++;
            if (bit_index == 8) {
                // If entire byte of message has been hidden, move to next byte
                byte_index++;
                bit_index = 0;
            }
        }
    }

    // If message has not been completely hidden, write remaining byte data to output file
    fwrite(output_bytes, sizeof(unsigned char), image_size, output_image);

    fclose(input_image);
    fclose(output_image);
    free(image_bytes);
    free(output_bytes);
}

int main() {
    char *message = "The elephant in the room has a coconut for a head";
    char *image_path = "surreal.jpg";
    char *output_path = "surreal_stego.jpg";

    hide_message(message, image_path, output_path);

    return 0;
}