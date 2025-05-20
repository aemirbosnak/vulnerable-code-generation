//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 25
#define BUFFER_SIZE 1024
#define ALPHABET_SIZE 26

void rotate_left(char *str, int shift) {
    char temp;
    int i;

    for (i = 0; i < strlen(str) - shift; i++) {
        temp = *(str + i);
        *(str + i) = *(str + i + shift);
        *(str + i + shift) = temp;
    }

    if (strlen(str) < shift) {
        memmove(str, str + shift, strlen(str));
    }
}

int main(int argc, char *argv[]) {
    char *key, *plaintext, *ciphertext;
    int i, j, k;
    char key_char[KEY_SIZE + 1];
    char plaintext_char[BUFFER_SIZE + 1];
    char ciphertext_char[BUFFER_SIZE + 1];
    char encrypted_char[ALPHABET_SIZE];
    char encrypted_char_inv[ALPHABET_SIZE];

    if (argc != 3) {
        printf("Usage: %s <key> <plaintext>\n", argv[0]);
        exit(1);
    }

    key = argv[1];
    plaintext = argv[2];

    if (strlen(key) != KEY_SIZE) {
        printf("Error: Key must be exactly %d characters long.\n", KEY_SIZE);
        exit(1);
    }

    strcpy(key_char, key);
    rotate_left(key_char, 1);

    strcpy(plaintext_char, plaintext);

    for (i = 0; i < ALPHABET_SIZE; i++) {
        encrypted_char[i] = i + 'A';
        encrypted_char_inv[encrypted_char[i]] = i;
    }

    for (i = 0, j = 0; i < strlen(plaintext_char) && j < strlen(plaintext_char); i++) {
        char current_char = plaintext_char[i];
        char key_char_index = key_char[i % KEY_SIZE];

        ciphertext_char[j++] = encrypted_char[((encrypted_char_inv[current_char] + key_char_index - 'A') % ALPHABET_SIZE)];
    }

    ciphertext_char[j] = '\0';

    printf("Plaintext: %s\n", plaintext_char);
    printf("Key: %s\n", key_char);
    printf("Ciphertext: %s\n", ciphertext_char);

    return 0;
}