//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: irregular
// A labyrinthine encryption algorithm - only the brave shall attempt to decipher its secrets!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The heart of the algorithm - a twisted cipher wheel with enigmatic shifts.
int cipherWheel(int key, int plain) {
    int shift = (key % 7) + 3;
    return (plain + shift) % 26;
}

// A labyrinthine maze of loops and twists, weaving the encrypted message.
char* encrypt(const char* plain, int key) {
    size_t len = strlen(plain);
    char* cipher = malloc(len + 1);

    for (size_t i = 0; i < len; i++) {
        if (plain[i] >= 'A' && plain[i] <= 'Z') {
            cipher[i] = cipherWheel(key, plain[i] - 'A') + 'A';
        } else if (plain[i] >= 'a' && plain[i] <= 'z') {
            cipher[i] = cipherWheel(key, plain[i] - 'a') + 'a';
        } else {
            cipher[i] = plain[i];
        }
    }

    cipher[len] = '\0';
    return cipher;
}

// A winding path through the labyrinth, revealing the hidden message.
char* decrypt(const char* cipher, int key) {
    size_t len = strlen(cipher);
    char* plain = malloc(len + 1);

    for (size_t i = 0; i < len; i++) {
        if (cipher[i] >= 'A' && cipher[i] <= 'Z') {
            plain[i] = cipherWheel(key, cipher[i] - 'A') + 'A';
        } else if (cipher[i] >= 'a' && cipher[i] <= 'z') {
            plain[i] = cipherWheel(key, cipher[i] - 'a') + 'a';
        } else {
            plain[i] = cipher[i];
        }
    }

    plain[len] = '\0';
    return plain;
}

int main() {
    int key;
    char plain[1000];
    char* cipher;
    char* plain2;

    printf("Enter the encryption key (an integer): ");
    scanf("%d", &key);

    printf("Enter the plaintext message: ");
    scanf(" %[^\n]%*c", plain); // Capture all input until newline

    printf("\nEncrypting...\n");
    cipher = encrypt(plain, key);
    printf("Ciphertext: %s\n", cipher);

    printf("\nDecrypting...\n");
    plain2 = decrypt(cipher, key);
    printf("Plaintext: %s\n", plain2);

    return 0;
}