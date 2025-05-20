//Falcon-180B DATASET v1.0 Category: Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26

void generate_key(char* key, int length) {
    for (int i = 0; i < length; i++) {
        char c = rand() % SIZE + 'a';
        key[i] = toupper(c);
    }
}

void encrypt(char* message, char* key, char* encrypted_message) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int encrypted_message_length = message_length;

    for (int i = 0; i < message_length; i++) {
        char c = toupper(message[i]);
        int k = toupper(key[i % key_length]) - 'A';
        encrypted_message[i] = (c - 'A' + k) % SIZE + 'A';
    }
}

void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    int decrypted_message_length = encrypted_message_length;

    for (int i = 0; i < encrypted_message_length; i++) {
        char c = encrypted_message[i];
        int k = toupper(key[i % key_length]) - 'A';
        decrypted_message[i] = ((c - 'A' - k + SIZE) % SIZE + 'A');
    }
}

int main() {
    char message[100];
    char key[10];
    char encrypted_message[100];
    char decrypted_message[100];

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    generate_key(key, strlen(message));

    encrypt(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}