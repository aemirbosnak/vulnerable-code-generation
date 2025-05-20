//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Encryption/decryption key
char key[] = "Abracadabra";

// Function to encrypt a string
void encrypt(char* plaintext) {
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++) {
        plaintext[i] = plaintext[i] ^ key[i % strlen(key)];
    }
}

// Function to decrypt a string
void decrypt(char* ciphertext) {
    int length = strlen(ciphertext);
    for (int i = 0; i < length; i++) {
        ciphertext[i] = ciphertext[i] ^ key[i % strlen(key)];
    }
}

// Function to generate a random string of a given length
char* generateRandomString(int length) {
    char* randomString = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        randomString[i] = (rand() % 26) + 97;
    }
    randomString[length] = '\0';
    return randomString;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random string to encrypt
    int length = 10;
    char* plaintext = generateRandomString(length);
    printf("Original plaintext: %s\n", plaintext);

    // Encrypt the string
    encrypt(plaintext);
    printf("Encrypted ciphertext: %s\n", plaintext);

    // Decrypt the string
    decrypt(plaintext);
    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}