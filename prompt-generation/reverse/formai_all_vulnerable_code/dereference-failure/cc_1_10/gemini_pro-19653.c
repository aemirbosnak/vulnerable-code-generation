//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define KEY "my secret key"

void encrypt(uint8_t *data, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        data[i] ^= KEY[i % strlen(KEY)];
    }
}

void decrypt(uint8_t *data, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        data[i] ^= KEY[i % strlen(KEY)];
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r+b");
    if (fp == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    size_t len = ftell(fp);
    rewind(fp);

    uint8_t *data = malloc(len);
    if (data == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    fread(data, 1, len, fp);
    encrypt(data, len);
    fwrite(data, 1, len, fp);

    free(data);
    fclose(fp);

    printf("File encrypted successfully!\n");

    return EXIT_SUCCESS;
}