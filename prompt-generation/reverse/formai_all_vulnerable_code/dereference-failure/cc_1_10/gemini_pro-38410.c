//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// This function generates a random key of length keylen
unsigned char *generate_key(int keylen) {
    unsigned char *key = malloc(keylen);
    for (int i = 0; i < keylen; i++) {
        key[i] = rand() % 256;
    }
    return key;
}

// This function encrypts a message using a key
unsigned char *encrypt(unsigned char *message, int msglen, unsigned char *key, int keylen) {
    unsigned char *ciphertext = malloc(msglen);
    for (int i = 0; i < msglen; i++) {
        ciphertext[i] = message[i] ^ key[i % keylen];
    }
    return ciphertext;
}

// This function decrypts a ciphertext using a key
unsigned char *decrypt(unsigned char *ciphertext, int msglen, unsigned char *key, int keylen) {
    unsigned char *message = malloc(msglen);
    for (int i = 0; i < msglen; i++) {
        message[i] = ciphertext[i] ^ key[i % keylen];
    }
    return message;
}

int main() {
    // Generate a random key of length 16
    unsigned char *key = generate_key(16);

    // Encrypt a message using the key
    unsigned char *message = "Hello, world!";
    int msglen = strlen(message);
    unsigned char *ciphertext = encrypt(message, msglen, key, 16);

    // Decrypt the ciphertext using the key
    unsigned char *decrypted_message = decrypt(ciphertext, msglen, key, 16);

    // Print the original message, the ciphertext, and the decrypted message
    printf("Original message: %s\n", message);
    printf("Ciphertext: ");
    for (int i = 0; i < msglen; i++) {
        printf("%02X", ciphertext[i]);
    }
    printf("\n");
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}