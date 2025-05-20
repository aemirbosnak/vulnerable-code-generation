//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_STOCKS 10

typedef struct {
  char symbol[10];
  double price;
  double change;
} stock_t;

typedef struct {
  stock_t stocks[NUM_STOCKS];
  int num_stocks;
} stock_market_t;

stock_market_t *create_stock_market() {
  stock_market_t *market = malloc(sizeof(stock_market_t));
  market->num_stocks = 0;
  return market;
}

void add_stock(stock_market_t *market, const char *symbol, double price, double change) {
  if (market->num_stocks >= NUM_STOCKS) {
    return;
  }

  strcpy(market->stocks[market->num_stocks].symbol, symbol);
  market->stocks[market->num_stocks].price = price;
  market->stocks[market->num_stocks].change = change;
  market->num_stocks++;
}

void print_stock_market(stock_market_t *market) {
  printf("Symbol\tPrice\tChange\n");
  for (int i = 0; i < market->num_stocks; i++) {
    printf("%s\t%f\t%f\n", market->stocks[i].symbol, market->stocks[i].price, market->stocks[i].change);
  }
}

int main() {
  srand(time(NULL));

  stock_market_t *market = create_stock_market();

  add_stock(market, "AAPL", 123.45, 1.23);
  add_stock(market, "GOOG", 1234.56, 2.34);
  add_stock(market, "MSFT", 123.45, 1.23);
  add_stock(market, "AMZN", 1234.56, 2.34);
  add_stock(market, "FB", 123.45, 1.23);
  add_stock(market, "BABA", 1234.56, 2.34);
  add_stock(market, "TSLA", 123.45, 1.23);
  add_stock(market, "NVDA", 1234.56, 2.34);
  add_stock(market, "NFLX", 123.45, 1.23);
  add_stock(market, "INTC", 1234.56, 2.34);

  print_stock_market(market);

  return 0;
}