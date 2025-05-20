//FormAI DATASET v1.0 Category: Image Steganography ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#define BMP_HEADER_SIZE 54
#define MAX_MESSAGE_LENGTH 1000
#define MESSAGE_MARKER "###"

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} pixel_t;

typedef struct {
    pixel_t *rows;
    int width;
    int height;
} bmp_image_t;

void encode_message(bmp_image_t *image, char *message) {
    int message_len = strlen(message);
    int message_start = image->width / 2;
    int message_end = image->width / 2 + message_len * 8 + 8;
    if (message_end >= image->width * image->height) {
        printf("Image is not large enough to hold message!\n");
        return;
    }

    srand(time(NULL));
    int seed = rand();

    // Encode message marker
    for (int i = 0; i < strlen(MESSAGE_MARKER); i++) {
        int row = i / image->width;
        int col = i % image->width;
        image->rows[row * image->width + col].red = MESSAGE_MARKER[i] ^ seed;
    }

    // Encode message length
    for (int i = 0; i < 32; i++) {
        int row = (message_start + i) / image->width;
        int col = (message_start + i) % image->width;
        uint8_t bit = (message_len >> (31 - i)) & 0x1;
        image->rows[row * image->width + col].green &= 0xFE;
        image->rows[row * image->width + col].green |= bit;
    }

    // Encode message
    for (int i = 0; i < message_len; i++) {
        char c = message[i];
        for (int j = 0; j < 8; j++) {
            int row = (message_start + i * 8 + j) / image->width;
            int col = (message_start + i * 8 + j) % image->width;
            uint8_t bit = (c >> (7 - j)) & 0x1;
            image->rows[row * image->width + col].red &= 0xFE;
            image->rows[row * image->width + col].red |= (bit ^ seed) & 0x1;
        }
    }

    printf("Message encoded successfully!\n");
}

void decode_message(bmp_image_t *image) {
    char message[MAX_MESSAGE_LENGTH] = {0};
    int message_start = image->width / 2;
    int message_end = image->width / 2 + MAX_MESSAGE_LENGTH * 8 + 8;

    srand(time(NULL));
    int seed = rand();

    // Decode message marker
    for (int i = 0; i < strlen(MESSAGE_MARKER); i++) {
        int row = i / image->width;
        int col = i % image->width;
        message[i] = image->rows[row * image->width + col].red ^ seed;
    }

    // Verify message marker
    if (strcmp(message, MESSAGE_MARKER) != 0) {
        printf("No message found in image!\n");
        return;
    }

    // Decode message length
    int message_len = 0;
    for (int i = 0; i < 32; i++) {
        int row = (message_start + i) / image->width;
        int col = (message_start + i) % image->width;
        uint8_t bit = image->rows[row * image->width + col].green & 0x1;
        message_len |= bit << (31 - i);
    }

    // Decode message
    for (int i = 0; i < message_len; i++) {
        char c = 0;
        for (int j = 0; j < 8; j++) {
            int row = (message_start + i * 8 + j) / image->width;
            int col = (message_start + i * 8 + j) % image->width;
            uint8_t bit = image->rows[row * image->width + col].red & 0x1;
            c |= bit << (7 - j);
        }
        message[i] = c ^ seed;
    }

    printf("Message decoded successfully: %s\n", message);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 0;
    }

    // Read input file
    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Failed to open input file!\n");
        return 0;
    }

    fseek(input_file, 0, SEEK_END);
    int input_file_size = ftell(input_file) - BMP_HEADER_SIZE;
    fseek(input_file, BMP_HEADER_SIZE, SEEK_SET);

    bmp_image_t image = {0};
    image.width = input_file_size / 3;
    image.height = 1;
    image.rows = malloc(image.width * sizeof(pixel_t));
    fread(image.rows, sizeof(pixel_t), image.width, input_file);

    // Encode or decode message
    char *message = "This is a secret message!";
    encode_message(&image, message);
    decode_message(&image);

    // Write output file
    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        printf("Failed to open output file!\n");
        return 0;
    }

    fwrite(image.rows, sizeof(pixel_t), image.width, output_file);
    fclose(output_file);

    free(image.rows);
    fclose(input_file);
    return 0;
}