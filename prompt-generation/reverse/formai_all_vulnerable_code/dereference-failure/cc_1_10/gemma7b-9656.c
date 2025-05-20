//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCK 10

struct Stock {
  char name[20];
  int price;
  int change;
  double volatility;
  char color;
};

void updateStock(struct Stock *stock) {
  stock->price = rand() % 1000;
  stock->change = rand() % 5 - 2;
  stock->volatility = rand() % 20 + 10.0;
  switch (rand() % 4) {
    case 0:
      stock->color = 'G';
      break;
    case 1:
      stock->color = 'R';
      break;
    case 2:
      stock->color = 'B';
      break;
    case 3:
      stock->color = 'Y';
      break;
  }
}

int main() {
  struct Stock stocks[MAX_STOCK];
  for (int i = 0; i < MAX_STOCK; i++) {
    strcpy(stocks[i].name, "Stock #" + i);
    stocks[i].price = rand() % 1000;
    stocks[i].change = rand() % 5 - 2;
    stocks[i].volatility = rand() % 20 + 10.0;
    switch (rand() % 4) {
      case 0:
        stocks[i].color = 'G';
        break;
      case 1:
        stocks[i].color = 'R';
        break;
      case 2:
        stocks[i].color = 'B';
        break;
      case 3:
        stocks[i].color = 'Y';
        break;
    }
  }

  time_t t = time(NULL);
  for (int i = 0; i < MAX_STOCK; i++) {
    updateStock(&stocks[i]);
    printf("%s: Price: %d, Change: %d, Volatility: %.2lf, Color: %c\n", stocks[i].name, stocks[i].price, stocks[i].change, stocks[i].volatility, stocks[i].color);
  }

  printf("\nTime: %s", ctime(&t));

  return 0;
}