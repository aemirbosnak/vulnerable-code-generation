//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define the encryption key
#define KEY 42

// Encrypt a character
char encrypt(char c) {
    return c + KEY;
}

// Decrypt a character
char decrypt(char c) {
    return c - KEY;
}

// Encrypt a string
char *encrypt_string(char *str) {
    int i;
    char *encrypted_str = malloc(strlen(str) + 1);
    for (i = 0; str[i] != '\0'; i++) {
        encrypted_str[i] = encrypt(str[i]);
    }
    encrypted_str[i] = '\0';
    return encrypted_str;
}

// Decrypt a string
char *decrypt_string(char *str) {
    int i;
    char *decrypted_str = malloc(strlen(str) + 1);
    for (i = 0; str[i] != '\0'; i++) {
        decrypted_str[i] = decrypt(str[i]);
    }
    decrypted_str[i] = '\0';
    return decrypted_str;
}

// Main function
int main() {
    // Get the input string
    char *str = "Hello, world!";

    // Encrypt the string
    char *encrypted_str = encrypt_string(str);

    // Print the encrypted string
    printf("Encrypted string: %s\n", encrypted_str);

    // Decrypt the string
    char *decrypted_str = decrypt_string(encrypted_str);

    // Print the decrypted string
    printf("Decrypted string: %s\n", decrypted_str);

    // Free the allocated memory
    free(encrypted_str);
    free(decrypted_str);

    return 0;
}