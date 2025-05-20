//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "my_secret_key"

// Function to encrypt a string
char *encrypt(char *plaintext) {
    // Allocate memory for the ciphertext
    char *ciphertext = malloc(strlen(plaintext) + 1);

    // Iterate over each character in the plaintext
    for (int i = 0; i < strlen(plaintext); i++) {
        // Get the ASCII value of the current character
        int ascii_value = (int)plaintext[i];

        // Shift the ASCII value by the key
        ascii_value += (int)KEY[i % strlen(KEY)];

        // Wrap the ASCII value around if it goes beyond 255
        if (ascii_value > 255) ascii_value -= 256;

        // Convert the shifted ASCII value back to a character
        ciphertext[i] = (char)ascii_value;
    }

    // Terminate the ciphertext with a null character
    ciphertext[strlen(plaintext)] = '\0';

    // Return the ciphertext
    return ciphertext;
}

// Function to decrypt a string
char *decrypt(char *ciphertext) {
    // Allocate memory for the plaintext
    char *plaintext = malloc(strlen(ciphertext) + 1);

    // Iterate over each character in the ciphertext
    for (int i = 0; i < strlen(ciphertext); i++) {
        // Get the ASCII value of the current character
        int ascii_value = (int)ciphertext[i];

        // Shift the ASCII value by the key
        ascii_value -= (int)KEY[i % strlen(KEY)];

        // Wrap the ASCII value around if it goes below 0
        if (ascii_value < 0) ascii_value += 256;

        // Convert the shifted ASCII value back to a character
        plaintext[i] = (char)ascii_value;
    }

    // Terminate the plaintext with a null character
    plaintext[strlen(ciphertext)] = '\0';

    // Return the plaintext
    return plaintext;
}

// Main function
int main() {
    // Get the plaintext from the user
    char plaintext[] = "Hello, world!";

    // Encrypt the plaintext
    char *ciphertext = encrypt(plaintext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    char *decrypted_plaintext = decrypt(ciphertext);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}