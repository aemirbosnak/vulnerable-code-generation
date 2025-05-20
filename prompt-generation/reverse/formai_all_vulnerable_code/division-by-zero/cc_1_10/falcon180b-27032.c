//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void encrypt(char *message, char *key) {
    int i, j;
    int key_length = strlen(key);
    int message_length = strlen(message);

    if (key_length > MAX_KEY_LENGTH || message_length > MAX_MESSAGE_LENGTH) {
        printf("Error: Key or message is too long.\n");
        return;
    }

    for (i = 0, j = 0; i < message_length; i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            char k = tolower(key[j % key_length]);
            if (isalpha(k)) {
                c = (c - k + 26) % 26 + 'a';
            }
        }
        printf("%c", c);
        j++;
    }
}

void decrypt(char *message, char *key) {
    int i, j;
    int key_length = strlen(key);
    int message_length = strlen(message);

    if (key_length > MAX_KEY_LENGTH || message_length > MAX_MESSAGE_LENGTH) {
        printf("Error: Key or message is too long.\n");
        return;
    }

    for (i = 0, j = 0; i < message_length; i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            char k = tolower(key[j % key_length]);
            if (isalpha(k)) {
                c = (c - k - 1 + 26) % 26 + 'a';
            }
        }
        printf("%c", c);
        j++;
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter a key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    encrypt(message, key);
    printf("\nEncrypted message: %s\n", message);

    decrypt(message, key);
    printf("\nDecrypted message: %s\n", message);

    return 0;
}