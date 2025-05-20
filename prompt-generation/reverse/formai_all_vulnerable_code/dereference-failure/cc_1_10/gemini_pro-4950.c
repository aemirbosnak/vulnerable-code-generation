//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 10

// Define the structure of a stock
typedef struct {
  char symbol[10];
  float price;
  float change;
  float percent_change;
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
    printf("%s: $%.2f (%.2f%%)\n", tracker->stocks[i].symbol, tracker->stocks[i].price, tracker->stocks[i].percent_change);
  }
}

// Update the prices and changes of the stocks in the tracker
void update_stocks(StockMarketTracker* tracker) {
  // Get the current time
  time_t t = time(NULL);
  struct tm* tm = localtime(&t);

  // Update the prices and changes of the stocks
  for (int i = 0; i < tracker->num_stocks; i++) {
    // Get the random price change
    float change = (rand() % 100) / 100.0;

    // Update the price and change
    tracker->stocks[i].price += change;
    tracker->stocks[i].change = change;

    // Calculate the percent change
    tracker->stocks[i].percent_change = (change / tracker->stocks[i].price) * 100.0;
  }
}

// Main function
int main() {
  // Create a new stock market tracker
  StockMarketTracker* tracker = create_stock_market_tracker();

  // Add some stocks to the tracker
  Stock stock1 = {"AAPL", 100.00, 0.00, 0.00};
  Stock stock2 = {"GOOG", 120.00, 0.00, 0.00};
  Stock stock3 = {"AMZN", 150.00, 0.00, 0.00};
  add_stock(tracker, stock1);
  add_stock(tracker, stock2);
  add_stock(tracker, stock3);

  // Print the stocks in the tracker
  print_stocks(tracker);

  // Update the prices and changes of the stocks in the tracker
  update_stocks(tracker);

  // Print the stocks in the tracker
  print_stocks(tracker);

  // Free the memory allocated for the tracker
  free(tracker);

  return 0;
}