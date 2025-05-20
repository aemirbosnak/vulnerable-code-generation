//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void encrypt_file(char *filename, int key)
{
    FILE *fp;
    char *buffer, *data;
    long int file_size;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    file_size = lseek(fileno(fp), 0, SEEK_END);
    buffer = malloc(file_size);
    data = buffer;

    fread(buffer, file_size, 1, fp);
    fclose(fp);

    for (int i = 0; i < file_size; i++)
    {
        data[i] ^= key;
    }

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    fwrite(buffer, file_size, 1, fp);
    fclose(fp);

    free(buffer);
}

int main()
{
    int key = 0x12345;
    char filename[] = "my_secret_file.txt";

    encrypt_file(filename, key);

    return 0;
}