//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SURREAL_ALPHABET "bjswqmkxzpfyvrtgdloaenuihc"

char* surreal_encrypt(char* message, int key) {
    // Initialize the result string
    char* result = malloc(sizeof(char) * strlen(message));
    memset(result, 0, strlen(message));

    // Encrypt each character in the message
    for(int i = 0; i < strlen(message); i++) {
        char c = message[i];

        // Check if the character is a letter
        if(c >= 'A' && c <= 'Z') {
            c += key; // Shift the character by the key value
            if(c > 'Z') c -= 26; // Wrap back around if necessary
            else if(c < 'A') c += 26;
        } else if(c >= 'a' && c <= 'z') {
            int idx = c - 'a';
            c = SURREAL_ALPHABET[(idx + key) % 26]; // Use surreal alphabet lookup table
        } // Do not encrypt other characters

        result[i] = c;
    }

    return result;
}

char* surreal_decrypt(char* ciphertext, int key) {
    // Initialize the result string
    char* result = malloc(sizeof(char) * strlen(ciphertext));
    memset(result, 0, strlen(ciphertext));

    // Decrypt each character in the ciphertext
    for(int i = 0; i < strlen(ciphertext); i++) {
        char c = ciphertext[i];

        // Check if the character is a letter
        if(c >= 'A' && c <= 'Z') {
            c -= key; // Shift the character back by the key value
            if(c > 'Z') c -= 26; // Wrap back around if necessary
            else if(c < 'A') c += 26;
        } else if(c >= 'a' && c <= 'z') {
            int idx = strchr(SURREAL_ALPHABET, c) - SURREAL_ALPHABET;
            c = 'a' + (idx - key + 26) % 26; // Use surreal alphabet lookup table in reverse
        } // Do not decrypt other characters

        result[i] = c;
    }

    return result;
}

int main() {
    char message[] = "This code is surreal!";
    int key = 13;

    char* ciphertext = surreal_encrypt(message, key);
    printf("Ciphertext: %s\n", ciphertext);

    char* plaintext = surreal_decrypt(ciphertext, key);
    printf("Plaintext: %s\n", plaintext);

    free(ciphertext);
    free(plaintext);

    return 0;
}