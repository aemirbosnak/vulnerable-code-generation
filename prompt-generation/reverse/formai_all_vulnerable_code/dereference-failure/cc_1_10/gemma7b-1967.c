//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int main()
{
    int n, i, j, k, l, m, count = 0, **a = NULL, **b = NULL;

    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of elements: ");
        scanf("%d", &m);

        a = (int *)malloc(m * sizeof(int));

        printf("Enter the elements: ");
        for (j = 0; j < m; j++)
            scanf("%d", &a[j]);

        b = compress(a, m);

        l = strlen(b);

        printf("The compressed data is: ");
        for (k = 0; k < l; k++)
            printf("%d ", b[k]);

        printf("\n");
    }

    return 0;
}

int compress(int *a, int n)
{
    int i, j, count = 0, **b = NULL;

    b = (int *)malloc((n + 1) * sizeof(int));

    for (i = 0; i < n; i++)
    {
        int frequency = 1;

        for (j = i + 1; j < n && a[i] == a[j]; j++)
            frequency++;

        b[count++] = a[i];
        b[count++] = frequency;
    }

    b[count] = '\0';

    return b;
}