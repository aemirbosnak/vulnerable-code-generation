//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 64
#define OUTPUT_SIZE 32

unsigned char* hash(const char* message, int message_len);

int main() {
    char message[1024];

    printf("Enter a message to hash (max length 1024): ");
    fgets(message, 1024, stdin);

    unsigned char* digest = hash(message, strlen(message));

    printf("Hash: ");
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        printf("%02x", *(digest + i));
    }
    printf("\n");

    free(digest);

    return 0;
}

unsigned char* hash(const char* message, int message_len) {
    // Initialize state variables
    unsigned int state[8] = {
        0x01234567,
        0x89abcdef,
        0xfedcba98,
        0x76543210,
        0xbadcfe00,
        0xdeadbeef,
        0xfaceb00c,
        0xfeedd00d
    };

    // Pad the input message
    int padding_len = BLOCK_SIZE - (message_len % BLOCK_SIZE);
    int padded_len = message_len + padding_len;

    unsigned char* data = (unsigned char*)calloc(padded_len, sizeof(unsigned char));
    memcpy(data, message, message_len);
    memset(data + message_len, 0x80, 1);
    memset(data + padded_len - 8, message_len*8, 8);

    // Process the padded message
    for (int i = 0; i < padded_len; i += BLOCK_SIZE) {
        unsigned int block[16];

        memcpy(block, data + i, BLOCK_SIZE);

        for (int j = 0; j < 16; j++) {
            if (j < 8) {
                state[j] ^= block[j];
            }
            else if (j % 8 == 0) {
                state[0] -= state[7];
                state[1] ^= state[0];
                state[2] += state[1];
                state[3] -= state[2];
                state[4] ^= state[3];
                state[5] += state[4];
                state[6] -= state[5];
                state[7] ^= state[6];

                state[j % 8] ^= block[j];
            }
            else {
                state[j % 8] ^= block[j];
            }
        }
    }

    // Generate output
    unsigned char* digest = (unsigned char*)calloc(OUTPUT_SIZE, sizeof(unsigned char));

    for (int i = 0; i < 8; i++) {
        unsigned char* temp = (unsigned char*)&state[i];
        memcpy(digest + (i*4), temp, 4);
    }

    free(data);

    return digest;
}