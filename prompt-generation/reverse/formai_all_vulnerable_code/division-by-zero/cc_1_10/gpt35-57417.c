//FormAI DATASET v1.0 Category: modern Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

void encrypt(char *input, char *key, char *output)
{
    int input_length = strlen(input);
    int key_length = strlen(key);
    int key_index = 0;

    for (int i = 0; i < input_length; i++)
    {
        output[i] = (input[i] + key[key_index]) % 256;
        key_index = (key_index + 1) % key_length;
    }
    output[input_length] = '\0';
}

void decrypt(char *input, char *key, char *output)
{
    int input_length = strlen(input);
    int key_length = strlen(key);
    int key_index = 0;

    for (int i = 0; i < input_length; i++)
    {
        output[i] = (input[i] - key[key_index] + 256) % 256;
        key_index = (key_index + 1) % key_length;
    }
    output[input_length] = '\0';
}

int main()
{
    char input[MAX_STRING_LENGTH];
    char key[MAX_STRING_LENGTH];
    char encrypted[MAX_STRING_LENGTH];
    char decrypted[MAX_STRING_LENGTH];

    printf("Enter string to encrypt: ");
    fgets(input, sizeof(input), stdin);
    printf("Enter encryption key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline character from input and key
    input[strcspn(input, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    // Encrypt input string using key
    encrypt(input, key, encrypted);
    printf("Encrypted string: %s\n", encrypted);

    // Decrypt encrypted string using key
    decrypt(encrypted, key, decrypted);
    printf("Decrypted string: %s\n", decrypted);

    return 0;
}