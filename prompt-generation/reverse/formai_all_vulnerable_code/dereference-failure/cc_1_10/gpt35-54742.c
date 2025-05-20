//FormAI DATASET v1.0 Category: Banking Record System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    float balance;
} Account;

void deposit(Account *acc, float amount)
{
    acc->balance += amount;
    printf("Deposited %.2f into account %s.\n", amount, acc->name);
}

void withdraw(Account *acc, float amount)
{
    if (amount <= acc->balance) {
        acc->balance -= amount;
        printf("Withdrawn %.2f from account %s.\n", amount, acc->name);
    }
    else {
        printf("Insufficient funds in account %s.\n", acc->name);
    }
}

void display(Account *acc)
{
    printf("Account Details: \nName: %s\nBalance: %.2f\n", acc->name, acc->balance);
}

int main()
{
    int num_accounts = 0, option;
    char name[30];
    float amount;
    Account *accounts = NULL;

    printf("Welcome to the C Banking Record System!\n");

    do {
        printf("\nSelect an option:\n");
        printf("1) Create New Account\n");
        printf("2) View Account Details\n");
        printf("3) Deposit Into Account\n");
        printf("4) Withdraw From Account\n");
        printf("5) Quit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter account name: ");
                scanf("%s", name);
                accounts = realloc(accounts, (num_accounts + 1) * sizeof(Account));
                strcpy(accounts[num_accounts].name, name);
                accounts[num_accounts].balance = 0;
                printf("Account created successfully!\n");
                num_accounts++;
                break;
            case 2:
                if (num_accounts == 0) {
                    printf("No accounts created yet.\n");
                }
                else {
                    printf("Enter account name: ");
                    scanf("%s", name);
                    for (int i = 0; i < num_accounts; i++) {
                        if (strcmp(accounts[i].name, name) == 0) {
                            display(&accounts[i]);
                            break;
                        }
                    }
                }
                break;
            case 3:
                if (num_accounts == 0) {
                    printf("No accounts created yet.\n");
                }
                else {
                    printf("Enter account name: ");
                    scanf("%s", name);
                    for (int i = 0; i < num_accounts; i++) {
                        if (strcmp(accounts[i].name, name) == 0) {
                            printf("Enter amount to deposit: ");
                            scanf("%f", &amount);
                            deposit(&accounts[i], amount);
                            break;
                        }
                    }
                }
                break;
            case 4:
                if (num_accounts == 0) {
                    printf("No accounts created yet.\n");
                }
                else {
                    printf("Enter account name: ");
                    scanf("%s", name);
                    for (int i = 0; i < num_accounts; i++) {
                        if (strcmp(accounts[i].name, name) == 0) {
                            printf("Enter amount to withdraw: ");
                            scanf("%f", &amount);
                            withdraw(&accounts[i], amount);
                            break;
                        }
                    }
                }
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option selected.\n");
                break;
        }
    } while (option != 5);

    free(accounts);

    return 0;
}