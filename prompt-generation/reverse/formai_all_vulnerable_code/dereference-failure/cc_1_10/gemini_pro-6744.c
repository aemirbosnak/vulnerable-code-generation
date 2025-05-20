//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 10

// Define the data structure to represent a stock
typedef struct stock {
    char symbol[10];  // The stock symbol (e.g., "AAPL")
    double price;     // The current stock price
    double change;    // The change in stock price since the previous day
} stock_t;

// Define the data structure to represent the stock market tracker
typedef struct stock_market_tracker {
    stock_t stocks[MAX_STOCKS];  // The array of stocks being tracked
    int num_stocks;              // The number of stocks being tracked
} stock_market_tracker_t;

// Function to create a new stock market tracker
stock_market_tracker_t* create_stock_market_tracker() {
    stock_market_tracker_t* tracker = (stock_market_tracker_t*)malloc(sizeof(stock_market_tracker_t));
    tracker->num_stocks = 0;
    return tracker;
}

// Function to add a stock to the stock market tracker
void add_stock(stock_market_tracker_t* tracker, stock_t stock) {
    if (tracker->num_stocks < MAX_STOCKS) {
        tracker->stocks[tracker->num_stocks] = stock;
        tracker->num_stocks++;
    }
}

// Function to print the stock market tracker
void print_stock_market_tracker(stock_market_tracker_t* tracker) {
    printf("Stock Market Tracker:\n");
    for (int i = 0; i < tracker->num_stocks; i++) {
        printf("  %s: $%.2f (%.2f%%)\n", tracker->stocks[i].symbol, tracker->stocks[i].price, tracker->stocks[i].change);
    }
}

// Function to free the memory used by the stock market tracker
void free_stock_market_tracker(stock_market_tracker_t* tracker) {
    free(tracker);
}

// Main function
int main() {
    // Create a new stock market tracker
    stock_market_tracker_t* tracker = create_stock_market_tracker();

    // Add some stocks to the tracker
    stock_t stock1 = {"AAPL", 170.00, 1.00};
    add_stock(tracker, stock1);
    stock_t stock2 = {"GOOG", 1,000.00, 2.00};
    add_stock(tracker, stock2);
    stock_t stock3 = {"MSFT", 290.00, 3.00};
    add_stock(tracker, stock3);

    // Print the stock market tracker
    print_stock_market_tracker(tracker);

    // Free the memory used by the stock market tracker
    free_stock_market_tracker(tracker);

    return 0;
}