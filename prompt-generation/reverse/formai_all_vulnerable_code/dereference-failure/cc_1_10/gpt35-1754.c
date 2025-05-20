//FormAI DATASET v1.0 Category: Image Steganography ; Style: Donald Knuth
// Donald Knuth Style Image Steganography Example

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>

#define BYTE 8

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} pixel;

void hide_message(char *message, char *image_path) {
    FILE *image_file = fopen(image_path, "r+b");
    int message_bits = strlen(message) * BYTE;
    struct stat image_stat;
    stat(image_path, &image_stat);
    int image_size = image_stat.st_size - sizeof(int);
    if (message_bits > image_size) {
        printf("Error: Message too large to hide, choose a larger image or a shorter message.\n");
        exit(1);
    }
    int message_index = 0;
    uint8_t message_byte = message[message_index];
    int bit_index = 0;
    int byte_index = 0;
    pixel current_pixel;
    while (fread(&current_pixel, sizeof(pixel), 1, image_file) == 1) {
        if (byte_index == sizeof(int)) {
            rewind(image_file);
            fwrite(&message_bits, sizeof(int), 1, image_file);
        }
        if (bit_index < BYTE) {
            current_pixel.red &= 0xFE;
            current_pixel.red |= ((message_byte >> bit_index) & 1);
            bit_index++;
            if (bit_index == BYTE) {
                bit_index = 0;
                message_index++;
                message_byte = message[message_index];
            }
        } else if (bit_index < BYTE * 2) {
            current_pixel.green &= 0xFE;
            current_pixel.green |= ((message_byte >> bit_index - BYTE) & 1);
            bit_index++;
        } else {
            current_pixel.blue &= 0xFE;
            current_pixel.blue |= ((message_byte >> bit_index - BYTE * 2) & 1);
            bit_index++;
            fwrite(&current_pixel, sizeof(pixel), 1, image_file);
            byte_index++;
            if (byte_index == image_size) {
                return;
            }
        }
    }
}

char *extract_message(char *image_path) {
    FILE *image_file = fopen(image_path, "rb");
    int message_bits;
    fread(&message_bits, sizeof(int), 1, image_file);
    if (message_bits < 0) {
        printf("Error: File not encoded with steganography.\n");
        exit(1);
    }
    int message_size = message_bits / BYTE;
    char *message = malloc((message_size + 1) * sizeof(char));
    memset(message, 0, (message_size + 1) * sizeof(char));
    int bit_index = 0;
    int byte_index = 0;
    uint8_t message_byte = 0;
    pixel current_pixel;
    while (fread(&current_pixel, sizeof(pixel), 1, image_file) == 1) {
        if (bit_index < BYTE) {
            message_byte |= ((current_pixel.red & 1) << bit_index);
            bit_index++;
            if (bit_index == BYTE) {
                bit_index = 0;
                message[byte_index] = message_byte;
                byte_index++;
                message_byte = 0;
                if (byte_index == message_size) {
                    message[message_size] = '\0';
                    return message;
                }
            }
        } else if (bit_index < BYTE * 2) {
            message_byte |= ((current_pixel.green & 1) << bit_index - BYTE);
            bit_index++;
        } else {
            message_byte |= ((current_pixel.blue & 1) << bit_index - BYTE * 2);
            bit_index++;
        }
    }
    return NULL;
}

int main() {
    char *message = "Hello World!";
    char *image_path = "test_image.bmp";
    hide_message(message, image_path);
    char *extracted_message = extract_message(image_path);
    printf("Extracted Message: %s\n", extracted_message);
    free(extracted_message);
    return 0;
}