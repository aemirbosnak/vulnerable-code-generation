//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A leafy expense
typedef struct Expense {
  char *name;
  float amount;
  char *category;
  struct Expense *next;
} Expense;

// A lush garden of expenses
typedef struct ExpenseList {
  Expense *head;
  Expense *tail;
} ExpenseList;

// Plant a new expense in the garden
Expense *createExpense(char *name, float amount, char *category) {
  Expense *newExpense = (Expense *)malloc(sizeof(Expense));
  newExpense->name = strdup(name);
  newExpense->amount = amount;
  newExpense->category = strdup(category);
  newExpense->next = NULL;
  return newExpense;
}

// Add an expense to the garden
void addExpense(ExpenseList *list, Expense *expense) {
  if (list->head == NULL) {
    list->head = expense;
    list->tail = expense;
  } else {
    list->tail->next = expense;
    list->tail = expense;
  }
}

// Prune an expense from the garden
void removeExpense(ExpenseList *list, char *name) {
  Expense *current = list->head;
  Expense *previous = NULL;

  while (current != NULL) {
    if (strcmp(current->name, name) == 0) {
      if (previous == NULL) {
        list->head = current->next;
      } else {
        previous->next = current->next;
      }
      free(current->name);
      free(current->category);
      free(current);
      break;
    }
    previous = current;
    current = current->next;
  }
}

// Calculate the total expenses from a category
float calculateTotal(ExpenseList *list, char *category) {
  float total = 0.0;
  Expense *current = list->head;

  while (current != NULL) {
    if (strcmp(current->category, category) == 0) {
      total += current->amount;
    }
    current = current->next;
  }
  return total;
}

// Print the garden of expenses
void printExpenses(ExpenseList *list) {
  Expense *current = list->head;

  printf("Here's your blossoming garden of expenses:\n");
  while (current != NULL) {
    printf("%s: %.2f (%s)\n", current->name, current->amount, current->category);
    current = current->next;
  }
}

// A wise old gardener to tend to the expenses
int main() {
  // Create a new lush garden
  ExpenseList garden;
  garden.head = NULL;
  garden.tail = NULL;

  // Plant some expenses
  addExpense(&garden, createExpense("Coffee", 2.50, "Food"));
  addExpense(&garden, createExpense("Lunch with friends", 15.00, "Social"));
  addExpense(&garden, createExpense("Movie tickets", 12.00, "Entertainment"));
  addExpense(&garden, createExpense("New shoes", 50.00, "Fashion"));

  // Prune an expense
  removeExpense(&garden, "Lunch with friends");

  // Calculate total expenses from different categories
  float foodTotal = calculateTotal(&garden, "Food");
  float socialTotal = calculateTotal(&garden, "Social");

  // Print the garden of expenses
  printExpenses(&garden);

  // Harvest the garden
  Expense *current = garden.head;
  while (current != NULL) {
    Expense *next = current->next;
    free(current->name);
    free(current->category);
    free(current);
    current = next;
  }

  return 0;
}