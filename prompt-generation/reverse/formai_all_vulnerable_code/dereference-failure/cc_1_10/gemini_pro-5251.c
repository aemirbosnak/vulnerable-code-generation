//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the structure of a stock
typedef struct {
  char symbol[5];
  float price;
  float change;
  float percent_change;
} stock_t;

// Define the structure of a portfolio
typedef struct {
  char name[20];
  int num_stocks;
  stock_t *stocks;
} portfolio_t;

// Create a new portfolio
portfolio_t *create_portfolio(char *name) {
  portfolio_t *portfolio = malloc(sizeof(portfolio_t));
  strcpy(portfolio->name, name);
  portfolio->num_stocks = 0;
  portfolio->stocks = NULL;
  return portfolio;
}

// Add a stock to a portfolio
void add_stock(portfolio_t *portfolio, stock_t *stock) {
  portfolio->num_stocks++;
  portfolio->stocks = realloc(portfolio->stocks, sizeof(stock_t) * portfolio->num_stocks);
  portfolio->stocks[portfolio->num_stocks - 1] = *stock;
}

// Print the portfolio
void print_portfolio(portfolio_t *portfolio) {
  printf("Portfolio: %s\n", portfolio->name);
  for (int i = 0; i < portfolio->num_stocks; i++) {
    printf("  %s: $%.2f (%.2f%%)\n", portfolio->stocks[i].symbol, portfolio->stocks[i].price, portfolio->stocks[i].percent_change);
  }
}

// Get a random stock price
float get_random_stock_price() {
  return (float)rand() / (float)RAND_MAX * 100.0f;
}

// Get a random stock change
float get_random_stock_change() {
  return (float)rand() / (float)RAND_MAX * 10.0f - 5.0f;
}

// Generate a random portfolio
portfolio_t *generate_random_portfolio(char *name) {
  portfolio_t *portfolio = create_portfolio(name);

  // Generate 10 random stocks
  for (int i = 0; i < 10; i++) {
    stock_t stock;
    strcpy(stock.symbol, "AAAA");
    stock.price = get_random_stock_price();
    stock.change = get_random_stock_change();
    stock.percent_change = stock.change / stock.price * 100.0f;
    add_stock(portfolio, &stock);
  }

  return portfolio;
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random portfolio
  portfolio_t *portfolio = generate_random_portfolio("My Portfolio");

  // Print the portfolio
  print_portfolio(portfolio);

  return 0;
}