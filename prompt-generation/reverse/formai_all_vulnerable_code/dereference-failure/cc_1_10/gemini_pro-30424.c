//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STOCKS 10
#define NUM_DAYS 30

// Stock structure
typedef struct {
  char *name;
  double price;
  double change;
} Stock;

// Function to generate a random stock name
char *generate_stock_name() {
  char *name = malloc(8);
  for (int i = 0; i < 7; i++) {
    name[i] = 'A' + rand() % 26;
  }
  name[7] = '\0';
  return name;
}

// Function to generate a random stock price
double generate_stock_price() {
  return (double)(rand() % 10000) / 100;
}

// Function to generate a random stock change
double generate_stock_change() {
  return (double)(rand() % 100) / 1000;
}

// Function to create a new stock
Stock *create_stock() {
  Stock *stock = malloc(sizeof(Stock));
  stock->name = generate_stock_name();
  stock->price = generate_stock_price();
  stock->change = generate_stock_change();
  return stock;
}

// Function to print a stock
void print_stock(Stock *stock) {
  printf("%s: $%.2f (%.2f%%)\n", stock->name, stock->price, stock->change * 100);
}

// Function to main
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create an array of stocks
  Stock *stocks[NUM_STOCKS];
  for (int i = 0; i < NUM_STOCKS; i++) {
    stocks[i] = create_stock();
  }

  // Print the initial stock prices
  printf("Initial stock prices:\n");
  for (int i = 0; i < NUM_STOCKS; i++) {
    print_stock(stocks[i]);
  }

  // Simulate the stock market for NUM_DAYS days
  for (int day = 0; day < NUM_DAYS; day++) {
    // Calculate the change in stock prices
    for (int i = 0; i < NUM_STOCKS; i++) {
      stocks[i]->change = generate_stock_change();
      stocks[i]->price += stocks[i]->change * stocks[i]->price;
    }

    // Print the stock prices for the day
    printf("\nDay %d stock prices:\n", day + 1);
    for (int i = 0; i < NUM_STOCKS; i++) {
      print_stock(stocks[i]);
    }
  }

  // Free the allocated memory
  for (int i = 0; i < NUM_STOCKS; i++) {
    free(stocks[i]->name);
    free(stocks[i]);
  }

  return 0;
}