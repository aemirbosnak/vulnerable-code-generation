//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define expense categories
#define CATEGORY_FOOD 1
#define CATEGORY_TRANSPORT 2
#define CATEGORY_ENTERTAINMENT 3

// Define expense types
#define TYPE_FIXED 1
#define TYPE_VARIABLE 2

// Define expense status
#define STATUS_PENDING 1
#define STATUS_APPROVED 2
#define STATUS_REJECTED 3

// Structure to represent an expense
typedef struct Expense {
  int category;
  int type;
  char description[100];
  float amount;
  int status;
} Expense;

// Function to create a new expense
Expense* create_expense(int category, int type, char* description, float amount) {
  Expense* expense = malloc(sizeof(Expense));
  expense->category = category;
  expense->type = type;
  strcpy(expense->description, description);
  expense->amount = amount;
  expense->status = STATUS_PENDING;
  return expense;
}

// Function to print an expense
void print_expense(Expense* expense) {
  printf("Category: %d\n", expense->category);
  printf("Type: %d\n", expense->type);
  printf("Description: %s\n", expense->description);
  printf("Amount: %.2f\n", expense->amount);
  printf("Status: %d\n", expense->status);
}

// Function to approve an expense
void approve_expense(Expense* expense) {
  expense->status = STATUS_APPROVED;
}

// Function to reject an expense
void reject_expense(Expense* expense) {
  expense->status = STATUS_REJECTED;
}

// Function to get the total amount of expenses in a given category
float get_total_amount_by_category(Expense** expenses, int num_expenses, int category) {
  float total = 0;
  for (int i = 0; i < num_expenses; i++) {
    if (expenses[i]->category == category) {
      total += expenses[i]->amount;
    }
  }
  return total;
}

// Function to get the total amount of expenses in a given type
float get_total_amount_by_type(Expense** expenses, int num_expenses, int type) {
  float total = 0;
  for (int i = 0; i < num_expenses; i++) {
    if (expenses[i]->type == type) {
      total += expenses[i]->amount;
    }
  }
  return total;
}

// Function to get the total amount of expenses in a given status
float get_total_amount_by_status(Expense** expenses, int num_expenses, int status) {
  float total = 0;
  for (int i = 0; i < num_expenses; i++) {
    if (expenses[i]->status == status) {
      total += expenses[i]->amount;
    }
  }
  return total;
}

// Function to print a report of all expenses
void print_expense_report(Expense** expenses, int num_expenses) {
  printf("Expense Report\n");
  printf("===================\n");

  // Print total amount by category
  printf("Total Amount by Category:\n");
  printf("-------------------------\n");
  printf("Food: %.2f\n", get_total_amount_by_category(expenses, num_expenses, CATEGORY_FOOD));
  printf("Transport: %.2f\n", get_total_amount_by_category(expenses, num_expenses, CATEGORY_TRANSPORT));
  printf("Entertainment: %.2f\n", get_total_amount_by_category(expenses, num_expenses, CATEGORY_ENTERTAINMENT));

  // Print total amount by type
  printf("\nTotal Amount by Type:\n");
  printf("---------------------\n");
  printf("Fixed: %.2f\n", get_total_amount_by_type(expenses, num_expenses, TYPE_FIXED));
  printf("Variable: %.2f\n", get_total_amount_by_type(expenses, num_expenses, TYPE_VARIABLE));

  // Print total amount by status
  printf("\nTotal Amount by Status:\n");
  printf("-----------------------\n");
  printf("Pending: %.2f\n", get_total_amount_by_status(expenses, num_expenses, STATUS_PENDING));
  printf("Approved: %.2f\n", get_total_amount_by_status(expenses, num_expenses, STATUS_APPROVED));
  printf("Rejected: %.2f\n", get_total_amount_by_status(expenses, num_expenses, STATUS_REJECTED));
}

int main() {

  // Create some sample expenses
  Expense* expenses[] = {
    create_expense(CATEGORY_FOOD, TYPE_VARIABLE, "Groceries", 100.00),
    create_expense(CATEGORY_TRANSPORT, TYPE_FIXED, "Mortgage", 1500.00),
    create_expense(CATEGORY_ENTERTAINMENT, TYPE_VARIABLE, "Movie tickets", 50.00),
    create_expense(CATEGORY_FOOD, TYPE_VARIABLE, "Restaurant meal", 75.00),
    create_expense(CATEGORY_TRANSPORT, TYPE_FIXED, "Car insurance", 200.00),
  };

  int num_expenses = sizeof(expenses) / sizeof(expenses[0]);

  // Print the expenses
  printf("Expenses:\n");
  printf("---------\n");
  for (int i = 0; i < num_expenses; i++) {
    print_expense(expenses[i]);
    printf("\n");
  }

  // Approve the first expense
  approve_expense(expenses[0]);

  // Reject the third expense
  reject_expense(expenses[2]);

  // Print the expense report
  print_expense_report(expenses, num_expenses);

  return 0;
}