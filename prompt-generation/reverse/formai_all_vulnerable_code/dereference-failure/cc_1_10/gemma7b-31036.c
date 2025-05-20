//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, h;
    char **a;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    a = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        a[i] = (char *)malloc(m * sizeof(char));
    }

    printf("Enter the height of the ASCII art: ");
    scanf("%d", &h);

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < m; k++)
            {
                scanf("%c", &a[j][k]);
            }
        }
    }

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < m; k++)
            {
                printf("%c ", a[j][k]);
            }
            printf("\n");
        }
    }

    for (i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}