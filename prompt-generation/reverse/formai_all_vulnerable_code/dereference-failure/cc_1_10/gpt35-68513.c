//FormAI DATASET v1.0 Category: Stock market tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stock {
    char symbol[6];
    char name[20];
    float price;
    float change;
} Stock;

void printStockData(Stock s) {
    printf("%-6s%-20s%-10.2f%-10.2f\n", s.symbol, s.name, s.price, s.change);
}

int main() {
    int numStocks = 0;
    printf("How many stocks do you want to track? ");
    scanf("%d", &numStocks);
    
    Stock *stocks = (Stock *) malloc(numStocks * sizeof(Stock));
    
    // fill in stock data
    for (int i = 0; i < numStocks; i++) {
        printf("\nStock %d\n", i+1);
        printf("Enter symbol: ");
        scanf("%s", stocks[i].symbol);
        printf("Enter name: ");
        scanf("%s", stocks[i].name);
        printf("Enter price: ");
        scanf("%f", &stocks[i].price);
        printf("Enter change: ");
        scanf("%f", &stocks[i].change);
    }
    
    // print table header
    printf("\n%-6s%-20s%-10s%-10s\n", "Symbol", "Name", "Price", "Change");
    
    // print stock data
    for (int i = 0; i < numStocks; i++) {
        printStockData(stocks[i]);
    }
    
    // calculate total value of all stocks
    float total = 0;
    for (int i = 0; i < numStocks; i++) {
        total += stocks[i].price;
    }
    printf("\nTotal value of all stocks: $%.2f\n", total);
    
    // find highest and lowest priced stocks
    Stock highest = stocks[0];
    Stock lowest = stocks[0];
    for (int i = 1; i < numStocks; i++) {
        if (stocks[i].price > highest.price) {
            highest = stocks[i];
        }
        if (stocks[i].price < lowest.price) {
            lowest = stocks[i];
        }
    }
    printf("\nHighest priced stock:\n");
    printStockData(highest);
    printf("\nLowest priced stock:\n");
    printStockData(lowest);
    
    // find stocks with a price change greater than 10%
    printf("\nStocks with a price change greater than 10%%:\n");
    for (int i = 0; i < numStocks; i++) {
        if (stocks[i].change > 10.0) {
            printStockData(stocks[i]);
        }
    }
    
    // free memory
    free(stocks);
    
    return 0;
}