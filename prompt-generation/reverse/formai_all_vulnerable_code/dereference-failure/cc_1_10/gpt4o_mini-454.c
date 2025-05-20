//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

void encrypt(char *plaintext, char *ciphertext, int key) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        // Simple Caesar cipher: shift character by key
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
        } else {
            ciphertext[i] = plaintext[i];  // Non-alphabetic characters remain unchanged
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the ciphertext string
}

void decrypt(char *ciphertext, char *plaintext, int key) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        // Reverse shift for decryption
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = (ciphertext[i] - 'a' - key + 26) % 26 + 'a';
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = (ciphertext[i] - 'A' - key + 26) % 26 + 'A';
        } else {
            plaintext[i] = ciphertext[i]; // Non-alphabetic characters remain unchanged
        }
    }
    plaintext[i] = '\0'; // Null-terminate the plaintext string
}

void print_usage(const char *program_name) {
    printf("Usage: %s [encrypt|decrypt] <key> <input text>\n", program_name);
    printf("Example:\n");
    printf("   %s encrypt 3 \"Hello World\"\n", program_name);
    printf("   %s decrypt 3 \"Khoor Zruog\"\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        print_usage(argv[0]);
        return 1;
    }
    
    int key = atoi(argv[2]);
    char ciphertext[MAX_BUFFER];
    char plaintext[MAX_BUFFER];
    
    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt(argv[3], ciphertext, key);
        printf("Encrypted: %s\n", ciphertext);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt(argv[3], plaintext, key);
        printf("Decrypted: %s\n", plaintext);
    } else {
        print_usage(argv[0]);
        return 1;
    }

    return 0;
}