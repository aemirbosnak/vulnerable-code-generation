//FormAI DATASET v1.0 Category: File Encyptor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 256

void encrypt(char *input_file, char *output_file, char *key);
void decrypt(char *input_file, char *output_file, char *key);

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        printf("Usage: %s [encrypt / decrypt] [input file] [output file] [key]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encrypt") == 0)
    {
        encrypt(argv[2], argv[3], argv[4]);
    }
    else if (strcmp(argv[1], "decrypt") == 0)
    {
        decrypt(argv[2], argv[3], argv[4]);
    }
    else
    {
        printf("Invalid operation specified. Please specify either 'encrypt' or 'decrypt'.\n");
        return 1;
    }

    return 0;
}

void encrypt(char *input_file, char *output_file, char *key)
{
    unsigned char buf[BUFSIZE];
    size_t len;

    FILE *infile = fopen(input_file, "rb");
    if (infile == NULL)
    {
        printf("Failed to open input file.\n");
        exit(1);
    }

    FILE *outfile = fopen(output_file, "wb");
    if (outfile == NULL)
    {
        printf("Failed to open output file.\n");
        exit(1);
    }

    size_t keylen = strlen(key);
    size_t i = 0;

    while ((len = fread(buf, 1, BUFSIZE, infile)) > 0)
    {
        for (size_t j = 0; j < len; ++j)
        {
            buf[j] ^= key[i % keylen];
            ++i;
        }

        fwrite(buf, 1, len, outfile);
    }

    fclose(infile);
    fclose(outfile);

    printf("Encryption complete.\n");
}

void decrypt(char *input_file, char *output_file, char *key)
{
    unsigned char buf[BUFSIZE];
    size_t len;

    FILE *infile = fopen(input_file, "rb");
    if (infile == NULL)
    {
        printf("Failed to open input file.\n");
        exit(1);
    }

    FILE *outfile = fopen(output_file, "wb");
    if (outfile == NULL)
    {
        printf("Failed to open output file.\n");
        exit(1);
    }

    size_t keylen = strlen(key);
    size_t i = 0;

    while ((len = fread(buf, 1, BUFSIZE, infile)) > 0)
    {
        for (size_t j = 0; j < len; ++j)
        {
            buf[j] ^= key[i % keylen];
            ++i;
        }

        fwrite(buf, 1, len, outfile);
    }

    fclose(infile);
    fclose(outfile);

    printf("Decryption complete.\n");
}