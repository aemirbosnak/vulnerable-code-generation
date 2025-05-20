//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our very own encryption function
char *encrypt(char *plaintext, char *key) {
    // Allocate memory for the ciphertext
    char *ciphertext = malloc(strlen(plaintext) + 1);

    // Loop through each character in the plaintext
    for (int i = 0; i < strlen(plaintext); i++) {
        // Encrypt the character using the key
        ciphertext[i] = plaintext[i] ^ key[i % strlen(key)];
    }

    // Terminate the ciphertext with a null character
    ciphertext[strlen(plaintext)] = '\0';

    // Return the ciphertext
    return ciphertext;
}

// Our very own decryption function
char *decrypt(char *ciphertext, char *key) {
    // Allocate memory for the plaintext
    char *plaintext = malloc(strlen(ciphertext) + 1);

    // Loop through each character in the ciphertext
    for (int i = 0; i < strlen(ciphertext); i++) {
        // Decrypt the character using the key
        plaintext[i] = ciphertext[i] ^ key[i % strlen(key)];
    }

    // Terminate the plaintext with a null character
    plaintext[strlen(ciphertext)] = '\0';

    // Return the plaintext
    return plaintext;
}

// Our main function
int main() {
    // Get the plaintext from the user
    char plaintext[] = "Hello, world!";

    // Get the key from the user
    char key[] = "secret";

    // Encrypt the plaintext using the key
    char *ciphertext = encrypt(plaintext, key);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the key
    char *decryptedText = decrypt(ciphertext, key);

    // Print the decrypted text
    printf("Decrypted text: %s\n", decryptedText);

    // Free the memory allocated for the ciphertext and the decrypted text
    free(ciphertext);
    free(decryptedText);

    return 0;
}