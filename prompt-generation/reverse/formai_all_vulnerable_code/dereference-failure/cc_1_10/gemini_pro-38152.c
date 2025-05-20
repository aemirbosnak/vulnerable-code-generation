//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct stock {
  char *symbol;
  double price;
  double change;
  double percent_change;
  struct stock *next;
} stock;

stock *head = NULL;

void add_stock(char *symbol, double price, double change, double percent_change) {
  stock *new_stock = malloc(sizeof(stock));
  new_stock->symbol = strdup(symbol);
  new_stock->price = price;
  new_stock->change = change;
  new_stock->percent_change = percent_change;
  new_stock->next = head;
  head = new_stock;
}

void print_stocks() {
  stock *current = head;
  while (current != NULL) {
    printf("%s %.2f %.2f %.2f%%\n", current->symbol, current->price, current->change, current->percent_change);
    current = current->next;
  }
}

void free_stocks() {
  stock *current = head;
  while (current != NULL) {
    stock *next = current->next;
    free(current->symbol);
    free(current);
    current = next;
  }
  head = NULL;
}

int main() {
  add_stock("AAPL", 120.00, 1.00, 0.83);
  add_stock("GOOG", 800.00, -2.00, -0.25);
  add_stock("AMZN", 1800.00, 5.00, 0.28);
  add_stock("TSLA", 300.00, 10.00, 3.33);
  add_stock("NFLX", 200.00, -5.00, -2.50);

  print_stocks();

  free_stocks();

  return 0;
}