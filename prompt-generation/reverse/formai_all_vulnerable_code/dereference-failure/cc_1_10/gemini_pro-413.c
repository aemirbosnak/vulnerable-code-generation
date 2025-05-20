//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT 1
#define DECRYPT 0

void print_usage(char *argv[]) {
    printf("Usage: %s {-e | -d} <key> <plaintext/ciphertext>\n", argv[0]);
    printf("Options:\n");
    printf("  -e  Encrypt plaintext using the given key\n");
    printf("  -d  Decrypt ciphertext using the given key\n");
    printf("Key: A sequence of lowercase English letters (a-z)\n");
    printf("Plaintext/ciphertext: A string of uppercase English letters (A-Z)\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv);
    }

    int mode;
    if (strcmp(argv[1], "-e") == 0) {
        mode = ENCRYPT;
    } else if (strcmp(argv[1], "-d") == 0) {
        mode = DECRYPT;
    } else {
        print_usage(argv);
    }

    char *key = argv[2];
    char *plaintext = argv[3];

    int key_length = strlen(key);
    int plaintext_length = strlen(plaintext);

    if (key_length != plaintext_length) {
        fprintf(stderr, "Key and plaintext must be of equal length\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < key_length; i++) {
        if (key[i] < 'a' || key[i] > 'z') {
            fprintf(stderr, "Key must contain only lowercase English letters (a-z)\n");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < plaintext_length; i++) {
        if (plaintext[i] < 'A' || plaintext[i] > 'Z') {
            fprintf(stderr, "Plaintext must contain only uppercase English letters (A-Z)\n");
            exit(EXIT_FAILURE);
        }
    }

    char *ciphertext = calloc(plaintext_length + 1, sizeof(char));

    for (int i = 0; i < plaintext_length; i++) {
        int shift = key[i] - 'a';
        if (mode == ENCRYPT) {
            ciphertext[i] = (plaintext[i] - 'A' + shift) % 26 + 'A';
        } else if (mode == DECRYPT) {
            ciphertext[i] = (plaintext[i] - 'A' - shift + 26) % 26 + 'A';
        }
    }

    printf("%s\n", ciphertext);

    free(ciphertext);

    return 0;
}