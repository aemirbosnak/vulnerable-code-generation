//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: modular
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
} Stock;

// Define the structure of the stock market tracker
typedef struct {
  Stock stocks[MAX_STOCKS];
  int num_stocks;
} StockMarketTracker;

// Create a new stock market tracker
StockMarketTracker* create_stock_market_tracker() {
  StockMarketTracker* tracker = malloc(sizeof(StockMarketTracker));
  tracker->num_stocks = 0;
  return tracker;
}

// Add a stock to the tracker
void add_stock(StockMarketTracker* tracker, Stock stock) {
  if (tracker->num_stocks < MAX_STOCKS) {
    tracker->stocks[tracker->num_stocks] = stock;
    tracker->num_stocks++;
  }
}

// Print the stocks in the tracker
void print_stocks(StockMarketTracker* tracker) {
  for (int i = 0; i < tracker->num_stocks; i++) {
    printf("%s: $%.2f (%.2f%%)\n", tracker->stocks[i].symbol, tracker->stocks[i].price, tracker->stocks[i].change);
  }
}

// Free the memory used by the tracker
void free_stock_market_tracker(StockMarketTracker* tracker) {
  free(tracker);
}

// Main function
int main() {
  // Create a new stock market tracker
  StockMarketTracker* tracker = create_stock_market_tracker();

  // Add some stocks to the tracker
  Stock stock1 = {"AAPL", 123.45, 1.23};
  add_stock(tracker, stock1);
  Stock stock2 = {"GOOG", 987.65, -2.34};
  add_stock(tracker, stock2);
  Stock stock3 = {"MSFT", 345.67, 0.56};
  add_stock(tracker, stock3);

  // Print the stocks in the tracker
  print_stocks(tracker);

  // Free the memory used by the tracker
  free_stock_market_tracker(tracker);

  return 0;
}