//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10

struct stock {
  char *symbol;
  float price;
  float change;
};

void print_stock(struct stock *stock) {
  printf("%s: $%.2f (%.2f%%)\n", stock->symbol, stock->price, stock->change);
}

int main() {
  struct stock stocks[MAX_STOCKS];

  // Initialize the stocks array with some post-apocalyptic symbols and prices
  strcpy(stocks[0].symbol, "RAD");
  stocks[0].price = 100.00;
  stocks[0].change = 0.00;

  strcpy(stocks[1].symbol, "MED");
  stocks[1].price = 50.00;
  stocks[1].change = -10.00;

  strcpy(stocks[2].symbol, "FOOD");
  stocks[2].price = 25.00;
  stocks[2].change = 5.00;

  strcpy(stocks[3].symbol, "WATER");
  stocks[3].price = 10.00;
  stocks[3].change = 2.00;

  strcpy(stocks[4].symbol, "AMMO");
  stocks[4].price = 5.00;
  stocks[4].change = -5.00;

  strcpy(stocks[5].symbol, "GAS");
  stocks[5].price = 2.00;
  stocks[5].change = -10.00;

  strcpy(stocks[6].symbol, "TOOLS");
  stocks[6].price = 1.00;
  stocks[6].change = 0.00;

  strcpy(stocks[7].symbol, "MEDKIT");
  stocks[7].price = 0.50;
  stocks[7].change = 5.00;

  strcpy(stocks[8].symbol, "DOGFOOD");
  stocks[8].price = 0.25;
  stocks[8].change = -2.00;

  strcpy(stocks[9].symbol, "TOILETPAPER");
  stocks[9].price = 0.10;
  stocks[9].change = 10.00;

  // Print the stock prices
  printf("Post-Apocalyptic Stock Prices:\n\n");
  for (int i = 0; i < MAX_STOCKS; i++) {
    print_stock(&stocks[i]);
  }

  return 0;
}