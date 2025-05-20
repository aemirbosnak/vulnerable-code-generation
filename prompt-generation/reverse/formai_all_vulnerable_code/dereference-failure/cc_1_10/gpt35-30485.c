//FormAI DATASET v1.0 Category: Modern Encryption ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

unsigned char* encrypt(unsigned char* plaintext, unsigned long long plaintext_len, unsigned char* key, unsigned char* iv, unsigned long long* ciphertext_len) {
    
    *ciphertext_len = plaintext_len + 16; // Add space for padding and IV
    
    if (*ciphertext_len % 16 != 0) {
        *ciphertext_len += 16 - (*ciphertext_len % 16); // Add padding to make ciphertext length a multiple of 16
    }

    unsigned char* ciphertext = malloc(*ciphertext_len);

    // Add IV to beginning of ciphertext
    memcpy(ciphertext, iv, 16);

    // Generate random seed for key schedule
    srand(time(NULL));

    // Key schedule 
    unsigned long long w[60];
    unsigned long long temp;

    for (int i = 0; i < 8; i++) {
        w[i] = key[i*8] << 56 | key[i*8+1] << 48 | key[i*8+2] << 40 | key[i*8+3] << 32 | key[i*8+4] << 24 | key[i*8+5] << 16 | key[i*8+6] << 8 | key[i*8+7];
    }

    for (int i = 8; i < 60; i++) {
        temp = w[i-8] ^ w[i-5] ^ w[i-3] ^ w[i-1] ^ 0x9e3779b97f4a7c13 ^ i; // Addition with constant is called add_const operation
        w[i] = (temp << 1) | (temp >> 63); // Rotate left by 1
    }

    // ECB mode encryption
    unsigned long long num_blocks = *ciphertext_len/16;

    for (int i = 0; i < num_blocks; i++) {

        unsigned long long block[2];
        memcpy(block, plaintext + (i*16), 16);

        // Whiten and permute input
        block[0] ^= w[0];
        block[1] ^= w[1];
        for (int j = 1; j <= 9; j++) {

            block[1] ^= ((block[0] << 7) | (block[0] >> 57));
            temp = block[0] ^ w[j*6];
            temp &= 0xaaaaaaaaaaaaaaaa; // Mask with 1010...
            block[0] ^= temp;
            block[1] ^= w[j*6+1];

            block[0] ^= ((block[1] << 7) | (block[1] >> 57));
            temp = block[1] ^ w[j*6+2];
            temp &= 0xaaaaaaaaaaaaaaaa; // Mask with 1010...
            block[1] ^= temp;
            block[0] ^= w[j*6+3];

        }
        block[1] ^= ((block[0] << 7) | (block[0] >> 57));
        block[0] ^= w[10];
        block[1] ^= w[11];

        // Write output
        memcpy(ciphertext + 16 + (i*16), block, 16);
    }

    return ciphertext;
}

unsigned char* decrypt(unsigned char* ciphertext, unsigned long long ciphertext_len, unsigned char* key, unsigned char* iv, unsigned long long* plaintext_len) {

    *plaintext_len = ciphertext_len - 16; // Subtract IV

    unsigned char* plaintext = malloc(*plaintext_len);

    // Key schedule
    unsigned long long w[60];
    unsigned long long temp;

    for (int i = 0; i < 8; i++) {
        w[i] = key[i*8] << 56 | key[i*8+1] << 48 | key[i*8+2] << 40 | key[i*8+3] << 32 | key[i*8+4] << 24 | key[i*8+5] << 16 | key[i*8+6] << 8 | key[i*8+7];
    }

    for (int i = 8; i < 60; i++) {
        temp = w[i-8] ^ w[i-5] ^ w[i-3] ^ w[i-1] ^ 0x9e3779b97f4a7c13 ^ i;
        w[i] = (temp << 1) | (temp >> 63);
    }

    // ECB decryption
    unsigned long long num_blocks = *plaintext_len/16;

    for (int i = 0; i < num_blocks; i++) {

        unsigned long long block[2];
        memcpy(block, ciphertext + 16 + (i*16), 16);

        // Create key schedule in reverse order
        unsigned long long reverse_w[60];
        for (int j = 0; j < 60; j++) {
            reverse_w[j] = w[59-j];
        }

        // Whiten and permute input
        block[1] ^= reverse_w[0];
        block[0] ^= reverse_w[1];
        for (int j = 1; j <= 9; j++) {
            block[0] ^= reverse_w[j*6+3];
            block[1] ^= reverse_w[j*6+2];

            temp = block[1] ^ reverse_w[j*6+1];
            temp &= 0xaaaaaaaaaaaaaaaa;
            block[1] ^= temp;
            block[0] ^= reverse_w[j*6];

            block[1] ^= ((block[0] << 7) | (block[0] >> 57));
            block[0] ^= reverse_w[(j*6)+3];

            temp = block[0] ^ reverse_w[j*6+2];
            temp &= 0xaaaaaaaaaaaaaaaa;
            block[0] ^= temp;
            block[1] ^= reverse_w[j*6+1];
        }
        block[0] ^= reverse_w[10];
        block[1] ^= reverse_w[11];
        block[1] ^= ((block[0] << 7) | (block[0] >> 57));

        // Write output
        memcpy(plaintext + (i*16), block, 16);
    }

    return plaintext;
}

int main() {

    unsigned char plaintext[] = "This is a secret message!";
    unsigned long long plaintext_len = strlen((const char*) plaintext);

    // Generate random key and IV
    unsigned char key[32];
    unsigned char iv[16];

    for (int i = 0; i < 32; i++) {
        key[i] = rand() % 256;
    }
    for (int i = 0; i < 16; i++) {
        iv[i] = rand() % 256;
    }

    // Encryption
    unsigned long long ciphertext_len;
    unsigned char* ciphertext = encrypt(plaintext, plaintext_len, key, iv, &ciphertext_len);

    // Decryption
    unsigned long long decrypted_len;
    unsigned char* decrypted = decrypt(ciphertext, ciphertext_len, key, iv, &decrypted_len);

    if (memcmp(plaintext, decrypted, plaintext_len) == 0) {
        printf("Success!\n");
    } else {
        printf("Error: plaintext and decrypted do not match.\n");
    }

    free(ciphertext);
    free(decrypted);

    return 0;
}