//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void compress(char *str)
{
    int original_length = strlen(str);
    int i = 0;
    char buffer[MAX_BUFFER_SIZE];
    int buffer_index = 0;
    char prev_char = '\0';
    int repeat = 1;

    for (i = 0; i < original_length; i++)
    {
        if (str[i] == prev_char)
        {
            repeat++;
        }
        else
        {
            if (prev_char != '\0')
            {
                buffer[buffer_index++] = prev_char;
                buffer[buffer_index++] = repeat - 1;
            }
            prev_char = str[i];
            repeat = 1;
        }
    }

    int compressed_length = buffer_index + 1;
    str = realloc(str, compressed_length);

    memcpy(str, buffer, compressed_length);
    str[compressed_length - 1] = '\0';

    printf("Compressed string: %s", str);
    printf("\n");
    printf("Original length: %d", original_length);
    printf("\n");
    printf("Compressed length: %d", compressed_length);
    printf("\n");
}

int main()
{
    char str[] = "aabbbbcccc";
    compress(str);

    return 0;
}