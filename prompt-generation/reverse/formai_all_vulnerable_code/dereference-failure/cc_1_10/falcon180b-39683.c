//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

typedef struct {
    char key[KEY_SIZE];
    int mode;
} Options;

void encrypt(char *input_file, char *output_file, char *key, int mode) {
    FILE *in, *out;
    Options opt;
    int i, j, len;
    char buffer[BLOCK_SIZE + 1];

    opt.mode = mode;
    strncpy(opt.key, key, KEY_SIZE);
    opt.key[KEY_SIZE - 1] = '\0';

    in = fopen(input_file, "rb");
    if (in == NULL) {
        printf("Error: failed to open input file.\n");
        exit(1);
    }

    out = fopen(output_file, "wb");
    if (out == NULL) {
        printf("Error: failed to open output file.\n");
        fclose(in);
        exit(2);
    }

    while ((len = fread(buffer, 1, BLOCK_SIZE, in)) > 0) {
        for (i = 0; i < len; i++) {
            buffer[i] ^= opt.key[i % KEY_SIZE];
        }
        fwrite(buffer, 1, len, out);
    }

    fclose(in);
    fclose(out);
}

void decrypt(char *input_file, char *output_file, char *key, int mode) {
    FILE *in, *out;
    Options opt;
    int i, j, len;
    char buffer[BLOCK_SIZE + 1];

    opt.mode = mode;
    strncpy(opt.key, key, KEY_SIZE);
    opt.key[KEY_SIZE - 1] = '\0';

    in = fopen(input_file, "rb");
    if (in == NULL) {
        printf("Error: failed to open input file.\n");
        exit(1);
    }

    out = fopen(output_file, "wb");
    if (out == NULL) {
        printf("Error: failed to open output file.\n");
        fclose(in);
        exit(2);
    }

    while ((len = fread(buffer, 1, BLOCK_SIZE, in)) > 0) {
        for (i = 0; i < len; i++) {
            buffer[i] ^= opt.key[i % KEY_SIZE];
        }
        fwrite(buffer, 1, len, out);
    }

    fclose(in);
    fclose(out);
}

int main(int argc, char *argv[]) {
    if (argc!= 6) {
        printf("Usage: %s [input_file] [output_file] [key] [mode]\n", argv[0]);
        printf("       [mode] = 1 for encryption, 0 for decryption\n");
        return 1;
    }

    Options opt;
    opt.mode = atoi(argv[4]);
    strncpy(opt.key, argv[3], KEY_SIZE);
    opt.key[KEY_SIZE - 1] = '\0';

    if (opt.mode == 1) {
        encrypt(argv[1], argv[2], opt.key, opt.mode);
    } else {
        decrypt(argv[1], argv[2], opt.key, opt.mode);
    }

    return 0;
}