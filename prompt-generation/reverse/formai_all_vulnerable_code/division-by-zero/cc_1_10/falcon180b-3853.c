//Falcon-180B DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to generate a random key
void generate_key(char* key) {
    const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
}

// Function to encrypt the message
void encrypt(char* message, char* key) {
    int i, j, k;
    char temp;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] + key[i % strlen(key)];
        }
    }
}

// Function to decrypt the message
void decrypt(char* message, char* key) {
    int i, j, k;
    char temp;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] - key[i % strlen(key)];
        }
    }
}

// Function to generate a random message
void generate_message(char* message) {
    const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int i;
    for (i = 0; i < strlen(message); i++) {
        message[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
}

// Function to print a message
void print_message(char* message) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        printf("%c", message[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    char message[MAX_LENGTH];
    char key[MAX_LENGTH];

    // Generate a random key
    generate_key(key);

    // Generate a random message
    generate_message(message);

    // Encrypt the message
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: ");
    print_message(message);

    // Decrypt the message
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: ");
    print_message(message);

    return 0;
}