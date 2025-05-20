//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 256

typedef struct {
    int size;
    unsigned char *data;
} PublicKey;

typedef struct {
    int size;
    unsigned char *data;
} PrivateKey;

PublicKey *generate_public_key(PrivateKey *private_key) {
    PublicKey *public_key = malloc(sizeof(PublicKey));
    public_key->size = private_key->size;
    public_key->data = malloc(private_key->size);
    memcpy(public_key->data, private_key->data, private_key->size);
    return public_key;
}

PrivateKey *generate_private_key(int size) {
    PrivateKey *private_key = malloc(sizeof(PrivateKey));
    private_key->size = size;
    private_key->data = malloc(size);
    for (int i = 0; i < size; i++) {
        private_key->data[i] = rand() % 256;
    }
    return private_key;
}

void encrypt(unsigned char *plaintext, int plaintext_size, PublicKey *public_key, unsigned char *ciphertext) {
    for (int i = 0; i < plaintext_size; i++) {
        ciphertext[i] = plaintext[i] ^ public_key->data[i % public_key->size];
    }
}

void decrypt(unsigned char *ciphertext, int ciphertext_size, PrivateKey *private_key, unsigned char *plaintext) {
    for (int i = 0; i < ciphertext_size; i++) {
        plaintext[i] = ciphertext[i] ^ private_key->data[i % private_key->size];
    }
}

void print_key(char *name, PublicKey *public_key) {
    printf("%s: ", name);
    for (int i = 0; i < public_key->size; i++) {
        printf("%02x", public_key->data[i]);
    }
    printf("\n");
}

int main() {
    PrivateKey *private_key = generate_private_key(MAX_KEY_SIZE);
    PublicKey *public_key = generate_public_key(private_key);

    print_key("Public key", public_key);
    print_key("Private key", private_key);

    unsigned char plaintext[] = "Hello, world!";
    int plaintext_size = strlen(plaintext);
    unsigned char ciphertext[MAX_KEY_SIZE];
    encrypt(plaintext, plaintext_size, public_key, ciphertext);

    unsigned char decryptedtext[MAX_KEY_SIZE];
    decrypt(ciphertext, plaintext_size, private_key, decryptedtext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for (int i = 0; i < plaintext_size; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    printf("Decryptedtext: %s\n", decryptedtext);

    free(private_key->data);
    free(private_key);
    free(public_key->data);
    free(public_key);

    return 0;
}