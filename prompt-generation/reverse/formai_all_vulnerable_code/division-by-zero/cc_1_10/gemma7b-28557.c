//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
    int i, j, n, m, a[MAX], b[MAX], c[MAX], d[MAX];

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of elements: ");
        scanf("%d", &m);

        a[i] = m;

        for (j = 0; j < m; j++)
        {
            printf("Enter the element: ");
            scanf("%d", &c[j]);
        }

        b[i] = calculate_mean(c, m);
        d[i] = calculate_stddev(c, m);
    }

    for (i = 0; i < n; i++)
    {
        printf("The mean is: %d\n", b[i]);
        printf("The standard deviation is: %d\n", d[i]);
    }

    return 0;
}

int calculate_mean(int *arr, int size)
{
    int sum = 0, i;

    for (i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum / size;
}

int calculate_stddev(int *arr, int size)
{
    int mean = calculate_mean(arr, size);
    int sqsum = 0, i;

    for (i = 0; i < size; i++)
    {
        sqsum += (arr[i] - mean) * (arr[i] - mean);
    }

    return (int)sqrt(sqsum / size);
}