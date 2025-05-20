//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a transaction
typedef struct {
  char description[50];
  double amount;
  int type; // 0 for income, 1 for expense
} transaction;

// Define the structure of a budget category
typedef struct {
  char name[50];
  double amount;
  double spent;
} category;

// Define the structure of a personal finance plan
typedef struct {
  transaction *transactions;
  int num_transactions;
  category *categories;
  int num_categories;
} plan;

// Create a new personal finance plan
plan *create_plan() {
  plan *p = malloc(sizeof(plan));
  p->transactions = NULL;
  p->num_transactions = 0;
  p->categories = NULL;
  p->num_categories = 0;
  return p;
}

// Add a transaction to a personal finance plan
void add_transaction(plan *p, transaction t) {
  p->transactions = realloc(p->transactions, (p->num_transactions + 1) * sizeof(transaction));
  p->transactions[p->num_transactions++] = t;
}

// Add a category to a personal finance plan
void add_category(plan *p, category c) {
  p->categories = realloc(p->categories, (p->num_categories + 1) * sizeof(category));
  p->categories[p->num_categories++] = c;
}

// Print a personal finance plan
void print_plan(plan *p) {
  printf("Transactions:\n");
  for (int i = 0; i < p->num_transactions; i++) {
    printf("  %s: $%.2f\n", p->transactions[i].description, p->transactions[i].amount);
  }

  printf("\nCategories:\n");
  for (int i = 0; i < p->num_categories; i++) {
    printf("  %s: $%.2f (spent: $%.2f)\n", p->categories[i].name, p->categories[i].amount, p->categories[i].spent);
  }
}

// Free the memory allocated for a personal finance plan
void free_plan(plan *p) {
  free(p->transactions);
  free(p->categories);
  free(p);
}

// Main function
int main() {
  // Create a new personal finance plan
  plan *p = create_plan();

  // Add some transactions to the plan
  transaction t1 = {"Salary", 2000.00, 0};
  add_transaction(p, t1);

  transaction t2 = {"Rent", -1000.00, 1};
  add_transaction(p, t2);

  transaction t3 = {"Groceries", -200.00, 1};
  add_transaction(p, t3);

  // Add some categories to the plan
  category c1 = {"Income", 2000.00, 0.00};
  add_category(p, c1);

  category c2 = {"Expenses", 1200.00, 0.00};
  add_category(p, c2);

  // Print the personal finance plan
  print_plan(p);

  // Free the memory allocated for the personal finance plan
  free_plan(p);

  return 0;
}