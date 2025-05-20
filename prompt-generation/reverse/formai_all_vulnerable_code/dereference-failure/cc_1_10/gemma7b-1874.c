//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct BudgetItem {
  char name[MAX_NAME_LENGTH];
  double amount;
  struct BudgetItem* next;
} BudgetItem;

typedef struct Budget {
  BudgetItem* head;
  double total_amount;
} Budget;

Budget* createBudget() {
  Budget* budget = malloc(sizeof(Budget));
  budget->head = NULL;
  budget->total_amount = 0.0;
  return budget;
}

void addBudgetItem(Budget* budget, char* name, double amount) {
  BudgetItem* new_item = malloc(sizeof(BudgetItem));
  strcpy(new_item->name, name);
  new_item->amount = amount;
  new_item->next = NULL;

  if (budget->head == NULL) {
    budget->head = new_item;
  } else {
    budget->head->next = new_item;
  }

  budget->total_amount += amount;
}

void printBudget(Budget* budget) {
  BudgetItem* item = budget->head;
  printf("Budget Items:\n");
  while (item) {
    printf("%s: %.2lf\n", item->name, item->amount);
    item = item->next;
  }

  printf("Total Amount: %.2lf\n", budget->total_amount);
}

int main() {
  Budget* budget = createBudget();
  addBudgetItem(budget, "Groceries", 100.0);
  addBudgetItem(budget, "Eating Out", 50.0);
  addBudgetItem(budget, "Clothing", 25.0);
  addBudgetItem(budget, "Entertainment", 75.0);

  printBudget(budget);

  return 0;
}