//FormAI DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 1000

// Structure for an expense
struct Expense {
  int id;
  char name[100];
  float amount;
  char date[50];
};

// List of expenses
struct Expense expenses[MAX_EXPENSES];
// Counter for number of expenses
int num_expenses = 0;

// Returns the current date and time
char *get_current_date_time() {
  time_t t = time(NULL);
  return asctime(localtime(&t));
}

// Adds a new expense
void add_new_expense() {
  struct Expense new_expense;
  new_expense.id = num_expenses + 1;

  printf("Enter expense name: ");
  scanf("%s", new_expense.name);

  printf("Enter expense amount: ");
  scanf("%f", &new_expense.amount);

  char *current_date_time = get_current_date_time();
  strcpy(new_expense.date, current_date_time);

  expenses[num_expenses] = new_expense;
  num_expenses++;

  printf("\nExpense added successfully!\n\n");
}

// Displays a list of all expenses
void view_all_expenses() {
  if (num_expenses == 0) {
    printf("\nNo expenses found.\n\n");
    return;
  }

  printf("\nList of all expenses:\n");
  printf("---------------------\n");

  for (int i = 0; i < num_expenses; i++) {
    printf("ID: %d\n", expenses[i].id);
    printf("Name: %s\n", expenses[i].name);
    printf("Amount: %.2f\n", expenses[i].amount);
    printf("Date: %s", expenses[i].date);
    printf("---------------------\n");
  }
}

// Searches for an expense by its name
void search_expense_by_name() {
  char query[100];

  printf("Enter expense name: ");
  scanf("%s", query);

  int found_count = 0;
  printf("\nList of expenses containing '%s':\n", query);
  printf("-----------------------------------\n");
  
  for (int i = 0; i < num_expenses; i++) {
    if (strstr(expenses[i].name, query) != NULL) {
      printf("ID: %d\n", expenses[i].id);
      printf("Name: %s\n", expenses[i].name);
      printf("Amount: %.2f\n", expenses[i].amount);
      printf("Date: %s", expenses[i].date);
      printf("---------------------\n");
      found_count++;
    }
  }

  if (found_count == 0) {
    printf("No expenses found containing '%s'.\n", query);
  } else {
    printf("%d expenses found containing '%s'.\n", found_count, query);
  }

  printf("\n");
}

// Deletes an expense by its ID
void delete_expense_by_id() {
  int expense_id;
  printf("Enter expense ID to delete: ");
  scanf("%d", &expense_id);

  int index_to_delete = -1;
  for (int i = 0; i < num_expenses; i++) {
    if (expenses[i].id == expense_id) {
      index_to_delete = i;
      break;
    }
  }

  if (index_to_delete == -1) {
    printf("\nNo expense found with ID %d.\n\n", expense_id);
    return;
  }

  for (int i = index_to_delete; i < num_expenses - 1; i++) {
    expenses[i] = expenses[i+1];
  }
  num_expenses--;

  printf("\nExpense with ID %d deleted successfully!\n\n", expense_id);
}

// Displays the main menu
void display_menu() {
  printf("Expense Tracker\n");
  printf("----------------\n");
  printf("1. Add a new expense\n");
  printf("2. View all expenses\n");
  printf("3. Search expense by name\n");
  printf("4. Delete expense by ID\n");
  printf("5. Exit\n");
  printf("\n");
}

// Main function
int main() {
  int choice;

  do {
    display_menu();
    printf("Enter choice (1-5): ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        add_new_expense();
        break;

      case 2:
        view_all_expenses();
        break;

      case 3:
        search_expense_by_name();
        break;

      case 4:
        delete_expense_by_id();
        break;

      case 5:
        printf("\nGoodbye!\n\n");
        exit(0);

      default:
        printf("\nInvalid choice. Please try again.\n\n");
        break;
    }
  } while (choice != 5);

  return 0;
}