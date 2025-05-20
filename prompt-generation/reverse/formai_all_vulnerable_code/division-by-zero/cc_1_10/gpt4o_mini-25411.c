//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024

void to_upper_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int text_len = strlen(plaintext);
    int key_len = strlen(key);
    int j = 0;
    for (int i = 0; i < text_len; i++) {
        if (isalpha(plaintext[i])) {
            char p = toupper(plaintext[i]) - 'A';
            char k = toupper(key[j % key_len]) - 'A';
            ciphertext[i] = (p + k) % 26 + 'A';

            j++;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[text_len] = '\0'; // null-terminate the string
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int text_len = strlen(ciphertext);
    int key_len = strlen(key);
    int j = 0;
    for (int i = 0; i < text_len; i++) {
        if (isalpha(ciphertext[i])) {
            char c = toupper(ciphertext[i]) - 'A';
            char k = toupper(key[j % key_len]) - 'A';
            plaintext[i] = (c - k + 26) % 26 + 'A';

            j++;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[text_len] = '\0'; // null-terminate the string
}

int main() {
    char plaintext[MAX_LEN];
    char key[MAX_LEN];
    char ciphertext[MAX_LEN];
    char decryptedtext[MAX_LEN];

    printf("Welcome to the Vigenère Cipher Encryption Program!\n");
    
    printf("Enter the plaintext: ");
    fgets(plaintext, MAX_LEN, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // Remove newline character

    printf("Enter the encryption key: ");
    fgets(key, MAX_LEN, stdin);
    key[strcspn(key, "\n")] = 0; // Remove newline character

    // Convert key to uppercase for consistency
    to_upper_case(key);

    // Encrypt the plaintext
    encrypt(plaintext, key, ciphertext);
    printf("Encrypted ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, key, decryptedtext);
    printf("Decrypted plaintext: %s\n", decryptedtext);

    return 0;
}