//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 32
#define MAX_MSG_LEN 100

void generate_key(char key[], int key_len) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < key_len; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
    key[key_len] = '\0';
}

void encrypt(char msg[], int msg_len, char key[]) {
    for (int i = 0; i < msg_len; i++) {
        char c = toupper(msg[i]);
        if (isalpha(c)) {
            c = (c - 'A' + key[i % strlen(key)] - 'A') % 26 + 'A';
        }
        msg[i] = c;
    }
}

void decrypt(char msg[], int msg_len, char key[]) {
    for (int i = 0; i < msg_len; i++) {
        char c = toupper(msg[i]);
        if (isalpha(c)) {
            c = (c - 'A' + 'Z' - key[i % strlen(key)] - 'A') % 26 + 'A';
        }
        msg[i] = c;
    }
}

int main() {
    char msg[MAX_MSG_LEN];
    char key[MAX_KEY_LEN];
    int msg_len = 0, key_len = 0;

    printf("Enter message: ");
    scanf("%s", msg);
    msg_len = strlen(msg);

    printf("Enter key length (max %d): ", MAX_KEY_LEN - 1);
    scanf("%d", &key_len);

    generate_key(key, key_len);

    printf("Encrypted message: %s\n", msg);
    encrypt(msg, msg_len, key);
    printf("Decrypted message: %s\n", msg);

    return 0;
}