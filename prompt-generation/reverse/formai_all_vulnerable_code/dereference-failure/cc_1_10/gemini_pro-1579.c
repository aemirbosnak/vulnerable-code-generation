//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 100

// Define the structure of a stock
typedef struct {
    char symbol[10];
    float price;
    float change;
} Stock;

// Define the structure of the stock market tracker
typedef struct {
    Stock stocks[MAX_STOCKS];
    int num_stocks;
} StockMarketTracker;

// Create a new stock market tracker
StockMarketTracker* create_stock_market_tracker() {
    StockMarketTracker* tracker = (StockMarketTracker*)malloc(sizeof(StockMarketTracker));
    tracker->num_stocks = 0;
    return tracker;
}

// Add a stock to the stock market tracker
void add_stock(StockMarketTracker* tracker, Stock stock) {
    tracker->stocks[tracker->num_stocks] = stock;
    tracker->num_stocks++;
}

// Print the stock market tracker
void print_stock_market_tracker(StockMarketTracker* tracker) {
    printf("Stock Market Tracker\n");
    printf("--------------------\n");
    for (int i = 0; i < tracker->num_stocks; i++) {
        printf("%s: $%.2f (%.2f%%)\n", tracker->stocks[i].symbol, tracker->stocks[i].price, tracker->stocks[i].change);
    }
}

// Free the memory allocated for the stock market tracker
void free_stock_market_tracker(StockMarketTracker* tracker) {
    free(tracker);
}

// Main function
int main() {
    // Create a new stock market tracker
    StockMarketTracker* tracker = create_stock_market_tracker();

    // Add some stocks to the stock market tracker
    Stock stock1 = {"AAPL", 100.00, 1.00};
    add_stock(tracker, stock1);
    Stock stock2 = {"GOOG", 120.00, 2.00};
    add_stock(tracker, stock2);
    Stock stock3 = {"AMZN", 150.00, 3.00};
    add_stock(tracker, stock3);

    // Print the stock market tracker
    print_stock_market_tracker(tracker);

    // Free the memory allocated for the stock market tracker
    free_stock_market_tracker(tracker);

    return 0;
}