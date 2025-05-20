//Gemma-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERMS 100

int main()
{
    int n, i, term_count, term_limit = MAX_TERMS;
    char **terms = (char**)malloc(term_limit * sizeof(char *));

    printf("Enter the number of terms to generate: ");
    scanf("%d", &n);

    term_count = n;
    if (term_count > term_limit)
    {
        term_count = term_limit;
    }

    for (i = 0; i < term_count; i++)
    {
        terms[i] = malloc(20 * sizeof(char));
        sprintf(terms[i], "%d", fibonacci(i));
    }

    printf("Fibonacci sequence of the first %d terms:\n", term_count);
    for (i = 0; i < term_count; i++)
    {
        printf("%s ", terms[i]);
    }

    for (i = 0; i < term_count; i++)
    {
        free(terms[i]);
    }

    free(terms);

    return 0;
}

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}