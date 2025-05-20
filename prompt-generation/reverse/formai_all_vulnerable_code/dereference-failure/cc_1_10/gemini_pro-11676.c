//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint8_t *data;
    int width;
    int height;
} Image;

Image *load_image(const char *filename) {
    Image *image = malloc(sizeof(Image));
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s.\n", filename);
        return NULL;
    }

    // Read the header
    uint8_t header[14];
    fread(header, sizeof(uint8_t), 14, file);

    // Make sure the file is a BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: File %s is not a BMP file.\n", filename);
        fclose(file);
        free(image);
        return NULL;
    }

    // Get the image dimensions
    image->width = *(uint32_t *)&header[18];
    image->height = *(uint32_t *)&header[22];

    // Allocate memory for the image data
    image->data = malloc(image->width * image->height * 3);

    // Read the image data
    fread(image->data, sizeof(uint8_t), image->width * image->height * 3, file);

    // Close the file
    fclose(file);

    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s.\n", filename);
        return;
    }

    // Write the header
    uint8_t header[14];
    memcpy(header, "BM", 2);
    *(uint32_t *)&header[2] = image->width * image->height * 3 + 54;
    *(uint32_t *)&header[10] = 54;

    fwrite(header, sizeof(uint8_t), 14, file);

    // Write the image data
    fwrite(image->data, sizeof(uint8_t), image->width * image->height * 3, file);

    // Close the file
    fclose(file);
}

void hide_message(Image *image, const char *message) {
    int message_length = strlen(message);
    for (int i = 0; i < message_length; i++) {
        // Get the current pixel
        uint8_t *pixel = image->data + (i % image->width) * 3 + (i / image->width) * image->width * 3;

        // Hide the message in the least significant bit of the blue channel
        pixel[2] &= ~1;
        pixel[2] |= (message[i] >> 7) & 1;
    }
}

char *reveal_message(Image *image) {
    int message_length = 0;
    while (image->data[message_length * 3 + 2] != '\0') {
        message_length++;
    }

    char *message = malloc(message_length + 1);
    for (int i = 0; i < message_length; i++) {
        // Get the current pixel
        uint8_t *pixel = image->data + (i % image->width) * 3 + (i / image->width) * image->width * 3;

        // Reveal the message from the least significant bit of the blue channel
        message[i] = (pixel[2] & 1) << 7;
    }
    message[message_length] = '\0';

    return message;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <message>\n", argv[0]);
        return 1;
    }

    // Load the input image
    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Hide the message in the image
    hide_message(image, argv[3]);

    // Save the output image
    save_image(argv[2], image);

    // Free the image
    free(image->data);
    free(image);

    return 0;
}