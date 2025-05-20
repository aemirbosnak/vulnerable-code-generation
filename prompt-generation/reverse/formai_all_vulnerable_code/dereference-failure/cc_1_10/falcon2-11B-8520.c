//Falcon2-11B DATASET v1.0 Category: Modern Encryption ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

void encrypt(unsigned char *data, unsigned char *key) {
    unsigned char block[BLOCK_SIZE];
    unsigned char output[BLOCK_SIZE];
    int i, j;

    for (i = 0; i < strlen(data); i += BLOCK_SIZE) {
        int block_start = i;
        int block_end = block_start + BLOCK_SIZE;
        if (block_end > strlen(data))
            block_end = strlen(data);

        // XOR each block with the corresponding key block
        for (j = 0; j < BLOCK_SIZE; j++) {
            output[j] = data[block_start + j] ^ key[j];
        }

        // Print the encrypted block
        for (j = 0; j < BLOCK_SIZE; j++) {
            printf("%02x", output[j]);
        }
        printf("\n");
    }
}

void decrypt(unsigned char *data, unsigned char *key) {
    unsigned char block[BLOCK_SIZE];
    unsigned char output[BLOCK_SIZE];
    int i, j;

    for (i = 0; i < strlen(data); i += BLOCK_SIZE) {
        int block_start = i;
        int block_end = block_start + BLOCK_SIZE;
        if (block_end > strlen(data))
            block_end = strlen(data);

        // XOR each block with the corresponding key block
        for (j = 0; j < BLOCK_SIZE; j++) {
            output[j] = data[block_start + j] ^ key[j];
        }

        // Print the decrypted block
        for (j = 0; j < BLOCK_SIZE; j++) {
            printf("%02x", output[j]);
        }
        printf("\n");
    }
}

int main() {
    unsigned char data[] = "Hello, World!";
    unsigned char key[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10};
    unsigned char encrypted_data[strlen(data) + 1];
    unsigned char decrypted_data[strlen(data) + 1];

    // Encrypt the data
    encrypt(data, key);

    // Decrypt the encrypted data
    decrypt(encrypted_data, key);

    // Print the decrypted data
    printf("Decrypted data: %s\n", decrypted_data);

    return 0;
}