//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
  char *description;
  float amount;
  struct expense *next;
};

struct income {
  char *description;
  float amount;
  struct income *next;
};

struct budget {
  char *name;
  float amount;
  struct expense *expenses;
  struct income *incomes;
  struct budget *next;
};

struct personal_finance_planner {
  char *name;
  struct budget *budgets;
};

struct personal_finance_planner *create_personal_finance_planner(char *name) {
  struct personal_finance_planner *planner = malloc(sizeof(struct personal_finance_planner));
  planner->name = strdup(name);
  planner->budgets = NULL;
  return planner;
}

void destroy_personal_finance_planner(struct personal_finance_planner *planner) {
  free(planner->name);
  struct budget *budget = planner->budgets;
  while (budget != NULL) {
    struct budget *next = budget->next;
    free(budget->name);
    struct expense *expense = budget->expenses;
    while (expense != NULL) {
      struct expense *next = expense->next;
      free(expense->description);
      free(expense);
    }
    struct income *income = budget->incomes;
    while (income != NULL) {
      struct income *next = income->next;
      free(income->description);
      free(income);
    }
    free(budget);
    budget = next;
  }
  free(planner);
}

struct budget *create_budget(char *name, float amount) {
  struct budget *budget = malloc(sizeof(struct budget));
  budget->name = strdup(name);
  budget->amount = amount;
  budget->expenses = NULL;
  budget->incomes = NULL;
  budget->next = NULL;
  return budget;
}

void destroy_budget(struct budget *budget) {
  free(budget->name);
  struct expense *expense = budget->expenses;
  while (expense != NULL) {
    struct expense *next = expense->next;
    free(expense->description);
    free(expense);
  }
  struct income *income = budget->incomes;
  while (income != NULL) {
    struct income *next = income->next;
    free(income->description);
    free(income);
  }
  free(budget);
}

struct expense *create_expense(char *description, float amount) {
  struct expense *expense = malloc(sizeof(struct expense));
  expense->description = strdup(description);
  expense->amount = amount;
  expense->next = NULL;
  return expense;
}

void destroy_expense(struct expense *expense) {
  free(expense->description);
  free(expense);
}

struct income *create_income(char *description, float amount) {
  struct income *income = malloc(sizeof(struct income));
  income->description = strdup(description);
  income->amount = amount;
  income->next = NULL;
  return income;
}

void destroy_income(struct income *income) {
  free(income->description);
  free(income);
}

void add_budget(struct personal_finance_planner *planner, struct budget *budget) {
  budget->next = planner->budgets;
  planner->budgets = budget;
}

void add_expense(struct budget *budget, struct expense *expense) {
  expense->next = budget->expenses;
  budget->expenses = expense;
}

void add_income(struct budget *budget, struct income *income) {
  income->next = budget->incomes;
  budget->incomes = income;
}

void print_personal_finance_planner(struct personal_finance_planner *planner) {
  printf("Personal Finance Planner: %s\n", planner->name);
  struct budget *budget = planner->budgets;
  while (budget != NULL) {
    printf("  Budget: %s ($%.2f)\n", budget->name, budget->amount);
    struct expense *expense = budget->expenses;
    while (expense != NULL) {
      printf("    Expense: %s ($%.2f)\n", expense->description, expense->amount);
      expense = expense->next;
    }
    struct income *income = budget->incomes;
    while (income != NULL) {
      printf("    Income: %s ($%.2f)\n", income->description, income->amount);
      income = income->next;
    }
    budget = budget->next;
  }
}

int main() {
  struct personal_finance_planner *planner = create_personal_finance_planner("John Doe");

  struct budget *budget1 = create_budget("Groceries", 200.00);
  add_budget(planner, budget1);

  struct expense *expense1 = create_expense("Milk", 3.50);
  add_expense(budget1, expense1);

  struct expense *expense2 = create_expense("Eggs", 2.50);
  add_expense(budget1, expense2);

  struct expense *expense3 = create_expense("Bread", 1.50);
  add_expense(budget1, expense3);

  struct budget *budget2 = create_budget("Entertainment", 100.00);
  add_budget(planner, budget2);

  struct expense *expense4 = create_expense("Movie tickets", 15.00);
  add_expense(budget2, expense4);

  struct expense *expense5 = create_expense("Dinner out", 50.00);
  add_expense(budget2, expense5);

  struct income *income1 = create_income("Salary", 2000.00);
  add_income(budget1, income1);

  struct income *income2 = create_income("Investments", 100.00);
  add_income(budget1, income2);

  print_personal_finance_planner(planner);

  destroy_personal_finance_planner(planner);

  return 0;
}