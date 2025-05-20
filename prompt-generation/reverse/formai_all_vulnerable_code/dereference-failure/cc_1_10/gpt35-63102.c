//FormAI DATASET v1.0 Category: Encryption ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

char *encrypt(char *plaintext, char *key);
char *decrypt(char *ciphertext, char *key);

int main(int argc, char **argv) {

    if (argc != 4) {
        printf("Usage: %s [--encrypt | --decrypt] [text] [key]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *text = argv[2];
    char *key = argv[3];

    if (strcmp(argv[1], "--encrypt") == 0) {
        char *cipher = encrypt(text, key);
        printf("%s\n", cipher);
        free(cipher);
    } else if (strcmp(argv[1], "--decrypt") == 0) {
        char *plain = decrypt(text, key);
        printf("%s\n", plain);
        free(plain);
    } else {
        printf("Usage: %s [--encrypt | --decrypt] [text] [key]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    return 0;
}

char *encrypt(char *plaintext, char *key) {

    int plaintext_length = strlen(plaintext);
    int key_length = strlen(key);
    int padded_length = plaintext_length + (plaintext_length % key_length);
    char *padded_plaintext = (char *) calloc(padded_length + 1, sizeof(char));
    strncpy(padded_plaintext, plaintext, plaintext_length);

    int i;
    for (i = plaintext_length; i < padded_length; i++) {
        padded_plaintext[i] = ' ';
    }

    char *ciphertext = (char *) calloc(padded_length + 1, sizeof(char));
    int j;
    for (i = 0; i < key_length; i++) {
        for (j = i; j < padded_length; j += key_length) {
            ciphertext[j] = ((padded_plaintext[j] - 'a' + key[i] - 'a') % 26) + 'a';
        }
    }

    free(padded_plaintext);
    return ciphertext;
}

char *decrypt(char *ciphertext, char *key) {

    int ciphertext_length = strlen(ciphertext);
    int key_length = strlen(key);

    char *plaintext = (char *) calloc(ciphertext_length + 1, sizeof(char));
    int i;
    for (i = 0; i < key_length; i++) {
        int j;
        for (j = i; j < ciphertext_length; j += key_length) {
            plaintext[j] = ((((ciphertext[j] - 'a') - (key[i] - 'a')) % 26) + 26) % 26 + 'a';
        }
    }

    return plaintext;
}