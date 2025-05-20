//FormAI DATASET v1.0 Category: Stock market tracker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_STOCK_NAME 50

struct Stock {
  char name[MAX_STOCK_NAME];
  float lastPrice;
  float currentPrice;
};

struct Watchlist {
  struct Stock* stocks[MAX_STOCKS];
  int numStocks;
};

int addStock(struct Watchlist* watchlist, char* name, float price) {
  if (watchlist->numStocks >= MAX_STOCKS) {
    return -1;
  }

  struct Stock* newStock = (struct Stock*)malloc(sizeof(struct Stock));
  
  strcpy(newStock->name, name);
  newStock->lastPrice = price;
  newStock->currentPrice = price;

  watchlist->stocks[watchlist->numStocks] = newStock;
  watchlist->numStocks++;

  return 0;
}

void updateStockPrices(struct Watchlist* watchlist) {
  for (int i = 0; i < watchlist->numStocks; i++) {
    watchlist->stocks[i]->lastPrice = watchlist->stocks[i]->currentPrice;
    watchlist->stocks[i]->currentPrice = (float)rand()/(float)(RAND_MAX/1000);
  }
}

void printStockPrices(struct Watchlist* watchlist) {
  printf("WATCHLIST\n");
  for (int i = 0; i < watchlist->numStocks; i++) {
    printf("%s: last price=%.2f, current price=%.2f\n", watchlist->stocks[i]->name, watchlist->stocks[i]->lastPrice, watchlist->stocks[i]->currentPrice);
  }
}

int main() {
  struct Watchlist watchlist;
  watchlist.numStocks = 0;

  addStock(&watchlist, "AAPL", 122.94);
  addStock(&watchlist, "MSFT", 214.07);
  addStock(&watchlist, "AMZN", 3024.25);
  addStock(&watchlist, "GOOG", 1501.48);
  addStock(&watchlist, "FB", 263.11);

  for (int i = 0; i < 10; i++) {
    updateStockPrices(&watchlist);
    printStockPrices(&watchlist);
    printf("=====================================\n");
  }

  return 0;
}