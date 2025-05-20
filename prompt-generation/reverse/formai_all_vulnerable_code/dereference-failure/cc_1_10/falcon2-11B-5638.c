//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define PIXEL_COUNT 256 // Number of pixels in the image
#define MAX_MESSAGE_LENGTH 1000 // Maximum length of the secret message

void show_message(uint8_t* message, int length);

int main(int argc, char** argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <image> <message>\n", argv[0]);
        exit(1);
    }

    const char* image_path = argv[1];
    const char* message_path = argv[2];

    FILE* image_file = fopen(image_path, "rb");
    if (!image_file) {
        fprintf(stderr, "Failed to open image file: %s\n", image_path);
        exit(1);
    }

    FILE* message_file = fopen(message_path, "r");
    if (!message_file) {
        fprintf(stderr, "Failed to open message file: %s\n", message_path);
        exit(1);
    }

    const uint8_t* image_data = (const uint8_t*) fread(NULL, 1, PIXEL_COUNT*3, image_file);
    if (!image_data) {
        fprintf(stderr, "Failed to read image file\n");
        exit(1);
    }

    char message[MAX_MESSAGE_LENGTH];
    fgets(message, MAX_MESSAGE_LENGTH, message_file);
    message[strcspn(message, "\n")] = '\0'; // Remove newline character

    int message_length = strlen(message);
    if (message_length > MAX_MESSAGE_LENGTH) {
        fprintf(stderr, "Message too long\n");
        exit(1);
    }

    int message_index = 0;
    for (int i = 0; i < PIXEL_COUNT; i++) {
        uint8_t* pixel = &image_data[i*3];
        uint8_t r = pixel[0];
        uint8_t g = pixel[1];
        uint8_t b = pixel[2];

        int message_byte = 0;
        for (int j = 0; j < 8; j++) {
            if (message_index >= message_length)
                break;

            message_byte |= ((message[message_index++] & 0x80) << j);
        }

        r = r & ~message_byte;
        g = g & ~message_byte;
        b = b & ~message_byte;

        pixel[0] = r;
        pixel[1] = g;
        pixel[2] = b;
    }

    FILE* output_file = fopen("stego.png", "wb");
    if (!output_file) {
        fprintf(stderr, "Failed to create output file: stego.png\n");
        exit(1);
    }

    fwrite(image_data, 1, PIXEL_COUNT*3, output_file);
    fclose(output_file);

    show_message(message, message_length);

    return 0;
}

void show_message(uint8_t* message, int length) {
    for (int i = 0; i < length; i++) {
        printf("%02x", message[i]);
    }
    printf("\n");
}