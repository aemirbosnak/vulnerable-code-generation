//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_SIZE 1024
#define MAX_MSG_SIZE 4096

typedef struct {
    char *public_key;
    char *private_key;
    long key_size;
} KeyPair;

KeyPair generate_keys() {
    KeyPair key_pair;
    char *public_key = malloc(MAX_KEY_SIZE);
    char *private_key = malloc(MAX_KEY_SIZE);
    long key_size = 1024;
    srand(time(NULL));
    for (int i = 0; i < key_size; i++) {
        public_key[i] = 'a' + rand() % 26;
        private_key[i] = 'A' + rand() % 26;
    }
    key_pair.public_key = public_key;
    key_pair.private_key = private_key;
    key_pair.key_size = key_size;
    return key_pair;
}

char *encrypt(char *message, KeyPair key_pair) {
    char *encrypted_message = malloc(MAX_MSG_SIZE);
    long message_size = strlen(message);
    long key_size = key_pair.key_size;
    for (int i = 0; i < message_size; i++) {
        char c = message[i];
        if (isupper(c)) {
            encrypted_message[i] = 'A' + (c - 'A' + key_pair.private_key[i % key_size] - 'A') % 26;
        } else {
            encrypted_message[i] = 'a' + (c - 'a' + key_pair.private_key[i % key_size] - 'A') % 26;
        }
    }
    return encrypted_message;
}

char *decrypt(char *message, KeyPair key_pair) {
    char *decrypted_message = malloc(MAX_MSG_SIZE);
    long message_size = strlen(message);
    long key_size = key_pair.key_size;
    for (int i = 0; i < message_size; i++) {
        char c = message[i];
        if (isupper(c)) {
            decrypted_message[i] = 'A' + (c - 'A' - key_pair.public_key[i % key_size] - 'A' + 26) % 26;
        } else {
            decrypted_message[i] = 'a' + (c - 'a' - key_pair.public_key[i % key_size] - 'A' + 26) % 26;
        }
    }
    return decrypted_message;
}

int main() {
    KeyPair key_pair = generate_keys();
    char *message = "Romeo, Romeo! wherefore art thou Romeo?";
    char *encrypted_message = encrypt(message, key_pair);
    printf("Encrypted message: %s\n", encrypted_message);
    char *decrypted_message = decrypt(encrypted_message, key_pair);
    printf("Decrypted message: %s\n", decrypted_message);
    return 0;
}