//FormAI DATASET v1.0 Category: Expense Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expen {
  char description[30];
  float amount;
  struct expen *next;
} Expense;

Expense *create_expense();
void add_expense(Expense *head, Expense *new);
void print_expenses(Expense *head);

int main(int argc, char *argv[]) {

  printf("Welcome to the Expense Tracker!\n\n");
  
  Expense *head = create_expense();

  int choice = 0;

  while (choice != 4) {

    printf("Please choose from the following options:\n");
    printf("1. Add expense\n");
    printf("2. View expenses\n");
    printf("3. Clear expenses\n");
    printf("4. Quit\n");

    scanf("%d", &choice);

    switch (choice) {

      case 1: {
        Expense *new_expense = create_expense();
        add_expense(head, new_expense);
        printf("Expense added!\n\n");
        break;
      }

      case 2: {
        print_expenses(head);
        break;
      }

      case 3: {
        free(head->next);
        head->next = NULL;
        printf("Expenses cleared!\n\n");
        break;
      }

      case 4: {
        printf("Goodbye!\n");
        break;
      }

      default: {
        printf("Invalid choice, please try again.\n\n");
        break;
      }
    }

  }

  free(head);

  return 0;

}

// function to create a new expense node
Expense *create_expense() {

  Expense *new_expense = (Expense *) malloc(sizeof(Expense));
  memset(new_expense, 0, sizeof(Expense));

  printf("Enter description: ");
  scanf("%s", new_expense->description);

  printf("Enter amount: ");
  scanf("%f", &new_expense->amount);

  new_expense->next = NULL;

  return new_expense;

}

// function to add a new expense node to the list
void add_expense(Expense *head, Expense *new) {

  Expense *current = head;

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new;

}

// function to print all of the expenses in the list
void print_expenses(Expense *head) {

  if (head->next == NULL) {
    printf("No expenses to display.\n\n");
    return;
  }

  Expense *current = head->next;

  while (current != NULL) {
    printf("Description: %s\n", current->description);
    printf("Amount: %.2f\n\n", current->amount);
    current = current->next;
  }

}