//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER 1024
#define ALPHABET_SIZE 26

void encrypt_caesar(const char *plaintext, char *ciphertext, int shift);
void decrypt_caesar(const char *ciphertext, char *plaintext, int shift);
void to_uppercase(char *str);
void print_help();

int main(int argc, char *argv[]) {
    char buffer[MAX_BUFFER];
    char plaintext[MAX_BUFFER];
    char ciphertext[MAX_BUFFER];
    int shift = 0;
    
    if (argc < 3) {
        print_help();
        return 1;
    }
    
    if (strcmp(argv[1], "encrypt") == 0) {
        shift = atoi(argv[2]);
        printf("Enter the plaintext: ");
        fgets(buffer, MAX_BUFFER, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character

        to_uppercase(buffer);
        encrypt_caesar(buffer, ciphertext, shift);

        printf("Ciphertext: %s\n", ciphertext);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        shift = atoi(argv[2]);
        printf("Enter the ciphertext: ");
        fgets(buffer, MAX_BUFFER, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character

        to_uppercase(buffer);
        decrypt_caesar(buffer, plaintext, shift);
        
        printf("Plaintext: %s\n", plaintext);
    } else {
        print_help();
        return 1;
    }

    return 0;
}

void encrypt_caesar(const char *plaintext, char *ciphertext, int shift) {
    int i;
    shift = shift % ALPHABET_SIZE; // Ensure shift is within alphabet size
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = (plaintext[i] - base + shift) % ALPHABET_SIZE + base;
        } else {
            ciphertext[i] = plaintext[i]; // Retain non-alphabetic characters
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the string
}

void decrypt_caesar(const char *ciphertext, char *plaintext, int shift) {
    int i;
    shift = shift % ALPHABET_SIZE; // Ensure shift is within alphabet size
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            plaintext[i] = (ciphertext[i] - base - shift + ALPHABET_SIZE) % ALPHABET_SIZE + base;
        } else {
            plaintext[i] = ciphertext[i]; // Retain non-alphabetic characters
        }
    }
    plaintext[i] = '\0'; // Null-terminate the string
}

void to_uppercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

void print_help() {
    printf("Usage:\n");
    printf("  cryptography encrypt <shift> : Encrypt the plaintext using Caesar cipher.\n");
    printf("  cryptography decrypt <shift> : Decrypt the ciphertext using Caesar cipher.\n");
}