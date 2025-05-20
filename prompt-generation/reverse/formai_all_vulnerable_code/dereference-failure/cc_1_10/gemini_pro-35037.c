//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store an expense
typedef struct Expense {
  char description[100];
  float amount;
  char category[50];
  struct Expense *next;
} Expense;

// Head of the linked list
Expense *head = NULL;

// Function to create a new expense
Expense *createExpense(char *description, float amount, char *category) {
  Expense *newExpense = (Expense *)malloc(sizeof(Expense));
  strcpy(newExpense->description, description);
  newExpense->amount = amount;
  strcpy(newExpense->category, category);
  newExpense->next = NULL;
  return newExpense;
}

// Function to add an expense to the linked list
void addExpense(Expense *newExpense) {
  if (head == NULL) {
    head = newExpense;
  } else {
    Expense *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newExpense;
  }
}

// Function to print the linked list of expenses
void printExpenses() {
  Expense *current = head;
  while (current != NULL) {
    printf("Description: %s\n", current->description);
    printf("Amount: %.2f\n", current->amount);
    printf("Category: %s\n\n", current->category);
    current = current->next;
  }
}

// Function to free the linked list of expenses
void freeExpenses() {
  Expense *current = head;
  while (current != NULL) {
    Expense *next = current->next;
    free(current);
    current = next;
  }
  head = NULL;
}

// Main function
int main() {
  // Create some expenses
  Expense *expense1 = createExpense("Groceries", 100.00, "Food");
  Expense *expense2 = createExpense("Gas", 50.00, "Transportation");
  Expense *expense3 = createExpense("Entertainment", 20.00, "Entertainment");

  // Add the expenses to the linked list
  addExpense(expense1);
  addExpense(expense2);
  addExpense(expense3);

  // Print the linked list of expenses
  printExpenses();

  // Free the linked list of expenses
  freeExpenses();

  return 0;
}