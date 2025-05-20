//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 1024
#define MAX_KEY_LENGTH 256

void encrypt(const char *text, char *encrypted_text, const char *key) {
    size_t text_length = strlen(text);
    size_t key_length = strlen(key);
    for (size_t i = 0; i < text_length; i++) {
        encrypted_text[i] = (text[i] + key[i % key_length]) % 256; // Simple encryption technique
    }
    encrypted_text[text_length] = '\0'; // Null-terminate the string
}

void decrypt(const char *encrypted_text, char *decrypted_text, const char *key) {
    size_t text_length = strlen(encrypted_text);
    size_t key_length = strlen(key);
    for (size_t i = 0; i < text_length; i++) {
        decrypted_text[i] = (encrypted_text[i] - key[i % key_length] + 256) % 256; // Simple decryption technique
    }
    decrypted_text[text_length] = '\0'; // Null-terminate the string
}

void read_input(char *buffer, size_t size) {
    printf("Enter text (max %zu characters): ", size - 1);
    if (fgets(buffer, size, stdin) == NULL) {
        perror("Failed to read input");
        exit(EXIT_FAILURE);
    }
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline
}

void read_key(char *key, size_t size) {
    printf("Enter encryption key (max %zu characters): ", size - 1);
    if (fgets(key, size, stdin) == NULL) {
        perror("Failed to read key");
        exit(EXIT_FAILURE);
    }
    key[strcspn(key, "\n")] = '\0'; // Remove trailing newline
}

int main() {
    char text[MAX_TEXT_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted_text[MAX_TEXT_LENGTH];
    char decrypted_text[MAX_TEXT_LENGTH];

    // Read user input
    read_input(text, MAX_TEXT_LENGTH);
    
    // Read encryption key
    read_key(key, MAX_KEY_LENGTH);
    
    // Encrypt the text
    encrypt(text, encrypted_text, key);
    printf("\nEncrypted text: ");
    for (size_t i = 0; i < strlen(text); i++) {
        printf("%02X ", (unsigned char)encrypted_text[i]); // Print encrypted text as hexadecimal
    }
    printf("\n");

    // Decrypt the text
    decrypt(encrypted_text, decrypted_text, key);
    printf("Decrypted text: %s\n", decrypted_text);
    
    return 0;
}