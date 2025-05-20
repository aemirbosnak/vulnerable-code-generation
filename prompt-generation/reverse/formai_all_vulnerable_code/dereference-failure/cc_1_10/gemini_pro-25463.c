//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: post-apocalyptic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct stock {
  char *name;
  double price;
  double change;
};

struct market {
  struct stock *stocks;
  int num_stocks;
};

void print_market(struct market *market) {
  printf("Post-Apocalyptic Stock Market\n");
  for (int i = 0; i < market->num_stocks; i++) {
    printf("%s: $%.2f (%.2f%%)\n", market->stocks[i].name, market->stocks[i].price, market->stocks[i].change);
  }
}

int main() {
  struct market market;
  market.stocks = malloc(sizeof(struct stock) * 5);
  market.num_stocks = 5;

  market.stocks[0].name = "Water";
  market.stocks[0].price = 100.0;
  market.stocks[0].change = 10.0;

  market.stocks[1].name = "Food";
  market.stocks[1].price = 50.0;
  market.stocks[1].change = -5.0;

  market.stocks[2].name = "Ammunition";
  market.stocks[2].price = 25.0;
  market.stocks[2].change = 15.0;

  market.stocks[3].name = "Medicine";
  market.stocks[3].price = 15.0;
  market.stocks[3].change = 0.0;

  market.stocks[4].name = "Gasoline";
  market.stocks[4].price = 10.0;
  market.stocks[4].change = -10.0;

  print_market(&market);

  return 0;
}