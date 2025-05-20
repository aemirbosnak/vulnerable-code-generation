//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stock {
    char *name;
    double price;
    double change;
} stock;

int main() {
    // Get the number of stocks to track.
    printf("How many stocks do you want to track? ");
    int num_stocks;
    scanf("%d", &num_stocks);

    // Allocate memory for the array of stocks.
    stock *stocks = malloc(sizeof(stock) * num_stocks);

    // Get the information for each stock.
    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the name of stock %d: ", i + 1);
        char *name = malloc(100);
        scanf("%s", name);

        printf("Enter the price of stock %d: ", i + 1);
        double price;
        scanf("%lf", &price);

        printf("Enter the change in price of stock %d: ", i + 1);
        double change;
        scanf("%lf", &change);

        // Store the information in the array of stocks.
        stocks[i].name = name;
        stocks[i].price = price;
        stocks[i].change = change;
    }

    // Print the information for each stock.
    printf("\nHere is the information for the stocks you entered:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("Stock %d:\n", i + 1);
        printf("Name: %s\n", stocks[i].name);
        printf("Price: $%.2f\n", stocks[i].price);
        printf("Change: %.2f%%\n", stocks[i].change);
        printf("\n");
    }

    // Free the memory allocated for the array of stocks.
    for (int i = 0; i < num_stocks; i++) {
        free(stocks[i].name);
    }
    free(stocks);

    return 0;
}