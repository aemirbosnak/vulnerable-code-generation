//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **a = NULL;
    int i = 0;
    int n = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    a = (char **)malloc(n * sizeof(char *));

    for (i = 0; i < n; i++)
    {
        a[i] = (char *)malloc(10 * sizeof(char));
    }

    printf("Enter the data: ");

    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            scanf("%c", &a[i][j]);
        }
    }

    printf("The data is: ");

    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        free(a[i]);
    }

    free(a);

    return 0;
}