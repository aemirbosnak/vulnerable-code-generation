//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **stocks = NULL;
    int numStocks = 0;
    char command;

    printf("Welcome to the Irregular Stock Market Tracker!\n");

    while (1)
    {
        printf("Please enter a command (add, list, exit): ");
        scanf(" %c", &command);

        switch (command)
        {
            case 'a':
                stocks = realloc(stocks, (numStocks + 1) * sizeof(char *));
                stocks[numStocks++] = malloc(20 * sizeof(char));
                printf("Enter the name of the stock: ");
                scanf(" %s", stocks[numStocks - 1]);
                printf("Enter the initial price: ");
                scanf(" %f", &stocks[numStocks - 1][0]);
                break;

            case 'l':
                if (numStocks > 0)
                {
                    for (int i = 0; i < numStocks; i++)
                    {
                        printf("%s: %f\n", stocks[i], stocks[i][0]);
                    }
                }
                else
                {
                    printf("No stocks to list.\n");
                }
                break;

            case 'e':
                exit(0);
                break;

            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}