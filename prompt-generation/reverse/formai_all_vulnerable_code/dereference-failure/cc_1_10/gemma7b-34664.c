//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a personal finance account
typedef struct Account {
    char name[50];
    int account_number;
    double balance;
    double interest_rate;
    struct Account* next;
} Account;

// Function to create a new personal finance account
Account* create_account(char* name, int account_number, double balance, double interest_rate) {
    Account* new_account = (Account*)malloc(sizeof(Account));
    strcpy(new_account->name, name);
    new_account->account_number = account_number;
    new_account->balance = balance;
    new_account->interest_rate = interest_rate;
    new_account->next = NULL;
    return new_account;
}

// Function to add a new account to the list
void add_account(Account* head, Account* new_account) {
    if (head == NULL) {
        head = new_account;
    } else {
        Account* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_account;
    }
}

// Function to calculate the interest on an account
double calculate_interest(Account* account, double years) {
    double interest = account->balance * account->interest_rate * years;
    return interest;
}

// Function to print the accounts
void print_accounts(Account* head) {
    Account* current = head;
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Account Number: %d\n", current->account_number);
        printf("Balance: %.2lf\n", current->balance);
        printf("Interest Rate: %.2lf%\n", current->interest_rate);
        printf("\n");
        current = current->next;
    }
}

int main() {
    Account* head = NULL;

    // Create a few accounts
    Account* account1 = create_account("John Doe", 123456, 1000.0, 2.5);
    Account* account2 = create_account("Jane Doe", 654321, 2000.0, 3.0);
    Account* account3 = create_account("Peter Pan", 324681, 3000.0, 3.5);

    // Add the accounts to the list
    add_account(head, account1);
    add_account(head, account2);
    add_account(head, account3);

    // Print the accounts
    print_accounts(head);

    // Calculate the interest on account1
    double interest = calculate_interest(account1, 5);

    // Print the interest
    printf("Interest on account1: %.2lf\n", interest);

    return 0;
}