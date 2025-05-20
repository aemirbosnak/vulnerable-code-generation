//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_MODE "rb+b"
#define KEY_LENGTH 256
#define BLOCK_SIZE 64

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void xor_bytes(const unsigned char *in, const unsigned char *key, unsigned char *out, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        out[i] = in[i] ^ key[i % KEY_LENGTH];
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    const char *key_str = argv[3];

    unsigned char key[KEY_LENGTH];
    if (strlen(key_str) != KEY_LENGTH) {
        fprintf(stderr, "Error: Key must be %d bytes long.\n", KEY_LENGTH);
        exit(EXIT_FAILURE);
    }

    memcpy(key, key_str, KEY_LENGTH);

    FILE *input_fd = fopen(input_file, FILE_MODE);
    if (input_fd == NULL) {
        die("Failed to open input file.");
    }

    FILE *output_fd = fopen(output_file, FILE_MODE);
    if (output_fd == NULL) {
        fclose(input_fd);
        die("Failed to open output file.");
    }

    size_t block_read;
    unsigned char input_buffer[BLOCK_SIZE];
    unsigned char output_buffer[BLOCK_SIZE];

    while ((block_read = fread(input_buffer, sizeof(unsigned char), BLOCK_SIZE, input_fd)) > 0) {
        xor_bytes(input_buffer, key, output_buffer, block_read);
        fwrite(output_buffer, sizeof(unsigned char), block_read, output_fd);
    }

    fclose(input_fd);
    fclose(output_fd);

    printf("Encryption complete.\n");

    return EXIT_SUCCESS;
}