//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

void encode(const char *filename, const char *message) {
    FILE *f = fopen(filename, "rb+");
    if (!f) {
        perror("fopen");
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    byte *data = malloc(size);
    fread(data, 1, size, f);

    int i = 0;
    for (const char *c = message; *c; c++) {
        for (int j = 7; j >= 0; j--) {
            data[i] ^= (*c >> j) & 1;
            i++;
        }
    }

    fseek(f, 0, SEEK_SET);
    fwrite(data, 1, size, f);

    fclose(f);
    free(data);
}

void decode(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("fopen");
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    byte *data = malloc(size);
    fread(data, 1, size, f);

    int i = 0;
    char c = 0;
    while (i < size) {
        for (int j = 7; j >= 0; j--) {
            c |= (data[i] & 1) << j;
            i++;
        }

        if (!c)
            break;

        putchar(c);
        c = 0;
    }

    fclose(f);
    free(data);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <encode/decode> <filename> [message]\n", argv[0]);
        exit(1);
    }

    if (!strcmp(argv[1], "encode")) {
        if (argc < 4) {
            fprintf(stderr, "Usage: %s <encode> <filename> <message>\n", argv[0]);
            exit(1);
        }

        encode(argv[2], argv[3]);
    } else if (!strcmp(argv[1], "decode")) {
        decode(argv[2]);
    } else {
        fprintf(stderr, "Invalid command: %s\n", argv[1]);
        exit(1);
    }

    return 0;
}