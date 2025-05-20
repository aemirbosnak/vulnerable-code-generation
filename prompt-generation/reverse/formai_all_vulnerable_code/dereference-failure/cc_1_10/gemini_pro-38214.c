//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 100

// Define the structure of a stock
typedef struct stock {
  char *name;
  double price;
  double change;
} stock;

// Create an array of stocks
stock stocks[MAX_STOCKS];

// Initialize the number of stocks to 0
int num_stocks = 0;

// Add a stock to the array
void add_stock(char *name, double price, double change) {
  // Check if the array is full
  if (num_stocks >= MAX_STOCKS) {
    printf("Error: array is full\n");
    return;
  }

  // Allocate memory for the stock name
  stocks[num_stocks].name = malloc(strlen(name) + 1);

  // Copy the stock name into the array
  strcpy(stocks[num_stocks].name, name);

  // Set the stock price and change
  stocks[num_stocks].price = price;
  stocks[num_stocks].change = change;

  // Increment the number of stocks
  num_stocks++;
}

// Print the stock information
void print_stocks() {
  // Loop through the array of stocks
  for (int i = 0; i < num_stocks; i++) {
    // Print the stock name, price, and change
    printf("%s: $%.2f (%.2f%%)\n", stocks[i].name, stocks[i].price, stocks[i].change);
  }
}

// Free the memory allocated for the stock names
void free_stocks() {
  // Loop through the array of stocks
  for (int i = 0; i < num_stocks; i++) {
    // Free the memory for the stock name
    free(stocks[i].name);
  }
}

// Main function
int main() {
  // Add some stocks to the array
  add_stock("AAPL", 123.45, 1.23);
  add_stock("GOOG", 1234.56, 2.34);
  add_stock("MSFT", 123.45, 3.45);

  // Print the stock information
  print_stocks();

  // Free the memory allocated for the stock names
  free_stocks();

  return 0;
}