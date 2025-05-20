//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16

void encrypt(char *message, char *key) {
    int i, j, k, n;
    char ciphertext[1000];
    char *encryption_table = malloc(256 * sizeof(char));

    for (i = 0; i < KEY_SIZE; i++) {
        encryption_table[i] = toupper(key[i]);
    }

    for (i = KEY_SIZE; i < 256; i++) {
        encryption_table[i] = 'Z';
    }

    n = strlen(message);
    for (i = 0, j = 0; i < n; i++) {
        if (isalpha(message[i])) {
            k = toupper(message[i]) - 65;
            ciphertext[j++] = encryption_table[k + (i % KEY_SIZE)];
        } else {
            ciphertext[j++] = message[i];
        }
    }

    ciphertext[j] = '\0';
    printf("Encrypted message: %s\n", ciphertext);
}

void decrypt(char *ciphertext, char *key) {
    int i, j, k, n;
    char message[1000];
    char *decryption_table = malloc(256 * sizeof(char));

    for (i = 0; i < KEY_SIZE; i++) {
        decryption_table[toupper(key[i]) - 65] = i;
    }

    n = strlen(ciphertext);
    for (i = 0, j = 0; i < n; i++) {
        if (isalpha(ciphertext[i])) {
            k = decryption_table[toupper(ciphertext[i]) - 65];
            message[j++] = k % 26 + 65;
        } else {
            message[j++] = ciphertext[i];
        }
    }

    message[j] = '\0';
    printf("Decrypted message: %s\n", message);
}

int main() {
    char message[1000], key[KEY_SIZE];
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}