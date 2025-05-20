//FormAI DATASET v1.0 Category: Image Steganography ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BMP_HEADER_SIZE 54
#define BITS_PER_PIXEL 24

bool read_bmp_header(FILE *in_file, int *width, int *height);
bool write_bmp_header(FILE *out_file, int width, int height);

void hide_message_in_pixel(unsigned char *pixel, char message_char);
char read_message_from_pixel(unsigned char *pixel);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <message>\n", argv[0]);
        return -1;
    }

    char *message = argv[3];
    int message_length = strlen(message);

    if (message_length >= 255) {
        printf("Message is too long.\n");
        return -1;
    }

    // Open input file
    FILE *in_file = fopen(argv[1], "rb");
    if (in_file == NULL) {
        printf("Error opening input file.\n");
        return -1;
    }

    // Read header
    int width, height;
    if (!read_bmp_header(in_file, &width, &height)) {
        printf("Error reading BMP header.\n");
        fclose(in_file);
        return -1;
    }

    int num_pixels = width * height;
    int message_index = 0;

    unsigned char *pixels = calloc(num_pixels * BITS_PER_PIXEL / 8, sizeof(unsigned char));

    // Read pixels
    fread(pixels, sizeof(unsigned char), num_pixels * BITS_PER_PIXEL / 8, in_file);
    fclose(in_file);

    // Hide message in pixels
    for (int i = 0; i < num_pixels && message_index < message_length; i++) {
        if (i % 4 != 3) { // skip alpha channel
            hide_message_in_pixel(&pixels[i * 3], message[message_index++]);
        }
    }

    // Write output file
    FILE *out_file = fopen(argv[2], "wb");
    if (out_file == NULL) {
        printf("Error opening output file.\n");
        free(pixels);
        return -1;
    }

    // Write header
    if (!write_bmp_header(out_file, width, height)) {
        printf("Error writing BMP header.\n");
        fclose(out_file);
        free(pixels);
        return -1;
    }

    // Write pixels
    fwrite(pixels, sizeof(unsigned char), num_pixels * BITS_PER_PIXEL / 8, out_file);
    fclose(out_file);

    free(pixels);

    return 0;
}

bool read_bmp_header(FILE *in_file, int *width, int *height) {
    unsigned char header[BMP_HEADER_SIZE];

    if (fread(header, sizeof(unsigned char), BMP_HEADER_SIZE, in_file) != BMP_HEADER_SIZE) {
        return false;
    }

    *width = *(int *)&header[18];
    *height = *(int *)&header[22];

    return true;
}

bool write_bmp_header(FILE *out_file, int width, int height) {
    unsigned char header[BMP_HEADER_SIZE];

    memset(header, 0, BMP_HEADER_SIZE);

    header[0] = 'B';
    header[1] = 'M';
    *(int *)&header[2] = BMP_HEADER_SIZE + width * height * BITS_PER_PIXEL / 8;
    *(int *)&header[10] = BMP_HEADER_SIZE;
    *(int *)&header[14] = BMP_HEADER_SIZE - 14;
    *(int *)&header[18] = width;
    *(int *)&header[22] = height;
    *(int *)&header[26] = 1;
    *(int *)&header[28] = BITS_PER_PIXEL;

    return fwrite(header, sizeof(unsigned char), BMP_HEADER_SIZE, out_file) == BMP_HEADER_SIZE;
}

void hide_message_in_pixel(unsigned char *pixel, char message_char) {
    *pixel = (*pixel & 0xFE) | ((message_char >> 7) & 1);
    *(pixel + 1) = (*(pixel + 1) & 0xFE) | ((message_char >> 6) & 1);
    *(pixel + 2) = (*(pixel + 2) & 0xFE) | ((message_char >> 5) & 1);
}

char read_message_from_pixel(unsigned char *pixel) {
    char message_char = 0;

    message_char |= (*pixel & 1) << 7;
    message_char |= (*(pixel + 1) & 1) << 6;
    message_char |= (*(pixel + 2) & 1) << 5;

    return message_char;
}