//FormAI DATASET v1.0 Category: Stock market tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_STOCKS 10
#define MAX_STOCK_NAME 20
#define MAX_STOCK_SYMBOL 5

typedef struct StockStruct {
    char name[MAX_STOCK_NAME];
    char symbol[MAX_STOCK_SYMBOL];
    float price;
    float change;
    float percentChange;
} Stock;

int main() {
    srand(time(0));
    int numStocks = rand() % MAX_STOCKS + 1;
    Stock stocks[numStocks];

    // Generate random stocks with names and symbols
    for (int i = 0; i < numStocks; i++) {
        char name[MAX_STOCK_NAME];
        char symbol[MAX_STOCK_SYMBOL];
        sprintf(name, "Stock %d", i+1);
        sprintf(symbol, "ST%d", i+1);
        stocks[i].price = ((float)rand()/(float)(RAND_MAX)) * 100 + 10;
        stocks[i].change = ((float)rand()/(float)(RAND_MAX)) * 20 - 10;
        stocks[i].percentChange = (stocks[i].change / stocks[i].price) * 100;
        strcpy(stocks[i].name, name);
        strcpy(stocks[i].symbol, symbol);
    }

    // Print out stock data
    printf("Today's Stock Market Tracker\n");
    printf("------------------------------\n");
    printf("%-10s%-10s%-10s%-10s\n", "Symbol", "Name", "Price", "Change");
    printf("------------------------------\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%-10s%-10s$%-9.2f%-+9.2f (%+.2f%%)\n", stocks[i].symbol, stocks[i].name, stocks[i].price, stocks[i].change, stocks[i].percentChange);
    }

    // Check for any major changes
    int numIncreases = 0;
    int numDecreases = 0;
    for (int i = 0; i < numStocks; i++) {
        if (stocks[i].percentChange >= 5.0) {
            numIncreases++;
        }
        else if (stocks[i].percentChange <= -5.0) {
            numDecreases++;
        }
    }
    if (numIncreases > 0) {
        printf("\n%d stocks have increased by more than 5%% today!\n", numIncreases);
    }
    if (numDecreases > 0) {
        printf("%d stocks have decreased by more than 5%% today!\n", numDecreases);
    }

    return 0;
}