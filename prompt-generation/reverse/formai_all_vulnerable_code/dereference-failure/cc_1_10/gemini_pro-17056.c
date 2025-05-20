//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string using a key
// The key is a 26-character string containing the alphabet in scrambled order
char* encrypt(char* plaintext, char* key) {
    char* ciphertext = malloc(strlen(plaintext) + 1);
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        char c = plaintext[i];
        int index = c - 'a';
        if (index < 0 || index >= 26) {
            ciphertext[i] = c;
        } else {
            ciphertext[i] = key[index];
        }
    }
    ciphertext[i] = '\0';
    return ciphertext;
}

// Function to decrypt a string using a key
// The key is the same as the one used to encrypt the string
char* decrypt(char* ciphertext, char* key) {
    char* plaintext = malloc(strlen(ciphertext) + 1);
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        char c = ciphertext[i];
        int index = strchr(key, c) - key;
        if (index < 0 || index >= 26) {
            plaintext[i] = c;
        } else {
            plaintext[i] = index + 'a';
        }
    }
    plaintext[i] = '\0';
    return plaintext;
}

// Main function
int main() {
    // The key is a scrambled alphabet
    char* key = "zyxwvutsrqponmlkjihgfedcba";

    // The plaintext is a message to be encrypted
    char* plaintext = "Hello, world!";

    // Encrypt the plaintext using the key
    char* ciphertext = encrypt(plaintext, key);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the key
    char* decryptedtext = decrypt(ciphertext, key);

    // Print the decrypted text
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}