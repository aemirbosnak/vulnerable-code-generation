//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 32
#define MAX_MSG_LEN 1024
#define MAX_BUF_LEN 1024

void encrypt(char *key, char *msg, char *buf);
void decrypt(char *key, char *buf, char *msg);

int main() {
    char key[MAX_KEY_LEN], msg[MAX_MSG_LEN], buf[MAX_BUF_LEN];

    printf("Enter the encryption key: ");
    fgets(key, MAX_KEY_LEN, stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove newline character

    printf("Enter the message to encrypt: ");
    fgets(msg, MAX_MSG_LEN, stdin);
    msg[strcspn(msg, "\n")] = '\0'; // Remove newline character

    encrypt(key, msg, buf);

    printf("Encrypted message: %s\n", buf);

    printf("Enter the encrypted message to decrypt: ");
    fgets(buf, MAX_BUF_LEN, stdin);
    buf[strcspn(buf, "\n")] = '\0'; // Remove newline character

    decrypt(key, buf, msg);

    printf("Decrypted message: %s\n", msg);

    return 0;
}

void encrypt(char *key, char *msg, char *buf) {
    int i, j, len = strlen(msg);

    for (i = 0, j = 0; i < len; i++, j += 2) {
        buf[j] = (char) (((int) msg[i] + (int) key[j % strlen(key)]) % 256);
    }

    buf[j] = '\0'; // Add null terminator
}

void decrypt(char *key, char *buf, char *msg) {
    int i, j, len = strlen(buf);

    for (i = 0, j = 0; i < len; i++, j += 2) {
        msg[i] = (char) (((int) buf[j] - (int) key[j % strlen(key)]) % 256);
    }

    msg[i] = '\0'; // Add null terminator
}