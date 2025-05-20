//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[] = "This is a string to be compressed.";
    int len = strlen(str);
    int i, j, count = 0, flag = 0;
    char **arr = NULL;

    arr = (char**)malloc(sizeof(char*) * len);

    for (i = 0; i < len; i++)
    {
        int freq = 0;
        for (j = 0; j < len; j++)
        {
            if (str[i] == str[j])
            {
                freq++;
            }
        }

        if (freq > 1)
        {
            arr[count++] = str[i];
            arr[count++] = (char)freq;
        }
        else
        {
            arr[count++] = str[i];
        }
    }

    int compressedLen = count;
    char compressedStr[compressedLen];

    for (i = 0; i < compressedLen; i++)
    {
        compressedStr[i] = arr[i];
    }

    printf("Original string: %s\n", str);
    printf("Compressed string: %s\n", compressedStr);
    printf("Number of characters compressed: %d\n", compressedLen - len);

    free(arr);

    return 0;
}