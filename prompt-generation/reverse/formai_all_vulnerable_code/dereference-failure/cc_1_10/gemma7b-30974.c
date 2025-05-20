//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_Stocks 20

typedef struct Stock {
    char name[20];
    double price;
    double change;
    double volatility;
} Stock;

void initializeStocks(Stock **stocks, int numStocks) {
    for (int i = 0; i < numStocks; i++) {
        stocks[i] = malloc(sizeof(Stock));
        stocks[i]->name[0] = '\0';
        stocks[i]->price = 0.0;
        stocks[i]->change = 0.0;
        stocks[i]->volatility = 0.0;
    }
}

void updateStockPrices(Stock **stocks, int numStocks) {
    for (int i = 0; i < numStocks; i++) {
        stocks[i]->price = rand() % 1000;
        stocks[i]->change = rand() % 20 - 10.0;
    }
}

void calculateVolatility(Stock **stocks, int numStocks) {
    for (int i = 0; i < numStocks; i++) {
        stocks[i]->volatility = sqrt(rand() % 100) * 0.1;
    }
}

int main() {
    Stock **stocks = NULL;
    int numStocks = MAX_Stocks;

    initializeStocks(&stocks, numStocks);
    updateStockPrices(stocks, numStocks);
    calculateVolatility(stocks, numStocks);

    for (int i = 0; i < numStocks; i++) {
        printf("%s: Price: %.2lf, Change: %.2lf, Volatility: %.2lf\n", stocks[i]->name, stocks[i]->price, stocks[i]->change, stocks[i]->volatility);
    }

    return 0;
}