//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stock {
  char *symbol;
  float price;
} Stock;

typedef struct Node {
  Stock *stock;
  struct Node *next;
} Node;

typedef struct StockList {
  Node *head;
  Node *tail;
} StockList;

StockList *create_stock_list() {
  StockList *list = malloc(sizeof(StockList));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void add_stock(StockList *list, Stock *stock) {
  Node *new_node = malloc(sizeof(Node));
  new_node->stock = stock;
  new_node->next = NULL;
  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
}

void print_stock_list(StockList *list) {
  Node *current_node = list->head;
  while (current_node != NULL) {
    printf("%s: $%.2f\n", current_node->stock->symbol, current_node->stock->price);
    current_node = current_node->next;
  }
}

void free_stock_list(StockList *list) {
  Node *current_node = list->head;
  while (current_node != NULL) {
    Node *next_node = current_node->next;
    free(current_node->stock->symbol);
    free(current_node->stock);
    free(current_node);
    current_node = next_node;
  }
  free(list);
}

int main() {
  StockList *list = create_stock_list();

  Stock *stock1 = malloc(sizeof(Stock));
  stock1->symbol = strdup("AAPL");
  stock1->price = 123.45;
  add_stock(list, stock1);

  Stock *stock2 = malloc(sizeof(Stock));
  stock2->symbol = strdup("GOOG");
  stock2->price = 987.65;
  add_stock(list, stock2);

  Stock *stock3 = malloc(sizeof(Stock));
  stock3->symbol = strdup("MSFT");
  stock3->price = 234.56;
  add_stock(list, stock3);

  print_stock_list(list);

  free_stock_list(list);

  return 0;
}