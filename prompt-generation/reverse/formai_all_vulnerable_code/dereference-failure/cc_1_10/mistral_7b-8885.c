//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct account {
    int account_number;
    char name[50];
    float balance;
    struct account *next;
} Account;

void create_account(Account **head, int account_number, char *name, float balance) {
    Account *new_account = (Account *)malloc(sizeof(Account));
    new_account->account_number = account_number;
    strcpy(new_account->name, name);
    new_account->balance = balance;
    new_account->next = *head;
    *head = new_account;
}

void display_accounts_recursive(Account *account) {
    if (account == NULL) {
        return;
    }
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
    display_accounts_recursive(account->next);
}

void deposit_money_recursive(Account *account, float amount) {
    if (account == NULL) {
        return;
    }
    account->balance += amount;
    deposit_money_recursive(account->next, amount);
}

int main() {
    Account *head = NULL;
    create_account(&head, 101, "John Doe", 1000.00);
    create_account(&head, 102, "Jane Doe", 2000.00);
    create_account(&head, 103, "Bob Smith", 500.00);

    printf("Displaying Accounts:\n");
    display_accounts_recursive(head);

    printf("\nDepositing 500 into all accounts:\n");
    deposit_money_recursive(head, 500.00);

    printf("\nDisplaying Accounts after Deposit:\n");
    display_accounts_recursive(head);

    return 0;
}