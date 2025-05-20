//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the expense structure
typedef struct Expense {
  char *description;
  double amount;
  struct Expense *next;
} Expense;

// Create a new expense
Expense *new_expense(char *description, double amount) {
  Expense *expense = malloc(sizeof(Expense));
  expense->description = strdup(description);
  expense->amount = amount;
  expense->next = NULL;
  return expense;
}

// Add an expense to the list
void add_expense(Expense **head, Expense *expense) {
  if (*head == NULL) {
    *head = expense;
  } else {
    Expense *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = expense;
  }
}

// Print the list of expenses
void print_expenses(Expense *head) {
  Expense *current = head;
  while (current != NULL) {
    printf("%s: $%.2f\n", current->description, current->amount);
    current = current->next;
  }
}

// Calculate the total expenses
double calculate_total(Expense *head) {
  double total = 0.0;
  Expense *current = head;
  while (current != NULL) {
    total += current->amount;
    current = current->next;
  }
  return total;
}

// Free the memory allocated for the list of expenses
void free_expenses(Expense *head) {
  Expense *current = head;
  while (current != NULL) {
    Expense *next = current->next;
    free(current->description);
    free(current);
    current = next;
  }
}

int main() {
  // Create a new expense list
  Expense *head = NULL;

  // Add some expenses to the list
  add_expense(&head, new_expense("Groceries", 100.00));
  add_expense(&head, new_expense("Gas", 50.00));
  add_expense(&head, new_expense("Entertainment", 25.00));

  // Print the list of expenses
  printf("Your expenses:\n");
  print_expenses(head);

  // Calculate the total expenses
  double total = calculate_total(head);
  printf("Total expenses: $%.2f\n", total);

  // Free the memory allocated for the list of expenses
  free_expenses(head);

  return 0;
}