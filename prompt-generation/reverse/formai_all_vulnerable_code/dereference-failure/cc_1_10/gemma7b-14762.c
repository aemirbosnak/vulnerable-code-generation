//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_KEY_LENGTH 256

void encrypt_file(char *key, char *filename)
{
    FILE *fp;
    char *buf, *enc_buf;
    int len, i, key_length, block_size;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    buf = malloc(1024);
    enc_buf = malloc(1024);

    key_length = strlen(key);
    block_size = 16;

    while ((len = read(fp, buf, 1024)) > 0)
    {
        for (i = 0; i < len; i++)
        {
            enc_buf[i] = buf[i] ^ key[i % key_length] ^ block_size;
        }

        write(fp, enc_buf, len);
    }

    fclose(fp);
    free(buf);
    free(enc_buf);
}

int main()
{
    char key[] = "Secret key";
    char filename[] = "myfile.txt";

    encrypt_file(key, filename);

    return 0;
}