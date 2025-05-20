//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void compress(char **buffer, int *bufferSize)
{
    int i, j, k, count = 1, originalSize = *bufferSize;
    char **compressedBuffer = NULL;

    *bufferSize = 0;

    for (i = 0; i < originalSize; i++)
    {
        for (j = i + 1; j < originalSize && buffer[i] == buffer[j]; j++)
        {
            count++;
        }

        if (count > 1)
        {
            compressedBuffer = realloc(compressedBuffer, (*bufferSize) * sizeof(char *) + 1);
            compressedBuffer[*bufferSize] = buffer[i];
            compressedBuffer[*bufferSize + 1] = count - 1;
            (*bufferSize)++;
        }
        else
        {
            compressedBuffer = realloc(compressedBuffer, (*bufferSize) * sizeof(char *) + 1);
            compressedBuffer[*bufferSize] = buffer[i];
            (*bufferSize)++;
        }

        count = 1;
    }

    *bufferSize = originalSize;

    if (compressedBuffer)
    {
        *buffer = compressedBuffer;
    }
}

int main()
{
    char *buffer = "aabbbbcccc";
    int bufferSize = 10;

    compress(&buffer, &bufferSize);

    printf("Compressed buffer: %s\n", buffer);
    printf("Compressed buffer size: %d\n", bufferSize);

    return 0;
}