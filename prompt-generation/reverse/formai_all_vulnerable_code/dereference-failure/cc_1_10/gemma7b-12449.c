//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_EXPENSES 10

typedef struct Expense {
  char name[50];
  int amount;
  char category[50];
} Expense;

void addExpense(Expense *expenses, int *numExpenses) {
  expenses = (Expense *)realloc(expenses, (*numExpenses + 1) * sizeof(Expense));
  (*numExpenses)++;
  expenses[*numExpenses - 1].name[0] = '\0';
  expenses[*numExpenses - 1].amount = 0;
  expenses[*numExpenses - 1].category[0] = '\0';
}

void printExpenses(Expense *expenses, int numExpenses) {
  for (int i = 0; i < numExpenses; i++) {
    printf("%s: %d, Category: %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
  }
}

int main() {
  Expense *expenses = NULL;
  int numExpenses = 0;

  // Add some expenses
  addExpense(expenses, &numExpenses);
  strcpy(expenses[numExpenses - 1].name, "Groceries");
  expenses[numExpenses - 1].amount = 50;
  strcpy(expenses[numExpenses - 1].category, "Food");

  addExpense(expenses, &numExpenses);
  strcpy(expenses[numExpenses - 1].name, "Electronics");
  expenses[numExpenses - 1].amount = 200;
  strcpy(expenses[numExpenses - 1].category, "Electronics");

  addExpense(expenses, &numExpenses);
  strcpy(expenses[numExpenses - 1].name, "Clothing");
  expenses[numExpenses - 1].amount = 100;
  strcpy(expenses[numExpenses - 1].category, "Clothing");

  // Print the expenses
  printExpenses(expenses, numExpenses);

  return 0;
}