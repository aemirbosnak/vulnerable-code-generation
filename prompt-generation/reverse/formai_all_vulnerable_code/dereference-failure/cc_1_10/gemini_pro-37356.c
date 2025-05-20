//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} pixel_t;

pixel_t image[IMAGE_WIDTH][IMAGE_HEIGHT];

void load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Read the image header
    uint32_t magic;
    uint32_t width;
    uint32_t height;
    fread(&magic, sizeof(uint32_t), 1, fp);
    fread(&width, sizeof(uint32_t), 1, fp);
    fread(&height, sizeof(uint32_t), 1, fp);

    // Check if the image is in the correct format
    if (magic != 0x424D) {
        fprintf(stderr, "Error: Invalid image format\n");
        exit(1);
    }

    // Read the image data
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fread(&image[x][y].b, sizeof(uint8_t), 1, fp);
            fread(&image[x][y].g, sizeof(uint8_t), 1, fp);
            fread(&image[x][y].r, sizeof(uint8_t), 1, fp);
        }
    }

    fclose(fp);
}

void hide_message(const char *message) {
    int message_length = strlen(message);
    int message_index = 0;

    // Iterate over the image pixels
    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            // Get the current pixel
            pixel_t *pixel = &image[x][y];

            // If there are still characters in the message, hide them in the pixel
            if (message_index < message_length) {
                // Get the least significant bit of the current pixel
                uint8_t lsb = pixel->b & 0x1;

                // Replace the least significant bit with the least significant bit of the current character
                pixel->b = (pixel->b & ~0x1) | (message[message_index] & 0x1);

                // If the least significant bit of the pixel was 1, increment the message index
                if (lsb) {
                    message_index++;
                }
            }
        }
    }
}

void extract_message() {
    int message_length = 0;
    char message[256];

    // Iterate over the image pixels
    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            // Get the current pixel
            pixel_t *pixel = &image[x][y];

            // Get the least significant bit of the current pixel
            uint8_t lsb = pixel->b & 0x1;

            // Add the least significant bit to the message
            message[message_length++] = lsb;

            // If the least significant bit was 1, null-terminate the message and break out of the loop
            if (lsb) {
                message[message_length] = '\0';
                break;
            }
        }
    }

    // Print the message
    printf("Extracted message: %s\n", message);
}

void save_image(const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Write the image header
    uint32_t magic = 0x424D;
    uint32_t width = IMAGE_WIDTH;
    uint32_t height = IMAGE_HEIGHT;
    fwrite(&magic, sizeof(uint32_t), 1, fp);
    fwrite(&width, sizeof(uint32_t), 1, fp);
    fwrite(&height, sizeof(uint32_t), 1, fp);

    // Write the image data
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fwrite(&image[x][y].b, sizeof(uint8_t), 1, fp);
            fwrite(&image[x][y].g, sizeof(uint8_t), 1, fp);
            fwrite(&image[x][y].r, sizeof(uint8_t), 1, fp);
        }
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image> <message> <output>\n", argv[0]);
        exit(1);
    }

    // Load the image
    load_image(argv[1]);

    // Hide the message in the image
    hide_message(argv[2]);

    // Save the image
    save_image(argv[3]);

    // Extract the message from the image
    extract_message();

    return 0;
}