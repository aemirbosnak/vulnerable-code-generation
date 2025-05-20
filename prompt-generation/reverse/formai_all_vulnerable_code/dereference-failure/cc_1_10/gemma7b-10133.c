//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

void compress(char **data, int **compressed_size)
{
    int i, j, count = 0, previous = -1, compressed_size_ = 0;
    char **compressed_data = malloc(MAX_SIZE);

    for (i = 0; data[i] != '\0'; i++)
    {
        if (previous != data[i])
        {
            compressed_data[compressed_size_] = data[i];
            compressed_size_++;
            previous = data[i];
            count = 1;
        } else
        {
            count++;
        }

        if (count > 1)
        {
            compressed_data[compressed_size_] = count - 1;
            compressed_size_++;
        }
    }

    *compressed_size = compressed_size_ + 1;
    *compressed_data = compressed_data;

    return;
}

int main()
{
    char data[] = "aabbbbcccccaa";
    int compressed_size;
    char **compressed_data = NULL;

    compress(&data, &compressed_size);

    printf("Original data: %s\n", data);
    printf("Compressed data: %s\n", compressed_data);
    printf("Compressed size: %d\n", compressed_size);

    return 0;
}