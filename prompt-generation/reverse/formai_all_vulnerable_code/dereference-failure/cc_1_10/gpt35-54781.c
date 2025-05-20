//FormAI DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate random key
char* generate_key(int length) {
    char* key = malloc(length * sizeof(char));
    int i;
    for (i = 0; i < length; i++) {
        // Generate random ASCII characters between 32 and 126
        key[i] = (char)((rand() % (126 - 32 + 1)) + 32);
    }
    return key;
}

// Function to perform encryption
char* encrypt(char* message, char* key) {
    int message_length = strlen(message);
    char* encrypted_message = malloc(message_length * sizeof(char));
    int i;
    for (i = 0; i < message_length; i++) {
        // XOR operation between message character and corresponding key character
        encrypted_message[i] = message[i] ^ key[i % strlen(key)];
    }
    return encrypted_message;
}

int main() {
    printf("Welcome to Modern Encryption Program!\n\n");

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Get message and key from user
    char message[100];
    printf("Enter message to be encrypted: ");
    scanf("%99[^\n]", message);
    getchar();

    int key_length;
    printf("Enter length of key: ");
    scanf("%d", &key_length);
    getchar();

    // Generate random key
    char* key = generate_key(key_length);
    printf("Generated key: %s\n", key);

    // Encrypt message using key
    char* encrypted_message = encrypt(message, key);
    printf("Encrypted Message: %s\n", encrypted_message);

    // Free memory
    free(key);
    free(encrypted_message);

    return 0;
}