//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>

struct expenses {
  char *category;
  double amount;
};

struct budget {
  char *category;
  double amount;
};

int main() {
  int num_expenses, num_budget;
  struct expenses *expenses;
  struct budget *budget;

  printf("Welcome to your personal finance planner!\n");

  printf("How many expenses do you have? ");
  scanf("%d", &num_expenses);

  expenses = (struct expenses *)malloc(num_expenses * sizeof(struct expenses));

  for (int i = 0; i < num_expenses; i++) {
    printf("Enter expense category: ");
    scanf("%s", expenses[i].category);

    printf("Enter expense amount: ");
    scanf("%lf", &expenses[i].amount);
  }

  printf("How many budget categories do you have? ");
  scanf("%d", &num_budget);

  budget = (struct budget *)malloc(num_budget * sizeof(struct budget));

  for (int i = 0; i < num_budget; i++) {
    printf("Enter budget category: ");
    scanf("%s", budget[i].category);

    printf("Enter budget amount: ");
    scanf("%lf", &budget[i].amount);
  }

  // Calculate total expenses
  double total_expenses = 0;
  for (int i = 0; i < num_expenses; i++) {
    total_expenses += expenses[i].amount;
  }

  // Calculate total budget
  double total_budget = 0;
  for (int i = 0; i < num_budget; i++) {
    total_budget += budget[i].amount;
  }

  // Print expenses and budget
  printf("\nExpenses:\n");
  for (int i = 0; i < num_expenses; i++) {
    printf("%s: $%.2lf\n", expenses[i].category, expenses[i].amount);
  }

  printf("\nBudget:\n");
  for (int i = 0; i < num_budget; i++) {
    printf("%s: $%.2lf\n", budget[i].category, budget[i].amount);
  }

  // Calculate and print budget variance
  double budget_variance = total_budget - total_expenses;
  printf("\nBudget variance: $%.2lf\n", budget_variance);

  // Free memory
  free(expenses);
  free(budget);

  return 0;
}