//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 10

// Define the structure of a stock
typedef struct {
    char symbol[10];
    double price;
    double change;
    double percent_change;
} stock_t;

// Define the structure of the stock market tracker
typedef struct {
    stock_t stocks[MAX_STOCKS];
    int num_stocks;
} stock_market_tracker_t;

// Create a new stock market tracker
stock_market_tracker_t* create_stock_market_tracker() {
    stock_market_tracker_t* tracker = malloc(sizeof(stock_market_tracker_t));
    tracker->num_stocks = 0;
    return tracker;
}

// Add a stock to the stock market tracker
void add_stock(stock_market_tracker_t* tracker, stock_t stock) {
    tracker->stocks[tracker->num_stocks] = stock;
    tracker->num_stocks++;
}

// Print the stock market tracker
void print_stock_market_tracker(stock_market_tracker_t* tracker) {
    printf("Stock Market Tracker\n");
    printf("--------------------\n");
    for (int i = 0; i < tracker->num_stocks; i++) {
        stock_t stock = tracker->stocks[i];
        printf("%s: $%.2f (%.2f%%)\n", stock.symbol, stock.price, stock.percent_change);
    }
}

// Free the memory allocated for the stock market tracker
void free_stock_market_tracker(stock_market_tracker_t* tracker) {
    free(tracker);
}

// Main function
int main() {
    // Create a new stock market tracker
    stock_market_tracker_t* tracker = create_stock_market_tracker();

    // Add some stocks to the stock market tracker
    stock_t stock1 = {"AAPL", 123.45, 1.23, 1.00};
    add_stock(tracker, stock1);
    stock_t stock2 = {"GOOG", 789.10, -2.34, -0.30};
    add_stock(tracker, stock2);
    stock_t stock3 = {"AMZN", 2345.67, 3.45, 0.15};
    add_stock(tracker, stock3);

    // Print the stock market tracker
    print_stock_market_tracker(tracker);

    // Free the memory allocated for the stock market tracker
    free_stock_market_tracker(tracker);

    return 0;
}