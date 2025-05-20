//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the given text using the given key
char* encrypt(char* text, char* key) {
    int text_len = strlen(text);
    int key_len = strlen(key);
    char* encrypted_text = malloc(text_len + 1);

    for (int i = 0; i < text_len; i++) {
        encrypted_text[i] = text[i] ^ key[i % key_len];
    }

    encrypted_text[text_len] = '\0';
    return encrypted_text;
}

// Function to decrypt the given text using the given key
char* decrypt(char* text, char* key) {
    int text_len = strlen(text);
    int key_len = strlen(key);
    char* decrypted_text = malloc(text_len + 1);

    for (int i = 0; i < text_len; i++) {
        decrypted_text[i] = text[i] ^ key[i % key_len];
    }

    decrypted_text[text_len] = '\0';
    return decrypted_text;
}

// Main function
int main() {
    // Get the text and key from the user
    char text[100];
    char key[100];
    printf("Enter the text to be encrypted: ");
    scanf("%s", text);
    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the text using the given key
    char* encrypted_text = encrypt(text, key);

    // Print the encrypted text
    printf("Encrypted text: %s\n", encrypted_text);

    // Decrypt the encrypted text using the given key
    char* decrypted_text = decrypt(encrypted_text, key);

    // Print the decrypted text
    printf("Decrypted text: %s\n", decrypted_text);

    // Free the allocated memory
    free(encrypted_text);
    free(decrypted_text);

    return 0;
}