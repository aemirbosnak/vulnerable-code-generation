//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the text using a Caesar cipher
char* encrypt(const char* text, int shift) {
    int len = strlen(text);
    char* encryptedText = (char*)malloc((len + 1) * sizeof(char));
    
    if (encryptedText == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    
    for (int i = 0; i < len; i++) {
        char ch = text[i];
        
        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            encryptedText[i] = (ch - 'A' + shift) % 26 + 'A';
        } 
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            encryptedText[i] = (ch - 'a' + shift) % 26 + 'a';
        } 
        // Keep other characters unchanged
        else {
            encryptedText[i] = ch;
        }
    }
    
    encryptedText[len] = '\0'; // Null-terminate the string
    return encryptedText;
}

// Function to decrypt the text using a Caesar cipher
char* decrypt(const char* encryptedText, int shift) {
    int len = strlen(encryptedText);
    char* decryptedText = (char*)malloc((len + 1) * sizeof(char));
    
    if (decryptedText == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    
    for (int i = 0; i < len; i++) {
        char ch = encryptedText[i];
        
        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            decryptedText[i] = (ch - 'A' - shift + 26) % 26 + 'A'; // Add 26 to handle negative shift
        } 
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            decryptedText[i] = (ch - 'a' - shift + 26) % 26 + 'a'; // Add 26 to handle negative shift
        } 
        // Keep other characters unchanged
        else {
            decryptedText[i] = ch;
        }
    }
    
    decryptedText[len] = '\0'; // Null-terminate the string
    return decryptedText;
}

int main() {
    char* text = NULL;
    size_t len = 0;
    int shift;

    printf("Enter the text to encrypt: ");
    getline(&text, &len, stdin);
    // Remove newline character if it exists
    text[strcspn(text, "\n")] = 0;

    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);
    
    if (shift < 1 || shift > 25) {
        fprintf(stderr, "Invalid shift value! It should be between 1 and 25.\n");
        free(text);
        return 1;
    }

    char* encryptedText = encrypt(text, shift);
    printf("Encrypted Text: %s\n", encryptedText);

    char* decryptedText = decrypt(encryptedText, shift);
    printf("Decrypted Text: %s\n", decryptedText);
    
    // Free dynamically allocated memory
    free(text);
    free(encryptedText);
    free(decryptedText);

    return 0;
}