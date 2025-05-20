//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void conquer(char **arr, int n)
{
    int i = 0, j = 0, count = 0;
    char key;

    printf("Enter the key to search for: ");
    scanf("%c", &key);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == key)
            {
                count++;
            }
        }
    }

    printf("Number of occurrences of the key: %d\n", count);
}

int main()
{
    char **arr = NULL;
    int n;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &n);

    arr = (char **)malloc(n * sizeof(char *) + 1);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(n * sizeof(char) + 1);
    }

    printf("Enter the elements of the matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%c", &arr[i][j]);
        }
    }

    conquer(arr, n);

    return 0;
}