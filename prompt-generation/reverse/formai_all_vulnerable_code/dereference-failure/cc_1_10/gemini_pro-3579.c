//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t byte;

void embed(const char *input_image, const char *message, const char *output_image) {
    FILE *input = fopen(input_image, "rb"), *output = fopen(output_image, "wb");
    if (!input || !output) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    fseek(input, 0, SEEK_END);
    long input_size = ftell(input);
    fseek(input, 0, SEEK_SET);

    byte *input_data = malloc(input_size);
    fread(input_data, 1, input_size, input);
    fclose(input);

    long message_size = strlen(message) + 1;
    byte *message_data = malloc(message_size);
    memcpy(message_data, message, message_size);

    long output_size = input_size + message_size;
    byte *output_data = malloc(output_size);
    memcpy(output_data, input_data, input_size);
    memcpy(output_data + input_size, message_data, message_size);

    fwrite(output_data, 1, output_size, output);
    fclose(output);

    free(input_data);
    free(message_data);
    free(output_data);
}

void extract(const char *input_image, const char *output_message) {
    FILE *input = fopen(input_image, "rb"), *output = fopen(output_message, "wb");
    if (!input || !output) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    fseek(input, 0, SEEK_END);
    long input_size = ftell(input);
    fseek(input, 0, SEEK_SET);

    byte *input_data = malloc(input_size);
    fread(input_data, 1, input_size, input);
    fclose(input);

    long message_size = input_size - (strlen(input_image) + 1);
    byte *message_data = malloc(message_size);
    memcpy(message_data, input_data + (strlen(input_image) + 1), message_size);

    fwrite(message_data, 1, message_size, output);
    fclose(output);

    free(input_data);
    free(message_data);
}

int main() {
    const char *input_image = "input.bmp", *message = "Hello, world!", *output_image = "output.bmp", *output_message = "output.txt";
    embed(input_image, message, output_image);
    extract(output_image, output_message);
    return 0;
}