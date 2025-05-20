//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 10

typedef struct Expense {
  char name[20];
  int amount;
  struct Expense* next;
} Expense;

Expense* createExpense() {
  Expense* newExpense = malloc(sizeof(Expense));
  newExpense->name[0] = '\0';
  newExpense->amount = 0;
  newExpense->next = NULL;
  return newExpense;
}

void addExpense(Expense* head, char* name, int amount) {
  Expense* newExpense = createExpense();
  strcpy(newExpense->name, name);
  newExpense->amount = amount;

  if (head == NULL) {
    head = newExpense;
  } else {
    head->next = newExpense;
  }
  head = newExpense;
}

void printExpenses(Expense* head) {
  while (head) {
    printf("%s: %d\n", head->name, head->amount);
    head = head->next;
  }
}

int main() {
  Expense* head = NULL;

  addExpense(head, "Groceries", 50);
  addExpense(head, "Rent", 120);
  addExpense(head, "Dining", 20);
  addExpense(head, "Transportation", 70);

  printExpenses(head);

  return 0;
}