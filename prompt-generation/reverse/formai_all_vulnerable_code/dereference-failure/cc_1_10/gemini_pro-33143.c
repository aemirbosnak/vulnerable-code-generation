//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 100

// Define the structure of a stock
typedef struct {
    char *symbol;
    double price;
    double change;
    double percent_change;
} Stock;

// Define the structure of the stock market tracker
typedef struct {
    Stock stocks[MAX_STOCKS];
    int num_stocks;
} StockMarketTracker;

// Create a new stock market tracker
StockMarketTracker *create_stock_market_tracker() {
    StockMarketTracker *tracker = malloc(sizeof(StockMarketTracker));
    tracker->num_stocks = 0;
    return tracker;
}

// Add a stock to the stock market tracker
void add_stock(StockMarketTracker *tracker, char *symbol, double price, double change, double percent_change) {
    if (tracker->num_stocks >= MAX_STOCKS) {
        printf("Error: cannot add more than %d stocks to the tracker.\n", MAX_STOCKS);
        return;
    }

    Stock stock = { .symbol = symbol, .price = price, .change = change, .percent_change = percent_change };
    tracker->stocks[tracker->num_stocks++] = stock;
}

// Print the stock market tracker
void print_stock_market_tracker(StockMarketTracker *tracker) {
    printf("Stock Market Tracker\n");
    printf("--------------------\n");
    for (int i = 0; i < tracker->num_stocks; i++) {
        Stock stock = tracker->stocks[i];
        printf("%s: $%.2f (%.2f%%)\n", stock.symbol, stock.price, stock.percent_change);
    }
}

// Free the memory allocated for the stock market tracker
void free_stock_market_tracker(StockMarketTracker *tracker) {
    for (int i = 0; i < tracker->num_stocks; i++) {
        free(tracker->stocks[i].symbol);
    }
    free(tracker);
}

// Generate a random stock price
double generate_random_stock_price() {
    return (double)rand() / (double)RAND_MAX * 100.0;
}

// Generate a random stock change
double generate_random_stock_change() {
    return (double)rand() / (double)RAND_MAX * 10.0 - 5.0;
}

// Generate a random stock percent change
double generate_random_stock_percent_change() {
    return (double)rand() / (double)RAND_MAX * 10.0 - 5.0;
}

// Generate a random stock symbol
char *generate_random_stock_symbol() {
    char *symbols[] = {"AAPL", "GOOG", "MSFT", "AMZN", "FB"};
    return symbols[rand() % 5];
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a new stock market tracker
    StockMarketTracker *tracker = create_stock_market_tracker();

    // Add 10 random stocks to the tracker
    for (int i = 0; i < 10; i++) {
        char *symbol = generate_random_stock_symbol();
        double price = generate_random_stock_price();
        double change = generate_random_stock_change();
        double percent_change = generate_random_stock_percent_change();
        add_stock(tracker, symbol, price, change, percent_change);
    }

    // Print the stock market tracker
    print_stock_market_tracker(tracker);

    // Free the memory allocated for the stock market tracker
    free_stock_market_tracker(tracker);

    return 0;
}