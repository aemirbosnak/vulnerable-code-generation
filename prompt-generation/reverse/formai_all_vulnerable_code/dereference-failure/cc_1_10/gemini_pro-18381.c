//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: happy
// Let's Encrypt a Secret Message with AES!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

// Our happy passphrase that will magically transform our message
unsigned char* passphrase = "SuperSecretPassphrase123";

// Function to encrypt our precious message
unsigned char* encrypt(unsigned char* message, int message_len) {
    unsigned char* encrypted_message = (unsigned char*)malloc(message_len + AES_BLOCK_SIZE);

    // Initialize our AES context with our happy passphrase
    AES_KEY aes_key;
    AES_set_encrypt_key(passphrase, 128, &aes_key);

    // Encrypt 16 bytes at a time
    int padded_message_len = ((message_len + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    for (int i = 0; i < padded_message_len; i += AES_BLOCK_SIZE) {
        AES_encrypt(message + i, encrypted_message + i, &aes_key);
    }

    return encrypted_message;
}

// Function to decrypt our secret message
unsigned char* decrypt(unsigned char* encrypted_message, int encrypted_message_len) {
    unsigned char* decrypted_message = (unsigned char*)malloc(encrypted_message_len);

    // Initialize our AES context with our happy passphrase
    AES_KEY aes_key;
    AES_set_decrypt_key(passphrase, 128, &aes_key);

    // Decrypt 16 bytes at a time
    int padded_encrypted_message_len = ((encrypted_message_len + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    for (int i = 0; i < padded_encrypted_message_len; i += AES_BLOCK_SIZE) {
        AES_decrypt(encrypted_message + i, decrypted_message + i, &aes_key);
    }

    return decrypted_message;
}

int main() {
    // Our super secret message to encrypt
    unsigned char* message = "This is our precious secret message!";

    // Encrypt our message with AES
    unsigned char* encrypted_message = encrypt(message, strlen(message));

    // Decrypt the encrypted message
    unsigned char* decrypted_message = decrypt(encrypted_message, strlen(encrypted_message));

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    // Clean up
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}