//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct budget_item {
  char *name;
  double amount;
};

struct budget {
  struct budget_item *items;
  int num_items;
};

struct transaction {
  char *description;
  double amount;
  int budget_item_index;
};

struct personal_finance_planner {
  struct budget budget;
  struct transaction *transactions;
  int num_transactions;
};

struct personal_finance_planner *create_personal_finance_planner() {
  struct personal_finance_planner *planner = malloc(sizeof(struct personal_finance_planner));
  planner->budget.items = NULL;
  planner->budget.num_items = 0;
  planner->transactions = NULL;
  planner->num_transactions = 0;
  return planner;
}

void destroy_personal_finance_planner(struct personal_finance_planner *planner) {
  for (int i = 0; i < planner->budget.num_items; i++) {
    free(planner->budget.items[i].name);
  }
  free(planner->budget.items);
  for (int i = 0; i < planner->num_transactions; i++) {
    free(planner->transactions[i].description);
  }
  free(planner->transactions);
  free(planner);
}

void add_budget_item(struct personal_finance_planner *planner, char *name, double amount) {
  planner->budget.items = realloc(planner->budget.items, sizeof(struct budget_item) * (planner->budget.num_items + 1));
  planner->budget.items[planner->budget.num_items].name = strdup(name);
  planner->budget.items[planner->budget.num_items].amount = amount;
  planner->budget.num_items++;
}

void add_transaction(struct personal_finance_planner *planner, char *description, double amount, int budget_item_index) {
  planner->transactions = realloc(planner->transactions, sizeof(struct transaction) * (planner->num_transactions + 1));
  planner->transactions[planner->num_transactions].description = strdup(description);
  planner->transactions[planner->num_transactions].amount = amount;
  planner->transactions[planner->num_transactions].budget_item_index = budget_item_index;
  planner->num_transactions++;
}

void print_budget(struct personal_finance_planner *planner) {
  for (int i = 0; i < planner->budget.num_items; i++) {
    printf("%s: $%.2f\n", planner->budget.items[i].name, planner->budget.items[i].amount);
  }
}

void print_transactions(struct personal_finance_planner *planner) {
  for (int i = 0; i < planner->num_transactions; i++) {
    printf("%s: $%.2f (%s)\n", planner->transactions[i].description, planner->transactions[i].amount, planner->budget.items[planner->transactions[i].budget_item_index].name);
  }
}

int main() {
  struct personal_finance_planner *planner = create_personal_finance_planner();

  add_budget_item(planner, "Rent", 1000);
  add_budget_item(planner, "Groceries", 200);
  add_budget_item(planner, "Entertainment", 100);

  add_transaction(planner, "Paid rent", -1000, 0);
  add_transaction(planner, "Bought groceries", -50, 1);
  add_transaction(planner, "Went to the movies", -20, 2);

  print_budget(planner);
  printf("\n");
  print_transactions(planner);

  destroy_personal_finance_planner(planner);

  return 0;
}