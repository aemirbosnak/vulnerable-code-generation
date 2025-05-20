//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to generate random key
char* generateRandomKey(int key_length) {
    char* key = malloc(key_length * sizeof(char));
    int i;
    for (i = 0; i < key_length; i++) {
        key[i] = (char)(rand() % 26 + 'a');
    }
    return key;
}

// Function to perform XOR operation between message and key
void xor(char* message, char* key, char* cipher_text) {
    int i, j;
    int message_length = strlen(message);
    int key_length = strlen(key);

    // perform XOR operation
    for (i = 0, j = 0; i < message_length; i++, j++) {
        // reset j if it surpasses the key length
        if (j == key_length) {
            j = 0;
        }
        cipher_text[i] = message[i] ^ key[j];
    }
}

int main() {
    // Define message and key
    char message[] = "Hello, how are you?";
    char* key = generateRandomKey(strlen(message));

    // Allocate memory for cipher text
    char* cipher_text = malloc((strlen(message) + 1)* sizeof(char));

    // Perform XOR operation
    xor(message, key, cipher_text);

    // Display Results
    printf("Original message: %s\n", message);
    printf("Generated key: %s\n", key);
    printf("Cipher text: %s\n", cipher_text);

    // Clean up memory
    free(key);
    free(cipher_text);

    return 0;
}