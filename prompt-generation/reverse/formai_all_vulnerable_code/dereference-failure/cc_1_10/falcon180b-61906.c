//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8

// Function to encrypt the input data using the given key
void encrypt(char* input, char* key, char* output)
{
    int i, j;
    char temp[KEY_LENGTH];

    // Copy the key to a temporary buffer
    strcpy(temp, key);

    // XOR each character in the input with the corresponding character in the key
    for (i = 0; i < strlen(input); i++)
    {
        output[i] = input[i] ^ temp[i % KEY_LENGTH];
    }
}

// Function to decrypt the input data using the given key
void decrypt(char* input, char* key, char* output)
{
    int i, j;
    char temp[KEY_LENGTH];

    // Copy the key to a temporary buffer
    strcpy(temp, key);

    // XOR each character in the input with the corresponding character in the key
    for (i = 0; i < strlen(input); i++)
    {
        output[i] = input[i] ^ temp[i % KEY_LENGTH];
    }
}

// Function to generate a random key
void generate_key(char* key)
{
    int i;

    // Fill the key with random characters
    for (i = 0; i < KEY_LENGTH; i++)
    {
        key[i] = rand() % 256;
    }
}

int main()
{
    char input[BLOCK_SIZE];
    char output[BLOCK_SIZE];
    char key[KEY_LENGTH];

    // Generate a random key
    generate_key(key);

    // Encrypt the input data
    printf("Enter the input data: ");
    scanf("%s", input);
    encrypt(input, key, output);
    printf("Encrypted data: %s\n", output);

    // Decrypt the encrypted data
    decrypt(output, key, input);
    printf("Decrypted data: %s\n", input);

    return 0;
}