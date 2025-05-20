//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int r, c, i, j, k, l, m, n;

    printf("Enter the number of rows: ");
    scanf("%d", &r);

    printf("Enter the number of columns: ");
    scanf("%d", &c);

    char **a = (char **)malloc(r * sizeof(char *));
    for(i = 0; i < r; i++)
    {
        a[i] = (char *)malloc(c * sizeof(char));
    }

    printf("Enter the data: ");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%c", &a[i][j]);
        }
    }

    printf("The data is:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }

    k = rand() % r;
    l = rand() % c;

    a[k][l] = 'X';

    printf("The data is after modification:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }

    free(a);

    return 0;
}