//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

void recover(char* filename);

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    recover(argv[1]);

    return 0;
}

void recover(char* filename)
{
    FILE* fp = fopen(filename, "rb");

    if (fp == NULL)
    {
        printf("Could not open file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* buffer = malloc(size);

    if (buffer == NULL)
    {
        printf("Could not allocate memory.\n");
        exit(1);
    }

    fread(buffer, size, 1, fp);

    int i, j;

    for(i = 0; i < size - 3; i++)
    {
        if (buffer[i] == 'd' && buffer[i+1] == 'e' &&
            buffer[i+2] == 'l' && buffer[i+3] == 'e')
        {
            for(j = i; j < i + 4; j++)
            {
                buffer[j] = 'X';
            }
        }
    }

    fclose(fp);

    fp = fopen(filename, "wb");

    if (fp == NULL)
    {
        printf("Could not open file.\n");
        exit(1);
    }

    fwrite(buffer, size, 1, fp);

    fclose(fp);

    free(buffer);

    printf("Recovery complete.\n");
}