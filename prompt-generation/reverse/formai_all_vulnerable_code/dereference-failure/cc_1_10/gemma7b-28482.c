//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSE 10

typedef struct Expense {
  char name[50];
  float amount;
  struct Expense* next;
} Expense;

Expense* createExpense() {
  Expense* newExpense = malloc(sizeof(Expense));
  newExpense->name[0] = '\0';
  newExpense->amount = 0.0f;
  newExpense->next = NULL;
  return newExpense;
}

void addExpense(Expense* head, char* name, float amount) {
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
    printf("%s: %.2f\n", head->name, head->amount);
    head = head->next;
  }
}

int main() {
  Expense* head = NULL;
  addExpense(head, "Groceries", 50.0f);
  addExpense(head, "Clothing", 20.0f);
  addExpense(head, "Eating out", 30.0f);

  printExpenses(head);

  return 0;
}