//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LENGTH 10
#define MAX_MESSAGE_LENGTH 1000

void generate_key(char key[], int key_length);
void encrypt_message(char message[], char key[], char encrypted_message[]);
void decrypt_message(char encrypted_message[], char key[], char decrypted_message[]);

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    generate_key(key, MAX_KEY_LENGTH);

    printf("Encrypted message: ");
    encrypt_message(message, key, encrypted_message);
    printf("%s\n", encrypted_message);

    printf("Decrypted message: ");
    decrypt_message(encrypted_message, key, decrypted_message);
    printf("%s\n", decrypted_message);

    return 0;
}

void generate_key(char key[], int key_length) {
    time_t now = time(NULL);
    srand(now);

    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }

    key[key_length] = '\0';
}

void encrypt_message(char message[], char key[], char encrypted_message[]) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    for (int i = 0; i < message_length; i++) {
        encrypted_message[i] = (isalpha(message[i])? (message[i] + (key[i % key_length] - 'a' + 13) % 26) : message[i]);
    }

    encrypted_message[message_length] = '\0';
}

void decrypt_message(char encrypted_message[], char key[], char decrypted_message[]) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);

    for (int i = 0; i < encrypted_message_length; i++) {
        decrypted_message[i] = (isalpha(encrypted_message[i])? (encrypted_message[i] - (key[i % key_length] - 'a' + 13) % 26) : encrypted_message[i]);
    }

    decrypted_message[encrypted_message_length] = '\0';
}