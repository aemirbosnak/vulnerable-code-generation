//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stock {
  char *name;
  float price;
  int volume;
} Stock;

typedef struct Portfolio {
  int numStocks;
  Stock *stocks;
} Portfolio;

void initPortfolio(Portfolio *portfolio) {
  portfolio->numStocks = 0;
  portfolio->stocks = NULL;
}

void addStock(Portfolio *portfolio, Stock *stock) {
  portfolio->numStocks++;
  portfolio->stocks = realloc(portfolio->stocks, sizeof(Stock) * portfolio->numStocks);
  portfolio->stocks[portfolio->numStocks - 1] = *stock;
}

void printPortfolio(Portfolio *portfolio) {
  for (int i = 0; i < portfolio->numStocks; i++) {
    printf("%s: $%.2f (%d)\n", portfolio->stocks[i].name, portfolio->stocks[i].price, portfolio->stocks[i].volume);
  }
}

int main() {
  Portfolio portfolio;
  initPortfolio(&portfolio);

  Stock stock1;
  stock1.name = "AAPL";
  stock1.price = 123.45;
  stock1.volume = 100;
  addStock(&portfolio, &stock1);

  Stock stock2;
  stock2.name = "GOOG";
  stock2.price = 987.65;
  stock2.volume = 200;
  addStock(&portfolio, &stock2);

  printPortfolio(&portfolio);

  return 0;
}