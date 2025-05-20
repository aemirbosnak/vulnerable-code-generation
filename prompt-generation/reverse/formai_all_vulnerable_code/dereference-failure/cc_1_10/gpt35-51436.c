//FormAI DATASET v1.0 Category: Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

/** Function declarations **/
void encrypt(char *key, char *message);
void decrypt(char *key, char *cipher);

/** Main function **/
int main(int argc, char **argv) {
    char key[MAX_LENGTH];
    char message[MAX_LENGTH];
    char cipher[MAX_LENGTH];
    
    // Ensure proper usage
    if (argc != 3) {
        printf("Usage: ./encryption key message\n");
        exit(1);
    }

    // Get key and message from arguments
    strcpy(key, argv[1]);
    strcpy(message, argv[2]);

    printf("Original message: %s\n", message);
    
    // Encrypt message
    encrypt(key, message);
    printf("Encrypted message: %s\n", message);

    // Decrypt cipher
    decrypt(key, message);
    printf("Decrypted message: %s\n", message);

    return 0;
}

/**
 * Function to encrypt a message using a given key.
 */
void encrypt(char *key, char *message) {
    int key_len = strlen(key);
    int msg_len = strlen(message);

    for (int i = 0; i < msg_len; i++) {
        message[i] = ((message[i] + key[i % key_len]) % 128);
    }
}

/**
 * Function to decrypt a cipher using a given key.
 */
void decrypt(char *key, char *cipher) {
    int key_len = strlen(key);
    int cipher_len = strlen(cipher);

    for (int i = 0; i < cipher_len; i++) {
        cipher[i] = ((cipher[i] - key[i % key_len] + 128) % 128);
    }
}