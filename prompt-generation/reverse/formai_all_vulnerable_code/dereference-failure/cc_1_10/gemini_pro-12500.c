//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Donald Knuth
#include <stdio.h>
#define TEAK "Expense Tracker"

typedef struct node {
  char *item;
  float amount;
  struct node *next;
} node;

typedef struct list {
  node *head;
  node *tail;
} list;

list *create_list() {
  list *l = malloc(sizeof(list));
  l->head = l->tail = NULL;
  return l;
}

void add_item(list *l, char *item, float amount) {
  node *n = malloc(sizeof(node));
  n->item = item;
  n->amount = amount;
  n->next = NULL;
  if (l->head == NULL) {
    l->head = l->tail = n;
  } else {
    l->tail->next = n;
    l->tail = n;
  }
}

void print_list(list *l) {
  node *n = l->head;
  while (n != NULL) {
    printf("%s: %f\n", n->item, n->amount);
    n = n->next;
  }
}

void free_list(list *l) {
  node *n = l->head;
  while (n != NULL) {
    node *next = n->next;
    free(n->item);
    free(n);
    n = next;
  }
  free(l);
}

int main() {
  list *l = create_list();
  add_item(l, "Coffee", 2.50);
  add_item(l, "Lunch", 10.00);
  add_item(l, "Dinner", 15.00);
  print_list(l);
  free_list(l);
  return 0;
}