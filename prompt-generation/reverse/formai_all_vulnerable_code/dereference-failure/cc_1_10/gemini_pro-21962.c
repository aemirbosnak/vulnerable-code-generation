//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define LSB_MASK 0x01

void embed_message(uint8_t *image_data, size_t image_size, const char *message) {
    size_t message_length = strlen(message);
    if (message_length > image_size * 8) {
        printf("Error: Message is too long for the image.\n");
        return;
    }

    uint8_t *message_bits = malloc(message_length);
    for (size_t i = 0; i < message_length; i++) {
        message_bits[i] = message[i];
    }

    size_t bit_index = 0;
    for (size_t i = 0; i < image_size; i++) {
        image_data[i] &= ~LSB_MASK;
        image_data[i] |= message_bits[bit_index] & LSB_MASK;
        bit_index++;
        if (bit_index == message_length) {
            break;
        }
    }

    free(message_bits);
}

char *extract_message(const uint8_t *image_data, size_t image_size) {
    size_t message_length = 0;
    for (size_t i = 0; i < image_size; i++) {
        if ((image_data[i] & LSB_MASK) == 0) {
            break;
        }
        message_length++;
    }

    char *message = malloc(message_length + 1);
    size_t bit_index = 0;
    for (size_t i = 0; i < image_size; i++) {
        message[bit_index] = (image_data[i] & LSB_MASK) << 7;
        bit_index++;
        if (bit_index == message_length) {
            break;
        }
    }
    message[message_length] = '\0';

    return message;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <image_file> <message>\n", argv[0]);
        return 1;
    }

    FILE *image_file = fopen(argv[1], "rb+");
    if (image_file == NULL) {
        printf("Error: Could not open image file.\n");
        return 1;
    }

    fseek(image_file, 0, SEEK_END);
    size_t image_size = ftell(image_file);
    rewind(image_file);

    uint8_t *image_data = malloc(image_size);
    fread(image_data, 1, image_size, image_file);

    embed_message(image_data, image_size, argv[2]);

    fseek(image_file, 0, SEEK_SET);
    fwrite(image_data, 1, image_size, image_file);

    fclose(image_file);
    free(image_data);

    printf("Message embedded in image.\n");

    return 0;
}