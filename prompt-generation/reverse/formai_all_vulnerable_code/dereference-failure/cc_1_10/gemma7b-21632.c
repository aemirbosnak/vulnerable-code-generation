//Gemma-7B DATASET v1.0 Category: Sorting ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_string(char **arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int comp = strcmp(arr[i], arr[j]);
            if (comp > 0)
            {
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    char **arr = NULL;
    int n = 0;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    arr = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(100 * sizeof(char));
    }

    printf("Enter the strings: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    sort_string(arr, n);

    printf("The sorted strings are: ");

    for (int i = 0; i < n; i++)
    {
        printf("%s ", arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}