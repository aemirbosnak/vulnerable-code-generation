//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 1024
#define MAX_KEY_LENGTH 128

// Function prototypes
void to_upper_case(char* str);
void encrypt(const char* plaintext, const char* key, char* ciphertext);
void decrypt(const char* ciphertext, const char* key, char* plaintext);
void repeat_key(const char* key, char* repeated_key, int text_length);
void strip_non_alpha(char* str);

// Main function to demonstrate Vigenère cipher
int main() {
    char plaintext[MAX_TEXT_LENGTH];
    char key[MAX_KEY_LENGTH];
    char ciphertext[MAX_TEXT_LENGTH];
    char decryptedtext[MAX_TEXT_LENGTH];

    // Input plaintext
    printf("Enter the plaintext (max %d characters): ", MAX_TEXT_LENGTH - 1);
    fgets(plaintext, sizeof(plaintext), stdin);
    strip_non_alpha(plaintext); // Remove non-alphabetic characters
    to_upper_case(plaintext); // Convert to uppercase

    // Input keyword for encryption
    printf("Enter the key (max %d characters): ", MAX_KEY_LENGTH - 1);
    fgets(key, sizeof(key), stdin);
    strip_non_alpha(key); // Remove non-alphabetic characters
    to_upper_case(key); // Convert to uppercase

    // Encrypt the plaintext
    encrypt(plaintext, key, ciphertext);
    printf("Encrypted ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, key, decryptedtext);
    printf("Decrypted plaintext: %s\n", decryptedtext);

    return 0;
}

// Function to convert a string to uppercase
void to_upper_case(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to encrypt plaintext using Vigenère cipher
void encrypt(const char* plaintext, const char* key, char* ciphertext) {
    int n = strlen(plaintext);
    char repeated_key[n + 1];
    repeat_key(key, repeated_key, n);

    for (int i = 0; i < n; i++) {
        ciphertext[i] = (plaintext[i] + repeated_key[i] - 2 * 'A') % 26 + 'A';
    }
    ciphertext[n] = '\0'; // Null terminate the string
}

// Function to decrypt ciphertext using Vigenère cipher
void decrypt(const char* ciphertext, const char* key, char* plaintext) {
    int n = strlen(ciphertext);
    char repeated_key[n + 1];
    repeat_key(key, repeated_key, n);

    for (int i = 0; i < n; i++) {
        plaintext[i] = (ciphertext[i] - repeated_key[i] + 26) % 26 + 'A';
    }
    plaintext[n] = '\0'; // Null terminate the string
}

// Function to repeat key so it matches the length of the text
void repeat_key(const char* key, char* repeated_key, int text_length) {
    int key_length = strlen(key);
    for (int i = 0; i < text_length; i++) {
        repeated_key[i] = key[i % key_length];
    }
    repeated_key[text_length] = '\0'; // Null terminate the string
}

// Function to strip non-alphabetic characters from a string
void strip_non_alpha(char* str) {
    char temp[MAX_TEXT_LENGTH];
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    strcpy(str, temp); // Copy sanitized text back to original
}