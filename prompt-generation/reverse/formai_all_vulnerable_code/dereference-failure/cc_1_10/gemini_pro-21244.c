//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
  char *name;
  double amount;
  struct expense *next;
};

struct income {
  char *name;
  double amount;
  struct income *next;
};

struct budget {
  struct expense *expenses;
  struct income *incomes;
  double total_expenses;
  double total_incomes;
};

struct budget *create_budget() {
  struct budget *b = malloc(sizeof(struct budget));
  b->expenses = NULL;
  b->incomes = NULL;
  b->total_expenses = 0;
  b->total_incomes = 0;
  return b;
}

void add_expense(struct budget *b, char *name, double amount) {
  struct expense *e = malloc(sizeof(struct expense));
  e->name = strdup(name);
  e->amount = amount;
  e->next = b->expenses;
  b->expenses = e;
  b->total_expenses += amount;
}

void add_income(struct budget *b, char *name, double amount) {
  struct income *i = malloc(sizeof(struct income));
  i->name = strdup(name);
  i->amount = amount;
  i->next = b->incomes;
  b->incomes = i;
  b->total_incomes += amount;
}

void print_budget(struct budget *b) {
  printf("Expenses:\n");
  struct expense *e = b->expenses;
  while (e != NULL) {
    printf("  %s: %.2f\n", e->name, e->amount);
    e = e->next;
  }

  printf("Incomes:\n");
  struct income *i = b->incomes;
  while (i != NULL) {
    printf("  %s: %.2f\n", i->name, i->amount);
    i = i->next;
  }

  printf("Total expenses: %.2f\n", b->total_expenses);
  printf("Total incomes: %.2f\n", b->total_incomes);
  printf("Net income: %.2f\n", b->total_incomes - b->total_expenses);
}

void free_budget(struct budget *b) {
  struct expense *e = b->expenses;
  while (e != NULL) {
    struct expense *next = e->next;
    free(e->name);
    free(e);
    e = next;
  }

  struct income *i = b->incomes;
  while (i != NULL) {
    struct income *next = i->next;
    free(i->name);
    free(i);
    i = next;
  }

  free(b);
}

int main() {
  struct budget *b = create_budget();

  add_expense(b, "Rent", 1200);
  add_expense(b, "Utilities", 200);
  add_expense(b, "Groceries", 300);
  add_expense(b, "Entertainment", 100);
  add_expense(b, "Other", 200);

  add_income(b, "Salary", 3000);
  add_income(b, "Investments", 500);
  add_income(b, "Other", 100);

  print_budget(b);

  free_budget(b);

  return 0;
}