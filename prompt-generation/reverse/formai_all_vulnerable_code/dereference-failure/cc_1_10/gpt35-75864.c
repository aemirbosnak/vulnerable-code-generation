//FormAI DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
  char date[20];
  char description[50];
  float amount;
} Expense;

int main() {
  Expense expenses[MAX_EXPENSES];
  int numExpenses = 0;
  float totalSpending = 0;

  while(1) {
    char userInput[50];
    printf("Enter expense information (date, description, amount) or type 'quit' to exit: ");
    fgets(userInput, 50, stdin);

    if (strcmp(userInput, "quit\n") == 0) {
      printf("\nSummary:\n");
      printf("%-15s %-30s %s\n", "Date", "Description", "Amount");
      printf("-------------------------------------------------\n");

      for (int i = 0; i < numExpenses; i++) {
        printf("%-15s %-30s $%.2f\n", expenses[i].date, expenses[i].description, expenses[i].amount);
        totalSpending += expenses[i].amount;
      }

      printf("-------------------------------------------------\n");
      printf("Total spending: $%.2f\n", totalSpending);

      return 0;
    }

    char* token = strtok(userInput, " ");
    strcpy(expenses[numExpenses].date, token);

    token = strtok(NULL, ",");
    strcpy(expenses[numExpenses].description, token);

    token = strtok(NULL, "\n");
    expenses[numExpenses].amount = strtof(token, NULL);

    numExpenses++;
  }
}