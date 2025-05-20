//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void compress(char **buffer, int *bufferSize)
{
    int i = 0, j = 0, count = 1, previousCharacter = -1, previousCount = 0;
    char compressedBuffer[MAX_BUFFER_SIZE];

    while (i < *bufferSize)
    {
        if (previousCharacter == buffer[i])
        {
            previousCount++;
        }
        else
        {
            if (previousCharacter != -1)
            {
                compressedBuffer[j++] = previousCharacter;
                compressedBuffer[j++] = previousCount;
            }

            previousCharacter = buffer[i];
            previousCount = 1;
        }

        i++;
    }

    if (previousCharacter != -1)
    {
        compressedBuffer[j++] = previousCharacter;
        compressedBuffer[j++] = previousCount;
    }

    *bufferSize = j;
    *buffer = compressedBuffer;
}

int main()
{
    char *buffer = "aabbbbcccccaa";
    int bufferSize = 13;

    compress(&buffer, &bufferSize);

    printf("Compressed buffer: %s\n", buffer);
    printf("Compressed buffer size: %d\n", bufferSize);

    return 0;
}