//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
  char *description;
  double amount;
  struct Expense *next;
};

struct Expense *head = NULL;

void add_expense(char *description, double amount) {
  struct Expense *new_expense = malloc(sizeof(struct Expense));
  new_expense->description = strdup(description);
  new_expense->amount = amount;
  new_expense->next = NULL;
  if (head == NULL) {
    head = new_expense;
  } else {
    struct Expense *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_expense;
  }
}

void print_expenses() {
  struct Expense *current = head;
  while (current != NULL) {
    printf("%s: $%.2f\n", current->description, current->amount);
    current = current->next;
  }
}

void free_expenses() {
  struct Expense *current = head;
  while (current != NULL) {
    struct Expense *next = current->next;
    free(current->description);
    free(current);
    current = next;
  }
  head = NULL;
}

int main() {
  add_expense("Groceries", 100.00);
  add_expense("Rent", 1200.00);
  add_expense("Utilities", 200.00);
  add_expense("Transportation", 300.00);
  add_expense("Entertainment", 100.00);

  print_expenses();

  free_expenses();

  return 0;
}