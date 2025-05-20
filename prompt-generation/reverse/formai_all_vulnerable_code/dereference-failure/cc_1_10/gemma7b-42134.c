//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void beautifier(char **arr, int n)
{
    int i, j, k, l, count = 0;
    char temp[100];

    for (i = 0; i < n; i++)
    {
        for (j = 0; arr[i][j] != '\0'; j++)
        {
            if (arr[i][j] == ' ')
            {
                count++;
            }
        }
    }

    k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; arr[i][j] != '\0'; j++)
        {
            if (count > 0)
            {
                temp[k++] = ' ';
            }
            temp[k++] = arr[i][j];
        }
        temp[k] = '\0';
        printf("%s\n", temp);
    }
}

int main()
{
    char **arr = (char **)malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = (char *)malloc(20 * sizeof(char));
    }

    arr[0] = "This is a sample text";
    arr[1] = "It has many lines";
    arr[2] = "And some code";

    beautifier(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}