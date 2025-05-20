//Gemma-7B DATASET v1.0 Category: Data mining ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    char **arr = NULL;
    int i, j, n, size = 0;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    arr = (char **)malloc(n * MAX_SIZE);

    for (i = 0; i < n; i++)
    {
        printf("Enter string %d: ", i + 1);
        arr[i] = (char *)malloc(MAX_SIZE);
        scanf("%s", arr[i]);
    }

    size = find_max_length(arr, n);

    printf("The maximum length of a string is: %d", size);

    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}

int find_max_length(char **arr, int n)
{
    int i, max_length = 0;

    for (i = 0; i < n; i++)
    {
        int length = strlen(arr[i]);
        if (length > max_length)
        {
            max_length = length;
        }
    }

    return max_length;
}