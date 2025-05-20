//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void compress(char *str)
{
    int i = 0, j = 0, count = 1, size = 0;
    char temp[MAX];

    while (str[i] != '\0')
    {
        temp[j] = str[i];
        i++;

        if (str[i] == temp[j])
        {
            count++;
        }
        else
        {
            size += 2 + (count - 1) * 2;
            temp[j] = str[i];
            count = 1;
        }
    }

    size += 2 + (count - 1) * 2;

    str = (char *)realloc(str, size);

    i = 0, j = 0;
    while (str[i] != '\0')
    {
        str[j] = temp[i];
        i++;
        j++;

        if (str[i] == temp[j])
        {
            count++;
        }
        else
        {
            str[j] = temp[i];
            j++;
            count = 1;
        }
    }
}

int main()
{
    char str[] = "aabbbbcccc";

    compress(str);

    printf("%s", str);

    return 0;
}