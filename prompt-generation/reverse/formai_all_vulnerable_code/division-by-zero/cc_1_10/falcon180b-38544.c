//Falcon-180B DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void encrypt(char* message, char* key) {
    int i, j, len = strlen(message);
    char result[MAX_LENGTH];
    result[0] = '\0';

    for(i = 0, j = 0; i < len; i++) {
        if(isalpha(message[i])) {
            message[i] = tolower(message[i]);
            result[j++] = message[i];
        }
    }

    for(i = 0, j = 0; i < len; i++) {
        if(isalpha(message[i])) {
            int key_index = tolower(key[j % strlen(key)]) - 'a';
            message[i] = 'a' + ((message[i] - 'a' + key_index) % 26);
            result[i] = message[i];
        } else {
            result[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", result);
}

void decrypt(char* message, char* key) {
    int i, j, len = strlen(message);
    char result[MAX_LENGTH];
    result[0] = '\0';

    for(i = 0, j = 0; i < len; i++) {
        if(isalpha(message[i])) {
            int key_index = tolower(key[j % strlen(key)]) - 'a';
            message[i] = 'a' + ((message[i] - 'a' - key_index + 26) % 26);
            result[i] = message[i];
        } else {
            result[i] = message[i];
        }
    }

    printf("Decrypted message: %s\n", result);
}

int main() {
    char message[MAX_LENGTH], key[MAX_LENGTH];

    printf("Enter message to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);

    printf("Enter encryption key: ");
    fgets(key, MAX_LENGTH, stdin);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}