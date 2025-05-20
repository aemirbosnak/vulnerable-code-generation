//Falcon-180B DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000
#define ALPHABET_SIZE 26

void generate_key(char key[], int key_length) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int i;
    for (i = 0; i < key_length; i++) {
        key[i] = alphabet[rand() % strlen(alphabet)];
    }
}

void encrypt(char message[], char key[], char encrypted_message[]) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            encrypted_message[j++] = key[(int)message[i] - 97];
        } else {
            encrypted_message[j++] = message[i];
        }
    }
    encrypted_message[j] = '\0';
}

void decrypt(char encrypted_message[], char key[], char decrypted_message[]) {
    int i, j;
    for (i = 0, j = 0; encrypted_message[i]!= '\0'; i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[j++] = (char)((int)encrypted_message[i] + 97);
        } else {
            decrypted_message[j++] = encrypted_message[i];
        }
    }
    decrypted_message[j] = '\0';
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter a key to encrypt the message: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    generate_key(key, strlen(key));

    encrypt(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}