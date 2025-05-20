//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 10

typedef struct Expense {
  char name[20];
  float amount;
  struct Expense* next;
} Expense;

void addExpense(Expense** head) {
  Expense* newExpense = (Expense*)malloc(sizeof(Expense));
  printf("Enter expense name: ");
  scanf("%s", newExpense->name);
  printf("Enter expense amount: ");
  scanf("%f", &newExpense->amount);
  newExpense->next = NULL;

  if (*head == NULL) {
    *head = newExpense;
  } else {
    (*head)->next = newExpense;
  }
}

void displayExpenses(Expense* head) {
  while (head) {
    printf("%s: %.2f\n", head->name, head->amount);
    head = head->next;
  }
}

int main() {
  Expense* head = NULL;

  while (1) {
    char choice;

    printf("Enter 'a' to add an expense, 'd' to display expenses, or 'q' to quit: ");
    scanf(" %c", &choice);

    switch (choice) {
      case 'a':
        addExpense(&head);
        break;
      case 'd':
        displayExpenses(head);
        break;
      case 'q':
        exit(0);
    }
  }

  return 0;
}