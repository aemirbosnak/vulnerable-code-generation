//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

// Function prototypes
void enigmaCipher(char *msg, int shift, char *result);
void decryptionMechanism(char *msg, int shift, char *result);
void displayResults(char *original, char *transformed, char *action);

// Main function
int main(int argc, char *argv[]) {
    char mysticalPhrase[MAX_LEN];
    int shiftValue;
    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <message> <shift>\n", argv[0]);
        return EXIT_FAILURE;
    }

    strncpy(mysticalPhrase, argv[1], MAX_LEN);
    shiftValue = atoi(argv[2]);
    
    char enchantedText[MAX_LEN];
    char decryptedText[MAX_LEN];

    // Encrypting the mystical phrase
    enigmaCipher(mysticalPhrase, shiftValue, enchantedText);
    displayResults(mysticalPhrase, enchantedText, "Encrypted");

    // Decrypting the enchanted phrase back
    decryptionMechanism(enchantedText, shiftValue, decryptedText);
    displayResults(enchantedText, decryptedText, "Decrypted");

    return EXIT_SUCCESS;
}

// Encrypt the input message
void enigmaCipher(char *msg, int shift, char *result) {
    int idx;
    for (idx = 0; msg[idx] != '\0'; ++idx) {
        char cypherChar = msg[idx];
        // Uppercase characters
        if (cypherChar >= 'A' && cypherChar <= 'Z') {
            result[idx] = (cypherChar - 'A' + shift) % 26 + 'A';
        }
        // Lowercase characters
        else if (cypherChar >= 'a' && cypherChar <= 'z') {
            result[idx] = (cypherChar - 'a' + shift) % 26 + 'a';
        } else {
            result[idx] = cypherChar; // Non-alphabetical characters are unchanged
        }
    }
    result[idx] = '\0'; // Null-terminate the result
}

// Decrypt the input message
void decryptionMechanism(char *msg, int shift, char *result) {
    int idx;
    for (idx = 0; msg[idx] != '\0'; ++idx) {
        char cypherChar = msg[idx];
        // Uppercase characters
        if (cypherChar >= 'A' && cypherChar <= 'Z') {
            result[idx] = (cypherChar - 'A' - shift + 26) % 26 + 'A';
        }
        // Lowercase characters
        else if (cypherChar >= 'a' && cypherChar <= 'z') {
            result[idx] = (cypherChar - 'a' - shift + 26) % 26 + 'a';
        } else {
            result[idx] = cypherChar; // Non-alphabetical characters are unchanged
        }
    }
    result[idx] = '\0'; // Null-terminate the result
}

// Display the results of encryption/decryption
void displayResults(char *original, char *transformed, char *action) {
    printf("Original: %s\n", original);
    printf("%s: %s\n", action, transformed);
    printf("-----------------------------\n");
}