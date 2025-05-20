//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 4096

void compress(char *buffer, int size)
{
    int i, j, count = 0, previous = -1;
    char *compressed = malloc(size);

    for (i = 0; i < size; i++)
    {
        if (previous == buffer[i])
        {
            count++;
        }
        else
        {
            if (count > 0)
            {
                compressed[j++] = count + 'a' - 1;
            }
            compressed[j++] = buffer[i];
            count = 1;
            previous = buffer[i];
        }
    }

    if (count > 0)
    {
        compressed[j++] = count + 'a' - 1;
    }

    memcpy(buffer, compressed, j);
    free(compressed);
}

int main()
{
    char buffer[MAX_BUFFER_SIZE];

    printf("Enter text: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    compress(buffer, strlen(buffer));

    printf("Compressed text: ");
    printf("%s", buffer);

    return 0;
}