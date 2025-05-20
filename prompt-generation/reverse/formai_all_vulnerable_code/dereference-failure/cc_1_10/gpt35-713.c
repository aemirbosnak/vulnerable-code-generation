//FormAI DATASET v1.0 Category: Encryption ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Macro to get the size of an array
#define ARR_SIZE(x) (sizeof(x) / sizeof(x[0]))

// Function to generate a random key
char *generate_key(int length) {
    char *key = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        int r = rand() % 26;
        key[i] = 'a' + r;
    }
    key[length] = '\0';
    return key;
}

// Function to apply the encryption
void encrypt(char *plaintext, char *key, char *ciphertext) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        int p = plaintext[i] - 'a';
        int k = key[i] - 'a';
        int c = (p + k) % 26;
        ciphertext[i] = 'a' + c;
    }
    ciphertext[len] = '\0';
}

// Function to apply the decryption
void decrypt(char *ciphertext, char *key, char *plaintext) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i++) {
        int c = ciphertext[i] - 'a';
        int k = key[i] - 'a';
        int p = (c - k + 26) % 26;
        plaintext[i] = 'a' + p;
    }
    plaintext[len] = '\0';
}

int main() {
    // Get user input
    char plaintext[100];
    printf("Enter a message to encrypt: ");
    fgets(plaintext, ARR_SIZE(plaintext), stdin);
    plaintext[strlen(plaintext) - 1] = '\0';

    // Generate a key and encrypt the plaintext
    srand(time(NULL));
    char *key = generate_key(strlen(plaintext));
    char ciphertext[100];
    encrypt(plaintext, key, ciphertext);
    printf("\nCiphertext: %s", ciphertext);

    // Prompt for the key and decrypt the ciphertext
    char user_key[100];
    printf("\nEnter the key to decrypt: ");
    fgets(user_key, ARR_SIZE(user_key), stdin);
    user_key[strlen(user_key) - 1] = '\0';
    if (strcmp(key, user_key) != 0) {
        printf("\nInvalid key, cannot decrypt.\n");
        return 1;
    }
    char decrypted[100];
    decrypt(ciphertext, key, decrypted);
    printf("\nDecrypted message: %s\n", decrypted);

    // Free the dynamically allocated memory
    free(key);

    return 0;
}