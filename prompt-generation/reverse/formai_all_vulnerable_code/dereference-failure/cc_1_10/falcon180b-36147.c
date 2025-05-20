//Falcon-180B DATASET v1.0 Category: Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "mysecretkey"
#define BUFFER_SIZE 1024

void encrypt(char* message, char* encrypted_message);
void decrypt(char* encrypted_message, char* decrypted_message);

int main() {
    char message[BUFFER_SIZE];
    char encrypted_message[BUFFER_SIZE];
    char decrypted_message[BUFFER_SIZE];

    printf("Enter a message to encrypt: ");
    fgets(message, BUFFER_SIZE, stdin);

    encrypt(message, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}

void encrypt(char* message, char* encrypted_message) {
    int i, j, k;
    char key[strlen(KEY)];

    strcpy(key, KEY);
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
            encrypted_message[j++] = message[i];
        } else {
            encrypted_message[j++] = message[i];
        }
    }

    for (i = 0, k = 0; i < strlen(encrypted_message); i++) {
        encrypted_message[i] = encrypted_message[i] + key[k];
        k = (k + 1) % strlen(key);
    }
}

void decrypt(char* encrypted_message, char* decrypted_message) {
    int i, j, k;
    char key[strlen(KEY)];

    strcpy(key, KEY);
    for (i = 0, j = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            encrypted_message[i] = encrypted_message[i] - key[j];
            decrypted_message[j++] = encrypted_message[i];
        } else {
            decrypted_message[j++] = encrypted_message[i];
        }
    }
}