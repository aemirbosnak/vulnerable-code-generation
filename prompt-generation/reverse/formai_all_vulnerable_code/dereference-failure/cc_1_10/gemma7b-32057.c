//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

void encrypt_file(char *filename)
{
    FILE *fp;
    char *buffer;
    int nread, i, key = 12;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    buffer = malloc(MAX);
    if (buffer == NULL)
    {
        perror("Error allocating memory");
        exit(1);
    }

    nread = fread(buffer, 1, MAX, fp);
    fclose(fp);

    for (i = 0; i < nread; i++)
    {
        buffer[i] ^= key;
    }

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    fwrite(buffer, 1, nread, fp);
    fclose(fp);

    free(buffer);
}

int main()
{
    encrypt_file("myfile.txt");
    return 0;
}