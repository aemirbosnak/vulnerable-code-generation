//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt_file(char *filename, int key)
{
    FILE *fp;
    char *buffer;
    int size, i;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    size = 0;
    buffer = NULL;
    while ((buffer = realloc(buffer, size + 1)) == NULL)
    {
        size++;
    }

    fread(buffer, 1, size, fp);
    fclose(fp);

    for (i = 0; i < size; i++)
    {
        buffer[i] ^= key;
    }

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    fwrite(buffer, 1, size, fp);
    fclose(fp);

    free(buffer);
}

int main()
{
    char filename[] = "myfile.txt";
    int key = 12;

    encrypt_file(filename, key);

    return 0;
}