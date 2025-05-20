//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the plaintext using Caesar cipher
void encrypt(char *plaintext, int shift, char *ciphertext) {
    int i;
    for(i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];

        // Encrypt lowercase letters
        if(ch >= 'a' && ch <= 'z') {
            ciphertext[i] = (ch - 'a' + shift) % 26 + 'a';
        }
        // Encrypt uppercase letters
        else if(ch >= 'A' && ch <= 'Z') {
            ciphertext[i] = (ch - 'A' + shift) % 26 + 'A';
        }
        // Non-alphabetic characters remain unchanged
        else {
            ciphertext[i] = ch;
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the string
}

// Function to decrypt the ciphertext using Caesar cipher
void decrypt(char *ciphertext, int shift, char *plaintext) {
    int i;
    for(i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];

        // Decrypt lowercase letters
        if(ch >= 'a' && ch <= 'z') {
            plaintext[i] = (ch - 'a' - shift + 26) % 26 + 'a';
        }
        // Decrypt uppercase letters
        else if(ch >= 'A' && ch <= 'Z') {
            plaintext[i] = (ch - 'A' - shift + 26) % 26 + 'A';
        }
        // Non-alphabetic characters remain unchanged
        else {
            plaintext[i] = ch;
        }
    }
    plaintext[i] = '\0'; // Null-terminate the string
}

// Function to dynamically allocate memory for strings
char* get_input() {
    char *buffer = NULL;
    size_t size = 0;
    getline(&buffer, &size, stdin);
    // Remove the newline character from the input
    buffer[strcspn(buffer, "\n")] = 0; 
    return buffer;
}

int main() {
    int choice, shift;
    char *input, *result;

    // Prompt user for the shift value
    printf("Enter a shift value for the Caesar cipher (1-25): ");
    scanf("%d", &shift);
    getchar(); // Flush newline from input buffer

    // Allocate memory for input and result strings
    input = (char*)malloc(1024 * sizeof(char)); // assuming maximal input size of 1024
    result = (char*)malloc(1024 * sizeof(char));

    if (!input || !result) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    while (1) {
        // Menu for user choices
        printf("\n=== Caesar Cipher ===\n");
        printf("1. Encrypt text\n");
        printf("2. Decrypt text\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Flush newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter text to encrypt: ");
                input = get_input();
                encrypt(input, shift, result);
                printf("Encrypted text: %s\n", result);
                free(input); // Release memory for input
                break;
            case 2:
                printf("Enter text to decrypt: ");
                input = get_input();
                decrypt(input, shift, result);
                printf("Decrypted text: %s\n", result);
                free(input); // Release memory for input
                break;
            case 3:
                printf("Exiting program.\n");
                free(input);
                free(result);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}