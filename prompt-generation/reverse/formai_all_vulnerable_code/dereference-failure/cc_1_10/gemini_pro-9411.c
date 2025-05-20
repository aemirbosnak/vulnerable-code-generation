//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 32

// Generate a random key of the specified length
unsigned char *generate_key(int key_len) {
    unsigned char *key = malloc(key_len);
    for (int i = 0; i < key_len; i++) {
        key[i] = rand() % 256;
    }
    return key;
}

// Encrypt a message using the XOR cipher
unsigned char *encrypt_xor(unsigned char *plaintext, int plaintext_len, unsigned char *key, int key_len) {
    unsigned char *ciphertext = malloc(plaintext_len);
    for (int i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }
    return ciphertext;
}

// Decrypt a message using the XOR cipher
unsigned char *decrypt_xor(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, int key_len) {
    unsigned char *plaintext = malloc(ciphertext_len);
    for (int i = 0; i < ciphertext_len; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % key_len];
    }
    return plaintext;
}

int main() {
    // Generate a random key of length 16
    int key_len = 16;
    unsigned char *key = generate_key(key_len);

    // Get the plaintext from the user
    char plaintext[1024];
    printf("Enter the plaintext: ");
    gets(plaintext);

    // Encrypt the plaintext using the XOR cipher
    int plaintext_len = strlen(plaintext);
    unsigned char *ciphertext = encrypt_xor((unsigned char *)plaintext, plaintext_len, key, key_len);

    // Print the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < plaintext_len; i++) {
        printf("%02X", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the ciphertext using the XOR cipher
    unsigned char *decrypted_plaintext = decrypt_xor(ciphertext, plaintext_len, key, key_len);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(key);
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}