//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: careful
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

// Add a stock to the tracker
void add_stock(stock_market_tracker_t* tracker, const char* symbol, double price, double change, double percent_change) {
    // Check if the tracker is full
    if (tracker->num_stocks >= MAX_STOCKS) {
        printf("Error: The tracker is full.\n");
        return;
    }

    // Add the stock to the tracker
    strcpy(tracker->stocks[tracker->num_stocks].symbol, symbol);
    tracker->stocks[tracker->num_stocks].price = price;
    tracker->stocks[tracker->num_stocks].change = change;
    tracker->stocks[tracker->num_stocks].percent_change = percent_change;
    tracker->num_stocks++;
}

// Print the stocks in the tracker
void print_stocks(stock_market_tracker_t* tracker) {
    for (int i = 0; i < tracker->num_stocks; i++) {
        printf("%s: $%.2f (%.2f%%)\n", tracker->stocks[i].symbol, tracker->stocks[i].price, tracker->stocks[i].percent_change);
    }
}

// Free the memory used by the tracker
void free_stock_market_tracker(stock_market_tracker_t* tracker) {
    free(tracker);
}

// Main function
int main() {
    // Create a new stock market tracker
    stock_market_tracker_t* tracker = create_stock_market_tracker();

    // Add some stocks to the tracker
    add_stock(tracker, "AAPL", 100.00, 1.00, 1.00);
    add_stock(tracker, "GOOG", 120.00, 2.00, 1.67);
    add_stock(tracker, "MSFT", 90.00, -1.00, -1.11);

    // Print the stocks in the tracker
    print_stocks(tracker);

    // Free the memory used by the tracker
    free_stock_market_tracker(tracker);

    return 0;
}