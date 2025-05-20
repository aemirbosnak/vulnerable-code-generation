//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void encrypt(char *plaintext, int shift, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char letter = plaintext[i];

        if (letter >= 'A' && letter <= 'Z') {
            ciphertext[i] = (letter - 'A' + shift) % 26 + 'A';
        } else if (letter >= 'a' && letter <= 'z') {
            ciphertext[i] = (letter - 'a' + shift) % 26 + 'a';
        } else {
            ciphertext[i] = letter;  // Non-alphabetic characters remain the same
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the string
}

void decrypt(char *ciphertext, int shift, char *plaintext) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        char letter = ciphertext[i];

        if (letter >= 'A' && letter <= 'Z') {
            plaintext[i] = (letter - 'A' - shift + 26) % 26 + 'A';
        } else if (letter >= 'a' && letter <= 'z') {
            plaintext[i] = (letter - 'a' - shift + 26) % 26 + 'a';
        } else {
            plaintext[i] = letter; // Non-alphabetic characters remain the same
        }
    }
    plaintext[i] = '\0'; // Null-terminate the string
}

void print_usage() {
    printf("Usage: ./encryption_program\n");
    printf("Options:\n");
    printf("  -e <plaintext> <shift> : Encrypt the plaintext with the specified shift.\n");
    printf("  -d <ciphertext> <shift> : Decrypt the ciphertext with the specified shift.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    char buffer[256];
    int shift;
    if (strcmp(argv[1], "-e") == 0 && argc == 4) {
        strcpy(buffer, argv[2]);
        shift = atoi(argv[3]);
        char encrypted[256];
        encrypt(buffer, shift, encrypted);
        printf("Encrypted text: %s\n", encrypted);
    } else if (strcmp(argv[1], "-d") == 0 && argc == 4) {
        strcpy(buffer, argv[2]);
        shift = atoi(argv[3]);
        char decrypted[256];
        decrypt(buffer, shift, decrypted);
        printf("Decrypted text: %s\n", decrypted);
    } else {
        print_usage();
        return 1;
    }

    return 0;
}