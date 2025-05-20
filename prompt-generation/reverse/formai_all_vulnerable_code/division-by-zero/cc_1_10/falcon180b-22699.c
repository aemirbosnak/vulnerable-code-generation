//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MESSAGE_SIZE 1000

// Function to generate a random key
void generate_key(char* key) {
    srand(time(NULL));
    for (int i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'a';
    }
}

// Function to encrypt the message using the key
void encrypt(char* message, char* key, char* encrypted_message) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = message[i] + (key[i % strlen(key)] - 'a');
        } else {
            encrypted_message[i] = message[i];
        }
    }
}

// Function to decrypt the message using the key
void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[i] = encrypted_message[i] - (key[i % strlen(key)] - 'a');
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_MESSAGE_SIZE];
    char encrypted_message[MAX_MESSAGE_SIZE];
    char decrypted_message[MAX_MESSAGE_SIZE];

    printf("Enter a message for Romeo to send to Juliet: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    generate_key(key);

    printf("Encrypted message: ");
    encrypt(message, key, encrypted_message);
    printf("%s\n", encrypted_message);

    printf("Decrypted message: ");
    decrypt(encrypted_message, key, decrypted_message);
    printf("%s\n", decrypted_message);

    return 0;
}