//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 1024

// Generate a random key of length key_len
unsigned char* generate_key(int key_len) {
    unsigned char* key = malloc(key_len);
    for (int i = 0; i < key_len; i++) {
        key[i] = rand() % 256;
    }
    return key;
}

// Encrypt a message using a one-time pad
unsigned char* encrypt(unsigned char* message, unsigned char* key, int message_len) {
    unsigned char* ciphertext = malloc(message_len);
    for (int i = 0; i < message_len; i++) {
        ciphertext[i] = message[i] ^ key[i];
    }
    return ciphertext;
}

// Decrypt a message using a one-time pad
unsigned char* decrypt(unsigned char* ciphertext, unsigned char* key, int ciphertext_len) {
    unsigned char* message = malloc(ciphertext_len);
    for (int i = 0; i < ciphertext_len; i++) {
        message[i] = ciphertext[i] ^ key[i];
    }
    return message;
}

int main() {
    // Generate a random key
    int key_len = 16;
    unsigned char* key = generate_key(key_len);

    // Get the message from the user
    char message[MAX_BUF];
    printf("Enter the message to encrypt: ");
    fgets(message, MAX_BUF, stdin);

    // Encrypt the message
    int message_len = strlen(message);
    unsigned char* ciphertext = encrypt((unsigned char*)message, key, message_len);

    // Print the ciphertext
    printf("Encrypted message: ");
    for (int i = 0; i < message_len; i++) {
        printf("%02X", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the message
    unsigned char* decrypted_message = decrypt(ciphertext, key, message_len);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    // Free the allocated memory
    free(key);
    free(ciphertext);
    free(decrypted_message);

    return 0;
}