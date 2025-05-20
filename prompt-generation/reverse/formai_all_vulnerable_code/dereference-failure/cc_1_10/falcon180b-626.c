//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LEN 1024
#define MAX_MSG_LEN 1024

// Function to generate a random key
void generate_key(char *key) {
    int i;
    for (i = 0; i < MAX_KEY_LEN; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_LEN - 1] = '\0';
}

// Function to encrypt the message using the key
void encrypt(char *message, char *key) {
    int i, j, len;
    char *cipher = (char *) malloc(MAX_MSG_LEN * sizeof(char));
    len = strlen(message);
    for (i = 0, j = 0; i < len; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                cipher[j] = 'A' + ((message[i] - 'A' + key[i % strlen(key)]) % 26);
            } else {
                cipher[j] = 'a' + ((message[i] - 'a' + key[i % strlen(key)]) % 26);
            }
        } else {
            cipher[j] = message[i];
        }
        j++;
    }
    cipher[j] = '\0';
    printf("Encrypted message: %s\n", cipher);
    free(cipher);
}

// Function to decrypt the message using the key
void decrypt(char *message, char *key) {
    int i, j, len;
    char *plaintext = (char *) malloc(MAX_MSG_LEN * sizeof(char));
    len = strlen(message);
    for (i = 0, j = 0; i < len; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                plaintext[j] = 'A' + (26 - ((message[i] - 'A' - key[i % strlen(key)]) % 26));
            } else {
                plaintext[j] = 'a' + (26 - ((message[i] - 'a' - key[i % strlen(key)]) % 26));
            }
        } else {
            plaintext[j] = message[i];
        }
        j++;
    }
    plaintext[j] = '\0';
    printf("Decrypted message: %s\n", plaintext);
    free(plaintext);
}

// Function to generate a random message
void generate_message(char *message) {
    int i;
    for (i = 0; i < MAX_MSG_LEN; i++) {
        message[i] = rand() % 26 + 'A';
    }
    message[MAX_MSG_LEN - 1] = '\0';
}

int main() {
    char *message, *key;
    srand(time(NULL));
    message = (char *) malloc(MAX_MSG_LEN * sizeof(char));
    key = (char *) malloc(MAX_KEY_LEN * sizeof(char));
    generate_message(message);
    generate_key(key);
    printf("Original message: %s\n", message);
    encrypt(message, key);
    decrypt(message, key);
    return 0;
}