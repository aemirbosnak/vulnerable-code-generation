//FormAI DATASET v1.0 Category: Stock market tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stock {
    char symbol[10];
    float price;
    float change;
};

int main() {

    int numStocks = 3;
    struct stock* stocks = malloc(numStocks * sizeof(struct stock));

    // initialize stocks
    strcpy(stocks[0].symbol, "AAPL");
    stocks[0].price = 132.05;
    stocks[0].change = 1.05;

    strcpy(stocks[1].symbol, "MSFT");
    stocks[1].price = 245.88;
    stocks[1].change = -0.32;

    strcpy(stocks[2].symbol, "GOOG");
    stocks[2].price = 1734.16;
    stocks[2].change = 3.21;

    // print initial stock prices
    printf("Initial Stock Prices:\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s: $%.2f (%+.2f%%)\n", stocks[i].symbol, stocks[i].price, stocks[i].change);
    }
    printf("\n");

    // simulate price changes
    printf("Simulating Price Changes:\n");
    for (int i = 0; i < numStocks; i++) {
        float randChange = ((float)rand()/(float)(RAND_MAX)) * 14.28 - 7.14; // random change between -7.14% and 7.14%
        stocks[i].price *= 1 + (randChange / 100);
        stocks[i].change = randChange;
    }

    // print updated stock prices
    printf("Updated Stock Prices:\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s: $%.2f (%+.2f%%)\n", stocks[i].symbol, stocks[i].price, stocks[i].change);
    }

    free(stocks); // free memory
    return 0;
}