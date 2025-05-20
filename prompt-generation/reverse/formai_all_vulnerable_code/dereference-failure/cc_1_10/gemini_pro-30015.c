//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_KEY_LENGTH 256
#define MAX_TEXT_LENGTH 1024

// Generate a random key of the specified length.
unsigned char *generate_key(int length) {
    unsigned char *key = malloc(length);
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 256;
    }
    return key;
}

// Encrypt the specified text using the specified key.
unsigned char *encrypt(unsigned char *text, unsigned char *key, int length) {
    unsigned char *ciphertext = malloc(length);
    for (int i = 0; i < length; i++) {
        ciphertext[i] = text[i] ^ key[i];
    }
    return ciphertext;
}

// Decrypt the specified ciphertext using the specified key.
unsigned char *decrypt(unsigned char *ciphertext, unsigned char *key, int length) {
    unsigned char *plaintext = malloc(length);
    for (int i = 0; i < length; i++) {
        plaintext[i] = ciphertext[i] ^ key[i];
    }
    return plaintext;
}

// Print the specified text to the console.
void print_text(unsigned char *text, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", text[i]);
    }
}

int main() {
    // Get the text to be encrypted from the user.
    unsigned char *text = malloc(MAX_TEXT_LENGTH);
    printf("Enter the text to be encrypted: ");
    scanf("%s", text);

    // Generate a random key.
    unsigned char *key = generate_key(strlen(text));

    // Encrypt the text using the key.
    unsigned char *ciphertext = encrypt(text, key, strlen(text));

    // Print the ciphertext to the console.
    printf("Encrypted text: ");
    print_text(ciphertext, strlen(text));
    printf("\n");

    // Decrypt the ciphertext using the key.
    unsigned char *plaintext = decrypt(ciphertext, key, strlen(text));

    // Print the plaintext to the console.
    printf("Decrypted text: ");
    print_text(plaintext, strlen(text));
    printf("\n");

    // Free the allocated memory.
    free(text);
    free(key);
    free(ciphertext);
    free(plaintext);

    return 0;
}