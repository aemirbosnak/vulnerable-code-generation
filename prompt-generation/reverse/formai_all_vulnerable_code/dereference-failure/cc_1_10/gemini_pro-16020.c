//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: ephemeral
/* Ephemeral C Stock Market Tracker */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Stock data structure
typedef struct {
    char *name;
    double price;
    int volume;
} Stock;

// Create a new stock
Stock *createStock(char *name, double price, int volume) {
    Stock *stock = malloc(sizeof(Stock));
    stock->name = malloc(strlen(name) + 1);
    strcpy(stock->name, name);
    stock->price = price;
    stock->volume = volume;
    return stock;
}

// Print a stock
void printStock(Stock *stock) {
    printf("%s: $%.2f (%d)\n", stock->name, stock->price, stock->volume);
}

// Update a stock's price
void updateStockPrice(Stock *stock, double newPrice) {
    stock->price = newPrice;
}

// Destroy a stock
void destroyStock(Stock *stock) {
    free(stock->name);
    free(stock);
}

// Stock market data
Stock *stocks[10];

// Initialize the stock market
void initStockMarket() {
    // Create some stocks
    stocks[0] = createStock("Apple", 120.00, 10000);
    stocks[1] = createStock("Microsoft", 90.00, 5000);
    stocks[2] = createStock("Amazon", 150.00, 3000);
    stocks[3] = createStock("Google", 130.00, 4000);
    stocks[4] = createStock("Tesla", 100.00, 2000);
    stocks[5] = createStock("Nvidia", 160.00, 1500);
    stocks[6] = createStock("AMD", 80.00, 2500);
    stocks[7] = createStock("Intel", 60.00, 3500);
    stocks[8] = createStock("IBM", 50.00, 4500);
    stocks[9] = createStock("Cisco", 40.00, 5500);
}

// Update the stock market
void updateStockMarket() {
    // Randomly update stock prices
    for (int i = 0; i < 10; i++) {
        double change = (rand() % 21) - 10.0;
        updateStockPrice(stocks[i], stocks[i]->price + change);
    }
}

// Print the stock market
void printStockMarket() {
    for (int i = 0; i < 10; i++) {
        printStock(stocks[i]);
    }
}

// Destroy the stock market
void destroyStockMarket() {
    for (int i = 0; i < 10; i++) {
        destroyStock(stocks[i]);
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the stock market
    initStockMarket();

    // Update the stock market 10 times
    for (int i = 0; i < 10; i++) {
        updateStockMarket();
        printStockMarket();
        printf("\n");
    }

    // Destroy the stock market
    destroyStockMarket();

    return 0;
}