//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 16
#define MAX_MSG_LENGTH 256

void encrypt(char *msg, char *key, char *encrypted) {
    int len = strlen(msg);
    int key_len = strlen(key);
    int i, j;
    char c;
    for (i = 0; i < len; i++) {
        c = msg[i];
        j = i % key_len;
        encrypted[i] = c ^ key[j];
    }
    encrypted[i] = '\0';
}

void decrypt(char *encrypted, char *key, char *decrypted) {
    int len = strlen(encrypted);
    int key_len = strlen(key);
    int i, j;
    char c;
    for (i = 0; i < len; i++) {
        c = encrypted[i];
        j = i % key_len;
        decrypted[i] = c ^ key[j];
    }
    decrypted[i] = '\0';
}

int main() {
    char msg[MAX_MSG_LENGTH], key[MAX_KEY_LENGTH], encrypted[MAX_MSG_LENGTH], decrypted[MAX_MSG_LENGTH];

    printf("Enter the message: ");
    fgets(msg, MAX_MSG_LENGTH, stdin);

    printf("Enter the encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    encrypt(msg, key, encrypted);
    printf("Encrypted message: %s\n", encrypted);

    decrypt(encrypted, key, decrypted);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}