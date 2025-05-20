//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of categories and transactions
#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

// Define the category struct
typedef struct {
  char name[50];
  double budget;
  double balance;
} Category;

// Define the transaction struct
typedef struct {
  char description[50];
  double amount;
  char category[50];
} Transaction;

// Define the personal finance planner struct
typedef struct {
  Category categories[MAX_CATEGORIES];
  Transaction transactions[MAX_TRANSACTIONS];
  int num_categories;
  int num_transactions;
} PersonalFinancePlanner;

// Create a new personal finance planner
PersonalFinancePlanner* create_personal_finance_planner() {
  PersonalFinancePlanner* planner = malloc(sizeof(PersonalFinancePlanner));
  planner->num_categories = 0;
  planner->num_transactions = 0;
  return planner;
}

// Add a category to the personal finance planner
void add_category(PersonalFinancePlanner* planner, char* name, double budget) {
  if (planner->num_categories >= MAX_CATEGORIES) {
    printf("Error: Maximum number of categories reached.\n");
    return;
  }

  strcpy(planner->categories[planner->num_categories].name, name);
  planner->categories[planner->num_categories].budget = budget;
  planner->categories[planner->num_categories].balance = 0;
  planner->num_categories++;
}

// Add a transaction to the personal finance planner
void add_transaction(PersonalFinancePlanner* planner, char* description, double amount, char* category) {
  if (planner->num_transactions >= MAX_TRANSACTIONS) {
    printf("Error: Maximum number of transactions reached.\n");
    return;
  }

  strcpy(planner->transactions[planner->num_transactions].description, description);
  planner->transactions[planner->num_transactions].amount = amount;
  strcpy(planner->transactions[planner->num_transactions].category, category);
  planner->num_transactions++;

  // Update the category balance
  for (int i = 0; i < planner->num_categories; i++) {
    if (strcmp(planner->categories[i].name, category) == 0) {
      planner->categories[i].balance += amount;
      break;
    }
  }
}

// Print the personal finance planner
void print_personal_finance_planner(PersonalFinancePlanner* planner) {
  // Print the categories
  printf("Categories:\n");
  for (int i = 0; i < planner->num_categories; i++) {
    printf("  - %s: $%.2f / $%.2f\n", planner->categories[i].name, planner->categories[i].balance, planner->categories[i].budget);
  }

  // Print the transactions
  printf("Transactions:\n");
  for (int i = 0; i < planner->num_transactions; i++) {
    printf("  - %s: $%.2f (%s)\n", planner->transactions[i].description, planner->transactions[i].amount, planner->transactions[i].category);
  }
}

// Free the memory allocated for the personal finance planner
void free_personal_finance_planner(PersonalFinancePlanner* planner) {
  free(planner);
}

// Main function
int main() {
  // Create a new personal finance planner
  PersonalFinancePlanner* planner = create_personal_finance_planner();

  // Add some categories
  add_category(planner, "Groceries", 200);
  add_category(planner, "Dining Out", 100);
  add_category(planner, "Entertainment", 50);

  // Add some transactions
  add_transaction(planner, "Groceries", -50, "Groceries");
  add_transaction(planner, "Dinner", -20, "Dining Out");
  add_transaction(planner, "Movie", -15, "Entertainment");

  // Print the personal finance planner
  print_personal_finance_planner(planner);

  // Free the memory allocated for the personal finance planner
  free_personal_finance_planner(planner);

  return 0;
}