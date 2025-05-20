//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_SIZE 32

// Function to generate a random key
void generate_key(char *key, int key_size) {
    int i;
    for (i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[key_size] = '\0';
}

// Function to encrypt the message using the Caesar cipher
void encrypt_message(char *message, char *key, char *ciphertext) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++, j++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                ciphertext[j] = 'A' + ((message[i] - 'A' + key[j % strlen(key)]) % 26);
            } else {
                ciphertext[j] = 'a' + ((message[i] - 'a' + key[j % strlen(key)]) % 26);
            }
        } else {
            ciphertext[j] = message[i];
        }
    }
    ciphertext[j] = '\0';
}

// Function to decrypt the message using the Caesar cipher
void decrypt_message(char *ciphertext, char *key, char *message) {
    int i, j;
    for (i = 0, j = 0; ciphertext[i]!= '\0'; i++, j++) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                message[j] = 'A' + (((ciphertext[i] - 'A' - key[j % strlen(key)]) % 26) + 26) % 26;
            } else {
                message[j] = 'a' + (((ciphertext[i] - 'a' - key[j % strlen(key)]) % 26) + 26) % 26;
            }
        } else {
            message[j] = ciphertext[i];
        }
    }
    message[j] = '\0';
}

// Function to print the key
void print_key(char *key) {
    printf("Key: %s\n", key);
}

// Function to print the encrypted message
void print_ciphertext(char *ciphertext) {
    printf("Encrypted message: %s\n", ciphertext);
}

// Function to print the decrypted message
void print_message(char *message) {
    printf("Decrypted message: %s\n", message);
}

int main() {
    char key[MAX_KEY_SIZE];
    char message[100];
    char ciphertext[100];

    // Generate a random key
    generate_key(key, strlen(key));

    // Get the message from the user
    printf("Enter your message: ");
    scanf("%s", message);

    // Encrypt the message
    encrypt_message(message, key, ciphertext);

    // Print the key and encrypted message
    printf("Key: ");
    print_key(key);
    printf("Encrypted message: ");
    print_ciphertext(ciphertext);

    // Decrypt the message
    decrypt_message(ciphertext, key, message);

    // Print the decrypted message
    printf("Decrypted message: ");
    print_message(message);

    return 0;
}