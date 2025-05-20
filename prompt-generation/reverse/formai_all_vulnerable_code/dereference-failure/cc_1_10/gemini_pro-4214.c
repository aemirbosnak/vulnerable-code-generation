//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 100

// Define the structure of a stock
typedef struct {
    char *name;          // The name of the stock
    char *symbol;        // The stock symbol
    float price;         // The current price of the stock
    float change;        // The change in the stock price since the last update
    float percent_change; // The percentage change in the stock price since the last update
} stock_t;

// Define the structure of the stock market tracker
typedef struct {
    stock_t stocks[MAX_STOCKS];  // The array of stocks being tracked
    int num_stocks;              // The number of stocks being tracked
} stock_market_tracker_t;

// Create a new stock market tracker
stock_market_tracker_t *create_stock_market_tracker() {
    stock_market_tracker_t *tracker = malloc(sizeof(stock_market_tracker_t));
    tracker->num_stocks = 0;
    return tracker;
}

// Add a stock to the tracker
void add_stock(stock_market_tracker_t *tracker, stock_t stock) {
    if (tracker->num_stocks >= MAX_STOCKS) {
        printf("Error: cannot add more stocks to the tracker\n");
        return;
    }

    tracker->stocks[tracker->num_stocks++] = stock;
}

// Remove a stock from the tracker
void remove_stock(stock_market_tracker_t *tracker, char *symbol) {
    for (int i = 0; i < tracker->num_stocks; i++) {
        if (strcmp(tracker->stocks[i].symbol, symbol) == 0) {
            // Found the stock, so remove it from the tracker
            for (int j = i + 1; j < tracker->num_stocks; j++) {
                tracker->stocks[j - 1] = tracker->stocks[j];
            }
            tracker->num_stocks--;
            return;
        }
    }

    // Stock not found
    printf("Error: stock not found\n");
}

// Update the prices of the stocks in the tracker
void update_prices(stock_market_tracker_t *tracker) {
    // Get the current time
    time_t now = time(NULL);

    // For each stock in the tracker, update its price
    for (int i = 0; i < tracker->num_stocks; i++) {
        // Get a random price for the stock
        float price = (float) (rand() % 1000) / 100.0;

        // Calculate the change in the stock price since the last update
        float change = price - tracker->stocks[i].price;

        // Calculate the percentage change in the stock price since the last update
        float percent_change = change / tracker->stocks[i].price * 100.0;

        // Update the stock's price, change, and percent_change
        tracker->stocks[i].price = price;
        tracker->stocks[i].change = change;
        tracker->stocks[i].percent_change = percent_change;
    }
}

// Print the stocks in the tracker
void print_stocks(stock_market_tracker_t *tracker) {
    printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-20s %-10s %-10s %-10s %-10s\n", "Name", "Symbol", "Price", "Change", "Percent Change");
    printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < tracker->num_stocks; i++) {
        printf("%-20s %-10s $%-10.2f %-10.2f %-10.2f%%\n", tracker->stocks[i].name, tracker->stocks[i].symbol, tracker->stocks[i].price, tracker->stocks[i].change, tracker->stocks[i].percent_change);
    }
    printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
}

// Free the memory allocated by the tracker
void free_stock_market_tracker(stock_market_tracker_t *tracker) {
    for (int i = 0; i < tracker->num_stocks; i++) {
        free(tracker->stocks[i].name);
        free(tracker->stocks[i].symbol);
    }
    free(tracker);
}

// The main function
int main() {
    // Create a new stock market tracker
    stock_market_tracker_t *tracker = create_stock_market_tracker();

    // Add some stocks to the tracker
    add_stock(tracker, (stock_t) { .name = "Apple", .symbol = "AAPL", .price = 100.0, .change = 0.0, .percent_change = 0.0 });
    add_stock(tracker, (stock_t) { .name = "Microsoft", .symbol = "MSFT", .price = 100.0, .change = 0.0, .percent_change = 0.0 });
    add_stock(tracker, (stock_t) { .name = "Alphabet", .symbol = "GOOGL", .price = 100.0, .change = 0.0, .percent_change = 0.0 });
    add_stock(tracker, (stock_t) { .name = "Amazon", .symbol = "AMZN", .price = 100.0, .change = 0.0, .percent_change = 0.0 });

    // Update the prices of the stocks in the tracker
    update_prices(tracker);

    // Print the stocks in the tracker
    print_stocks(tracker);

    // Free the memory allocated by the tracker
    free_stock_market_tracker(tracker);

    return 0;
}