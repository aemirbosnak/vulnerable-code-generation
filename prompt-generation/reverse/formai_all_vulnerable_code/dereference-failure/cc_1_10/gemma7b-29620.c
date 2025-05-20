//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CompressData {
    char *buffer;
    int size;
    int offset;
} CompressData;

CompressData *compress(char *str)
{
    int str_len = strlen(str) + 1;
    CompressData *data = malloc(sizeof(CompressData));
    data->buffer = malloc(MAX_BUFFER_SIZE);
    data->size = str_len;
    data->offset = 0;

    int i = 0;
    for (i = 0; i < str_len - 1; i++)
    {
        char current_char = str[i];
        char next_char = str[i + 1];

        if (current_char == next_char)
        {
            data->buffer[data->offset] = current_char;
            data->offset++;
        }
        else
        {
            data->buffer[data->offset] = current_char;
            data->offset++;
            data->buffer[data->offset] = next_char;
            data->offset++;
        }
    }

    return data;
}

int main()
{
    char *str = "AABBCCDDEEE";
    CompressData *data = compress(str);

    printf("Original string: %s\n", str);
    printf("Compressed string: %s\n", data->buffer);

    return 0;
}