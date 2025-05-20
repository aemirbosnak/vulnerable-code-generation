//FormAI DATASET v1.0 Category: Modern Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define max_key_len 16
#define max_message_len 1024

struct Cipher {
    unsigned char key[max_key_len];
    unsigned char decipher_key[max_key_len];
};

void generate_key(struct Cipher *cipher) {
    // This function generates a random key for the cipher
    for (int i = 0; i < max_key_len; i++) {
        cipher->key[i] = rand() % 256;
        cipher->decipher_key[i] = cipher->key[i];
    }
}

void encrypt(struct Cipher cipher, unsigned char *message, unsigned char *encrypted_message) {
    // This function encrypts a message using the provided cipher
    int key_len = strlen(cipher.key);
    int message_len = strlen(message);

    // XOR each message byte with a corresponding key byte
    for (int i = 0; i < message_len; i++) {
        encrypted_message[i] = message[i] ^ cipher.key[i % key_len];
    }
}

void decipher(struct Cipher cipher, unsigned char *encrypted_message, unsigned char *deciphered_message) {
    // This function deciphers an encrypted message using the provided cipher
    int key_len = strlen(cipher.decipher_key);
    int message_len = strlen(encrypted_message);

    // XOR each encrypted message byte with a corresponding decipher key byte
    for (int i = 0; i < message_len; i++) {
        deciphered_message[i] = encrypted_message[i] ^ cipher.decipher_key[i % key_len];
    }
}

int main() {
    srand(time(NULL));
    struct Cipher cipher;
    unsigned char message[max_message_len];
    unsigned char encrypted_message[max_message_len];
    unsigned char deciphered_message[max_message_len];

    generate_key(&cipher);

    printf("Enter a message to encrypt (max %d characters):\n", max_message_len);
    fgets(message, max_message_len, stdin);

    encrypt(cipher, message, encrypted_message);

    printf("Encrypted message:\n");
    for (int i = 0; i < strlen(message); i++) {
        printf("%02x ", encrypted_message[i]);
    }
    printf("\n");

    decipher(cipher, encrypted_message, deciphered_message);

    printf("Deciphered message:\n%s", deciphered_message);

    return 0;
}