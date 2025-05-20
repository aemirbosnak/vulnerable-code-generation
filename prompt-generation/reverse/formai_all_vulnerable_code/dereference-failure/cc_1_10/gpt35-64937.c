//FormAI DATASET v1.0 Category: Image Steganography ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hide_data(unsigned char *image_data, char *secret_message) {
    int message_length = strlen(secret_message);
    unsigned char mask = 1;
    int bit_count = 0;
    int byte_count = 0;

    for (int i = 0; i < message_length; i++) {
        char current_char = secret_message[i];

        for (int j = 0; j < 8; j++) {
            unsigned char current_byte = image_data[byte_count];

            if (((current_char >> j) & mask) == 1) {
                current_byte |= mask;
            } else {
                current_byte &= ~mask;
            }

            image_data[byte_count] = current_byte;

            bit_count++;

            if (bit_count == 8) {
                bit_count = 0;
                byte_count++;
            }
        }
    }
}

char *extract_data(unsigned char *image_data, int message_length) {
    char *secret_message = malloc((message_length + 1) * sizeof(char));
    unsigned char mask = 1;
    int bit_count = 0;
    int byte_count = 0;

    for (int i = 0; i < message_length; i++) {
        char current_char = 0x00;

        for (int j = 0; j < 8; j++) {
            unsigned char current_byte = image_data[byte_count];

            if ((current_byte & mask) == 1) {
                current_char |= (1 << j);
            }

            bit_count++;

            if (bit_count == 8) {
                bit_count = 0;
                byte_count++;
            }
        }

        secret_message[i] = current_char;
    }

    secret_message[message_length] = '\0';

    return secret_message;
}

int main() {
    FILE *image_fp = fopen("image.bmp", "rb");
    FILE *output_image_fp = fopen("output_image.bmp", "wb");

    if (image_fp == NULL) {
        printf("Error: could not open image file.\n");
        return 1;
    }

    if (output_image_fp == NULL) {
        printf("Error: could not create output image file.\n");
        return 1;
    }

    fseek(image_fp, 0, SEEK_END);
    int image_size = ftell(image_fp);
    rewind(image_fp);

    unsigned char *image_data = malloc(image_size * sizeof(unsigned char));
    fread(image_data, sizeof(unsigned char), image_size, image_fp);

    // Hide the message "Hello, world!"
    char *secret_message = "Hello, world!";
    hide_data(image_data, secret_message);

    // Extract the hidden data
    int message_length = strlen(secret_message);
    char *extracted_message = extract_data(image_data, message_length);

    printf("Extracted message: %s\n", extracted_message);

    // Write the modified image to disk
    fwrite(image_data, sizeof(unsigned char), image_size, output_image_fp);

    fclose(image_fp);
    fclose(output_image_fp);
    free(image_data);
    free(extracted_message);

    return 0;
}