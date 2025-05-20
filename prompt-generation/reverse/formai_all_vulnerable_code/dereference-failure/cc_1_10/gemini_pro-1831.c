//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input string.
#define MAX_INPUT_SIZE 1024

// Define the encryption key.
const char *KEY = "my secret key";

// Define the encryption function.
char *encrypt(char *input) {
    char *output = malloc(strlen(input) + 1);
    for (int i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ KEY[i % strlen(KEY)];
    }
    output[strlen(input)] = '\0';
    return output;
}

// Define the decryption function.
char *decrypt(char *input) {
    char *output = malloc(strlen(input) + 1);
    for (int i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ KEY[i % strlen(KEY)];
    }
    output[strlen(input)] = '\0';
    return output;
}

// Get the input string from the user.
char *get_input() {
    char *input = malloc(MAX_INPUT_SIZE + 1);
    printf("Enter the string to encrypt: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    return input;
}

// Print the encrypted string.
void print_encrypted(char *input) {
    char *encrypted = encrypt(input);
    printf("Encrypted string: %s\n", encrypted);
    free(encrypted);
}

// Print the decrypted string.
void print_decrypted(char *input) {
    char *decrypted = decrypt(input);
    printf("Decrypted string: %s\n", decrypted);
    free(decrypted);
}

// Main function.
int main() {
    // Get the input string from the user.
    char *input = get_input();

    // Encrypt the input string.
    print_encrypted(input);

    // Decrypt the encrypted string.
    print_decrypted(input);

    // Free the allocated memory.
    free(input);

    return 0;
}