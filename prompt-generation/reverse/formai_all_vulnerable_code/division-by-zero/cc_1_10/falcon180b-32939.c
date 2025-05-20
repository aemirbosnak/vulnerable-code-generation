//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 32
#define MAX_INPUT_LENGTH 1000

// XOR encryption function
void encrypt(char* input, char* key) {
    int i;
    for (i = 0; input[i]!= '\0'; i++) {
        if (isalpha(input[i])) {
            input[i] = input[i] ^ key[i % strlen(key)];
        }
    }
}

// Decrypt function
void decrypt(char* input, char* key) {
    int i;
    for (i = 0; input[i]!= '\0'; i++) {
        if (isalpha(input[i])) {
            input[i] = input[i] ^ key[i % strlen(key)];
        }
    }
}

// Main function
int main() {
    char input[MAX_INPUT_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get input from user
    printf("Enter input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Get key from user
    printf("Enter key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    // Encrypt input
    encrypt(input, key);

    // Print encrypted input
    printf("Encrypted input: %s\n", input);

    // Decrypt input
    decrypt(input, key);

    // Print decrypted input
    printf("Decrypted input: %s\n", input);

    return 0;
}