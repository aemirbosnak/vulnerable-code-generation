//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 32
#define MAX_MSG_LEN 1024

void generate_key(char* key, int len) {
    for (int i = 0; i < len; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[len] = '\0';
}

void encrypt(char* msg, char* key, char* res) {
    int len = strlen(msg);
    for (int i = 0; i < len; i++) {
        if (isalpha(msg[i])) {
            res[i] = (tolower(msg[i]) - 'a' + (key[i % strlen(key)] - 'a')) % 26 + 'a';
        } else {
            res[i] = msg[i];
        }
    }
    res[len] = '\0';
}

void decrypt(char* msg, char* key, char* res) {
    int len = strlen(msg);
    for (int i = 0; i < len; i++) {
        if (isalpha(msg[i])) {
            res[i] = (tolower(msg[i]) - 'a' - (key[i % strlen(key)] - 'a' + 26) % 26) % 26 + 'a';
        } else {
            res[i] = msg[i];
        }
    }
    res[len] = '\0';
}

int main() {
    char key[MAX_KEY_LEN];
    char msg[MAX_MSG_LEN];
    char res[MAX_MSG_LEN];

    printf("Enter message to encrypt: ");
    fgets(msg, MAX_MSG_LEN, stdin);
    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_LEN, stdin);

    generate_key(key, strlen(key));
    encrypt(msg, key, res);

    printf("Encrypted message: %s\n", res);

    printf("Enter decryption key: ");
    fgets(key, MAX_KEY_LEN, stdin);

    decrypt(res, key, msg);
    printf("Decrypted message: %s\n", msg);

    return 0;
}