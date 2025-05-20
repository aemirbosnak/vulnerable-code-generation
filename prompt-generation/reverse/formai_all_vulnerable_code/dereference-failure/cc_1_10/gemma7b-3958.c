//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n = 10;
    char **arr = (char **)malloc(n * sizeof(char *));
    for(int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(10 * sizeof(char));
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            arr[i][j] = rand() % 26 + 'a';
        }
    }

    int target = rand() % 26 + 'a';
    char *search_target = (char *)malloc(10 * sizeof(char));
    for(int i = 0; i < 10; i++)
    {
        search_target[i] = target;
    }

    int result = search(arr, search_target, n);
    if(result)
    {
        printf("Target found.\n");
    }
    else
    {
        printf("Target not found.\n");
    }

    return 0;
}

int search(char **arr, char *search_target, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(strcmp(arr[i][j], search_target) == 0)
            {
                return 1;
            }
        }
    }

    return 0;
}