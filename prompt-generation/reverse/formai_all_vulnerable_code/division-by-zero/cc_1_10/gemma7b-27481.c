//Gemma-7B DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>

int main()
{
    int n, i, a[100], b[100], c[100], d[100], e[100], f[100], g[100], h[100], j[100], k[100], l[100], m[100], n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, sum, product, average, max, min;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    printf("Enter the elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    sum = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }

    product = 1;
    for (i = 0; i < n; i++)
    {
        product = product * a[i];
    }

    average = sum / n;

    max = a[0];
    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    min = a[0];
    for (i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }

    printf("The sum of the elements is:");
    printf("\n%d", sum);

    printf("The product of the elements is:");
    printf("\n%d", product);

    printf("The average of the elements is:");
    printf("\n%d", average);

    printf("The maximum element is:");
    printf("\n%d", max);

    printf("The minimum element is:");
    printf("\n%d", min);

    return 0;
}