//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Welcome to the most rad Expense Tracker ever! Get ready to track your cash like a pro!

// Let's define some cool structures to hold our expenses and categories
typedef struct expense {
  char *description;
  float amount;
  struct expense *next;
} expense;

typedef struct category {
  char *name;
  float total;
  struct expense *expenses;
  struct category *next;
} category;

// Now let's create the rockin' functions to manage our expenses and categories
void add_expense(category *cat, expense *exp) {
  // Let's rock and roll! Add that expense to the category
  exp->next = cat->expenses;
  cat->expenses = exp;
  cat->total += exp->amount;
}

void print_expenses(category *cat) {
  // Show me the money! Print out all the expenses in a category
  expense *curr = cat->expenses;
  while (curr) {
    printf(" - %s: $%.2f\n", curr->description, curr->amount);
    curr = curr->next;
  }
}

void print_categories(category *head) {
  // Time to crush it! Print out all the categories and their expenses
  category *curr = head;
  while (curr) {
    printf("\nCategory: %s\n", curr->name);
    print_expenses(curr);
    curr = curr->next;
  }
}

void free_expenses(expense *head) {
  // Let's clean up our act! Free all the expenses in a category
  expense *curr = head;
  while (curr) {
    expense *next = curr->next;
    free(curr->description);
    free(curr);
    curr = next;
  }
}

void free_categories(category *head) {
  // Time to say goodbye! Free all the categories and their expenses
  category *curr = head;
  while (curr) {
    category *next = curr->next;
    free_expenses(curr->expenses);
    free(curr->name);
    free(curr);
    curr = next;
  }
}

int main() {
  // Let's get this party started! Initialize our categories and expenses
  category *food = malloc(sizeof(category));
  food->name = "Food";
  food->total = 0;
  food->expenses = NULL;

  category *entertainment = malloc(sizeof(category));
  entertainment->name = "Entertainment";
  entertainment->total = 0;
  entertainment->expenses = NULL;

  category *travel = malloc(sizeof(category));
  travel->name = "Travel";
  travel->total = 0;
  travel->expenses = NULL;

  // Time to add some rad expenses to our categories
  expense *pizza = malloc(sizeof(expense));
  pizza->description = "Pizza night with the crew";
  pizza->amount = 20.00;

  expense *concert = malloc(sizeof(expense));
  concert->description = "Tickets to the best concert ever";
  concert->amount = 100.00;

  expense *vacation = malloc(sizeof(expense));
  vacation->description = "Dream vacation to the tropics";
  vacation->amount = 1500.00;

  // Let's rock and roll! Add those expenses to their categories
  add_expense(food, pizza);
  add_expense(entertainment, concert);
  add_expense(travel, vacation);

  // Show me the money! Print out all the categories and their expenses
  print_categories(food);
  print_categories(entertainment);
  print_categories(travel);

  // Time to clean up our act! Free all the categories and expenses
  free_categories(food);
  free_categories(entertainment);
  free_categories(travel);

  // That's a wrap! We're expense tracking rock stars!
  return 0;
}