//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store stock data
typedef struct stock {
  char symbol[10];
  double price;
  double change;
  double percent_change;
} stock;

// Function to compare stocks by symbol
int compare_stocks(const void *a, const void *b) {
  return strcmp(((stock *)a)->symbol, ((stock *)b)->symbol);
}

// Function to print stock data
void print_stock(stock *s) {
  printf("%-10s %9.2f %9.2f %6.2f%%\n", s->symbol, s->price, s->change, s->percent_change);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if command line arguments are valid
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <stock_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Open stock file
  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  // Read stock data from file
  int num_stocks;
  fscanf(file, "%d", &num_stocks);

  stock stocks[num_stocks];
  for (int i = 0; i < num_stocks; i++) {
    fscanf(file, "%s %lf %lf %lf", stocks[i].symbol, &stocks[i].price, &stocks[i].change, &stocks[i].percent_change);
  }

  // Close stock file
  fclose(file);

  // Sort stocks by symbol
  qsort(stocks, num_stocks, sizeof(stock), compare_stocks);

  // Print stock data
  printf("%-10s %9s %9s %6s\n", "Symbol", "Price", "Change", "Change %");
  for (int i = 0; i < num_stocks; i++) {
    print_stock(&stocks[i]);
  }

  return EXIT_SUCCESS;
}