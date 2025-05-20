//Gemma-7B DATASET v1.0 Category: Prime Number Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Please enter the number of primes you want: ");
    scanf("%d", &n);

    // Allocate memory for the primes
    int *primes = (int *)malloc(n * sizeof(int));

    // Generate the primes
    for (int i = 0; i < n; i++)
    {
        primes[i] = primeGen(i + 1);
    }

    // Print the primes
    for (int i = 0; i < n; i++)
    {
        printf("%d ", primes[i]);
    }

    // Free the memory
    free(primes);

    return 0;
}

int primeGen(int n)
{
    int prime = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            prime = 1;
            break;
        }
    }

    if (prime)
    {
        return n;
    }
    else
    {
        return 0;
    }
}