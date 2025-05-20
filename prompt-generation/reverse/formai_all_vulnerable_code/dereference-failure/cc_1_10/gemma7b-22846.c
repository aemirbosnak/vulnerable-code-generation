//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1024

void calculate_prime(int **primes, int *size)
{
    int i, j, prime, count = 0;

    *size = MAX_SIZE;
    primes = (int *)malloc((*size) * sizeof(int));

    for (i = 0; i < MAX_SIZE; i++)
    {
        prime = 1;
        for (j = 2; j * j <= MAX_SIZE; j++)
        {
            if (i % j == 0)
            {
                prime = 0;
                break;
            }
        }

        if (prime)
        {
            primes[count++] = i;
        }
    }

    *size = count;
}

int main()
{
    int size;
    int *primes;

    calculate_prime(&primes, &size);

    printf("Prime numbers up to %d:", size);

    for (int i = 0; i < size; i++)
    {
        printf(", %d", primes[i]);
    }

    printf("\n");

    free(primes);

    return 0;
}