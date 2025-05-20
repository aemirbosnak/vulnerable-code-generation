//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Expense {
  char *description;
  float amount;
  time_t date;
};

struct Node {
  struct Expense expense;
  struct Node *next;
};

struct LinkedList {
  struct Node *head;
  struct Node *tail;
  int size;
};

struct LinkedList *create_linked_list() {
  struct LinkedList *list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

void add_expense(struct LinkedList *list, char *description, float amount, time_t date) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->expense.description = strdup(description);
  new_node->expense.amount = amount;
  new_node->expense.date = date;
  new_node->next = NULL;
  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
  list->size++;
}

void print_expense(struct Expense expense) {
  printf("Description: %s\n", expense.description);
  printf("Amount: %.2f\n", expense.amount);
  printf("Date: %s\n", ctime(&expense.date));
}

void print_linked_list(struct LinkedList *list) {
  struct Node *current = list->head;
  while (current != NULL) {
    print_expense(current->expense);
    printf("\n");
    current = current->next;
  }
}

void free_linked_list(struct LinkedList *list) {
  struct Node *current = list->head;
  while (current != NULL) {
    struct Node *next = current->next;
    free(current->expense.description);
    free(current);
    current = next;
  }
  free(list);
}

int main() {
  struct LinkedList *expenses = create_linked_list();
  add_expense(expenses, "Groceries", 50.00, time(NULL));
  add_expense(expenses, "Rent", 1000.00, time(NULL));
  add_expense(expenses, "Utilities", 200.00, time(NULL));
  add_expense(expenses, "Entertainment", 100.00, time(NULL));
  add_expense(expenses, "Other", 50.00, time(NULL));
  print_linked_list(expenses);
  free_linked_list(expenses);
  return 0;
}