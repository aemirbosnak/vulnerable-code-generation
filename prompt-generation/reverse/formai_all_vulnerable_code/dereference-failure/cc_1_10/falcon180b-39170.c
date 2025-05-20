//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the Alien language alphabet
#define ALIEN_ALPHABET_SIZE 26
char alien_alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l','m', 'n', 'o', 'p', 'q', 'r','s', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void generate_key(char *key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = alien_alphabet[rand() % ALIEN_ALPHABET_SIZE];
    }
}

void encrypt(char *message, char *key, char *ciphertext) {
    for (int i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            int index = message[i] - 'a';
            ciphertext[i] = key[(index + key[0] - 'a') % ALIEN_ALPHABET_SIZE];
        } else {
            ciphertext[i] = message[i];
        }
    }
    ciphertext[strlen(message)] = '\0';
}

void decrypt(char *ciphertext, char *key, char *message) {
    for (int i = 0; ciphertext[i]!= '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            int index = ciphertext[i] - 'a';
            message[i] = 'a' + ((index - key[0] - 1) % ALIEN_ALPHABET_SIZE + 26) % 26;
        } else {
            message[i] = ciphertext[i];
        }
    }
    message[strlen(ciphertext)] = '\0';
}

int main() {
    char message[1000] = "Hello, world!";
    char key[26];

    generate_key(key, ALIEN_ALPHABET_SIZE);

    char ciphertext[1000];
    encrypt(message, key, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    char decrypted_message[1000];
    decrypt(ciphertext, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}