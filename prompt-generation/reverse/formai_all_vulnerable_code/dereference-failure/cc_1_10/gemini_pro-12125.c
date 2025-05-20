//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

typedef struct {
  char name[50];
  double amount;
} transaction_t;

typedef struct {
  char name[50];
  double budget;
  double total_spent;
  transaction_t transactions[MAX_TRANSACTIONS];
  int num_transactions;
} category_t;

typedef struct {
  category_t categories[MAX_CATEGORIES];
  int num_categories;
} finance_plan_t;

finance_plan_t* create_finance_plan() {
  finance_plan_t* plan = malloc(sizeof(finance_plan_t));
  plan->num_categories = 0;
  return plan;
}

void add_category(finance_plan_t* plan, char* name, double budget) {
  if (plan->num_categories < MAX_CATEGORIES) {
    strcpy(plan->categories[plan->num_categories].name, name);
    plan->categories[plan->num_categories].budget = budget;
    plan->categories[plan->num_categories].total_spent = 0;
    plan->categories[plan->num_categories].num_transactions = 0;
    plan->num_categories++;
  }
}

void add_transaction(finance_plan_t* plan, char* category, char* name, double amount) {
  int i;
  for (i = 0; i < plan->num_categories; i++) {
    if (strcmp(plan->categories[i].name, category) == 0) {
      strcpy(plan->categories[i].transactions[plan->categories[i].num_transactions].name, name);
      plan->categories[i].transactions[plan->categories[i].num_transactions].amount = amount;
      plan->categories[i].total_spent += amount;
      plan->categories[i].num_transactions++;
      break;
    }
  }
}

void print_finance_plan(finance_plan_t* plan) {
  int i, j;
  for (i = 0; i < plan->num_categories; i++) {
    printf("Category: %s\n", plan->categories[i].name);
    printf("Budget: %.2f\n", plan->categories[i].budget);
    printf("Total Spent: %.2f\n", plan->categories[i].total_spent);
    printf("---------------\n");
    for (j = 0; j < plan->categories[i].num_transactions; j++) {
      printf("Transaction: %s\n", plan->categories[i].transactions[j].name);
      printf("Amount: %.2f\n", plan->categories[i].transactions[j].amount);
    }
  }
}

void free_finance_plan(finance_plan_t* plan) {
  free(plan);
}

int main() {
  finance_plan_t* plan = create_finance_plan();

  add_category(plan, "Groceries", 200);
  add_category(plan, "Entertainment", 100);
  add_category(plan, "Transportation", 250);

  add_transaction(plan, "Groceries", "Milk", 10);
  add_transaction(plan, "Groceries", "Eggs", 5);
  add_transaction(plan, "Entertainment", "Movie Tickets", 50);
  add_transaction(plan, "Entertainment", "Concert Tickets", 75);
  add_transaction(plan, "Transportation", "Gas", 75);
  add_transaction(plan, "Transportation", "Car Payment", 150);

  print_finance_plan(plan);

  free_finance_plan(plan);

  return 0;
}