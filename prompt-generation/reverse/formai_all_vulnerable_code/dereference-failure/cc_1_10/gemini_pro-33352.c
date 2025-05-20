//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
  char *symbol;
  double open;
  double high;
  double low;
  double close;
  double volume;
} Stock;

typedef struct {
  int num_stocks;
  Stock *stocks;
} Portfolio;

Portfolio *create_portfolio(int num_stocks) {
  Portfolio *portfolio = malloc(sizeof(Portfolio));
  portfolio->num_stocks = num_stocks;
  portfolio->stocks = malloc(sizeof(Stock) * num_stocks);
  return portfolio;
}

void free_portfolio(Portfolio *portfolio) {
  for (int i = 0; i < portfolio->num_stocks; i++) {
    free(portfolio->stocks[i].symbol);
  }
  free(portfolio->stocks);
  free(portfolio);
}

void generate_random_stock(Stock *stock) {
  char *symbols[] = {"AAPL", "GOOGL", "MSFT", "AMZN", "FB"};
  stock->symbol = symbols[rand() % 5];
  stock->open = (double)rand() / RAND_MAX * 100;
  stock->high = stock->open * (1 + (double)rand() / RAND_MAX * 0.1);
  stock->low = stock->open * (1 - (double)rand() / RAND_MAX * 0.1);
  stock->close = (stock->open + stock->high + stock->low) / 3;
  stock->volume = rand() % 1000000;
}

void generate_random_portfolio(Portfolio *portfolio) {
  for (int i = 0; i < portfolio->num_stocks; i++) {
    generate_random_stock(&portfolio->stocks[i]);
  }
}

double calculate_portfolio_value(Portfolio *portfolio) {
  double value = 0;
  for (int i = 0; i < portfolio->num_stocks; i++) {
    value += portfolio->stocks[i].close * portfolio->stocks[i].volume;
  }
  return value;
}

void print_portfolio(Portfolio *portfolio) {
  printf("Portfolio:\n");
  for (int i = 0; i < portfolio->num_stocks; i++) {
    printf("  %s: %.2f\n", portfolio->stocks[i].symbol, portfolio->stocks[i].close);
  }
  printf("Total value: %.2f\n", calculate_portfolio_value(portfolio));
}

int main() {
  srand(time(NULL));

  Portfolio *portfolio = create_portfolio(5);
  generate_random_portfolio(portfolio);
  print_portfolio(portfolio);

  free_portfolio(portfolio);
  return 0;
}