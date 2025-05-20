//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Stock {
  char *name;
  float price;
  time_t timestamp;
} Stock;

typedef struct StockList {
  Stock **stocks;
  size_t capacity;
  size_t size;
} StockList;

Stock *stock_new(const char *name, float price, time_t timestamp) {
  Stock *stock = malloc(sizeof(Stock));
  stock->name = strdup(name);
  stock->price = price;
  stock->timestamp = timestamp;
  return stock;
}

void stock_free(Stock *stock) {
  free(stock->name);
  free(stock);
}

StockList *stocklist_new(size_t capacity) {
  StockList *stocklist = malloc(sizeof(StockList));
  stocklist->stocks = malloc(capacity * sizeof(Stock *));
  stocklist->capacity = capacity;
  stocklist->size = 0;
  return stocklist;
}

void stocklist_free(StockList *stocklist) {
  for (size_t i = 0; i < stocklist->size; i++) {
    stock_free(stocklist->stocks[i]);
  }
  free(stocklist->stocks);
  free(stocklist);
}

void stocklist_add(StockList *stocklist, Stock *stock) {
  if (stocklist->size == stocklist->capacity) {
    stocklist->capacity *= 2;
    stocklist->stocks = realloc(stocklist->stocks, stocklist->capacity * sizeof(Stock *));
  }
  stocklist->stocks[stocklist->size] = stock;
  stocklist->size++;
}

int main(int argc, char *argv[]) {
  StockList *stocklist = stocklist_new(10);
  Stock *stock1 = stock_new("GOOG", 1000.0, time(NULL));
  Stock *stock2 = stock_new("AAPL", 2000.0, time(NULL));
  Stock *stock3 = stock_new("MSFT", 3000.0, time(NULL));
  stocklist_add(stocklist, stock1);
  stocklist_add(stocklist, stock2);
  stocklist_add(stocklist, stock3);

  for (size_t i = 0; i < stocklist->size; i++) {
    printf("%s: $%.2f\n", stocklist->stocks[i]->name, stocklist->stocks[i]->price);
  }

  stocklist_free(stocklist);

  return 0;
}