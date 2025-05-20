//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: random
// A whimsical expense tracker that dances with your finances.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// The magic hat: our data structure to hold expenses.
typedef struct {
  char *name;
  float amount;
  time_t timestamp;
} Expense;

// The legendary unicorn: our expenses manager.
typedef struct {
  Expense *expenses;
  int count;
  int capacity;
} ExpenseManager;

// Create a new expense manager.
ExpenseManager *createExpenseManager() {
  ExpenseManager *manager = malloc(sizeof(ExpenseManager));
  if (!manager) return NULL;
  manager->expenses = malloc(sizeof(Expense) * 10);
  if (!manager->expenses) {
    free(manager);
    return NULL;
  }
  manager->count = 0;
  manager->capacity = 10;
  return manager;
}

// Free the resources used by the expense manager.
void freeExpenseManager(ExpenseManager *manager) {
  for (int i = 0; i < manager->count; i++) {
    free(manager->expenses[i].name);
  }
  free(manager->expenses);
  free(manager);
}

// Add a new expense to the manager's hat.
void addExpense(ExpenseManager *manager, char *name, float amount) {
  // Resize the hat if needed.
  if (manager->count == manager->capacity) {
    manager->capacity *= 2;
    manager->expenses = realloc(manager->expenses,
                               sizeof(Expense) * manager->capacity);
    if (!manager->expenses) {
      printf("Oops! The hat is too full.\n");
      return;
    }
  }

  // Store the expense in the hat.
  manager->expenses[manager->count].name = strdup(name);
  manager->expenses[manager->count].amount = amount;
  manager->expenses[manager->count++].timestamp = time(NULL);
}

// Print the expenses.
void printExpenses(ExpenseManager *manager) {
  printf("Behold! Your expenses:\n");
  for (int i = 0; i < manager->count; i++) {
    printf("%d. %s: %.2f %s\n", i + 1,
           manager->expenses[i].name, manager->expenses[i].amount,
           ctime(&manager->expenses[i].timestamp));
  }
}

// Search for an expense by name.
int findExpense(ExpenseManager *manager, char *name) {
  for (int i = 0; i < manager->count; i++) {
    if (strcmp(manager->expenses[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

// Edit an expense's amount.
void editExpense(ExpenseManager *manager, int index, float amount) {
  if (index < 0 || index >= manager->count) {
    printf("Oops! That expense doesn't exist.\n");
    return;
  }
  manager->expenses[index].amount = amount;
}

// Delete an expense.
void deleteExpense(ExpenseManager *manager, int index) {
  if (index < 0 || index >= manager->count) {
    printf("Oops! That expense doesn't exist.\n");
    return;
  }
  free(manager->expenses[index].name);
  for (int i = index; i < manager->count - 1; i++) {
    manager->expenses[i] = manager->expenses[i + 1];
  }
  manager->count--;
}

// The main dance: the program's entry point.
int main() {
  srand(time(NULL));

  // Create the expense manager.
  ExpenseManager *manager = createExpenseManager();

  // Add some sample expenses.
  addExpense(manager, "Coffee", 3.50);
  addExpense(manager, "Movie tickets", 15.00);
  addExpense(manager, "Groceries", 50.00);
  addExpense(manager, "Concert tickets", 75.00);

  // Print the expenses.
  printf("Here's what you've spent so far:\n");
  printExpenses(manager);

  // Search for an expense by name.
  int index = findExpense(manager, "Coffee");
  if (index >= 0) {
    printf("Found 'Coffee' at index %d.\n", index);
  } else {
    printf("Couldn't find 'Coffee'.\n");
  }

  // Edit the amount of an expense.
  editExpense(manager, 1, 18.00);
  printf("Updated 'Movie tickets' to $18.00.\n");

  // Delete an expense.
  deleteExpense(manager, 3);
  printf("Deleted 'Concert tickets'.\n");

  // Print the expenses again.
  printf("Here's the updated list of expenses:\n");
  printExpenses(manager);

  // Free the resources used by the expense manager.
  freeExpenseManager(manager);

  // The grand finale: a touch of whimsy.
  printf("\nMay your expenses dance gracefully through life!\n");
  int pause;
  scanf("%d", &pause);

  return 0;
}