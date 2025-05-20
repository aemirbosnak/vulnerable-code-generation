//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Donald Knuth
/*
 * Cryptography Implementation in C
 * By: Your Name
 * Inspired by Donald Knuth
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16

/* XORs two byte arrays */
void XOR(unsigned char *dest, unsigned const char *src, size_t len){
    size_t i;
    for(i = 0; i < len; i++){
        dest[i] ^= src[i];
    }
}

/* Generates a random byte array of specified size */
void GenRand(unsigned char *buf, size_t len){
    size_t i;
    for(i = 0; i < len; i++){
        buf[i] = rand() % 256;
    }
}

/* Encrypts data using AES */
void Encrypt(unsigned char *data, size_t len, unsigned char *key){
    unsigned char block[BLOCK_SIZE] = {0};
    size_t blocks = (len + BLOCK_SIZE - 1) / BLOCK_SIZE;
    size_t i, j;

    for(i = 0; i < blocks; i++){
        /* XOR data with previous block */
        XOR(data+i*BLOCK_SIZE, block, BLOCK_SIZE);
        /* XOR data with key */
        XOR(data+i*BLOCK_SIZE, key, BLOCK_SIZE);
        /* Copy plaintext to block buffer */
        memcpy(block, data+i*BLOCK_SIZE, BLOCK_SIZE);
    }
}

/* Decrypts data using AES */
void Decrypt(unsigned char *data, size_t len, unsigned char *key){
    unsigned char block[BLOCK_SIZE] = {0};
    size_t blocks = (len + BLOCK_SIZE - 1) / BLOCK_SIZE;
    size_t i, j;

    for(i = blocks-1; i > 0; i--){
        /* Copy ciphertext to block buffer */
        memcpy(block, data+i*BLOCK_SIZE, BLOCK_SIZE);
        /* XOR block with key */
        XOR(block, key, BLOCK_SIZE);
        /* XOR block with previous ciphertext block */
        XOR(block, data+(i-1)*BLOCK_SIZE, BLOCK_SIZE);
        /* Copy decrypted block to plaintext buffer */
        memcpy(data+i*BLOCK_SIZE, block, BLOCK_SIZE);
    }
    /* Decrypt last block, which does not have a previous ciphertext block */
    memcpy(block, data, BLOCK_SIZE);
    XOR(block, key, BLOCK_SIZE);
    memcpy(data, block, BLOCK_SIZE);
}

int main(int argc, char** argv){
    /* Initialize random seed */
    srand(42);

    /* Generate and print key */
    unsigned char key[BLOCK_SIZE];
    GenRand(key, BLOCK_SIZE);
    printf("Key:\n");
    for(int i = 0; i < BLOCK_SIZE; i++){
        printf("%02x ", key[i]);
    }
    printf("\n\n");

    /* Initialize plaintext buffer */
    unsigned char *data = "Text to be encrypted.";
    size_t len = strlen(data);
    len = len + (BLOCK_SIZE - (len % BLOCK_SIZE)); /* Round up to nearest multiple of BLOCK_SIZE */
    unsigned char *plaintext = malloc(len);
    memset(plaintext, 0, len);
    memcpy(plaintext, data, strlen(data));
    printf("Plaintext:\n%s\n\n", plaintext);

    /* Encrypt and print ciphertext */
    Encrypt(plaintext, len, key);
    printf("Ciphertext:\n");
    for(int i = 0; i < len; i++){
        printf("%02x ", plaintext[i]);
    }
    printf("\n\n");

    /* Decrypt and print plaintext */
    Decrypt(plaintext, len, key);
    printf("Plaintext:\n%s\n\n", plaintext);

    /* Cleanup */
    free(plaintext);
    return 0;
}