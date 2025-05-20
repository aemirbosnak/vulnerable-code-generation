//FormAI DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16

void encrypt(char message[], char key[]);
void decrypt(char message[], char key[]);

int main()
{
    char message[] = "secret message";
    char key[] = "my secret key";

    printf("Original message: %s\n", message);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char message[], char key[])
{
    int i, j, k = 0;
    char block[BLOCK_SIZE];
    unsigned char round_key[BLOCK_SIZE];

    size_t message_length = strlen(message);
    size_t key_length = strlen(key);

    // Initialize roundkeys
    for (i = 0; i < BLOCK_SIZE; i++)
    {
        round_key[i] = key[i % key_length];
    }

    // Divide message into blocks and encrypt each block
    for (i = 0; i < message_length; i += BLOCK_SIZE)
    {
        // Copy block into buffer
        memset(block, 0, BLOCK_SIZE);
        memcpy(block, message + i, BLOCK_SIZE);

        // XOR block with round_key
        for (j = 0; j < BLOCK_SIZE; j++)
        {
            block[j] ^= round_key[j];
        }

        // Copy block back into message
        memcpy(message + i, block, BLOCK_SIZE);

        // Update round_key
        for (j = 0; j < BLOCK_SIZE; j++)
        {
            round_key[j] += block[(j + k) % BLOCK_SIZE];
        }

        k++;
    }
}

void decrypt(char message[], char key[])
{
    int i, j, k = 0;
    char block[BLOCK_SIZE];
    unsigned char round_key[BLOCK_SIZE];
    unsigned char temp_round_key[BLOCK_SIZE];

    size_t message_length = strlen(message);
    size_t key_length = strlen(key);

    // Initialize roundkeys
    for (i = 0; i < BLOCK_SIZE; i++)
    {
        round_key[i] = key[i % key_length];
    }

    // Discover original key
    for (i = message_length; i >= 0; i -= BLOCK_SIZE)
    {
        // Copy block into buffer
        memset(block, 0, BLOCK_SIZE);
        memcpy(block, message + i - BLOCK_SIZE, BLOCK_SIZE);

        // Update temp_round_key
        for (j = 0; j < BLOCK_SIZE; j++)
        {
            temp_round_key[j] = round_key[j];
            round_key[j] -= block[(j + k) % BLOCK_SIZE];
        }

        // XOR block with temp_round_key
        for (j = 0; j < BLOCK_SIZE; j++)
        {
            block[j] ^= temp_round_key[j];
        }

        // Copy block back into message
        memcpy(message + i - BLOCK_SIZE, block, BLOCK_SIZE);

        k++;
    }
}