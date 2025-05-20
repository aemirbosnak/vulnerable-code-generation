//FormAI DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int num_of_expenses, expense_index = 0, i, j, sum = 0;
  char name[30], date[30];

  printf("Welcome to Expense Tracker! \n\n");

  printf("How many expenses would you like to track? ");
  scanf("%d", &num_of_expenses);

  char **expenses = (char **)malloc(num_of_expenses * sizeof(char *));
  int *prices = (int *)malloc(num_of_expenses * sizeof(int));
  char **dates = (char **)malloc(num_of_expenses * sizeof(char *));

  for (i = 0; i < num_of_expenses; i++)
  {
    printf("\nEnter the name of expense %d: ", i + 1);
    scanf("%s", name);

    printf("Enter the price of %s: ", name);
    scanf("%d", &prices[i]);

    printf("Enter the date of %s (MM/DD/YYYY): ", name);
    scanf("%s", date);

    int n = strlen(name);
    expenses[expense_index] = (char *)malloc(n * sizeof(char));
    strcpy(expenses[expense_index], name);

    n = strlen(date);
    dates[expense_index] = (char *)malloc(n * sizeof(char));
    strcpy(dates[expense_index], date);

    expense_index++;
  }

  printf("\nExcellent! Here's your list:");
  printf("\n-----------------------------------------");

  for (i = 0; i < num_of_expenses; i++)
  {
    printf("\n%d. Name: %s", i + 1, expenses[i]);
    printf("\n   Price: $%d", prices[i]);
    printf("\n   Date: %s", dates[i]);
    sum += prices[i];
  }

  printf("\n-----------------------------------------");
  printf("\nTotal expenses: $%d\n\n", sum);

  printf("Thank you for using Expense Tracker! \n");

  free(expenses);
  free(prices);
  free(dates);

  return 0;
}