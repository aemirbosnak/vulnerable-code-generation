//Gemma-7B DATASET v1.0 Category: Prime Number Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct PrimeNumbers
{
    int number;
    struct PrimeNumbers* next;
} PrimeNumbers;

PrimeNumbers* insertPrimeNumber(PrimeNumbers* head, int number)
{
    PrimeNumbers* newNode = malloc(sizeof(PrimeNumbers));
    newNode->number = number;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        PrimeNumbers* traverse = head;
        while (traverse->next)
        {
            traverse = traverse->next;
        }
        traverse->next = newNode;
    }

    return head;
}

void printPrimes(PrimeNumbers* head)
{
    PrimeNumbers* traverse = head;
    while (traverse)
    {
        printf("%d ", traverse->number);
        traverse = traverse->next;
    }
    printf("\n");
}

int main()
{
    PrimeNumbers* primeNumbersHead = NULL;

    for (int i = 0; i < 100; i++)
    {
        insertPrimeNumber(primeNumbersHead, rand() % 1000);
    }

    printPrimes(primeNumbersHead);

    return 0;
}