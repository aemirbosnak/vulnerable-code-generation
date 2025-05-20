//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void encrypt(char *message, char *key);
void decrypt(char *encrypted_message, char *key);

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter your message:\n");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter your key:\n");
    fgets(key, MAX_KEY_LENGTH, stdin);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, char *key) {
    int i, j, k;
    char encrypted_message[MAX_MESSAGE_LENGTH];

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isupper(message[i])) {
            message[i] = toupper(message[i] + key[j]);
        } else if (islower(message[i])) {
            message[i] = tolower(message[i] + key[j]);
        } else {
            message[i] = message[i];
        }
        j = (j + 1) % strlen(key);
    }

    strcpy(encrypted_message, message);
}

void decrypt(char *encrypted_message, char *key) {
    int i, j, k;
    char decrypted_message[MAX_MESSAGE_LENGTH];

    for (i = 0, j = 0; encrypted_message[i]!= '\0'; i++) {
        if (isupper(encrypted_message[i])) {
            encrypted_message[i] = toupper(encrypted_message[i] - key[j]);
        } else if (islower(encrypted_message[i])) {
            encrypted_message[i] = tolower(encrypted_message[i] - key[j]);
        } else {
            encrypted_message[i] = encrypted_message[i];
        }
        j = (j + 1) % strlen(key);
    }

    strcpy(decrypted_message, encrypted_message);
}