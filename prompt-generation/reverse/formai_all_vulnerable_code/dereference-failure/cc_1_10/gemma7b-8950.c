//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(char *str)
{
    int i = 0, j = 0, count = 1, size = 0;
    char temp[MAX];

    while (str[i] != '\0')
    {
        if (str[i] == str[i - 1])
        {
            count++;
        }
        else
        {
            temp[j++] = str[i];
            temp[j++] = count;
            count = 1;
        }

        i++;
    }

    size = j + 1;
    str = (char *)realloc(str, size);

    i = 0;
    j = 0;

    while (temp[i] != '\0')
    {
        str[j++] = temp[i++];
    }

    str[j] = '\0';
}

int main()
{
    char str[] = "aabbbbccc";

    compress(str);

    printf("%s", str);

    return 0;
}