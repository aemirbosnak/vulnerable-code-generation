//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 16

// Function to generate a random key
void generateKey() {
    char key[KEY_SIZE];
    int i;

    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = (char) rand() % 26 + 'A';
    }
    printf("Generated key: %s\n", key);
}

// Function to encrypt a string
void encrypt(char* str, char* key) {
    int i, j;
    char cipher[strlen(str) + KEY_SIZE - 1];
    int keyIndex = 0;

    for (i = 0; i < strlen(str); i++) {
        cipher[i] = str[i];
    }

    for (j = 0; j < strlen(str); j++) {
        int index = (int) str[j] - 97;
        cipher[j] = (char) (cipher[j] ^ key[keyIndex++]);
    }

    cipher[strlen(str)] = '\0';
    printf("Encrypted message: %s\n", cipher);
}

// Function to decrypt a string
void decrypt(char* str, char* key) {
    int i, j;
    char plaintext[strlen(str) + KEY_SIZE - 1];
    int keyIndex = 0;

    for (i = 0; i < strlen(str); i++) {
        plaintext[i] = str[i];
    }

    for (j = 0; j < strlen(str); j++) {
        int index = (int) str[j] - 97;
        plaintext[j] = (char) (plaintext[j] ^ key[keyIndex++]);
    }

    plaintext[strlen(str)] = '\0';
    printf("Decrypted message: %s\n", plaintext);
}

int main() {
    generateKey();
    char str[] = "This is a secret message";
    char key[] = "ThisIsTheKey";

    encrypt(str, key);
    decrypt(str, key);

    return 0;
}