//FormAI DATASET v1.0 Category: Modern Encryption ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000

char *encrypt(char text[], char key[]);
void encryptBlock(char *input, char *output, char *key);
void decryptBlock(char *input, char *output, char *key);

int main()
{
    char text[MAX_TEXT_LENGTH], key[MAX_TEXT_LENGTH];
    printf("Enter the text to encrypt: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);
    printf("Enter the encryption key: ");
    fgets(key, MAX_TEXT_LENGTH, stdin);

    char *encryptedText = encrypt(text, key);
    printf("\nEncrypted text: %s", encryptedText);

    free(encryptedText);
    return 0;
}

char *encrypt(char text[], char key[])
{
    char *encryptedText = malloc(sizeof(char) * MAX_TEXT_LENGTH);
    char block1[MAX_TEXT_LENGTH], block2[MAX_TEXT_LENGTH];
    int textLength = strlen(text) - 1;
    int keyLength = strlen(key) - 1;

    for(int i = 0; i < textLength; i += keyLength)
    {
        strncpy(block1, text + i, keyLength);
        encryptBlock(block1, block2, key);
        strncat(encryptedText, block2, keyLength);
    }

    return encryptedText;
}

void encryptBlock(char *input, char *output, char *key)
{
    int keyLength = strlen(key) - 1;
    for(int i = 0; i < keyLength; i++)
    {
        output[i] = input[i] ^ key[i];
    }
}

void decryptBlock(char *input, char *output, char *key)
{
    int keyLength = strlen(key) - 1;
    for(int i = 0; i < keyLength; i++)
    {
        output[i] = input[i] ^ key[i];
    }
}