//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGE_LENGTH 1024
#define MAX_KEYWORD_LENGTH 100

// Function to clean the keyword by removing non-alphabetical characters
void cleanKeyword(const char *input, char *keyword) {
    int j = 0;
    for (int i = 0; input[i]; i++) {
        if (isalpha(input[i])) {
            keyword[j++] = toupper(input[i]);
        }
    }
    keyword[j] = '\0'; // null terminate the cleaned keyword
}

// Function to encrypt the plaintext using the Vigenère cipher
void encrypt(const char *plaintext, const char *keyword, char *ciphertext) {
    int keywordLength = strlen(keyword);
    for (int i = 0, j = 0; plaintext[i]; i++) {
        if (isalpha(plaintext[i])) {
            char shifted = (toupper(plaintext[i]) - 'A' + (keyword[j % keywordLength] - 'A')) % 26 + 'A';
            ciphertext[i] = shifted;
            j++;
        } else {
            ciphertext[i] = plaintext[i]; // non-alphabet character remains unchanged
        }
    }
    ciphertext[strlen(plaintext)] = '\0'; // null terminate
}

// Function to decrypt the ciphertext using the Vigenère cipher
void decrypt(const char *ciphertext, const char *keyword, char *plaintext) {
    int keywordLength = strlen(keyword);
    for (int i = 0, j = 0; ciphertext[i]; i++) {
        if (isalpha(ciphertext[i])) {
            char shifted = (toupper(ciphertext[i]) - 'A' - (keyword[j % keywordLength] - 'A') + 26) % 26 + 'A';
            plaintext[i] = shifted;
            j++;
        } else {
            plaintext[i] = ciphertext[i]; // non-alphabet character remains unchanged
        }
    }
    plaintext[strlen(ciphertext)] = '\0'; // null terminate
}

// Main function to interact with the user
int main() {
    char plaintext[MAX_MESSAGE_LENGTH];
    char keyword[MAX_KEYWORD_LENGTH];
    char ciphertext[MAX_MESSAGE_LENGTH];
    char decrypted[MAX_MESSAGE_LENGTH];

    printf("Welcome to the Vigenère Cipher Program!\n");

    // Input plaintext message
    printf("Enter the plaintext message (max %d characters): ", MAX_MESSAGE_LENGTH - 1);
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // Remove newline character

    // Input keyword for encryption
    printf("Enter the keyword (max %d characters): ", MAX_KEYWORD_LENGTH - 1);
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = 0; // Remove newline character

    // Clean the keyword
    char cleanedKeyword[MAX_KEYWORD_LENGTH];
    cleanKeyword(keyword, cleanedKeyword);
    
    // Encrypt the plaintext
    encrypt(plaintext, cleanedKeyword, ciphertext);
    printf("\nEncrypted Message: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, cleanedKeyword, decrypted);
    printf("Decrypted Message: %s\n", decrypted);

    return 0;
}