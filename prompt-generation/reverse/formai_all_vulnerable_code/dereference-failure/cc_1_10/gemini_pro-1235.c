//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512
#define IMAGE_SIZE (IMAGE_WIDTH * IMAGE_HEIGHT * 3)

typedef struct {
    uint8_t r, g, b;
} Pixel;

void encode(const char *filename, const char *message) {
    FILE *image_file = fopen(filename, "rb+");
    if (image_file == NULL) {
        perror("fopen");
        exit(1);
    }

    Pixel image[IMAGE_WIDTH][IMAGE_HEIGHT];
    fread(image, sizeof(Pixel), IMAGE_SIZE, image_file);

    size_t message_length = strlen(message);
    if (message_length > IMAGE_SIZE) {
        fprintf(stderr, "Message too long\n");
        exit(1);
    }

    for (size_t i = 0; i < message_length; i++) {
        uint8_t byte = message[i];
        for (int j = 7; j >= 0; j--) {
            int bit = (byte >> j) & 1;
            image[i / 3][i % 3].r = (image[i / 3][i % 3].r & ~1) | bit;
            i++;
        }
    }

    fseek(image_file, 0, SEEK_SET);
    fwrite(image, sizeof(Pixel), IMAGE_SIZE, image_file);

    fclose(image_file);
}

void decode(const char *filename) {
    FILE *image_file = fopen(filename, "rb");
    if (image_file == NULL) {
        perror("fopen");
        exit(1);
    }

    Pixel image[IMAGE_WIDTH][IMAGE_HEIGHT];
    fread(image, sizeof(Pixel), IMAGE_SIZE, image_file);

    char message[IMAGE_SIZE];
    memset(message, 0, IMAGE_SIZE);

    for (size_t i = 0; i < IMAGE_SIZE; i += 3) {
        uint8_t byte = 0;
        for (int j = 0; j < 8; j++) {
            byte |= (image[i / 3][i % 3].r & 1) << j;
            i++;
        }
        message[i / 3] = byte;
    }

    printf("%s\n", message);

    fclose(image_file);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <encode|decode> <filename> <message>\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "encode") == 0) {
        encode(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decode") == 0) {
        decode(argv[2]);
    } else {
        fprintf(stderr, "Invalid command\n");
        exit(1);
    }

    return 0;
}