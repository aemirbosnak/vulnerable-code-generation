//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the expense struct
typedef struct expense {
  char *description;
  float amount;
  char *category;
  char *date;
} expense;

// Function to create a new expense
expense *new_expense(char *description, float amount, char *category, char *date) {
  expense *e = malloc(sizeof(expense));
  e->description = strdup(description);
  e->amount = amount;
  e->category = strdup(category);
  e->date = strdup(date);
  return e;
}

// Function to print an expense
void print_expense(expense *e) {
  printf("%s\t%.2f\t%s\t%s\n", e->description, e->amount, e->category, e->date);
}

// Function to free an expense
void free_expense(expense *e) {
  free(e->description);
  free(e->category);
  free(e->date);
  free(e);
}

// Main function
int main() {
  // Create a new expense tracker
  expense *tracker = NULL;

  // Add some expenses to the tracker
  expense *e1 = new_expense("Coffee", 3.50, "Food", "2023-02-01");
  expense *e2 = new_expense("Lunch", 10.00, "Food", "2023-02-02");
  expense *e3 = new_expense("Dinner", 15.00, "Food", "2023-02-03");
  expense *e4 = new_expense("Gas", 20.00, "Transportation", "2023-02-04");
  expense *e5 = new_expense("Movie", 10.00, "Entertainment", "2023-02-05");

  // Print the expenses
  print_expense(e1);
  print_expense(e2);
  print_expense(e3);
  print_expense(e4);
  print_expense(e5);

  // Free the expenses
  free_expense(e1);
  free_expense(e2);
  free_expense(e3);
  free_expense(e4);
  free_expense(e5);

  // Free the expense tracker
  free(tracker);

  return 0;
}