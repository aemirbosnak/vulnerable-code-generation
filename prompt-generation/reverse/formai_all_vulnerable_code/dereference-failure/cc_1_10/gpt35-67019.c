//FormAI DATASET v1.0 Category: Modern Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "abc123"

void encrypt(char* message, char* key)
{
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < message_length; i++, j++)
    {
        if (j == key_length)
            j = 0;

        message[i] += key[j];
    }
}

void decrypt(char* message, char* key)
{
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < message_length; i++, j++)
    {
        if (j == key_length)
            j = 0;

        message[i] -= key[j];
    }
}

int main(int argc, char* argv[])
{
    char* message = "Hello, world!";
    char* encrypted_message = malloc(strlen(message) + 1);
    strcpy(encrypted_message, message);

    encrypt(encrypted_message, KEY);

    printf("Original message: \"%s\"\n", message);
    printf("Encrypted message: \"%s\"\n", encrypted_message);

    char* decrypted_message = malloc(strlen(encrypted_message) + 1);
    strcpy(decrypted_message, encrypted_message);

    decrypt(decrypted_message, KEY);

    printf("Decrypted message: \"%s\"\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);

    return 0;
}