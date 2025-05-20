//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16

typedef unsigned char byte;

void encrypt(const byte *key, const byte *plaintext, byte *ciphertext) {
    byte round_key[BLOCK_SIZE];
    memcpy(round_key, key, BLOCK_SIZE);

    for (int i = 0; i < BLOCK_SIZE; i++) {
        ciphertext[i] = plaintext[i] ^ round_key[i];
    }

    for (int round = 0; round < 10; round++) {
        byte s_box[BLOCK_SIZE];
        for (int i = 0; i < BLOCK_SIZE; i++) {
            s_box[i] = ciphertext[i] ^ round_key[i];
        }

        byte sub_key[BLOCK_SIZE];
        for (int i = 0; i < BLOCK_SIZE; i++) {
            sub_key[i] = round_key[(i + 1) % BLOCK_SIZE];
        }

        byte s_box_output[BLOCK_SIZE];
        for (int i = 0; i < BLOCK_SIZE; i++) {
            s_box_output[i] = s_box[(i + s_box[i]) % BLOCK_SIZE];
        }

        for (int i = 0; i < BLOCK_SIZE; i++) {
            round_key[i] = sub_key[i] ^ s_box_output[i];
        }

        for (int i = 0; i < BLOCK_SIZE; i++) {
            ciphertext[i] = s_box_output[i] ^ plaintext[i];
        }
    }
}

int main() {
    const char *key_str = "Cryptography!";
    const char *plaintext_str = "Hello, world!";
    const size_t len = strlen(plaintext_str);
    
    byte key[BLOCK_SIZE];
    memcpy(key, key_str, BLOCK_SIZE);
    
    byte plaintext[BLOCK_SIZE];
    byte ciphertext[BLOCK_SIZE];

    for (int i = 0; i < len; i += BLOCK_SIZE) {
        strncpy(plaintext, plaintext_str + i, BLOCK_SIZE);
        encrypt(key, plaintext, ciphertext);
        fwrite(ciphertext, sizeof(byte), BLOCK_SIZE, stdout);
    }
    
    return 0;
}