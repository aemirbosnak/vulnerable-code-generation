//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses that can be tracked
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
  char description[50];  // Description of the expense
  float amount;         // Amount of the expense
  int category;         // Category of the expense (e.g., food, entertainment, etc.)
  int date;             // Date of the expense (e.g., YYYYMMDD)
} Expense;

// Define the structure of the expense tracker
typedef struct {
  Expense expenses[MAX_EXPENSES];  // Array of expenses
  int num_expenses;                // Number of expenses
} ExpenseTracker;

// Create a new expense tracker
ExpenseTracker* create_expense_tracker() {
  ExpenseTracker* tracker = malloc(sizeof(ExpenseTracker));
  tracker->num_expenses = 0;
  return tracker;
}

// Add an expense to the expense tracker
void add_expense(ExpenseTracker* tracker, Expense expense) {
  if (tracker->num_expenses < MAX_EXPENSES) {
    tracker->expenses[tracker->num_expenses] = expense;
    tracker->num_expenses++;
  } else {
    printf("Error: Maximum number of expenses reached.\n");
  }
}

// Print the expenses in the expense tracker
void print_expenses(ExpenseTracker* tracker) {
  for (int i = 0; i < tracker->num_expenses; i++) {
    Expense expense = tracker->expenses[i];
    printf("%s: $%.2f (%d, %d)\n", expense.description, expense.amount, expense.category, expense.date);
  }
}

// Get the total amount of expenses in the expense tracker
float get_total_amount(ExpenseTracker* tracker) {
  float total_amount = 0;
  for (int i = 0; i < tracker->num_expenses; i++) {
    Expense expense = tracker->expenses[i];
    total_amount += expense.amount;
  }
  return total_amount;
}

// Get the average amount of expenses in the expense tracker
float get_average_amount(ExpenseTracker* tracker) {
  if (tracker->num_expenses > 0) {
    return get_total_amount(tracker) / tracker->num_expenses;
  } else {
    return 0;
  }
}

// Get the most expensive category in the expense tracker
int get_most_expensive_category(ExpenseTracker* tracker) {
  int most_expensive_category = -1;
  float max_amount = 0;
  for (int i = 0; i < tracker->num_expenses; i++) {
    Expense expense = tracker->expenses[i];
    if (expense.amount > max_amount) {
      max_amount = expense.amount;
      most_expensive_category = expense.category;
    }
  }
  return most_expensive_category;
}

// Free the memory allocated for the expense tracker
void free_expense_tracker(ExpenseTracker* tracker) {
  free(tracker);
}

// Main function
int main() {
  // Create a new expense tracker
  ExpenseTracker* tracker = create_expense_tracker();

  // Add some sample expenses to the expense tracker
  Expense expense1 = {"Groceries", 50.00, 1, 20230301};
  Expense expense2 = {"Entertainment", 20.00, 2, 20230302};
  Expense expense3 = {"Transportation", 30.00, 3, 20230303};
  Expense expense4 = {"Other", 10.00, 4, 20230304};
  add_expense(tracker, expense1);
  add_expense(tracker, expense2);
  add_expense(tracker, expense3);
  add_expense(tracker, expense4);

  // Print the expenses in the expense tracker
  printf("Expenses:\n");
  print_expenses(tracker);

  // Get the total amount of expenses in the expense tracker
  float total_amount = get_total_amount(tracker);
  printf("Total amount: $%.2f\n", total_amount);

  // Get the average amount of expenses in the expense tracker
  float average_amount = get_average_amount(tracker);
  printf("Average amount: $%.2f\n", average_amount);

  // Get the most expensive category in the expense tracker
  int most_expensive_category = get_most_expensive_category(tracker);
  printf("Most expensive category: %d\n", most_expensive_category);

  // Free the memory allocated for the expense tracker
  free_expense_tracker(tracker);

  return 0;
}