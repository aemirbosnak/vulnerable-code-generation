//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    int i, j, k, n, m;
    char **a = (char **)malloc(MAX * sizeof(char *));
    char **b = (char **)malloc(MAX * sizeof(char *));
    char **c = (char **)malloc(MAX * sizeof(char *));
    char **d = (char **)malloc(MAX * sizeof(char *));

    n = 0;
    m = 0;

    for (i = 0; i < MAX; i++)
    {
        a[i] = (char *)malloc(MAX * sizeof(char));
        b[i] = (char *)malloc(MAX * sizeof(char));
        c[i] = (char *)malloc(MAX * sizeof(char));
        d[i] = (char *)malloc(MAX * sizeof(char));
    }

    printf("Enter the number of stocks: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the name of the stock: ");
        scanf("%s", a[i]);

        printf("Enter the current price of the stock: ");
        scanf("%f", &b[i]);

        printf("Enter the historical price of the stock: ");
        scanf("%f", &c[i]);

        printf("Enter the dividend yield of the stock: ");
        scanf("%f", &d[i]);
    }

    printf("Here is a summary of your stock portfolio: \n");

    for (i = 0; i < n; i++)
    {
        printf("Stock name: %s \n", a[i]);
        printf("Current price: $%.2f \n", b[i]);
        printf("Historical price: $%.2f \n", c[i]);
        printf("Dividend yield: %%.2f% \n", d[i]);
        printf("\n");
    }

    for (i = 0; i < MAX; i++)
    {
        free(a[i]);
        free(b[i]);
        free(c[i]);
        free(d[i]);
    }

    free(a);
    free(b);
    free(c);
    free(d);

    return 0;
}