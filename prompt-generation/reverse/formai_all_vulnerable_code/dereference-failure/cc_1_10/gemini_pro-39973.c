//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom XOR function
unsigned char custom_xor(unsigned char a, unsigned char b) {
    return (a ^ b);
}

// Custom encryption function
void custom_encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, int key_len, unsigned char *ciphertext) {
    for (int i = 0; i < plaintext_len; i++) {
        ciphertext[i] = custom_xor(plaintext[i], key[i % key_len]);
    }
}

// Custom decryption function
void custom_decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, int key_len, unsigned char *plaintext) {
    for (int i = 0; i < ciphertext_len; i++) {
        plaintext[i] = custom_xor(ciphertext[i], key[i % key_len]);
    }
}

int main() {
    // Define the plaintext and key
    char plaintext[] = "This is a secret message.";
    char key[] = "My secret key";

    // Get the lengths of the plaintext and key
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);

    // Allocate memory for the ciphertext
    unsigned char *ciphertext = malloc(plaintext_len);

    // Encrypt the plaintext using the custom encryption function
    custom_encrypt((unsigned char *)plaintext, plaintext_len, (unsigned char *)key, key_len, ciphertext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the custom decryption function
    unsigned char *decrypted_plaintext = malloc(plaintext_len);
    custom_decrypt(ciphertext, plaintext_len, (unsigned char *)key, key_len, decrypted_plaintext);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}