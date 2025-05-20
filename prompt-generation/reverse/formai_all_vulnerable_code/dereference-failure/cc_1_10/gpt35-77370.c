//FormAI DATASET v1.0 Category: Stock market tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numStocks = 0;
    printf("How many stocks are you tracking? (enter a positive integer): ");
    scanf("%d", &numStocks);
    char **stockNames = (char**) malloc(numStocks * sizeof(char*));
    double *stockPrices = (double*) malloc(numStocks * sizeof(double));
    for (int i = 0; i < numStocks; i++) {
        printf("Enter the name of stock %d: ", i+1);
        stockNames[i] = (char*) malloc(50 * sizeof(char));
        scanf("%s", stockNames[i]);
        printf("Enter the current price of %s: $", stockNames[i]);
        scanf("%lf", &stockPrices[i]);
    }

    printf("\n");
    printf("Your stock tracker:\n");

    for (int i = 0; i < numStocks; i++) {
        printf("%s: $%.2lf\n", stockNames[i], stockPrices[i]);
    }

    printf("\n");
    while (1) {
        char input[50];
        printf("Enter the name of a stock you want to update (or \"-1\" to quit): ");
        scanf("%s", input);

        if (strcmp(input, "-1") == 0) {
            break;
        } 

        double newPrice = 0;
        int index = -1;
        for (int i = 0; i < numStocks; i++) {
            if (strcmp(input, stockNames[i]) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            printf("Invalid stock name. Try again.\n");
            continue;
        }

        printf("Enter the new price for %s: $", input);
        scanf("%lf", &newPrice);
        stockPrices[index] = newPrice;

        printf("\n");
        printf("Updated stock tracker:\n");

        for (int i = 0; i < numStocks; i++) {
            printf("%s: $%.2lf\n", stockNames[i], stockPrices[i]);
        }

        printf("\n");
    }

    printf("Thank you for using our stock tracker!\n");

    for (int i = 0; i < numStocks; i++) {
        free(stockNames[i]);
    }
    free(stockNames);
    free(stockPrices);

    return 0;
}