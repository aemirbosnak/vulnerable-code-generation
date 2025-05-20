//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 10

// Define the structure of a stock
typedef struct stock {
    char* name;
    float price;
    float change;
} stock;

// Define the structure of the stock market tracker
typedef struct stock_market_tracker {
    stock stocks[MAX_STOCKS];
    int num_stocks;
} stock_market_tracker;

// Create a new stock market tracker
stock_market_tracker* create_stock_market_tracker() {
    stock_market_tracker* tracker = malloc(sizeof(stock_market_tracker));
    tracker->num_stocks = 0;
    return tracker;
}

// Add a stock to the stock market tracker
void add_stock(stock_market_tracker* tracker, char* name, float price, float change) {
    if (tracker->num_stocks >= MAX_STOCKS) {
        printf("Error: cannot add more stocks to the tracker.\n");
        return;
    }

    tracker->stocks[tracker->num_stocks].name = strdup(name);
    tracker->stocks[tracker->num_stocks].price = price;
    tracker->stocks[tracker->num_stocks].change = change;
    tracker->num_stocks++;
}

// Print the stock market tracker
void print_stock_market_tracker(stock_market_tracker* tracker) {
    printf("Stock Market Tracker\n");
    printf("--------------------\n");
    for (int i = 0; i < tracker->num_stocks; i++) {
        printf("%s: $%.2f (%.2f%%)\n", tracker->stocks[i].name, tracker->stocks[i].price, tracker->stocks[i].change);
    }
}

// Free the memory used by the stock market tracker
void free_stock_market_tracker(stock_market_tracker* tracker) {
    for (int i = 0; i < tracker->num_stocks; i++) {
        free(tracker->stocks[i].name);
    }
    free(tracker);
}

// Main function
int main() {
    // Create a new stock market tracker
    stock_market_tracker* tracker = create_stock_market_tracker();

    // Add some stocks to the tracker
    add_stock(tracker, "Apple", 123.45, 1.23);
    add_stock(tracker, "Microsoft", 234.56, -2.34);
    add_stock(tracker, "Google", 345.67, 3.45);

    // Print the stock market tracker
    print_stock_market_tracker(tracker);

    // Free the memory used by the stock market tracker
    free_stock_market_tracker(tracker);

    return 0;
}