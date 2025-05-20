//Falcon-180B DATASET v1.0 Category: Encryption ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_KEY_SIZE 16
#define MAX_MESSAGE_SIZE 1000

// Function to generate a random key
void generate_key(char* key) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    srand(time(0));
    for (int i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
    key[MAX_KEY_SIZE] = '\0';
}

// Function to encrypt the message using the key
void caesar_encrypt(char* message, char* key) {
    for (int i = 0; message[i]!= '\0'; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] + key[i % MAX_KEY_SIZE] - 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] + key[i % MAX_KEY_SIZE] - 'a';
        }
    }
}

// Function to decrypt the message using the key
void caesar_decrypt(char* message, char* key) {
    for (int i = 0; message[i]!= '\0'; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] - key[i % MAX_KEY_SIZE] + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] - key[i % MAX_KEY_SIZE] + 'a';
        }
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];
    generate_key(key);
    printf("Enter the message to encrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);
    caesar_encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    printf("Enter the key: ");
    fgets(key, MAX_KEY_SIZE, stdin);
    caesar_decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}