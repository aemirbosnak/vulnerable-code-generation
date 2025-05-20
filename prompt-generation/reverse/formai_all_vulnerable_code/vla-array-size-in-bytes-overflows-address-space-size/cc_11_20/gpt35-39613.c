//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, j, k = 0;

    printf("Please enter the number of terms in the Fibonacci sequence to be generated: ");
    scanf("%d", &num);

    int fib[num];

    //generate Fibonacci sequence and store in fib array
    for(i = 0; i < num; i++)
    {
        if(i == 0)
        {
            fib[i] = 0;
        }
        else if(i == 1)
        {
            fib[i] = 1;
        }
        else
        {
            fib[i] = fib[i-1] + fib[i-2];
        }
    }

    //find maximum value in fib array
    int max = fib[0];
    for(j = 0; j < num; j++)
    {
        if(fib[j] > max)
        {
            max = fib[j];
        }
    }

    //draw Fibonacci sequence visualizer
    printf("\n");
    for(j = max; j > 0; j--)
    {
        printf("%d| ", j);
        for(i = 0; i < num; i++)
        {
            if(fib[i] >= j)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("   ");
    for(i = 0; i < num; i++)
    {
        printf("--");
    }
    printf("\n   ");
    for(i = 0; i < num; i++)
    {
        printf("%d ", fib[i]);
    }
    printf("\n");

    return 0;
}