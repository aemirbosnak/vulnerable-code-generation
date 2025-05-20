//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define ALPHABET_SIZE 26

// Function to encrypt message using a key
void encrypt(char message[MAX_SIZE], char key[MAX_SIZE]) {
    int i, j;
    char encrypted_message[MAX_SIZE];
    memset(encrypted_message, 0, sizeof(encrypted_message));

    // Loop through message and encrypt each character
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            // Convert character to uppercase
            message[i] = toupper(message[i]);

            // Encrypt character using key
            j = (int) message[i] - 65 + (int) key[i % strlen(key)] - 65;

            // Check for wraparound
            if (j > 25) {
                j -= 26;
            } else if (j < 0) {
                j += 26;
            }

            // Convert encrypted character back to lowercase
            encrypted_message[i] = (char) (j + 65);
        } else {
            // Copy non-alphabetic characters as is
            encrypted_message[i] = message[i];
        }
    }

    // Copy encrypted message to original message
    strcpy(message, encrypted_message);
}

// Function to decrypt message using a key
void decrypt(char message[MAX_SIZE], char key[MAX_SIZE]) {
    int i, j;
    char decrypted_message[MAX_SIZE];
    memset(decrypted_message, 0, sizeof(decrypted_message));

    // Loop through message and decrypt each character
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            // Convert character to uppercase
            message[i] = toupper(message[i]);

            // Decrypt character using key
            j = (int) message[i] - 65 - (int) key[i % strlen(key)] - 65;

            // Check for wraparound
            if (j < 0) {
                j += 26;
            } else if (j > 25) {
                j -= 26;
            }

            // Convert decrypted character back to lowercase
            decrypted_message[i] = (char) (j + 65);
        } else {
            // Copy non-alphabetic characters as is
            decrypted_message[i] = message[i];
        }
    }

    // Copy decrypted message to original message
    strcpy(message, decrypted_message);
}

// Function to generate a random key
void generate_key(char key[MAX_SIZE]) {
    int i;

    // Loop through key and assign a random character from the alphabet
    for (i = 0; i < strlen(key); i++) {
        key[i] = 'A' + rand() % ALPHABET_SIZE;
    }
}

int main() {
    char message[MAX_SIZE];
    char key[MAX_SIZE];

    // Get message from user
    printf("Enter message: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key);

    // Encrypt message using key
    encrypt(message, key);

    // Print encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt message using key
    decrypt(message, key);

    // Print decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}