//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 100

// Define the structure of a stock
typedef struct {
    char symbol[10];
    double price;
    double change;
    double volume;
} Stock;

// Define the structure of the stock market tracker
typedef struct {
    int num_stocks;
    Stock stocks[MAX_STOCKS];
} StockMarketTracker;

// Create a new stock market tracker
StockMarketTracker* create_stock_market_tracker() {
    StockMarketTracker* tracker = malloc(sizeof(StockMarketTracker));
    tracker->num_stocks = 0;
    return tracker;
}

// Add a stock to the stock market tracker
void add_stock(StockMarketTracker* tracker, char* symbol, double price, double change, double volume) {
    strcpy(tracker->stocks[tracker->num_stocks].symbol, symbol);
    tracker->stocks[tracker->num_stocks].price = price;
    tracker->stocks[tracker->num_stocks].change = change;
    tracker->stocks[tracker->num_stocks].volume = volume;
    tracker->num_stocks++;
}

// Print the stock market tracker
void print_stock_market_tracker(StockMarketTracker* tracker) {
    printf("Stock Market Tracker\n");
    printf("--------------------\n");
    for (int i = 0; i < tracker->num_stocks; i++) {
        printf("%s %.2f %.2f %.2f\n", tracker->stocks[i].symbol, tracker->stocks[i].price, tracker->stocks[i].change, tracker->stocks[i].volume);
    }
}

// Free the memory allocated for the stock market tracker
void free_stock_market_tracker(StockMarketTracker* tracker) {
    free(tracker);
}

// Generate a random stock
Stock generate_random_stock() {
    Stock stock;
    strcpy(stock.symbol, "XYZ");
    stock.price = rand() % 100;
    stock.change = rand() % 10;
    stock.volume = rand() % 1000;
    return stock;
}

// Generate a random stock market tracker
StockMarketTracker* generate_random_stock_market_tracker() {
    StockMarketTracker* tracker = create_stock_market_tracker();
    for (int i = 0; i < MAX_STOCKS; i++) {
        Stock stock = generate_random_stock();
        add_stock(tracker, stock.symbol, stock.price, stock.change, stock.volume);
    }
    return tracker;
}

int main() {
    // Create a new stock market tracker
    StockMarketTracker* tracker = create_stock_market_tracker();

    // Add some random stocks to the stock market tracker
    for (int i = 0; i < MAX_STOCKS; i++) {
        Stock stock = generate_random_stock();
        add_stock(tracker, stock.symbol, stock.price, stock.change, stock.volume);
    }

    // Print the stock market tracker
    print_stock_market_tracker(tracker);

    // Free the memory allocated for the stock market tracker
    free_stock_market_tracker(tracker);

    return 0;
}