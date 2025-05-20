//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    // Define variables
    int num_accounts = 0;
    char **account_names = NULL;
    double *account_balances = NULL;

    // Allocate memory for accounts
    account_names = (char **)malloc(MAX * sizeof(char *));
    account_balances = (double *)malloc(MAX * sizeof(double));

    // Get the number of accounts
    printf("How many accounts do you have? ");
    scanf("%d", &num_accounts);

    // Create accounts
    for (int i = 0; i < num_accounts; i++)
    {
        account_names[i] = (char *)malloc(20 * sizeof(char));
        printf("Enter the name of account %d: ", i + 1);
        scanf("%s", account_names[i]);

        account_balances[i] = 0.0;
        printf("Enter the initial balance of account %d: ", i + 1);
        scanf("%lf", &account_balances[i]);
    }

    // Print account information
    printf("Here is your account information:\n");
    for (int i = 0; i < num_accounts; i++)
    {
        printf("Account name: %s\n", account_names[i]);
        printf("Account balance: %.2lf\n", account_balances[i]);
    }

    // Free memory
    for (int i = 0; i < num_accounts; i++)
    {
        free(account_names[i]);
    }
    free(account_names);
    free(account_balances);

    return 0;
}