//Gemma-7B DATASET v1.0 Category: Data mining ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    char **arr = NULL;
    int i, j, n, m, size = 0;
    char str[MAX];

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    arr = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(m * sizeof(char));
    }

    printf("Enter the data: ");
    fgets(str, MAX, stdin);

    size = strlen(str) - 1;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i][j] = str[i * m + j];
        }
    }

    printf("The data in the array is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}