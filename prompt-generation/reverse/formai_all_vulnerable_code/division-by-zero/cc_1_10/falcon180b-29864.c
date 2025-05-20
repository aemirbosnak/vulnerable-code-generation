//Falcon-180B DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

void encrypt(char *message, char *key) {
    int i, j;
    char new_message[MAX_SIZE];
    strcpy(new_message, message);

    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                new_message[j++] = (char) (((int) message[i] + (int) key[i % strlen(key)]) % 26 + 65);
            } else {
                new_message[j++] = (char) (((int) message[i] + (int) key[i % strlen(key)]) % 26 + 97);
            }
        } else {
            new_message[j++] = message[i];
        }
    }

    new_message[j] = '\0';
    printf("Encrypted message: %s\n", new_message);
}

void decrypt(char *message, char *key) {
    int i, j;
    char new_message[MAX_SIZE];
    strcpy(new_message, message);

    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                new_message[j++] = (char) (((int) message[i] - (int) key[i % strlen(key)]) % 26 + 65);
            } else {
                new_message[j++] = (char) (((int) message[i] - (int) key[i % strlen(key)]) % 26 + 97);
            }
        } else {
            new_message[j++] = message[i];
        }
    }

    new_message[j] = '\0';
    printf("Decrypted message: %s\n", new_message);
}

int main() {
    char message[MAX_SIZE], key[MAX_SIZE];
    printf("Enter the message to be encrypted: ");
    fgets(message, MAX_SIZE, stdin);
    printf("Enter the encryption key: ");
    fgets(key, MAX_SIZE, stdin);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}