//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a stock
typedef struct {
    char symbol[10];
    float price;
    int quantity;
} Stock;

// Function to compare two stocks based on their prices
int compare(const void *a, const void *b) {
    const Stock *stockA = (const Stock *)a;
    const Stock *stockB = (const Stock *)b;

    if (stockA->price < stockB->price) {
        return -1;
    } else if (stockA->price > stockB->price) {
        return 1;
    } else {
        return 0;
    }
}

// Function to display the current state of the stock market
void displayStockMarket(Stock stocks[], int numStocks) {
    printf("Current State of the Stock Market:\n");
    printf("-----------------------------------------------------\n");
    printf("Symbol\tPrice\tQuantity\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s\t%.2f\t%d\n", stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }
    printf("-----------------------------------------------------\n");
}

// Function to simulate the stock market
void simulateStockMarket(Stock stocks[], int numStocks, int numDays) {
    for (int day = 0; day < numDays; day++) {
        printf("Day %d:\n", day + 1);
        displayStockMarket(stocks, numStocks);

        // Randomly increase or decrease the price of each stock
        for (int i = 0; i < numStocks; i++) {
            stocks[i].price += (rand() % 101) - 50;
            if (stocks[i].price < 0) {
                stocks[i].price = 0;
            }
        }

        // Sort the stocks based on their prices
        qsort(stocks, numStocks, sizeof(Stock), compare);
    }
}

// Main function
int main() {
    int numStocks, numDays;

    printf("Enter the number of stocks: ");
    scanf("%d", &numStocks);

    Stock stocks[numStocks];

    for (int i = 0; i < numStocks; i++) {
        printf("Enter the symbol of stock %d: ", i + 1);
        scanf("%s", stocks[i].symbol);
        printf("Enter the initial price of stock %s: ", stocks[i].symbol);
        scanf("%f", &stocks[i].price);
        printf("Enter the initial quantity of stock %s: ", stocks[i].symbol);
        scanf("%d", &stocks[i].quantity);
    }

    printf("Enter the number of days to simulate the stock market: ");
    scanf("%d", &numDays);

    simulateStockMarket(stocks, numStocks, numDays);

    return 0;
}