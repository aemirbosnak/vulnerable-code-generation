//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n = 10;
    char **arr = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(10 * sizeof(char));
    }

    arr[0][0] = 'a';
    arr[0][1] = 'b';
    arr[0][2] = 'c';
    arr[0][3] = 'd';
    arr[0][4] = 'e';

    arr[1][0] = 'f';
    arr[1][1] = 'g';
    arr[1][2] = 'h';
    arr[1][3] = 'i';
    arr[1][4] = 'j';

    arr[2][0] = 'k';
    arr[2][1] = 'l';
    arr[2][2] = 'm';
    arr[2][3] = 'n';
    arr[2][4] = 'o';

    char *search = "bcd";
    int result = search_algo(arr, n, search);

    if (result == 1)
    {
        printf("Search successful\n");
    }
    else
    {
        printf("Search unsuccessful\n");
    }

    return 0;
}

int search_algo(char **arr, int n, char *search)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (strcmp(arr[i][j], search) == 0)
            {
                return 1;
            }
        }
    }

    return 0;
}