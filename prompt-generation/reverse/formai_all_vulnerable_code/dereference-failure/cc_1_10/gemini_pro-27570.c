//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

struct expense {
  char *description;
  double amount;
  struct expense *next;
};

struct expense_tracker {
  struct expense *head;
  int num_expenses;
  double total_amount;
};

void add_expense(struct expense_tracker *tracker, char *description, double amount) {
  struct expense *new_expense = malloc(sizeof(struct expense));
  new_expense->description = malloc(strlen(description) + 1);
  strcpy(new_expense->description, description);
  new_expense->amount = amount;
  new_expense->next = NULL;

  if (tracker->head == NULL) {
    tracker->head = new_expense;
  } else {
    struct expense *current_expense = tracker->head;
    while (current_expense->next != NULL) {
      current_expense = current_expense->next;
    }
    current_expense->next = new_expense;
  }

  tracker->num_expenses++;
  tracker->total_amount += amount;
}

void print_expenses(struct expense_tracker *tracker) {
  if (tracker->head == NULL) {
    printf("No expenses to print!\n");
  } else {
    struct expense *current_expense = tracker->head;
    while (current_expense != NULL) {
      printf("%s: $%.2f\n", current_expense->description, current_expense->amount);
      current_expense = current_expense->next;
    }
  }
}

void free_expenses(struct expense_tracker *tracker) {
  if (tracker->head == NULL) {
    return;
  } else {
    struct expense *current_expense = tracker->head;
    while (current_expense != NULL) {
      struct expense *next_expense = current_expense->next;
      free(current_expense->description);
      free(current_expense);
      current_expense = next_expense;
    }
  }

  tracker->head = NULL;
  tracker->num_expenses = 0;
  tracker->total_amount = 0.0;
}

int main() {
  struct expense_tracker tracker;
  tracker.head = NULL;
  tracker.num_expenses = 0;
  tracker.total_amount = 0.0;

  add_expense(&tracker, "Coffee", 2.50);
  add_expense(&tracker, "Lunch", 10.00);
  add_expense(&tracker, "Dinner", 15.00);
  add_expense(&tracker, "Groceries", 50.00);
  add_expense(&tracker, "Rent", 1000.00);

  print_expenses(&tracker);

  printf("Total expenses: $%.2f\n", tracker.total_amount);

  free_expenses(&tracker);

  return 0;
}