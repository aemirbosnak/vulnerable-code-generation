//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt_file(char *filename)
{
    FILE *fp;
    char *buffer;
    int length, i;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    length = 0;
    buffer = NULL;
    while ((buffer = realloc(buffer, length + 1)) != NULL)
    {
        int read_size = fread(buffer, 1, length + 1, fp);
        length += read_size;
    }

    fclose(fp);

    for (i = 0; i < length; i++)
    {
        buffer[i] ^= 0x2A;
    }

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    fwrite(buffer, 1, length, fp);
    fclose(fp);

    free(buffer);
}

int main()
{
    encrypt_file("my_secret.txt");
    return 0;
}