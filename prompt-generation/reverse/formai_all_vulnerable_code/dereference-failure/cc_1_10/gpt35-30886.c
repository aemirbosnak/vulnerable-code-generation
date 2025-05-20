//FormAI DATASET v1.0 Category: Encryption ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

struct key_material {
    unsigned char key[KEY_SIZE];
    unsigned char iv[BLOCK_SIZE];
};

void initialize_key_material(struct key_material* material) {
    //generate random key and iv
    srand(time(NULL));
    for(int i=0; i<KEY_SIZE; i++) {
        material->key[i] = rand() % 256;
    }
    for(int i=0; i<BLOCK_SIZE; i++) {
        material->iv[i] = rand() % 256;
    }
}

void encrypt(unsigned char* plaintext, unsigned char* ciphertext, int size, struct key_material* material) {
    //initialize block cipher parameters
    unsigned char* key = material->key;
    unsigned char* iv = material->iv;

    //pad plaintext to multiple of BLOCK_SIZE
    int padding = BLOCK_SIZE - (size % BLOCK_SIZE);
    unsigned char* plaintext_padded = (unsigned char*) malloc(size + padding);
    memcpy(plaintext_padded, plaintext, size);
    memset(plaintext_padded + size, padding, padding);
    int blocks = (size + padding) / BLOCK_SIZE;

    //initialize previous block to iv
    unsigned char prev_block[BLOCK_SIZE];
    memcpy(prev_block, iv, BLOCK_SIZE);

    //encrypt each block using CBC mode
    for(int i=0; i<blocks; i++) {
        unsigned char block[BLOCK_SIZE];
        memcpy(block, plaintext_padded + (i * BLOCK_SIZE), BLOCK_SIZE);

        //xor with previous block
        for(int j=0; j<BLOCK_SIZE; j++) {
            block[j] ^= prev_block[j];
        }

        //apply block cipher
        for(int j=0; j<BLOCK_SIZE; j++) {
            block[j] ^= key[j];
        }

        //save ciphertext and previous block
        memcpy(ciphertext + (i * BLOCK_SIZE), block, BLOCK_SIZE);
        memcpy(prev_block, block, BLOCK_SIZE);
    }

    free(plaintext_padded);
}

int main() {
    //prompt user for plaintext
    char input[1000];
    printf("Enter plaintext: ");
    fgets(input, 1000, stdin);
    int size = strlen(input) - 1;
    unsigned char plaintext[size];
    memcpy(plaintext, input, size);

    //initialize key material
    struct key_material material;
    initialize_key_material(&material);

    //encrypt plaintext
    unsigned char ciphertext[size + BLOCK_SIZE];
    encrypt(plaintext, ciphertext, size, &material);

    //print ciphertext and key/iv
    printf("Ciphertext: ");
    for(int i=0; i<size+BLOCK_SIZE; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\nKey: ");
    for(int i=0; i<KEY_SIZE; i++) {
        printf("%02x", material.key[i]);
    }
    printf("\nIV: ");
    for(int i=0; i<BLOCK_SIZE; i++) {
        printf("%02x", material.iv[i]);
    }
    printf("\n");

    return 0;
}