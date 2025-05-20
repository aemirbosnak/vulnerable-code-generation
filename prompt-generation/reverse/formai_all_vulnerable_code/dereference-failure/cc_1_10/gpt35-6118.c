//FormAI DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Encrypt function
void encrypt(char* message, char* key) {
    int message_len = strlen(message);
    int key_len = strlen(key);

    int i, j;
    for (i = 0, j = 0; i < message_len; ++i, ++j) {
        if (j == key_len) {
            j = 0;
        }
        message[i] = ((message[i] + key[j]) % 26) + 'A';
    }
}

// Decrypt function
void decrypt(char* message, char* key) {
    int message_len = strlen(message);
    int key_len = strlen(key);

    int i, j;
    for (i = 0, j = 0; i < message_len; ++i, ++j) {
        if (j == key_len) {
            j = 0;
        }
        message[i] = (((message[i] - 'A') - key[j] + 26) % 26) + 'A';
    }
}

// Main function
int main() {
    printf("*****************************************\n");
    printf("Welcome to the Artistic Encryption Program\n");
    printf("*****************************************\n");

    char message[50], key[10];
    printf("\nPlease enter your message (max 50 characters): ");
    fgets(message, 50, stdin);
    printf("Please enter your key (max 10 characters): ");
    fgets(key, 10, stdin);

    // Remove newline character from fgets
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    printf("\n\nEncrypting your message...\n");
    encrypt(message, key);
    printf("\nEncrypted message: %s\n", message);

    printf("\nDecrypting your message...\n");
    decrypt(message, key);
    printf("\nDecrypted message: %s\n", message);

    printf("\nThanks for using the Artistic Encryption Program :)\n");

    return 0;
}