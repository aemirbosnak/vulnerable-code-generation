//MISTRAL-7B DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <unistd.h>

#define KEY_SIZE 27
#define BUFFER_SIZE 1024

void key_gen(unsigned char key[]) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % CHAR_MAX;
    }
}

void encrypt_char(unsigned char plain_text, unsigned char key, unsigned char *encrypted_char) {
    *encrypted_char = plain_text ^ key;
}

void encrypt_string_recursive(unsigned char *plain_text, unsigned char *key, int length, unsigned char *encrypted_text) {
    if (length == 0) {
        *encrypted_text = '\0';
        return;
    }

    encrypt_char(*plain_text, *(key++), &(*encrypted_text));
    encrypt_string_recursive(plain_text + 1, key, length - 1, encrypted_text + 1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <plaintext> <key>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    unsigned char *plain_text = (unsigned char *)malloc(strlen(argv[1]) + 1);
    unsigned char *key = (unsigned char *)malloc(KEY_SIZE * sizeof(unsigned char));
    unsigned char *encrypted_text = (unsigned char *)calloc(strlen(argv[1]) + 1, sizeof(unsigned char));

    strcpy((char *)plain_text, argv[1]);

    key_gen(key);

    encrypt_string_recursive(plain_text, key, strlen(plain_text), encrypted_text);

    printf("Encrypted text: %s\n", encrypted_text);

    free(plain_text);
    free(key);
    free(encrypted_text);

    return EXIT_SUCCESS;
}