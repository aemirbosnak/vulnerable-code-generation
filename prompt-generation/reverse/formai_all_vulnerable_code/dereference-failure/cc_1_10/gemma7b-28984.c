//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: modular
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

void initializeStocks(Stock *stocks, int numStocks) {
    for (int i = 0; i < numStocks; i++) {
        stocks[i].name[0] = '\0';
        stocks[i].currentPrice = 0.0;
        stocks[i].previousPrice = 0.0;
        stocks[i].change = 0.0;
    }
}

void calculateChanges(Stock *stocks, int numStocks) {
    for (int i = 0; i < numStocks; i++) {
        stocks[i].change = (stocks[i].currentPrice - stocks[i].previousPrice) / stocks[i].previousPrice * 100.0;
    }
}

void displayStocks(Stock *stocks, int numStocks) {
    printf("--------------------------------------------------------------------------------\n");
    printf("Name\t\tCurrent Price\t\tPrevious Price\t\tChange\n");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s\t\t%.2lf\t\t%.2lf\t\t%.2lf%%\n", stocks[i].name, stocks[i].currentPrice, stocks[i].previousPrice, stocks[i].change);
    }
    printf("--------------------------------------------------------------------------------\n");
}

int main() {
    Stock *stocks = (Stock *)malloc(MAX_Stocks * sizeof(Stock));
    initializeStocks(stocks, MAX_Stocks);

    // Add sample data
    strcpy(stocks[0].name, "Apple");
    stocks[0].currentPrice = 150.0;
    stocks[0].previousPrice = 140.0;

    strcpy(stocks[1].name, "Microsoft");
    stocks[1].currentPrice = 200.0;
    stocks[1].previousPrice = 190.0;

    strcpy(stocks[2].name, "Google");
    stocks[2].currentPrice = 170.0;
    stocks[2].previousPrice = 160.0;

    calculateChanges(stocks, MAX_Stocks);
    displayStocks(stocks, MAX_Stocks);

    free(stocks);

    return 0;
}