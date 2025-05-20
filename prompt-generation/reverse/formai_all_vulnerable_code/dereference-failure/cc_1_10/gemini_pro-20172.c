//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom XOR encryption function
char *xor_encrypt(char *plaintext, char *key) {
    // Calculate the length of the plaintext and key
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);

    // Create a buffer to store the encrypted ciphertext
    char *ciphertext = malloc(plaintext_len + 1);

    // Iterate over each character in the plaintext
    for (int i = 0; i < plaintext_len; i++) {
        // Perform XOR encryption using the corresponding character from the key
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }

    // Null-terminate the ciphertext
    ciphertext[plaintext_len] = '\0';

    // Return the encrypted ciphertext
    return ciphertext;
}

// Define a custom XOR decryption function
char *xor_decrypt(char *ciphertext, char *key) {
    // Calculate the length of the ciphertext and key
    int ciphertext_len = strlen(ciphertext);
    int key_len = strlen(key);

    // Create a buffer to store the decrypted plaintext
    char *plaintext = malloc(ciphertext_len + 1);

    // Iterate over each character in the ciphertext
    for (int i = 0; i < ciphertext_len; i++) {
        // Perform XOR decryption using the corresponding character from the key
        plaintext[i] = ciphertext[i] ^ key[i % key_len];
    }

    // Null-terminate the plaintext
    plaintext[ciphertext_len] = '\0';

    // Return the decrypted plaintext
    return plaintext;
}

int main() {
    // Define the plaintext message to be encrypted
    char *plaintext = "This is a secret message.";

    // Define the encryption key
    char *key = "my_secret_key";

    // Encrypt the plaintext using the XOR encryption function
    char *ciphertext = xor_encrypt(plaintext, key);

    // Print the encrypted ciphertext
    printf("Encrypted ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the XOR decryption function
    char *decrypted_plaintext = xor_decrypt(ciphertext, key);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory for the ciphertext and decrypted plaintext
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}