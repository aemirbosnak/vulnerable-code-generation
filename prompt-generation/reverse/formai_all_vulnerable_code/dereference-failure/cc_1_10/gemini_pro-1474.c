//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_IMAGE_SIZE (1024 * 1024)
#define MAX_MESSAGE_SIZE (1024 * 1024)

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} pixel;

pixel image[MAX_IMAGE_SIZE];
char message[MAX_MESSAGE_SIZE];

void embed_message(const char *message, int message_size) {
    int i, j, k;
    unsigned char mask = 1;
    for (i = j = k = 0; i < message_size; i++) {
        for (int bit = 7; bit >= 0; bit--) {
            if ((message[i] & (1 << bit)) != 0) {
                image[j].blue |= mask;
            } else {
                image[j].blue &= ~mask;
            }
            mask <<= 1;
            if (mask == 0) {
                mask = 1;
                j++;
            }
        }
    }
}

void extract_message(char *message, int *message_size) {
    int i, j, k;
    unsigned char mask = 1;
    for (i = j = k = 0; i < *message_size; i++) {
        for (int bit = 7; bit >= 0; bit--) {
            if ((image[j].blue & mask) != 0) {
                message[i] |= mask;
            } else {
                message[i] &= ~mask;
            }
            mask <<= 1;
            if (mask == 0) {
                mask = 1;
                j++;
            }
        }
    }
}

int main() {
    int image_size, message_size;
    FILE *image_file, *message_file;

    image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        perror("Error opening image file");
        return EXIT_FAILURE;
    }

    image_size = fread(image, sizeof(pixel), MAX_IMAGE_SIZE, image_file);
    if (image_size == 0) {
        perror("Error reading image file");
        return EXIT_FAILURE;
    }

    fclose(image_file);

    message_file = fopen("message.txt", "rb");
    if (message_file == NULL) {
        perror("Error opening message file");
        return EXIT_FAILURE;
    }

    message_size = fread(message, sizeof(char), MAX_MESSAGE_SIZE, message_file);
    if (message_size == 0) {
        perror("Error reading message file");
        return EXIT_FAILURE;
    }

    fclose(message_file);

    embed_message(message, message_size);

    image_file = fopen("image_with_message.bmp", "wb");
    if (image_file == NULL) {
        perror("Error opening image file");
        return EXIT_FAILURE;
    }

    fwrite(image, sizeof(pixel), image_size, image_file);
    fclose(image_file);

    extract_message(message, &message_size);

    message_file = fopen("extracted_message.txt", "wb");
    if (message_file == NULL) {
        perror("Error opening message file");
        return EXIT_FAILURE;
    }

    fwrite(message, sizeof(char), message_size, message_file);
    fclose(message_file);

    return EXIT_SUCCESS;
}