//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a stock
typedef struct Stock {
  char *name;
  double price;
  double change;
  double volume;
} Stock;

// Function to create a new stock
Stock *create_stock(char *name, double price, double change, double volume) {
  Stock *stock = malloc(sizeof(Stock));
  stock->name = strdup(name);
  stock->price = price;
  stock->change = change;
  stock->volume = volume;
  return stock;
}

// Function to print a stock
void print_stock(Stock *stock) {
  printf("%s: %f (%f%%) %f\n", stock->name, stock->price, stock->change, stock->volume);
}

// Function to compare two stocks by price
int compare_stocks_by_price(const void *a, const void *b) {
  const Stock *stock1 = *(const Stock **)a;
  const Stock *stock2 = *(const Stock **)b;
  return stock1->price - stock2->price;
}

// Function to compare two stocks by change
int compare_stocks_by_change(const void *a, const void *b) {
  const Stock *stock1 = *(const Stock **)a;
  const Stock *stock2 = *(const Stock **)b;
  return stock1->change - stock2->change;
}

// Function to compare two stocks by volume
int compare_stocks_by_volume(const void *a, const void *b) {
  const Stock *stock1 = *(const Stock **)a;
  const Stock *stock2 = *(const Stock **)b;
  return stock1->volume - stock2->volume;
}

// Function to sort an array of stocks by price
void sort_stocks_by_price(Stock **stocks, int num_stocks) {
  qsort(stocks, num_stocks, sizeof(Stock *), compare_stocks_by_price);
}

// Function to sort an array of stocks by change
void sort_stocks_by_change(Stock **stocks, int num_stocks) {
  qsort(stocks, num_stocks, sizeof(Stock *), compare_stocks_by_change);
}

// Function to sort an array of stocks by volume
void sort_stocks_by_volume(Stock **stocks, int num_stocks) {
  qsort(stocks, num_stocks, sizeof(Stock *), compare_stocks_by_volume);
}

int main() {
  // Create an array of stocks
  Stock *stocks[] = {
    create_stock("Apple", 120.00, 1.00, 1000000),
    create_stock("Google", 1000.00, 2.00, 500000),
    create_stock("Amazon", 2000.00, 3.00, 250000),
    create_stock("Microsoft", 500.00, 4.00, 1500000),
    create_stock("Tesla", 600.00, 5.00, 100000),
  };

  // Sort the stocks by price
  sort_stocks_by_price(stocks, 5);

  // Print the stocks sorted by price
  printf("Stocks sorted by price:\n");
  for (int i = 0; i < 5; i++) {
    print_stock(stocks[i]);
  }

  // Sort the stocks by change
  sort_stocks_by_change(stocks, 5);

  // Print the stocks sorted by change
  printf("\nStocks sorted by change:\n");
  for (int i = 0; i < 5; i++) {
    print_stock(stocks[i]);
  }

  // Sort the stocks by volume
  sort_stocks_by_volume(stocks, 5);

  // Print the stocks sorted by volume
  printf("\nStocks sorted by volume:\n");
  for (int i = 0; i < 5; i++) {
    print_stock(stocks[i]);
  }

  // Free the memory allocated for the stocks
  for (int i = 0; i < 5; i++) {
    free(stocks[i]->name);
    free(stocks[i]);
  }

  return 0;
}