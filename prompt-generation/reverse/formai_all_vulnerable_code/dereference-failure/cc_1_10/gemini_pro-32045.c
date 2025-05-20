//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define ENCODE 1
#define DECODE 0

void encrypt_block(uint8_t *block, uint8_t *key);
void decrypt_block(uint8_t *block, uint8_t *key);

int main(int argc, char **argv) {
    char *key = NULL;
    FILE *in = NULL;
    FILE *out = NULL;
    int mode = DECODE;
    int c;
    uint8_t buffer[16];
    int i = 0;
    int bytes_read;

    if (argc < 4) {
        fprintf(stderr, "Usage: %s [-e|-d] key input_file output_file\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-e") == 0) {
        mode = ENCODE;
    } else if (strcmp(argv[1], "-d") == 0) {
        mode = DECODE;
    } else {
        fprintf(stderr, "Invalid mode: %s\n", argv[1]);
        return 1;
    }

    key = argv[2];
    in = fopen(argv[3], "rb");
    if (in == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", argv[3]);
        return 1;
    }

    out = fopen(argv[4], "wb");
    if (out == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", argv[4]);
        return 1;
    }

    while ((bytes_read = fread(buffer, 1, 16, in)) > 0) {
        if (bytes_read < 16) {
            memset(buffer + bytes_read, 0, 16 - bytes_read);
        }
        if (mode == ENCODE) {
            encrypt_block(buffer, key);
        } else {
            decrypt_block(buffer, key);
        }
        fwrite(buffer, 1, 16, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}

void encrypt_block(uint8_t *block, uint8_t *key) {
    uint32_t *state = (uint32_t *) block;
    uint32_t temp;
    int round;

    for (round = 0; round < 10; round++) {
        temp = state[0] + state[3];
        state[0] = state[1];
        state[1] = state[2];
        state[2] = state[3];
        state[3] = temp;

        temp = state[0] ^ state[1];
        state[0] = state[0] ^ key[round % 4];
        state[1] = state[1] ^ temp;
    }
}

void decrypt_block(uint8_t *block, uint8_t *key) {
    uint32_t *state = (uint32_t *) block;
    uint32_t temp;
    int round;

    for (round = 9; round >= 0; round--) {
        temp = state[0] ^ state[1];
        state[0] = state[0] ^ key[round % 4];
        state[1] = state[1] ^ temp;

        temp = state[0] + state[3];
        state[0] = state[2];
        state[1] = state[3];
        state[2] = state[1];
        state[3] = temp;
    }
}