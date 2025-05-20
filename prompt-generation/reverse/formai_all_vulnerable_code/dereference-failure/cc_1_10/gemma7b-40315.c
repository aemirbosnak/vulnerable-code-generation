//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct EncryptionKey
{
    int keySize;
    unsigned char *key;
} EncryptionKey;

EncryptionKey *generateKey(int keySize, unsigned char *key)
{
    EncryptionKey *keyStruct = malloc(sizeof(EncryptionKey));
    keyStruct->keySize = keySize;
    keyStruct->key = key;

    return keyStruct;
}

void encryptFile(EncryptionKey *keyStruct, FILE *file)
{
    unsigned char buffer[MAX_BUFFER_SIZE];
    int readBytes, writeBytes;

    while ((readBytes = fread(buffer, 1, MAX_BUFFER_SIZE, file)) > 0)
    {
        for (int i = 0; i < readBytes; i++)
        {
            buffer[i] ^= keyStruct->key[i % keyStruct->keySize];
        }

        writeBytes = fwrite(buffer, 1, readBytes, file);
    }
}

int main()
{
    unsigned char key[] = "This is a secret key";
    EncryptionKey *keyStruct = generateKey(16, key);
    FILE *file = fopen("my_file.txt", "r");

    encryptFile(keyStruct, file);

    fclose(file);
    free(keyStruct);

    return 0;
}