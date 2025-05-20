//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void compress(char **buffer, int *bufferSize)
{
    int i = 0, j = 0, count = 1, previousChar = '\0';

    for (i = 0; i < *bufferSize; i++)
    {
        if (previousChar == buffer[i])
        {
            count++;
        }
        else
        {
            if (count > 1)
            {
                sprintf(buffer[j], "%c%d", previousChar, count);
                j++;
            }
            else
            {
                buffer[j] = previousChar;
                j++;
            }

            previousChar = buffer[i];
            count = 1;
        }
    }

    *bufferSize = j;
}

int main()
{
    char *buffer = NULL;
    int bufferSize = 0;

    buffer = (char *)malloc(MAX_BUFFER_SIZE);
    bufferSize = MAX_BUFFER_SIZE;

    // Sample text to be compressed
    buffer[0] = 'a';
    buffer[1] = 'a';
    buffer[2] = 'b';
    buffer[3] = 'b';
    buffer[4] = 'c';
    buffer[5] = 'c';
    buffer[6] = 'c';
    buffer[7] = '\0';

    compress(&buffer, &bufferSize);

    // Compressed text
    printf("Compressed text: ");
    for (int i = 0; i < bufferSize; i++)
    {
        printf("%c ", buffer[i]);
    }

    printf("\n");

    free(buffer);

    return 0;
}