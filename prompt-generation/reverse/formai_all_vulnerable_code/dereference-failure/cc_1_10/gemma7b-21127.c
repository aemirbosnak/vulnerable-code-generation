//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 10

struct Expense {
  char name[50];
  int amount;
  struct Expense* next;
};

void addExpense(struct Expense** head) {
  struct Expense* newExpense = malloc(sizeof(struct Expense));
  printf("Enter expense name: ");
  scanf("%s", newExpense->name);
  printf("Enter expense amount: ");
  scanf("%d", &newExpense->amount);
  newExpense->next = *head;
  *head = newExpense;
}

void printExpenses(struct Expense* head) {
  while (head) {
    printf("%s - %d\n", head->name, head->amount);
    head = head->next;
  }
}

int main() {
  struct Expense* head = NULL;
  int choice;

  do {
    printf("1. Add Expense\n");
    printf("2. Print Expenses\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addExpense(&head);
        break;
      case 2:
        printExpenses(head);
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (choice != 3);

  return 0;
}