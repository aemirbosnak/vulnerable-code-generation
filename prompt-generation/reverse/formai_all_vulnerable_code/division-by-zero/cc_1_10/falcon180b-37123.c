//Falcon-180B DATASET v1.0 Category: Encryption ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 256
#define MAX_TEXT_SIZE 1000

// Function to encrypt the given text using the given key
void encrypt(char* text, char* key) {
    int i, j, k;
    int key_index = 0;
    char encrypted_text[MAX_TEXT_SIZE];

    // Initialize the encrypted text
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            encrypted_text[i] = text[i] + key[key_index];
        } else {
            encrypted_text[i] = text[i];
        }
        key_index = (key_index + 1) % strlen(key);
    }

    // Copy the encrypted text to the original text buffer
    for (i = 0; i < strlen(encrypted_text); i++) {
        text[i] = encrypted_text[i];
    }
}

// Function to decrypt the given text using the given key
void decrypt(char* text, char* key) {
    int i, j, k;
    int key_index = 0;
    char decrypted_text[MAX_TEXT_SIZE];

    // Initialize the decrypted text
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            decrypted_text[i] = text[i] - key[key_index];
        } else {
            decrypted_text[i] = text[i];
        }
        key_index = (key_index + 1) % strlen(key);
    }

    // Copy the decrypted text to the original text buffer
    for (i = 0; i < strlen(decrypted_text); i++) {
        text[i] = decrypted_text[i];
    }
}

int main() {
    char text[MAX_TEXT_SIZE];
    char key[MAX_KEY_SIZE];

    // Get the text and key from the user
    printf("Enter the text to encrypt: ");
    fgets(text, MAX_TEXT_SIZE, stdin);
    printf("Enter the encryption key: ");
    fgets(key, MAX_KEY_SIZE, stdin);

    // Remove the newline characters from the input strings
    text[strcspn(text, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    // Encrypt the text using the key
    encrypt(text, key);

    // Print the encrypted text
    printf("Encrypted text: %s\n", text);

    // Decrypt the encrypted text using the same key
    decrypt(text, key);

    // Print the decrypted text
    printf("Decrypted text: %s\n", text);

    return 0;
}