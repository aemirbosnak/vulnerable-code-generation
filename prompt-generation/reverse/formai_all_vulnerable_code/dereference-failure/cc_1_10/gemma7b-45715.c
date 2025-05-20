//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void compress(char **arr, int **size)
{
    int i = 0, j = 0, count = 1, repeat = 0, old_size = 0;
    char temp[MAX] = "";

    *size = 0;

    for (i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == arr[i - 1] && repeat == 0)
        {
            repeat = 1;
            count++;
        }
        else
        {
            if (repeat)
            {
                sprintf(temp, "%c%d", arr[i - 1], count);
                old_size += strlen(temp) + 1;
                *size += strlen(temp) + 1;
                arr[j++] = temp[0];
                arr[j++] = temp[1];
            }
            else
            {
                old_size++;
                *size++;
                arr[j++] = arr[i];
            }
            repeat = 0;
            count = 1;
        }
    }

    if (repeat)
    {
        sprintf(temp, "%c%d", arr[i - 1], count);
        old_size += strlen(temp) + 1;
        *size += strlen(temp) + 1;
        arr[j++] = temp[0];
        arr[j++] = temp[1];
    }

    *size = old_size;

    return;
}

int main()
{
    char *arr = "aabbbbcccccaa";
    int size = 0;

    compress(&arr, &size);

    printf("Original size: %d\n", strlen(arr));
    printf("Compressed size: %d\n", size);
    printf("Compressed data: %s\n", arr);

    return 0;
}