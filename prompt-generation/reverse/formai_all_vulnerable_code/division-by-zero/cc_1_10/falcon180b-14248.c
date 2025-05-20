//Falcon-180B DATASET v1.0 Category: Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26

void generate_key(char *key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
    }
}

int get_index(char c) {
    if (isalpha(c)) {
        return c - 'A';
    } else if (isdigit(c)) {
        return c - '0' + 26;
    } else {
        return -1;
    }
}

void encrypt(char *message, char *key) {
    int i, j;
    for (i = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            int index = get_index(message[i]);
            if (index >= 0) {
                index = (index + get_index(key[i % strlen(key)]) - 1) % SIZE;
                message[i] = (index < 26)? 'A' + index : 'a' + index - 26;
            }
        }
    }
}

void decrypt(char *message, char *key) {
    int i, j;
    for (i = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            int index = get_index(message[i]);
            if (index >= 0) {
                index = (index - get_index(key[i % strlen(key)]) + 26) % SIZE;
                message[i] = (index < 26)? 'A' + index : 'a' + index - 26;
            }
        }
    }
}

int main() {
    char message[1000], key[100];
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter a key to encrypt the message: ");
    fgets(key, sizeof(key), stdin);

    generate_key(key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}