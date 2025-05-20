//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16

int encrypt_file(char *filename, char *key)
{
    FILE *fp;
    int i, j, k;
    unsigned char *buf, *enc_buf;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return -1;
    }

    buf = (unsigned char *)malloc(1024);
    enc_buf = (unsigned char *)malloc(1024);

    while (!feof(fp))
    {
        i = fread(buf, 1, 1024, fp);
        for (j = 0; j < i; j++)
        {
            k = 0;
            for (int l = 0; l < KEY_LENGTH; l++)
            {
                enc_buf[k] = (buf[j] ^ key[l]) & 0xFF;
                k++;
            }
            fwrite(enc_buf, 1, k, fp);
        }
    }

    fclose(fp);
    free(buf);
    free(enc_buf);

    return 0;
}

int main()
{
    char filename[] = "my_secret.txt";
    char key[] = "super_secret";

    encrypt_file(filename, key);

    return 0;
}