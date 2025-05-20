//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
const char *key = "MySecret";

// Define the encryption function
char *encrypt(const char *plaintext, const char *key) {
    // Get the length of the plaintext and key
    size_t plaintext_len = strlen(plaintext);
    size_t key_len = strlen(key);

    // Allocate memory for the ciphertext
    char *ciphertext = malloc(plaintext_len + 1);

    // Encrypt the plaintext using the key
    for (size_t i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }

    // Terminate the ciphertext with a null character
    ciphertext[plaintext_len] = '\0';

    // Return the ciphertext
    return ciphertext;
}

// Define the decryption function
char *decrypt(const char *ciphertext, const char *key) {
    // Get the length of the ciphertext and key
    size_t ciphertext_len = strlen(ciphertext);
    size_t key_len = strlen(key);

    // Allocate memory for the plaintext
    char *plaintext = malloc(ciphertext_len + 1);

    // Decrypt the ciphertext using the key
    for (size_t i = 0; i < ciphertext_len; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % key_len];
    }

    // Terminate the plaintext with a null character
    plaintext[ciphertext_len] = '\0';

    // Return the plaintext
    return plaintext;
}

// Get the input from the user
char *get_input(char *prompt) {
    printf("%s", prompt);
    char *input = malloc(1024);
    fgets(input, 1024, stdin);
    return input;
}

// Print the output to the user
void print_output(char *output) {
    printf("%s", output);
}

// Get the encryption key from the user
char *get_key() {
    char *key = get_input("Enter the encryption key: ");
    return key;
}

// Encrypt the plaintext using the key
char *encrypt_plaintext(char *plaintext, char *key) {
    char *ciphertext = encrypt(plaintext, key);
    return ciphertext;
}

// Decrypt the ciphertext using the key
char *decrypt_ciphertext(char *ciphertext, char *key) {
    char *plaintext = decrypt(ciphertext, key);
    return plaintext;
}

// Print the encrypted and decrypted text
void print_results(char *plaintext, char *ciphertext) {
    print_output("Plaintext: ");
    print_output(plaintext);
    print_output("\n");
    print_output("Ciphertext: ");
    print_output(ciphertext);
    print_output("\n");
}

// Main function
int main() {
    // Get the plaintext from the user
    char *plaintext = get_input("Enter the plaintext: ");

    // Get the encryption key from the user
    char *key = get_key();

    // Encrypt the plaintext using the key
    char *ciphertext = encrypt_plaintext(plaintext, key);

    // Decrypt the ciphertext using the key
    char *decrypted_plaintext = decrypt_ciphertext(ciphertext, key);

    // Print the encrypted and decrypted text
    print_results(plaintext, ciphertext);

    // Free the allocated memory
    free(plaintext);
    free(ciphertext);
    free(decrypted_plaintext);
    free(key);

    return 0;
}