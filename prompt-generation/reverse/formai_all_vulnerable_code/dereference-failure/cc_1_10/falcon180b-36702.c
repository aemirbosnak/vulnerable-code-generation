//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt a string using the Caesar cipher
char* encrypt(char* message, int key) {
    int length = strlen(message);
    char* encrypted = (char*)malloc(length + 1);
    memset(encrypted, 0, length + 1);

    for (int i = 0; i < length; i++) {
        char c = message[i];

        if (c >= 'a' && c <= 'z') {
            encrypted[i] = ((c - 'a' + key) % 26) + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            encrypted[i] = ((c - 'A' + key) % 26) + 'A';
        } else {
            encrypted[i] = c;
        }
    }

    return encrypted;
}

// Function to decrypt a string using the Caesar cipher
char* decrypt(char* message, int key) {
    int length = strlen(message);
    char* decrypted = (char*)malloc(length + 1);
    memset(decrypted, 0, length + 1);

    for (int i = 0; i < length; i++) {
        char c = message[i];

        if (c >= 'a' && c <= 'z') {
            decrypted[i] = ((c - 'a' - key + 26) % 26) + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            decrypted[i] = ((c - 'A' - key + 26) % 26) + 'A';
        } else {
            decrypted[i] = c;
        }
    }

    return decrypted;
}

int main() {
    char* message = "This is a secret message!";
    int key = 13;

    // Encrypt the message
    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);

    // Decrypt the message
    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);

    free(encrypted);
    free(decrypted);

    return 0;
}