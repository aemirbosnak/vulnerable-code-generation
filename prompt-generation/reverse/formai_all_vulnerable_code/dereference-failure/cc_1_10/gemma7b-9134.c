//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_EXPENSE_NUM 100

typedef struct Expense {
  char name[50];
  double amount;
  struct Expense* next;
} Expense;

Expense* createExpense(char* name, double amount) {
  Expense* newExpense = malloc(sizeof(Expense));
  strcpy(newExpense->name, name);
  newExpense->amount = amount;
  newExpense->next = NULL;
  return newExpense;
}

void addToExpenseList(Expense* head, Expense* newExpense) {
  if (head == NULL) {
    head = newExpense;
  } else {
    head->next = newExpense;
  }
}

void printExpenses(Expense* head) {
  while (head) {
    printf("%s: %.2lf\n", head->name, head->amount);
    head = head->next;
  }
}

int main() {
  Expense* head = NULL;

  // Paranoia begins...

  while (1) {
    char* name = malloc(50);
    double amount;

    printf("Enter expense name: ");
    scanf("%s", name);

    printf("Enter expense amount: ");
    scanf("%lf", &amount);

    Expense* newExpense = createExpense(name, amount);
    addToExpenseList(head, newExpense);

    printf("Enter 'q' to quit or any key to continue: ");
    char quit;
    scanf(" %c", &quit);

    if (quit == 'q') {
      break;
    }
  }

  printExpenses(head);

  return 0;
}