//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(unsigned char *key)
{
    time_t t;
    time(&t);
    srand(t);
    for(int i=0; i<KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *ciphertext)
{
    int i, j;
    unsigned char pad[BLOCK_SIZE];
    int pad_len = BLOCK_SIZE - (plaintext_len % BLOCK_SIZE);
    for(i=0; i<pad_len; i++) {
        pad[i] = pad_len;
    }
    for(i=0; i<plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % KEY_SIZE];
    }
    for(i=0; i<pad_len; i++) {
        ciphertext[plaintext_len + i] = pad[i];
    }
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *plaintext)
{
    int i, j;
    unsigned char pad[BLOCK_SIZE];
    int pad_len = ciphertext[ciphertext_len - 1];
    for(i=0; i<pad_len; i++) {
        pad[i] = pad_len;
    }
    for(i=0; i<ciphertext_len - pad_len; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % KEY_SIZE];
    }
}

int main()
{
    unsigned char key[KEY_SIZE];
    generate_key(key);

    unsigned char plaintext[100];
    strcpy(plaintext, "This is a secret message");
    int plaintext_len = strlen(plaintext);

    unsigned char ciphertext[100];
    int ciphertext_len;

    encrypt(plaintext, plaintext_len, key, ciphertext);
    printf("Encrypted message: %s\n", ciphertext);
    ciphertext_len = strlen(ciphertext);

    decrypt(ciphertext, ciphertext_len, key, plaintext);
    printf("Decrypted message: %s\n", plaintext);

    return 0;
}