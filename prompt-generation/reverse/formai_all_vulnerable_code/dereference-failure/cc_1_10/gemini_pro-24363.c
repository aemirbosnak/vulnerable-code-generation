//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data structures
typedef struct {
    char* name;
    double price;
    double change;
} Stock;

typedef struct {
    int num_stocks;
    Stock* stocks;
} StockMarket;

// Function prototypes
StockMarket* create_stock_market(int num_stocks);
void add_stock(StockMarket* market, Stock stock);
void print_stock_market(StockMarket* market);

// Main function
int main() {
    // Create a stock market with 5 stocks
    StockMarket* market = create_stock_market(5);

    // Add some stocks to the market
    Stock stock1 = {"Apple", 100.00, 1.00};
    add_stock(market, stock1);
    Stock stock2 = {"Google", 85.00, -0.50};
    add_stock(market, stock2);
    Stock stock3 = {"Microsoft", 60.00, 0.25};
    add_stock(market, stock3);
    Stock stock4 = {"Amazon", 120.00, 2.00};
    add_stock(market, stock4);
    Stock stock5 = {"Tesla", 75.00, -1.00};
    add_stock(market, stock5);

    // Print the stock market
    print_stock_market(market);

    return 0;
}

// Creates a stock market with the specified number of stocks
StockMarket* create_stock_market(int num_stocks) {
    StockMarket* market = malloc(sizeof(StockMarket));
    market->num_stocks = num_stocks;
    market->stocks = malloc(sizeof(Stock) * num_stocks);
    return market;
}

// Adds a stock to the stock market
void add_stock(StockMarket* market, Stock stock) {
    market->stocks[market->num_stocks++] = stock;
}

// Prints the stock market
void print_stock_market(StockMarket* market) {
    printf("===============================================================\n");
    printf("| Name | Price | Change |\n");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < market->num_stocks; i++) {
        printf("| %s | $%.2f | $%.2f |\n", market->stocks[i].name, market->stocks[i].price, market->stocks[i].change);
    }
    printf("===============================================================\n");
}