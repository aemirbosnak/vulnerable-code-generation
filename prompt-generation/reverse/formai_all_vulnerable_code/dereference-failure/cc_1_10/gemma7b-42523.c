//Gemma-7B DATASET v1.0 Category: Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

#define ENCRYPT 1
#define DECRYPT 0

void encrypt(char *message, int key[], int key_size)
{
    int i, j, block_size, offset;

    block_size = key_size / BLOCK_SIZE;
    offset = key_size % BLOCK_SIZE;

    for (i = 0; i < block_size; i++)
    {
        for (j = 0; j < BLOCK_SIZE; j++)
        {
            int index = (i * BLOCK_SIZE) + j;

            if (index < key_size)
            {
                message[index] ^= key[index];
            }
        }
    }

    if (offset)
    {
        for (i = 0; i < offset; i++)
        {
            message[i] ^= key[i];
        }
    }
}

void decrypt(char *message, int key[], int key_size)
{
    int i, j, block_size, offset;

    block_size = key_size / BLOCK_SIZE;
    offset = key_size % BLOCK_SIZE;

    for (i = 0; i < block_size; i++)
    {
        for (j = 0; j < BLOCK_SIZE; j++)
        {
            int index = (i * BLOCK_SIZE) + j;

            if (index < key_size)
            {
                message[index] ^= key[index];
            }
        }
    }

    if (offset)
    {
        for (i = 0; i < offset; i++)
        {
            message[i] ^= key[i];
        }
    }
}

int main()
{
    char message[] = "The quick brown fox jumps over the lazy dog.";
    int key[] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xFF, 0x1B, 0x3D, 0x5F, 0x7B, 0x9D, 0xBF, 0xD1, 0xF3};

    encrypt(message, key, sizeof(key));

    printf("Encrypted message: %s\n", message);

    decrypt(message, key, sizeof(key));

    printf("Decrypted message: %s\n", message);

    return 0;
}