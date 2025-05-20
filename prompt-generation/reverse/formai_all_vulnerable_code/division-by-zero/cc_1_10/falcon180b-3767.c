//Falcon-180B DATASET v1.0 Category: Encryption ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 16
#define MAX_MESSAGE_SIZE 1000

void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;

    if (key_length > MAX_KEY_SIZE) {
        printf("Error: Key is too long\n");
        exit(1);
    }

    for (i = 0; i < message_length; i++) {
        char c = toupper(message[i]);

        if (isalpha(c)) {
            int shift = (int) (key[i % key_length] - 'A');

            if (isupper(c)) {
                c = (char) (((c - 'A') + shift) % 26 + 'A');
            } else {
                c = (char) (((c - 'a') + shift) % 26 + 'a');
            }
        }

        printf("%c", c);
    }
}

void decrypt(char *encrypted_message, char *key) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    int i, j;

    if (key_length > MAX_KEY_SIZE) {
        printf("Error: Key is too long\n");
        exit(1);
    }

    for (i = 0; i < encrypted_message_length; i++) {
        char c = encrypted_message[i];

        if (isalpha(c)) {
            int shift = (int) (key[i % key_length] - 'A');

            if (isupper(c)) {
                c = (char) (((c - 'A') - shift + 26) % 26 + 'A');
            } else {
                c = (char) (((c - 'a') - shift + 26) % 26 + 'a');
            }
        }

        printf("%c", c);
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];

    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_SIZE, stdin);

    encrypt(message, key);
    printf("\nEncrypted message: %s\n", message);

    decrypt(message, key);
    printf("\nDecrypted message: %s\n", message);

    return 0;
}