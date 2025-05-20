//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculate_balance(int **account_balance, int num_accounts);
void display_account_summary(int **account_balance, int num_accounts);

int main()
{
  int num_accounts = 3;
  int *account_balance = malloc(num_accounts * sizeof(int));

  account_balance[0] = 1000;
  account_balance[1] = 2000;
  account_balance[2] = 3000;

  calculate_balance(&account_balance, num_accounts);
  display_account_summary(account_balance, num_accounts);

  free(account_balance);

  return 0;
}

void calculate_balance(int **account_balance, int num_accounts)
{
  int i;
  int total_balance = 0;

  for (i = 0; i < num_accounts; i++)
  {
    total_balance += account_balance[i];
  }

  account_balance[num_accounts - 1] = total_balance;
}

void display_account_summary(int **account_balance, int num_accounts)
{
  int i;

  printf("Account Summary:\n");

  for (i = 0; i < num_accounts; i++)
  {
    printf("Account %d: $%d\n", i + 1, account_balance[i]);
  }

  printf("Total Balance: $%d\n", account_balance[num_accounts - 1]);
}