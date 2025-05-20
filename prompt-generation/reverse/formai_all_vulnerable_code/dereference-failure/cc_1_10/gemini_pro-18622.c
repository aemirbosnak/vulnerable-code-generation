//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store an expense
typedef struct Expense {
  char *description;
  double amount;
  char *category;
  struct Expense *next;
} Expense;

// Data structure to store a category
typedef struct Category {
  char *name;
  double total;
  struct Category *next;
} Category;

// Head of the expense list
Expense *expense_list = NULL;

// Head of the category list
Category *category_list = NULL;

// Function to add an expense to the list
void add_expense(char *description, double amount, char *category) {
  // Create a new expense
  Expense *new_expense = malloc(sizeof(Expense));
  new_expense->description = malloc(strlen(description) + 1);
  strcpy(new_expense->description, description);
  new_expense->amount = amount;
  new_expense->category = malloc(strlen(category) + 1);
  strcpy(new_expense->category, category);
  new_expense->next = NULL;

  // Add the new expense to the list
  if (expense_list == NULL) {
    expense_list = new_expense;
  } else {
    Expense *current = expense_list;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_expense;
  }

  // Update the category total
  Category *current_category = category_list;
  while (current_category != NULL) {
    if (strcmp(current_category->name, category) == 0) {
      current_category->total += amount;
      break;
    }
    current_category = current_category->next;
  }

  // If the category does not exist, create it
  if (current_category == NULL) {
    Category *new_category = malloc(sizeof(Category));
    new_category->name = malloc(strlen(category) + 1);
    strcpy(new_category->name, category);
    new_category->total = amount;
    new_category->next = NULL;

    if (category_list == NULL) {
      category_list = new_category;
    } else {
      Category *current = category_list;
      while (current->next != NULL) {
        current = current->next;
      }
      current->next = new_category;
    }
  }
}

// Function to print the expense list
void print_expenses() {
  Expense *current = expense_list;
  while (current != NULL) {
    printf("%s: %f (%s)\n", current->description, current->amount, current->category);
    current = current->next;
  }
}

// Function to print the category list
void print_categories() {
  Category *current = category_list;
  while (current != NULL) {
    printf("%s: %f\n", current->name, current->total);
    current = current->next;
  }
}

// Function to free the memory allocated for the expense list
void free_expenses() {
  Expense *current = expense_list;
  while (current != NULL) {
    Expense *next = current->next;
    free(current->description);
    free(current->category);
    free(current);
    current = next;
  }
}

// Function to free the memory allocated for the category list
void free_categories() {
  Category *current = category_list;
  while (current != NULL) {
    Category *next = current->next;
    free(current->name);
    free(current);
    current = next;
  }
}

// Main function
int main() {
  // Add some expenses to the list
  add_expense("Groceries", 100.00, "Food");
  add_expense("Gas", 50.00, "Transportation");
  add_expense("Entertainment", 20.00, "Entertainment");
  add_expense("Utilities", 75.00, "Housing");
  add_expense("Credit card payment", 250.00, "Debt");

  // Print the expense list
  printf("Expenses:\n");
  print_expenses();

  // Print the category list
  printf("\nCategories:\n");
  print_categories();

  // Free the memory allocated for the expense list and category list
  free_expenses();
  free_categories();

  return 0;
}