//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

void compress(char **arr, int *size)
{
    int i, j, count = 0, prev = 0, pos = 0, block = 0;
    char temp[MAX_SIZE];

    for (i = 0; i < *size; i++)
    {
        for (j = i + 1; j < *size && arr[i] == arr[j]; j++)
        {
            count++;
        }

        if (count > prev)
        {
            prev = count;
            block++;
            temp[pos++] = block;
            temp[pos++] = count - 1;
        }

        count = 0;
    }

    *size = pos;
    *arr = temp;
}

int main()
{
    char arr[] = "aabbbbcccc";
    int size = 10;

    compress(&arr, &size);

    printf("Compressed size: %d\n", size);
    printf("Compressed data: ");

    for (int i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }

    printf("\n");

    return 0;
}