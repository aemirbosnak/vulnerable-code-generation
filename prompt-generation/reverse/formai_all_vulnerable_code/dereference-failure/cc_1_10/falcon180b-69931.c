//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 1000
#define MAX_MSG_SIZE 1000

typedef struct {
    char *key;
    int key_size;
} KeyPair;

KeyPair generate_keys() {
    int key_size = rand() % MAX_KEY_SIZE + 1;
    char *key = (char *) malloc(key_size * sizeof(char));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    return (KeyPair) {
       .key = key,
       .key_size = key_size
    };
}

char *encrypt(char *msg, KeyPair key) {
    int msg_size = strlen(msg);
    char *cipher_text = (char *) malloc(msg_size * sizeof(char));
    for (int i = 0; i < msg_size; i++) {
        if (isalpha(msg[i])) {
            cipher_text[i] = msg[i] ^ key.key[i % key.key_size];
        } else {
            cipher_text[i] = msg[i];
        }
    }
    return cipher_text;
}

char *decrypt(char *cipher_text, KeyPair key) {
    int msg_size = strlen(cipher_text);
    char *msg = (char *) malloc(msg_size * sizeof(char));
    for (int i = 0; i < msg_size; i++) {
        if (isalpha(cipher_text[i])) {
            msg[i] = cipher_text[i] ^ key.key[i % key.key_size];
        } else {
            msg[i] = cipher_text[i];
        }
    }
    return msg;
}

int main() {
    KeyPair keys = generate_keys();
    char *msg = "Hello, World!";
    char *cipher_text = encrypt(msg, keys);
    printf("Encrypted message: %s\n", cipher_text);
    char *decrypted_msg = decrypt(cipher_text, keys);
    printf("Decrypted message: %s\n", decrypted_msg);
    free(cipher_text);
    free(decrypted_msg);
    free(keys.key);
    return 0;
}