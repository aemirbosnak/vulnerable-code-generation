//Gemma-7B DATASET v1.0 Category: Data mining ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[] = "The quick brown fox jumps over the lazy dog.";
    char str2[] = "A bright copper kettle sits on the table.";
    char str3[] = "The old man and the sea";

    int i = 0;
    int j = 0;
    int k = 0;

    char **arr = NULL;

    arr = (char**)malloc(10 * sizeof(char*));

    for (i = 0; i < 3; i++)
    {
        arr[i] = (char*)malloc(20 * sizeof(char));
    }

    for (i = 0; str1[i] != '\0'; i++)
    {
        arr[0][j] = str1[i];
        j++;
    }

    for (i = 0; str2[i] != '\0'; i++)
    {
        arr[1][k] = str2[i];
        k++;
    }

    for (i = 0; str3[i] != '\0'; i++)
    {
        arr[2][k] = str3[i];
        k++;
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; arr[i][j] != '\0'; j++)
        {
            printf("%c ", arr[i][j]);
        }

        printf("\n");
    }

    for (i = 0; i < 3; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}