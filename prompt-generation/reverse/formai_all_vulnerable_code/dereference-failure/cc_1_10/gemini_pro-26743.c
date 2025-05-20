//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string using a Caesar cipher
char *encrypt_caesar(char *plaintext, int shift) {
    char *ciphertext = malloc(strlen(plaintext) + 1);  // Allocate memory for the ciphertext
    int i;

    // Iterate over each character in the plaintext
    for (i = 0; i < strlen(plaintext); i++) {
        // Check if the character is a letter
        if (isalpha(plaintext[i])) {
            // Shift the character by the specified amount
            if (isupper(plaintext[i])) {
                ciphertext[i] = (((plaintext[i] - 'A') + shift) % 26) + 'A';
            } else {
                ciphertext[i] = (((plaintext[i] - 'a') + shift) % 26) + 'a';
            }
        } else {
            // If the character is not a letter, copy it to the ciphertext unchanged
            ciphertext[i] = plaintext[i];
        }
    }

    // Add the null terminator to the ciphertext
    ciphertext[i] = '\0';

    return ciphertext;
}

// Function to decrypt a string using a Caesar cipher
char *decrypt_caesar(char *ciphertext, int shift) {
    char *plaintext = malloc(strlen(ciphertext) + 1);  // Allocate memory for the plaintext
    int i;

    // Iterate over each character in the ciphertext
    for (i = 0; i < strlen(ciphertext); i++) {
        // Check if the character is a letter
        if (isalpha(ciphertext[i])) {
            // Shift the character by the specified amount
            if (isupper(ciphertext[i])) {
                plaintext[i] = (((ciphertext[i] - 'A') - shift) % 26) + 'A';
            } else {
                plaintext[i] = (((ciphertext[i] - 'a') - shift) % 26) + 'a';
            }
        } else {
            // If the character is not a letter, copy it to the plaintext unchanged
            plaintext[i] = ciphertext[i];
        }
    }

    // Add the null terminator to the plaintext
    plaintext[i] = '\0';

    return plaintext;
}

// Function to generate a random key for the Vigenere cipher
char *generate_vigenere_key(int length) {
    char *key = malloc(length + 1);  // Allocate memory for the key
    int i;

    // Iterate over each character in the key
    for (i = 0; i < length; i++) {
        // Generate a random character between 'A' and 'Z'
        key[i] = 'A' + (rand() % 26);
    }

    // Add the null terminator to the key
    key[i] = '\0';

    return key;
}

// Function to encrypt a string using a Vigenere cipher
char *encrypt_vigenere(char *plaintext, char *key) {
    char *ciphertext = malloc(strlen(plaintext) + 1);  // Allocate memory for the ciphertext
    int i, key_index = 0;

    // Iterate over each character in the plaintext
    for (i = 0; i < strlen(plaintext); i++) {
        // Check if the character is a letter
        if (isalpha(plaintext[i])) {
            // Shift the character by the amount specified by the key character
            if (isupper(plaintext[i])) {
                ciphertext[i] = (((plaintext[i] - 'A') + (key[key_index] - 'A')) % 26) + 'A';
            } else {
                ciphertext[i] = (((plaintext[i] - 'a') + (key[key_index] - 'a')) % 26) + 'a';
            }
            // Increment the key index
            key_index = (key_index + 1) % strlen(key);
        } else {
            // If the character is not a letter, copy it to the ciphertext unchanged
            ciphertext[i] = plaintext[i];
        }
    }

    // Add the null terminator to the ciphertext
    ciphertext[i] = '\0';

    return ciphertext;
}

// Function to decrypt a string using a Vigenere cipher
char *decrypt_vigenere(char *ciphertext, char *key) {
    char *plaintext = malloc(strlen(ciphertext) + 1);  // Allocate memory for the plaintext
    int i, key_index = 0;

    // Iterate over each character in the ciphertext
    for (i = 0; i < strlen(ciphertext); i++) {
        // Check if the character is a letter
        if (isalpha(ciphertext[i])) {
            // Shift the character by the amount specified by the key character
            if (isupper(ciphertext[i])) {
                plaintext[i] = (((ciphertext[i] - 'A') - (key[key_index] - 'A')) % 26) + 'A';
            } else {
                plaintext[i] = (((ciphertext[i] - 'a') - (key[key_index] - 'a')) % 26) + 'a';
            }
            // Increment the key index
            key_index = (key_index + 1) % strlen(key);
        } else {
            // If the character is not a letter, copy it to the plaintext unchanged
            plaintext[i] = ciphertext[i];
        }
    }

    // Add the null terminator to the plaintext
    plaintext[i] = '\0';

    return plaintext;
}

// Main function
int main() {
    // Get the plaintext from the user
    char *plaintext = malloc(100);
    printf("Enter the plaintext: ");
    scanf(" %[^\n]", plaintext);

    // Get the encryption method from the user
    int encryption_method;
    printf("Select an encryption method:\n1. Caesar cipher\n2. Vigenere cipher\n");
    scanf(" %d", &encryption_method);

    // Get the key for the encryption method
    char *key;
    if (encryption_method == 2) {
        printf("Enter the Vigenere key: ");
        scanf(" %[^\n]", key);
    }

    // Encrypt the plaintext
    char *ciphertext;
    switch (encryption_method) {
        case 1:
            ciphertext = encrypt_caesar(plaintext, 3);
            break;
        case 2:
            ciphertext = encrypt_vigenere(plaintext, key);
            break;
        default:
            printf("Invalid encryption method selected.\n");
            return 1;
    }

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    char *decrypted_plaintext;
    switch (encryption_method) {
        case 1:
            decrypted_plaintext = decrypt_caesar(ciphertext, 3);
            break;
        case 2:
            decrypted_plaintext = decrypt_vigenere(ciphertext, key);
            break;
        default:
            printf("Invalid encryption method selected.\n");
            return 1;
    }

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(plaintext);
    free(ciphertext);
    free(decrypted_plaintext);
    if (encryption_method == 2) {
        free(key);
    }

    return 0;
}