//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Stocks 10

typedef struct Stock {
    char name[20];
    double currentPrice;
    double previousPrice;
    double change;
} Stock;

int main()
{
    // Allocate memory for the stocks
    Stock *stocks = (Stock *)malloc(MAX_Stocks * sizeof(Stock));

    // Initialize the stocks
    for (int i = 0; i < MAX_Stocks; i++)
    {
        stocks[i].name[0] = '\0';
        stocks[i].currentPrice = 0.0;
        stocks[i].previousPrice = 0.0;
        stocks[i].change = 0.0;
    }

    // Get the stock data
    printf("Enter the name of the stock: ");
    scanf("%s", stocks[0].name);

    printf("Enter the current price of the stock: ");
    scanf("%lf", &stocks[0].currentPrice);

    printf("Enter the previous price of the stock: ");
    scanf("%lf", &stocks[0].previousPrice);

    // Calculate the change in the stock price
    stocks[0].change = (stocks[0].currentPrice - stocks[0].previousPrice) / stocks[0].previousPrice * 100;

    // Print the stock data
    printf("Stock name: %s\n", stocks[0].name);
    printf("Current price: %.2lf\n", stocks[0].currentPrice);
    printf("Previous price: %.2lf\n", stocks[0].previousPrice);
    printf("Change: %.2lf%\n", stocks[0].change);

    // Free the memory
    free(stocks);

    return 0;
}