//FormAI DATASET v1.0 Category: Modern Encryption ; Style: lively
#include <stdio.h>
#include <string.h>

/**
 * A function to encrypt a given string with the modern encryption algorithm
 *
 * @param plain_text - The plain text to be encrypted
 * @param key - The secret key used for encryption
 *
 * @return - The encrypted string
 */
char* modern_encrypt(char* plain_text, char* key) {
    int key_len = strlen(key);
    int text_len = strlen(plain_text);
    char encrypted[text_len];

    // Perform encryption operation on each character in the plain text
    for (int i = 0; i < text_len; ++i) {
        encrypted[i] = plain_text[i] ^ key[(i % key_len)];
    }

    // Allocate memory to store the encrypted text
    char* encrypted_text = (char*) malloc(text_len * sizeof(char));

    if (encrypted_text == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(0);
    }

    // Copy the encrypted text to the allocated memory
    strcpy(encrypted_text, encrypted);

    return encrypted_text;
}

int main() {
    char* plain_text = "Hello, World!";
    char* key = "my_secret_key_123";

    printf("Plain Text: %s\n", plain_text);

    // Encrypt the plain text
    char* encrypted_text = modern_encrypt(plain_text, key);

    printf("Encrypted Text: %s\n", encrypted_text);

    free(encrypted_text); // Free memory allocated to encrypted_text

    return 0;
}