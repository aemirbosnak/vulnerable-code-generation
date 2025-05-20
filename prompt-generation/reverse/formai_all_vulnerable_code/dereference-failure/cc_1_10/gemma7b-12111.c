//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>

void compress(char **a, int n)
{
    int i, j, count = 0, flag = 0;
    char **b = (char **)malloc(n * sizeof(char *));

    for (i = 0; i < n; i++)
    {
        b[i] = (char *)malloc(10 * sizeof(char));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 10; j++)
        {
            b[i][j] = '\0';
        }
    }

    for (i = 0; i < n; i++)
    {
        count = 0;
        for (j = 0; j < 10; j++)
        {
            if ((*a)[i] == b[i][j])
            {
                count++;
            }
        }

        if (count > flag)
        {
            flag = count;
        }
    }

    printf("The maximum number of consecutive characters is: %d\n", flag);
    free(b);
}

int main()
{
    char **a = (char **)malloc(10 * sizeof(char *));

    for (int i = 0; i < 10; i++)
    {
        a[i] = (char *)malloc(10 * sizeof(char));
    }

    a[0] = "This is a string";
    a[1] = "With a lot of consecutive characters";
    a[2] = "But not as much as this one";

    compress(a, 3);

    free(a);

    return 0;
}