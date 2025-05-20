//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store stock data
typedef struct stock {
  char *name;
  float price;
  int volume;
} stock;

// Function to compare stocks by price
int compare_stocks_by_price(const void *a, const void *b) {
  stock *stock1 = (stock *)a;
  stock *stock2 = (stock *)b;
  return stock1->price - stock2->price;
}

// Function to print stock data
void print_stock(stock *stock) {
  printf("Name: %s\n", stock->name);
  printf("Price: %f\n", stock->price);
  printf("Volume: %d\n\n", stock->volume);
}

// Function to load stock data from a file
void load_stock_data(stock **stocks, int *num_stocks, char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    exit(1);
  }

  // Read the number of stocks
  fscanf(file, "%d", num_stocks);

  // Allocate memory for the stocks
  *stocks = (stock *)malloc(*num_stocks * sizeof(stock));
  if (*stocks == NULL) {
    printf("Error allocating memory for stocks\n");
    exit(1);
  }

  // Read the stock data
  for (int i = 0; i < *num_stocks; i++) {
    fscanf(file, "%s %f %d", (*stocks)[i].name, &(*stocks)[i].price,
            &(*stocks)[i].volume);
  }

  fclose(file);
}

// Function to find the average stock price
float average_stock_price(stock *stocks, int num_stocks) {
  float total_price = 0;
  for (int i = 0; i < num_stocks; i++) {
    total_price += stocks[i].price;
  }
  return total_price / num_stocks;
}

// Function to find the highest stock price
float highest_stock_price(stock *stocks, int num_stocks) {
  float highest_price = stocks[0].price;
  for (int i = 1; i < num_stocks; i++) {
    if (stocks[i].price > highest_price) {
      highest_price = stocks[i].price;
    }
  }
  return highest_price;
}

// Function to find the lowest stock price
float lowest_stock_price(stock *stocks, int num_stocks) {
  float lowest_price = stocks[0].price;
  for (int i = 1; i < num_stocks; i++) {
    if (stocks[i].price < lowest_price) {
      lowest_price = stocks[i].price;
    }
  }
  return lowest_price;
}

// Function to print stock market summary
void print_stock_market_summary(stock *stocks, int num_stocks) {
  printf("Stock Market Summary:\n");
  printf("---------------------\n");
  printf("Number of stocks: %d\n", num_stocks);
  printf("Average stock price: %f\n", average_stock_price(stocks, num_stocks));
  printf("Highest stock price: %f\n", highest_stock_price(stocks, num_stocks));
  printf("Lowest stock price: %f\n", lowest_stock_price(stocks, num_stocks));
  printf("\n");
}

// Function to main
int main() {
  // Declare variables
  stock *stocks = NULL;
  int num_stocks = 0;

  // Load stock data from file
  load_stock_data(&stocks, &num_stocks, "stocks.txt");

  // Sort stocks by price
  qsort(stocks, num_stocks, sizeof(stock), compare_stocks_by_price);

  // Print stock market summary
  print_stock_market_summary(stocks, num_stocks);

  // Print stock data
  for (int i = 0; i < num_stocks; i++) {
    print_stock(&stocks[i]);
  }

  // Free memory
  for (int i = 0; i < num_stocks; i++) {
    free(stocks[i].name);
  }
  free(stocks);

  return 0;
}