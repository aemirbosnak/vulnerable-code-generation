//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    char **stocks = (char **)malloc(MAX * sizeof(char *));
    int i = 0;
    int numStocks = 0;

    for (i = 0; i < MAX; i++)
    {
        stocks[i] = (char *)malloc(20 * sizeof(char));
    }

    printf("Welcome to the Wall Street Dream Machine!\n");

    while (1)
    {
        printf("What stock symbol would you like to track? (Enter 'q' to quit): ");
        char symbol[20];
        scanf("%s", symbol);

        if (strcmp(symbol, "q") == 0)
        {
            break;
        }

        printf("Please enter the current price of the stock: ");
        double price;
        scanf("%lf", &price);

        stocks[numStocks] = symbol;
        numStocks++;

        printf("Stock added! You're a Wall Street wizard now!\n");
    }

    printf("Thank you for using the Wall Street Dream Machine. Goodbye!\n");

    for (i = 0; i < numStocks; i++)
    {
        free(stocks[i]);
    }
    free(stocks);

    return 0;
}