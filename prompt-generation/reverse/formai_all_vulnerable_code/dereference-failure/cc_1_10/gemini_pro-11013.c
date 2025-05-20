//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *description;
  double amount;
  int category;
} expense_t;

typedef struct {
  char *name;
  int num_expenses;
  expense_t *expenses;
} category_t;

int main() {
  // Create an array of categories
  category_t categories[] = {
    {"Food", 0, NULL},
    {"Entertainment", 0, NULL},
    {"Transportation", 0, NULL},
    {"Other", 0, NULL},
  };

  // Get the number of categories from the user
  int num_categories = sizeof(categories) / sizeof(category_t);

  // Create an array of pointers to the categories
  category_t **category_ptrs = malloc(sizeof(category_t *) * num_categories);
  for (int i = 0; i < num_categories; i++) {
    category_ptrs[i] = &categories[i];
  }

  // Create an array of expenses
  expense_t expenses[] = {
    {"Groceries", 100.00, 0},
    {"Dinner out", 50.00, 0},
    {"Movie tickets", 20.00, 1},
    {"Gas", 50.00, 2},
    {"Car payment", 300.00, 2},
    {"Other", 10.00, 3},
  };

  // Get the number of expenses from the user
  int num_expenses = sizeof(expenses) / sizeof(expense_t);

  // Add the expenses to the categories
  for (int i = 0; i < num_expenses; i++) {
    category_ptrs[expenses[i].category]->expenses =
        realloc(category_ptrs[expenses[i].category]->expenses,
                sizeof(expense_t) *
                    (category_ptrs[expenses[i].category]->num_expenses + 1));
    category_ptrs[expenses[i].category]->expenses[category_ptrs[expenses[i].category]->num_expenses++] = expenses[i];
  }

  // Print the expenses for each category
  for (int i = 0; i < num_categories; i++) {
    printf("%s\n", categories[i].name);
    for (int j = 0; j < categories[i].num_expenses; j++) {
      printf("  %s: $%.2f\n", categories[i].expenses[j].description, categories[i].expenses[j].amount);
    }
    printf("\n");
  }

  // Free the memory allocated for the expenses
  for (int i = 0; i < num_categories; i++) {
    free(categories[i].expenses);
  }

  // Free the memory allocated for the categories
  free(category_ptrs);

  return 0;
}