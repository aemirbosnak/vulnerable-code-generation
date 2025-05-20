//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string using a Caesar cipher
char* encrypt(char* plaintext, int key) {
    int length = strlen(plaintext);
    char* ciphertext = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        ciphertext[i] = (plaintext[i] + key) % 26 + 'a';
    }
    ciphertext[length] = '\0';
    return ciphertext;
}

// Function to decrypt a string using a Caesar cipher
char* decrypt(char* ciphertext, int key) {
    int length = strlen(ciphertext);
    char* plaintext = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        plaintext[i] = (ciphertext[i] - key) % 26 + 'a';
    }
    plaintext[length] = '\0';
    return plaintext;
}

// Function to generate a random key for the Caesar cipher
int generate_key() {
    return rand() % 26;
}

int main() {
    // Generate a random key
    int key = generate_key();

    // Get the plaintext from the user
    char plaintext[100];
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    // Encrypt the plaintext using the Caesar cipher
    char* ciphertext = encrypt(plaintext, key);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the Caesar cipher
    char* decrypted_plaintext = decrypt(ciphertext, key);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}