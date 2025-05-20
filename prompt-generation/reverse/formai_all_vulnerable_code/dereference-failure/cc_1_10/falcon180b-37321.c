//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char *generate_key(int key_size) {
    char *key = (char *)malloc(key_size * sizeof(char));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    return key;
}

void encrypt(char *message, char *key, char *ciphertext) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;
    for (i = 0, j = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                ciphertext[j] = 'A' + ((message[i] - 'A' + key[j % key_length] - 'A') % 26);
            } else {
                ciphertext[j] = 'a' + ((message[i] - 'a' + key[j % key_length] - 'a') % 26);
            }
            j++;
        } else {
            ciphertext[j] = message[i];
            j++;
        }
    }
    ciphertext[j] = '\0';
}

void decrypt(char *ciphertext, char *key, char *message) {
    int ciphertext_length = strlen(ciphertext);
    int key_length = strlen(key);
    int i, j;
    for (i = 0, j = 0; i < ciphertext_length; i++) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                message[j] = 'A' + ((ciphertext[i] - 'A' - key[j % key_length] + 26) % 26);
            } else {
                message[j] = 'a' + ((ciphertext[i] - 'a' - key[j % key_length] + 26) % 26);
            }
            j++;
        } else {
            message[j] = ciphertext[i];
            j++;
        }
    }
    message[j] = '\0';
}

int main() {
    srand(time(NULL));
    int key_size = 10;
    char *key = generate_key(key_size);
    char message[100] = "Hello, World!";
    char ciphertext[100];
    encrypt(message, key, ciphertext);
    printf("Encrypted message: %s\n", ciphertext);
    decrypt(ciphertext, key, message);
    printf("Decrypted message: %s\n", message);
    return 0;
}