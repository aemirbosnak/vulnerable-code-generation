//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

void compress(char **str)
{
    int i, j, k, count = 1, l = 0, flag = 0, original_length = strlen(*str);
    char **compressed_str = (char **)malloc(sizeof(char *) * MAX);

    for (i = 0; i < original_length; i++)
    {
        for (j = i + 1; j < original_length && str[i] == str[j]; j++)
        {
            count++;
        }

        if (count > 1)
        {
            compressed_str[l++] = str[i];
            compressed_str[l++] = count - 1 + 'a' - 1;
            flag = 1;
        }
        else
        {
            compressed_str[l++] = str[i];
        }

        count = 1;
    }

    if (!flag)
    {
        *str = strdup(*str);
    }
    else
    {
        *str = compressed_str;
    }
}

int main()
{
    char *str = "aabbbb";
    compress(&str);
    printf("%s", str);

    return 0;
}