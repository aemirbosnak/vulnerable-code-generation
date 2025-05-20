//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100

struct stock {
  char *name;
  float price;
  float change;
};

struct stock_list {
  struct stock *stocks;
  int count;
};

struct stock_list *create_stock_list() {
  struct stock_list *list = malloc(sizeof(struct stock_list));
  list->stocks = malloc(MAX_STOCKS * sizeof(struct stock));
  list->count = 0;
  return list;
}

void add_stock(struct stock_list *list, char *name, float price, float change) {
  if (list->count == MAX_STOCKS) {
    fprintf(stderr, "Error: Stock list is full.\n");
    return;
  }

  list->stocks[list->count].name = strdup(name);
  list->stocks[list->count].price = price;
  list->stocks[list->count].change = change;
  list->count++;
}

void print_stock_list(struct stock_list *list) {
  for (int i = 0; i < list->count; i++) {
    printf("%s: %.2f (%.2f%%)\n", list->stocks[i].name, list->stocks[i].price,
           list->stocks[i].change);
  }
}

void free_stock_list(struct stock_list *list) {
  for (int i = 0; i < list->count; i++) {
    free(list->stocks[i].name);
  }
  free(list->stocks);
  free(list);
}

int main() {
  struct stock_list *list = create_stock_list();

  add_stock(list, "AAPL", 123.45, 1.23);
  add_stock(list, "GOOG", 987.65, -2.34);
  add_stock(list, "MSFT", 234.56, 0.00);

  print_stock_list(list);

  free_stock_list(list);

  return 0;
}