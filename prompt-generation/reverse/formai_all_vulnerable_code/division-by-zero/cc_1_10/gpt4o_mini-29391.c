//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void encryptVigenere(char *plaintext, char *keyword, char *ciphertext) {
    int plainLen = strlen(plaintext);
    int keyLen = strlen(keyword);
    int j = 0;

    for (int i = 0; i < plainLen; i++) {
        if (isalpha(plaintext[i])) {
            char offset = keyword[j % keyLen] - 'a';
            ciphertext[i] = ((plaintext[i] - 'a' + offset) % 26) + 'a';
            j++;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[plainLen] = '\0'; // Null-terminate the ciphertext
}

void decryptVigenere(char *ciphertext, char *keyword, char *plaintext) {
    int cipherLen = strlen(ciphertext);
    int keyLen = strlen(keyword);
    int j = 0;

    for (int i = 0; i < cipherLen; i++) {
        if (isalpha(ciphertext[i])) {
            char offset = keyword[j % keyLen] - 'a';
            plaintext[i] = ((ciphertext[i] - 'a' - offset + 26) % 26) + 'a'; // +26 for positive mod
            j++;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[cipherLen] = '\0'; // Null-terminate the plaintext
}

int main() {
    char plaintext[256], keyword[256], ciphertext[256], decryptedtext[256];

    printf("Welcome to Vigenère Cipher Encryption!\n");
    printf("Please enter the plaintext (lowercase only): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // Remove trailing newline

    printf("Please enter the keyword (lowercase only): ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = 0; // Remove trailing newline

    toLowerCase(plaintext);
    toLowerCase(keyword);

    encryptVigenere(plaintext, keyword, ciphertext);
    printf("\nEncrypted Text: %s\n", ciphertext);

    decryptVigenere(ciphertext, keyword, decryptedtext);
    printf("Decrypted Text: %s\n", decryptedtext);

    return 0;
}