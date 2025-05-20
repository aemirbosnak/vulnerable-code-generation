//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 16
#define MAX_MESSAGE_SIZE 100
#define MAX_ENCRYPTED_SIZE (MAX_MESSAGE_SIZE + 1)

// XOR encryption function
void xor_encrypt(char* message, char* key, char* encrypted) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        encrypted[i] = message[i] ^ key[i % strlen(key)];
    }
    encrypted[strlen(message)] = '\0';
}

// XOR decryption function
void xor_decrypt(char* encrypted, char* key, char* decrypted) {
    int i;
    for (i = 0; i < strlen(encrypted); i++) {
        decrypted[i] = encrypted[i] ^ key[i % strlen(key)];
    }
    decrypted[strlen(encrypted)] = '\0';
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];
    char encrypted[MAX_ENCRYPTED_SIZE];
    char decrypted[MAX_MESSAGE_SIZE];

    // Get message and key from user
    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);
    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_SIZE, stdin);

    // Remove newline character from input
    message[strcspn(message, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    // Encrypt message
    xor_encrypt(message, key, encrypted);

    // Display encrypted message
    printf("Encrypted message: %s\n", encrypted);

    // Decrypt message
    xor_decrypt(encrypted, key, decrypted);

    // Display decrypted message
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}