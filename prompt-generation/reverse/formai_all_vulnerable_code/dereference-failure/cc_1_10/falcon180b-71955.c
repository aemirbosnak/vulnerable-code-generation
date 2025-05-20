//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 64
#define MAX_KEY_LENGTH 16

// Function to generate a random key
void generate_key(char *key) {
    int i;
    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_LENGTH] = '\0';
}

// Function to encrypt a message using the Caesar cipher
void encrypt(char *message, char *key) {
    int i, j, k;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
            j = (int)message[i] - 65;
            k = (int)key[j % MAX_KEY_LENGTH] - 65;
            message[i] = (char)(k + j) % 26 + 65;
        }
    }
}

// Function to decrypt a message using the Caesar cipher
void decrypt(char *message, char *key) {
    int i, j, k;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
            j = (int)message[i] - 65;
            k = (int)key[j % MAX_KEY_LENGTH] - 65;
            message[i] = (char)(k - j + 26) % 26 + 65;
        }
    }
}

// Function to read a message from the user
void read_message(char *message) {
    printf("Enter your message: ");
    fgets(message, MAX_WORD_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0';
}

// Function to write a message to the user
void write_message(char *message) {
    printf("%s\n", message);
}

int main() {
    // Generate a random key
    char key[MAX_KEY_LENGTH];
    generate_key(key);

    // Read the message from the user
    char message[MAX_WORD_LENGTH];
    read_message(message);

    // Encrypt the message
    encrypt(message, key);

    // Write the encrypted message to the user
    write_message("Encrypted message: ");
    write_message(message);

    // Decrypt the message
    decrypt(message, key);

    // Write the decrypted message to the user
    write_message("\nDecrypted message: ");
    write_message(message);

    return 0;
}