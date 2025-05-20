//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_HISTORY 1000

typedef struct {
  char *name;
  double price;
  double *history;
  int history_size;
} Stock;

Stock *stocks[MAX_STOCKS];
int num_stocks = 0;

void add_stock(char *name, double price) {
  if (num_stocks >= MAX_STOCKS) {
    printf("Error: Maximum number of stocks reached.\n");
    return;
  }

  stocks[num_stocks] = malloc(sizeof(Stock));
  stocks[num_stocks]->name = strdup(name);
  stocks[num_stocks]->price = price;
  stocks[num_stocks]->history = malloc(sizeof(double) * MAX_HISTORY);
  stocks[num_stocks]->history_size = 0;
  num_stocks++;
}

void update_stock_price(char *name, double price) {
  int i;

  for (i = 0; i < num_stocks; i++) {
    if (strcmp(stocks[i]->name, name) == 0) {
      stocks[i]->price = price;
      stocks[i]->history[stocks[i]->history_size++] = price;
      break;
    }
  }

  if (i == num_stocks) {
    printf("Error: Stock not found.\n");
  }
}

void print_stock_info(char *name) {
  int i;

  for (i = 0; i < num_stocks; i++) {
    if (strcmp(stocks[i]->name, name) == 0) {
      printf("Name: %s\n", stocks[i]->name);
      printf("Price: %f\n", stocks[i]->price);
      printf("History:\n");
      for (int j = 0; j < stocks[i]->history_size; j++) {
        printf("%f\n", stocks[i]->history[j]);
      }
      break;
    }
  }

  if (i == num_stocks) {
    printf("Error: Stock not found.\n");
  }
}

int main() {
  // Initialize the stock market
  add_stock("Apple", 100.0);
  add_stock("Google", 120.0);
  add_stock("Microsoft", 150.0);

  // Update the stock prices
  update_stock_price("Apple", 105.0);
  update_stock_price("Google", 125.0);
  update_stock_price("Microsoft", 160.0);

  // Print the stock information
  print_stock_info("Apple");
  print_stock_info("Google");
  print_stock_info("Microsoft");

  return 0;
}