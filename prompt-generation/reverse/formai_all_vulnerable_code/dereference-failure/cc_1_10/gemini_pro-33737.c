//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stock
typedef struct Stock {
  char *name;
  double price;
  double change;
} Stock;

// Function to create a new stock
Stock *createStock(char *name, double price, double change) {
  Stock *stock = malloc(sizeof(Stock));
  stock->name = name;
  stock->price = price;
  stock->change = change;
  return stock;
}

// Function to print a stock
void printStock(Stock *stock) {
  printf("%s: $%.2f (%.2f%%)\n", stock->name, stock->price, stock->change);
}

// Function to compare two stocks by price
int compareStocks(const void *a, const void *b) {
  Stock *stockA = (Stock *)a;
  Stock *stockB = (Stock *)b;
  return stockA->price - stockB->price;
}

// Main function
int main() {
  // Create an array of stocks
  Stock *stocks[] = {
    createStock("AAPL", 170.00, 1.23),
    createStock("GOOG", 1000.00, 0.78),
    createStock("MSFT", 200.00, 0.99),
    createStock("AMZN", 3000.00, 1.56),
    createStock("TSLA", 1000.00, 2.34)
  };

  // Sort the array of stocks by price
  qsort(stocks, 5, sizeof(Stock *), compareStocks);

  // Print the sorted array of stocks
  printf("Sorted stocks by price:\n");
  for (int i = 0; i < 5; i++) {
    printStock(stocks[i]);
  }

  // Free the memory allocated for the stocks
  for (int i = 0; i < 5; i++) {
    free(stocks[i]->name);
    free(stocks[i]);
  }

  return 0;
}