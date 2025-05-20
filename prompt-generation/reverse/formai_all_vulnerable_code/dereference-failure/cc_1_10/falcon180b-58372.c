//Falcon-180B DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000
#define KEY_SIZE 16
#define ENCRYPT 1
#define DECRYPT 2

// Function to encrypt/decrypt the message
void encrypt_decrypt(char *message, int mode, char *key) {
    int i, j, n;
    char *result = malloc(MAX_SIZE);
    char *key_ptr = malloc(KEY_SIZE);

    if (result == NULL || key_ptr == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    // Copy the key into the key buffer
    for (i = 0; i < KEY_SIZE; i++) {
        key_ptr[i] = tolower(key[i]);
    }

    // XOR the message with the key
    n = strlen(message);
    for (i = 0; i < n; i++) {
        result[i] = message[i] ^ key_ptr[i % KEY_SIZE];
    }

    // Print the result
    if (mode == ENCRYPT) {
        printf("Encrypted message: %s\n", result);
    } else {
        printf("Decrypted message: %s\n", result);
    }

    free(result);
    free(key_ptr);
}

int main() {
    char message[MAX_SIZE];
    char key[KEY_SIZE];
    int mode;

    // Get the message from the user
    printf("Enter the message to be (e)ncrypted or (d)ecrypted: ");
    fgets(message, MAX_SIZE, stdin);

    // Get the key from the user
    printf("Enter the encryption/decryption key: ");
    fgets(key, KEY_SIZE, stdin);

    // Get the mode from the user
    printf("Enter the mode (e)ncrypt or (d)ecrypt: ");
    scanf("%d", &mode);

    // Encrypt/decrypt the message
    encrypt_decrypt(message, mode, key);

    return 0;
}