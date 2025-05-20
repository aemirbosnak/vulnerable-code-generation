//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A macro to define the maximum number of transactions.
#define MAX_TRANSACTIONS 100

// A macro to define the maximum length of a transaction description.
#define MAX_DESCRIPTION_LENGTH 50

// A structure to represent a transaction.
typedef struct transaction {
  char description[MAX_DESCRIPTION_LENGTH];
  float amount;
} transaction;

// A function to add a transaction to the expense tracker.
void add_transaction(transaction *transactions, int *num_transactions, char *description, float amount) {
  // Check if the number of transactions has reached the maximum.
  if (*num_transactions == MAX_TRANSACTIONS) {
    printf("Error: The maximum number of transactions has been reached.\n");
    return;
  }

  // Copy the description and amount to the new transaction.
  strcpy(transactions[*num_transactions].description, description);
  transactions[*num_transactions].amount = amount;

  // Increment the number of transactions.
  (*num_transactions)++;
}

// A function to print the expense tracker.
void print_expense_tracker(transaction *transactions, int num_transactions) {
  // Print the header.
  printf("Expense Tracker\n");
  printf("--------------\n");

  // Print each transaction.
  for (int i = 0; i < num_transactions; i++) {
    printf("%-50s $%.2f\n", transactions[i].description, transactions[i].amount);
  }

  // Print the total amount.
  float total_amount = 0;
  for (int i = 0; i < num_transactions; i++) {
    total_amount += transactions[i].amount;
  }
  printf("\nTotal: $%.2f\n", total_amount);
}

// A function to get user input.
char *get_input(char *prompt) {
  char *input = malloc(100);
  printf("%s", prompt);
  scanf("%s", input);
  return input;
}

// The main function.
int main() {
  // Create an array of transactions.
  transaction transactions[MAX_TRANSACTIONS];

  // Initialize the number of transactions to 0.
  int num_transactions = 0;

  // Get user input.
  char *description = get_input("Enter a description: ");
  float amount = atof(get_input("Enter an amount: "));

  // Add the transaction to the expense tracker.
  add_transaction(transactions, &num_transactions, description, amount);

  // Print the expense tracker.
  print_expense_tracker(transactions, num_transactions);

  return 0;
}