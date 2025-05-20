//Falcon-180B DATASET v1.0 Category: Encryption ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_MSG_LEN 1000

void encrypt(char *key, char *msg, char *result) {
    int i, j, n;
    char ch;
    int key_index = 0;

    for (i = 0; i < strlen(msg); i++) {
        ch = tolower(msg[i]);
        if (isalpha(ch)) {
            n = ch - 'a';
            if (n < 0) {
                n += 26;
            }
            result[i] = (char) ((ch + key[key_index]) % 26 + 'a');
            key_index = (key_index + 1) % strlen(key);
        } else {
            result[i] = msg[i];
        }
    }
    result[strlen(msg)] = '\0';
}

void decrypt(char *key, char *msg, char *result) {
    int i, j, n;
    char ch;
    int key_index = 0;

    for (i = 0; i < strlen(msg); i++) {
        ch = tolower(msg[i]);
        if (isalpha(ch)) {
            n = ch - 'a';
            if (n < 0) {
                n += 26;
            }
            result[i] = (char) ((ch - key[key_index]) % 26 + 'a');
            key_index = (key_index + 25) % strlen(key);
        } else {
            result[i] = msg[i];
        }
    }
    result[strlen(msg)] = '\0';
}

int main() {
    char key[MAX_KEY_LEN];
    char msg[MAX_MSG_LEN];
    char result[MAX_MSG_LEN];

    printf("Enter a message to encrypt: ");
    fgets(msg, sizeof(msg), stdin);
    printf("Enter a key: ");
    fgets(key, sizeof(key), stdin);

    encrypt(key, msg, result);

    printf("Encrypted message: %s\n", result);

    printf("Enter the encrypted message to decrypt: ");
    fgets(result, sizeof(result), stdin);
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    decrypt(key, result, msg);

    printf("Decrypted message: %s\n", msg);

    return 0;
}