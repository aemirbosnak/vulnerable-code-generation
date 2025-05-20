//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Transaction types
#define INCOME 1
#define EXPENSE 2

// Transaction categories
#define HOUSING 1
#define FOOD 2
#define TRANSPORTATION 3
#define ENTERTAINMENT 4
#define OTHER 5

// Data structure to store a transaction
typedef struct {
  int type;
  int category;
  char *description;
  double amount;
} transaction_t;

// Data structure to store a list of transactions
typedef struct {
  int count;
  transaction_t *transactions;
} transaction_list_t;

// Function to create a new transaction
transaction_t *create_transaction(int type, int category, char *description, double amount) {
  transaction_t *transaction = malloc(sizeof(transaction_t));
  transaction->type = type;
  transaction->category = category;
  transaction->description = strdup(description);
  transaction->amount = amount;
  return transaction;
}

// Function to add a transaction to a list
void add_transaction(transaction_list_t *list, transaction_t *transaction) {
  list->count++;
  list->transactions = realloc(list->transactions, sizeof(transaction_t) * list->count);
  list->transactions[list->count - 1] = *transaction;
}

// Function to print a transaction
void print_transaction(transaction_t *transaction) {
  printf("%s (%s): $%.2f\n", transaction->description,
         transaction->type == INCOME ? "Income" : "Expense", transaction->amount);
}

// Function to print a list of transactions
void print_transaction_list(transaction_list_t *list) {
  for (int i = 0; i < list->count; i++) {
    print_transaction(&list->transactions[i]);
  }
}

// Function to get the total amount of a list of transactions
double get_total_amount(transaction_list_t *list) {
  double total = 0;
  for (int i = 0; i < list->count; i++) {
    total += list->transactions[i].amount;
  }
  return total;
}

// Function to get the total amount of a specific category of transactions
double get_total_amount_by_category(transaction_list_t *list, int category) {
  double total = 0;
  for (int i = 0; i < list->count; i++) {
    if (list->transactions[i].category == category) {
      total += list->transactions[i].amount;
    }
  }
  return total;
}

// Main function
int main() {
  // Create a new transaction list
  transaction_list_t *list = malloc(sizeof(transaction_list_t));
  list->count = 0;
  list->transactions = NULL;

  // Add some transactions to the list
  add_transaction(list, create_transaction(INCOME, HOUSING, "Salary", 2000));
  add_transaction(list, create_transaction(EXPENSE, FOOD, "Groceries", 200));
  add_transaction(list, create_transaction(EXPENSE, TRANSPORTATION, "Gas", 100));
  add_transaction(list, create_transaction(EXPENSE, ENTERTAINMENT, "Movies", 50));
  add_transaction(list, create_transaction(EXPENSE, OTHER, "Other", 100));

  // Print the list of transactions
  print_transaction_list(list);

  // Get the total amount of the list of transactions
  double total_amount = get_total_amount(list);
  printf("Total amount: $%.2f\n", total_amount);

  // Get the total amount of a specific category of transactions
  double total_housing_amount = get_total_amount_by_category(list, HOUSING);
  printf("Total housing amount: $%.2f\n", total_housing_amount);

  // Free the allocated memory
  for (int i = 0; i < list->count; i++) {
    free(list->transactions[i].description);
  }
  free(list->transactions);
  free(list);

  return 0;
}