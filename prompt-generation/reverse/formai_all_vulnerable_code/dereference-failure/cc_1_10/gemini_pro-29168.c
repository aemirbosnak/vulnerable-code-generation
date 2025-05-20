//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stock {
  char symbol[10];
  float price;
  float change;
};

struct StockList {
  struct Stock *stocks;
  int count;
};

struct StockList* createStockList(int size) {
  struct StockList *list = malloc(sizeof(struct StockList));
  list->stocks = malloc(sizeof(struct Stock) * size);
  list->count = 0;
  return list;
}

void freeStockList(struct StockList *list) {
  free(list->stocks);
  free(list);
}

void addStock(struct StockList *list, struct Stock stock) {
  list->stocks[list->count++] = stock;
}

void printStockList(struct StockList *list) {
  for (int i = 0; i < list->count; i++) {
    printf("%s: %.2f (%.2f%%)\n", list->stocks[i].symbol, list->stocks[i].price, list->stocks[i].change);
  }
}

int main() {
  struct StockList *list = createStockList(10);

  struct Stock stock1 = {"AAPL", 123.45, 1.23};
  addStock(list, stock1);

  struct Stock stock2 = {"GOOG", 789.10, -0.56};
  addStock(list, stock2);

  struct Stock stock3 = {"MSFT", 234.56, 0.00};
  addStock(list, stock3);

  printStockList(list);

  freeStockList(list);

  return 0;
}