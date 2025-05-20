//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int main()
{
    // Declare variables
    int i, j, k, l, n, m, index, price, total_price = 0, avg_price = 0;
    char symbol[MAX];
    double percent_change, total_change = 0;

    // Create an array of stock prices
    int prices[MAX] = {0};

    // Get the number of stocks
    printf("Enter the number of stocks: ");
    scanf("%d", &n);

    // Get the stock symbols
    printf("Enter the stock symbols: ");
    for (i = 0; i < n; i++)
    {
        scanf("%s", symbol);
        prices[i] = rand() % 1000;
    }

    // Calculate the total price
    for (i = 0; i < n; i++)
    {
        total_price += prices[i];
    }

    // Calculate the average price
    avg_price = total_price / n;

    // Calculate the total change
    for (i = 0; i < n; i++)
    {
        percent_change = (prices[i] - avg_price) / avg_price * 100;
        total_change += percent_change;
    }

    // Print the results
    printf("Total price: $%d\n", total_price);
    printf("Average price: $%d\n", avg_price);
    printf("Total change: %.2f%\n", total_change);

    return 0;
}