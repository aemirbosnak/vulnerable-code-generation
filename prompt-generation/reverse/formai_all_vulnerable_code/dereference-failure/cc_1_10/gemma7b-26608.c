//Gemma-7B DATASET v1.0 Category: Prime Number Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct PrimeNumber
{
    int number;
    struct PrimeNumber* next;
} PrimeNumber;

PrimeNumber* generatePrimes(int n)
{
    PrimeNumber* head = NULL;
    PrimeNumber* tail = NULL;

    for (int i = 2; i <= n; i++)
    {
        PrimeNumber* newPrime = malloc(sizeof(PrimeNumber));
        newPrime->number = i;
        newPrime->next = NULL;

        if (head == NULL)
        {
            head = newPrime;
            tail = newPrime;
        }
        else
        {
            tail->next = newPrime;
            tail = newPrime;
        }
    }

    return head;
}

void printPrimes(PrimeNumber* head)
{
    PrimeNumber* current = head;

    while (current)
    {
        printf("%d ", current->number);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    PrimeNumber* primes = generatePrimes(100);
    printPrimes(primes);

    return 0;
}