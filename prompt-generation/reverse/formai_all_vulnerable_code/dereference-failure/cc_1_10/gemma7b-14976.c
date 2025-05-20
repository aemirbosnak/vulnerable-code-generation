//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 256
#define MAX_CIPHER_LENGTH 256

void encrypt_file(char *key, char *cipher, char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    long file_size = 0;
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    char *buffer = malloc(file_size);
    if (buffer == NULL)
    {
        perror("Error allocating memory");
        exit(1);
    }

    fread(buffer, file_size, 1, fp);

    for (int i = 0; i < file_size; i++)
    {
        buffer[i] ^= key[i % MAX_KEY_LENGTH];
    }

    memcpy(cipher, buffer, file_size);

    free(buffer);
    fclose(fp);
}

int main()
{
    char key[] = "SECRET KEY";
    char cipher[MAX_CIPHER_LENGTH];

    encrypt_file(key, cipher, "my_file.txt");

    printf("Cipher: %s\n", cipher);

    return 0;
}