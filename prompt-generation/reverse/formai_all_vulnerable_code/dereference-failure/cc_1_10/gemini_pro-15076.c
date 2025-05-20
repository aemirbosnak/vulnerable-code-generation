//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int account_number;
    double balance;
} account;

int main() {
    account accounts[100];
    int num_accounts = 0;

    while (1) {
        printf("Enter a command (n to create a new account, d to deposit, w to withdraw, b to get balance, q to quit): ");
        char command;
        scanf(" %c", &command);

        switch (command) {
            case 'n':
                printf("Enter the name of the account holder: ");
                char *name = malloc(100);
                scanf(" %s", name);

                accounts[num_accounts].name = name;
                accounts[num_accounts].account_number = num_accounts + 1;
                accounts[num_accounts].balance = 0.0;

                num_accounts++;

                printf("Account created.\n");
                break;

            case 'd':
                printf("Enter the account number: ");
                int account_number;
                scanf(" %d", &account_number);

                account *account = &accounts[account_number - 1];

                printf("Enter the amount to deposit: ");
                double amount;
                scanf(" %lf", &amount);

                account->balance += amount;

                printf("Deposit successful.\n");
                break;

            case 'w':
                printf("Enter the account number: ");
                scanf(" %d", &account_number);

                account = &accounts[account_number - 1];

                printf("Enter the amount to withdraw: ");
                scanf(" %lf", &amount);

                if (amount > account->balance) {
                    printf("Insufficient funds.\n");
                } else {
                    account->balance -= amount;

                    printf("Withdrawal successful.\n");
                }
                break;

            case 'b':
                printf("Enter the account number: ");
                scanf(" %d", &account_number);

                account = &accounts[account_number - 1];

                printf("Balance: $%.2f\n", account->balance);
                break;

            case 'q':
                printf("Quitting.\n");
                return 0;

            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}