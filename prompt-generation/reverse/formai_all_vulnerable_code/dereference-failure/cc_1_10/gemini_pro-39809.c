//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t byte;

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fseek(input, 0, SEEK_END);
    long input_size = ftell(input);
    rewind(input);

    fseek(output, 0, SEEK_END);
    long output_size = ftell(output);
    rewind(output);

    byte *input_buffer = malloc(input_size);
    if (input_buffer == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    byte *output_buffer = malloc(output_size + strlen(argv[3]));
    if (output_buffer == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    fread(input_buffer, sizeof(byte), input_size, input);
    fclose(input);

    memcpy(output_buffer, input_buffer, input_size);
    for (int i = 0; i < strlen(argv[3]); i++) {
        for (int j = 0; j < 8; j++) {
            output_buffer[output_size + i * 8 + j] = (input_buffer[output_size + i * 8 + j] & ~(1 << j)) | ((argv[3][i] >> j) & 1) << j;
        }
    }

    fwrite(output_buffer, sizeof(byte), output_size + strlen(argv[3]), output);
    fclose(output);

    free(input_buffer);
    free(output_buffer);

    return EXIT_SUCCESS;
}