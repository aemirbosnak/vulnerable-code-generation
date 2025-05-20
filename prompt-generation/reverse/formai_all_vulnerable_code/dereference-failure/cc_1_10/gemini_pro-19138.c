//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N_STOCKS 10
#define N_DAYS 250
#define N_RETURNS N_DAYS - 1

typedef struct {
  char *symbol;
  double *prices;
} stock_t;

typedef struct {
  stock_t *stocks;
  int n_stocks;
} portfolio_t;

portfolio_t *create_portfolio(int n_stocks)
{
  portfolio_t *portfolio = malloc(sizeof(portfolio_t));
  portfolio->stocks = malloc(sizeof(stock_t) * n_stocks);
  portfolio->n_stocks = n_stocks;
  return portfolio;
}

void destroy_portfolio(portfolio_t *portfolio)
{
  for (int i = 0; i < portfolio->n_stocks; i++) {
    free(portfolio->stocks[i].symbol);
    free(portfolio->stocks[i].prices);
  }
  free(portfolio->stocks);
  free(portfolio);
}

int read_data(portfolio_t *portfolio, char *filename)
{
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return -1;
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    char *symbol = strtok(line, ",");
    double *prices = malloc(sizeof(double) * N_DAYS);
    for (int i = 0; i < N_DAYS; i++) {
      prices[i] = atof(strtok(NULL, ","));
    }

    int i;
    for (i = 0; i < portfolio->n_stocks; i++) {
      if (strcmp(portfolio->stocks[i].symbol, symbol) == 0) {
        break;
      }
    }

    if (i == portfolio->n_stocks) {
      portfolio->stocks[i].symbol = malloc(strlen(symbol) + 1);
      strcpy(portfolio->stocks[i].symbol, symbol);
      portfolio->stocks[i].prices = prices;
    }
  }

  fclose(fp);

  return 0;
}

void calculate_returns(portfolio_t *portfolio)
{
  for (int i = 0; i < portfolio->n_stocks; i++) {
    for (int j = 0; j < N_RETURNS; j++) {
      portfolio->stocks[i].prices[j] =
          (portfolio->stocks[i].prices[j + 1] - portfolio->stocks[i].prices[j]) /
          portfolio->stocks[i].prices[j];
    }
  }
}

void print_portfolio(portfolio_t *portfolio)
{
  for (int i = 0; i < portfolio->n_stocks; i++) {
    printf("%s: ", portfolio->stocks[i].symbol);
    for (int j = 0; j < N_RETURNS; j++) {
      printf("%.2f%% ", portfolio->stocks[i].prices[j] * 100);
    }
    printf("\n");
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return -1;
  }

  portfolio_t *portfolio = create_portfolio(N_STOCKS);
  if (read_data(portfolio, argv[1]) != 0) {
    printf("Error reading data from file.\n");
    destroy_portfolio(portfolio);
    return -1;
  }

  calculate_returns(portfolio);
  print_portfolio(portfolio);

  destroy_portfolio(portfolio);

  return 0;
}