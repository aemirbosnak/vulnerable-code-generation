//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Cryptic
// Secret Algorithm V2.1
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k, l, r, b, d;
    char **a = NULL, **c = NULL, **e = NULL;

    printf("Enter the dimensions of the ASCII art (n x m): ");
    scanf("%d %d", &n, &m);

    a = (char **)malloc(n * sizeof(char *));
    c = (char **)malloc(n * sizeof(char *));
    e = (char **)malloc(n * sizeof(char *));

    for (i = 0; i < n; i++)
    {
        a[i] = (char *)malloc(m * sizeof(char));
        c[i] = (char *)malloc(m * sizeof(char));
        e[i] = (char *)malloc(m * sizeof(char));
    }

    printf("Enter the ASCII art (each line as a separate command): ");

    for (i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            c[i][j] = a[i][j];
        }
    }

    printf("Here is your ASCII art:");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%c ", c[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(c);
    free(e);

    return 0;
}