//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encrypt a string using the Caesar cipher
char* caesar_encrypt(char* plaintext, int key) {
    char* ciphertext = malloc(strlen(plaintext) + 1);
    for (int i = 0; i < strlen(plaintext); i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
    return ciphertext;
}

// Decrypt a string using the Caesar cipher
char* caesar_decrypt(char* ciphertext, int key) {
    char* plaintext = malloc(strlen(ciphertext) + 1);
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = ((ciphertext[i] - 'a' - key) % 26) + 'a';
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = ((ciphertext[i] - 'A' - key) % 26) + 'A';
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
    return plaintext;
}

// Encrypt a string using the substitution cipher
char* substitution_encrypt(char* plaintext, char* key) {
    char* ciphertext = malloc(strlen(plaintext) + 1);
    for (int i = 0; i < strlen(plaintext); i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = key[plaintext[i] - 'a'];
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = key[plaintext[i] - 'A'];
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
    return ciphertext;
}

// Decrypt a string using the substitution cipher
char* substitution_decrypt(char* ciphertext, char* key) {
    char* plaintext = malloc(strlen(ciphertext) + 1);
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = key[ciphertext[i] - 'a'];
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = key[ciphertext[i] - 'A'];
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
    return plaintext;
}

int main() {
    // Encrypt a string using the Caesar cipher
    char* plaintext = "Hello, world!";
    int key = 3;
    char* ciphertext = caesar_encrypt(plaintext, key);
    printf("Caesar cipher: %s\n", ciphertext);

    // Decrypt the ciphertext using the Caesar cipher
    char* decrypted_plaintext = caesar_decrypt(ciphertext, key);
    printf("Caesar cipher decrypted: %s\n", decrypted_plaintext);

    // Encrypt a string using the substitution cipher
    char* substitution_key = "zyxwvutsrqponmlkjihgfedcba";
    char* substitution_ciphertext = substitution_encrypt(plaintext, substitution_key);
    printf("Substitution cipher: %s\n", substitution_ciphertext);

    // Decrypt the ciphertext using the substitution cipher
    char* substitution_decrypted_plaintext = substitution_decrypt(substitution_ciphertext, substitution_key);
    printf("Substitution cipher decrypted: %s\n", substitution_decrypted_plaintext);

    return 0;
}