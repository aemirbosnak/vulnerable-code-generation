//Gemma-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fibonacci_visualizer()
{
    int n, i, j, k, l, m, x, y, z;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    int fib_sequence[n];
    fib_sequence[0] = fib_sequence[1] = 1;

    for (i = 2; i < n; i++)
    {
        fib_sequence[i] = fib_sequence[i - 1] + fib_sequence[i - 2];
    }

    system("clear");

    for (i = 0; i < n; i++)
    {
        printf("%d ", fib_sequence[i]);
    }

    printf("\n");

    for (x = 0; x < n; x++)
    {
        for (y = 0; y < n; y++)
        {
            for (z = 0; z < n; z++)
            {
                if (fib_sequence[x] == fib_sequence[y] && fib_sequence[x] == fib_sequence[z])
                {
                    printf("(");
                }
            }
        }
    }

    printf("\n");

    system("clear");

    for (i = 0; i < n; i++)
    {
        printf("%d ", fib_sequence[i]);
    }

    printf("\n");

    for (l = 0; l < n; l++)
    {
        for (m = 0; m < n; m++)
        {
            if (fib_sequence[l] == fib_sequence[m])
            {
                printf("(");
            }
        }
    }

    printf("\n");

    system("clear");

    for (i = 0; i < n; i++)
    {
        printf("%d ", fib_sequence[i]);
    }

    printf("\n");

    for (k = 0; k < n; k++)
    {
        for (j = 0; j < n; j++)
        {
            if (fib_sequence[k] == fib_sequence[j])
            {
                printf("(");
            }
        }
    }

    printf("\n");

    system("clear");

    for (i = 0; i < n; i++)
    {
        printf("%d ", fib_sequence[i]);
    }

    printf("\n");

    system("clear");

    return;
}

int main()
{
    fibonacci_visualizer();

    return 0;
}