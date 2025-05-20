//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY "This is the key"

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    int size = (int)fread(NULL, 1, 0, fp);
    if (size == -1)
    {
        printf("Error reading from file: %s\n", filename);
        return 1;
    }

    char *buf = malloc(size);
    if (buf == NULL)
    {
        printf("Error allocating memory: %s\n", filename);
        return 1;
    }

    int res = fread(buf, 1, size, fp);
    if (res!= size)
    {
        printf("Error reading from file: %s\n", filename);
        free(buf);
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        buf[i] = (char)((buf[i] + 1) % 256);
    }

    FILE *fp_out = fopen(filename, "wb");
    if (fp_out == NULL)
    {
        printf("Error opening output file: %s\n", filename);
        free(buf);
        return 1;
    }

    res = fwrite(buf, 1, size, fp_out);
    if (res!= size)
    {
        printf("Error writing to file: %s\n", filename);
        fclose(fp_out);
        free(buf);
        return 1;
    }

    fclose(fp);
    fclose(fp_out);
    printf("File %s encrypted successfully.\n", filename);
    free(buf);
    return 0;
}