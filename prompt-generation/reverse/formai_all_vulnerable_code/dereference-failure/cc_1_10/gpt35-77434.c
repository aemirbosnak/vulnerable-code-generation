//FormAI DATASET v1.0 Category: Encryption ; Style: visionary
// A visionary implementation of a unique C encryption program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* text, int shift);

int main() {

    // Get user input
    char text[1000];
    printf("Enter text to be encrypted: ");
    fgets(text, sizeof(text), stdin);

    // Get user key
    int key;
    printf("Enter number of characters to shift: ");
    scanf("%d", &key);

    // Encrypt the text using the given key
    char* encrypted_text = encrypt(text, key);

    // Print out the encrypted text
    printf("Encrypted text: %s\n", encrypted_text);

    // Destroy the encrypted text to prevent unauthorized access
    memset(encrypted_text, 0, strlen(encrypted_text));
    free(encrypted_text);

    return 0;
}

char* encrypt(char* text, int shift) {
    int i, n = strlen(text);
    char* encrypted_text = malloc(n + 1);

    // Loop through each character in the text
    for (i = 0; i < n; i++) {
        // If the character is a letter, shift it by the given amount
        if (text[i] >= 'a' && text[i] <= 'z') {
            encrypted_text[i] = 'a' + (text[i] - 'a' + shift) % 26;
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            encrypted_text[i] = 'A' + (text[i] - 'A' + shift) % 26;
        } else {
            // If it's not a letter, just copy it over
            encrypted_text[i] = text[i];
        }
    }

    encrypted_text[n] = '\0';
    return encrypted_text;
}