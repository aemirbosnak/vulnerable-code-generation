//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 512

typedef struct {
    int len;
    unsigned char *data;
} message;

typedef struct {
    int len;
    unsigned char *data;
} key;

typedef struct {
    unsigned char *data;
} block;

int rand_int(int max) {
    return (rand() % max);
}

block random_block(void) {
    block b;
    b.data = malloc(BLOCK_SIZE);
    for (int i = 0; i < BLOCK_SIZE; i++) {
        b.data[i] = rand_int(256);
    }
    return b;
}

int blocks_equal(block b1, block b2) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        if (b1.data[i] != b2.data[i]) {
            return 0;
        }
    }
    return 1;
}

key generate_key() {
    key k;
    k.len = KEY_SIZE;
    k.data = malloc(k.len);
    for (int i = 0; i < k.len; i++) {
        k.data[i] = rand_int(256);
    }
    return k;
}

block encrypt_block(block plaintext, key k) {
    block ciphertext;
    ciphertext.data = malloc(BLOCK_SIZE);
    for (int i = 0; i < BLOCK_SIZE; i++) {
        int sum = 0;
        for (int j = 0; j < BLOCK_SIZE; j++) {
            sum += plaintext.data[j] * k.data[i * BLOCK_SIZE + j];
        }
        ciphertext.data[i] = sum % 256;
    }
    return ciphertext;
}

block decrypt_block(block ciphertext, key k) {
    block plaintext;
    plaintext.data = malloc(BLOCK_SIZE);
    for (int i = 0; i < BLOCK_SIZE; i++) {
        int sum = 0;
        for (int j = 0; j < BLOCK_SIZE; j++) {
            sum += ciphertext.data[j] * k.data[i * BLOCK_SIZE + j];
        }
        plaintext.data[i] = sum % 256;
    }
    return plaintext;
}

message encrypt_message(message plaintext, key k) {
    message ciphertext;
    ciphertext.len = plaintext.len;
    ciphertext.data = malloc(ciphertext.len);
    for (int i = 0; i < ciphertext.len / BLOCK_SIZE; i++) {
        block plaintext_block;
        plaintext_block.data = plaintext.data + i * BLOCK_SIZE;
        block ciphertext_block = encrypt_block(plaintext_block, k);
        memcpy(ciphertext.data + i * BLOCK_SIZE, ciphertext_block.data, BLOCK_SIZE);
    }
    return ciphertext;
}

message decrypt_message(message ciphertext, key k) {
    message plaintext;
    plaintext.len = ciphertext.len;
    plaintext.data = malloc(plaintext.len);
    for (int i = 0; i < plaintext.len / BLOCK_SIZE; i++) {
        block ciphertext_block;
        ciphertext_block.data = ciphertext.data + i * BLOCK_SIZE;
        block plaintext_block = decrypt_block(ciphertext_block, k);
        memcpy(plaintext.data + i * BLOCK_SIZE, plaintext_block.data, BLOCK_SIZE);
    }
    return plaintext;
}

int main(void) {
    srand(time(NULL));
    key k = generate_key();

    char plaintext_msg[] = "Hello, world!";
    int plaintext_len = strlen(plaintext_msg) + 1;
    message plaintext;
    plaintext.len = plaintext_len;
    plaintext.data = malloc(plaintext.len);
    memcpy(plaintext.data, plaintext_msg, plaintext.len);

    message ciphertext = encrypt_message(plaintext, k);

    printf("Plaintext: %s\n", plaintext.data);
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext.len; i++) {
        printf("%02x", ciphertext.data[i]);
    }
    printf("\n");

    message decrypted = decrypt_message(ciphertext, k);
    printf("Decrypted: %s\n", decrypted.data);

    free(plaintext.data);
    free(ciphertext.data);
    free(decrypted.data);
    free(k.data);

    return 0;
}