//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void compress(char **buffer, int *buffer_size)
{
    int i = 0, j = 0, count = 1, repeat = 0;
    char prev = '\0';

    for (i = 0; i < *buffer_size && buffer[i] != '\0'; i++)
    {
        if (buffer[i] == prev)
        {
            repeat++;
        }
        else
        {
            if (repeat)
            {
                buffer[j++] = repeat + 'a' - 1;
                repeat = 0;
            }
            prev = buffer[i];
            buffer[j++] = buffer[i];
        }
    }

    *buffer_size = j;
}

int main()
{
    char *buffer = malloc(MAX_BUFFER_SIZE);
    int buffer_size = MAX_BUFFER_SIZE;

    printf("Enter text: ");
    fgets(buffer, buffer_size, stdin);

    compress(&buffer, &buffer_size);

    printf("Compressed text: ");
    for (int i = 0; i < buffer_size && buffer[i] != '\0'; i++)
    {
        printf("%c ", buffer[i]);
    }

    printf("\n");

    free(buffer);

    return 0;
}