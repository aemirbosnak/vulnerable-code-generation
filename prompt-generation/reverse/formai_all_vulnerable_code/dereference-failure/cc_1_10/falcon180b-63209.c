//Falcon-180B DATASET v1.0 Category: Encryption ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LEN 32
#define MAX_MSG_LEN 1024

void generate_key(char* key, int key_len) {
    srand(time(NULL));
    for (int i = 0; i < key_len; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[key_len] = '\0';
}

void encrypt(char* msg, char* key, char* enc_msg) {
    int msg_len = strlen(msg);
    int key_len = strlen(key);

    for (int i = 0; i < msg_len; i++) {
        char ch = msg[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + key_len) % key_len + 'A';
        }
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + key_len) % key_len + 'a';
        }
        enc_msg[i] = ch;
    }
    enc_msg[msg_len] = '\0';
}

void decrypt(char* enc_msg, char* key, char* dec_msg) {
    int enc_len = strlen(enc_msg);
    int key_len = strlen(key);

    for (int i = 0; i < enc_len; i++) {
        char ch = enc_msg[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - key_len + 26) % 26 + 'A';
        }
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - key_len + 26) % 26 + 'a';
        }
        dec_msg[i] = ch;
    }
    dec_msg[enc_len] = '\0';
}

int main() {
    char msg[MAX_MSG_LEN];
    char key[MAX_KEY_LEN];
    char enc_msg[MAX_MSG_LEN];
    char dec_msg[MAX_MSG_LEN];

    printf("Enter a message to encrypt: ");
    fgets(msg, MAX_MSG_LEN, stdin);

    generate_key(key, MAX_KEY_LEN);

    encrypt(msg, key, enc_msg);

    printf("Encrypted message: %s\n", enc_msg);

    decrypt(enc_msg, key, dec_msg);

    printf("Decrypted message: %s\n", dec_msg);

    return 0;
}