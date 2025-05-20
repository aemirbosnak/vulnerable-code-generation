//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Account structure
typedef struct {
    int account_number;
    char *name;
    double balance;
} Account;

// Linked list node structure
typedef struct node {
    Account *account;
    struct node *next;
} Node;

// Linked list head pointer
Node *head = NULL;

// Create a new account
Account *create_account(int account_number, char *name, double balance) {
    Account *account = malloc(sizeof(Account));
    account->account_number = account_number;
    account->name = strdup(name);
    account->balance = balance;
    return account;
}

// Insert a new account into the linked list
void insert_account(Account *account) {
    Node *new_node = malloc(sizeof(Node));
    new_node->account = account;
    new_node->next = head;
    head = new_node;
}

// Find an account by account number
Account *find_account(int account_number) {
    Node *current = head;
    while (current != NULL) {
        if (current->account->account_number == account_number) {
            return current->account;
        }
        current = current->next;
    }
    return NULL;
}

// Deposit money into an account
void deposit(int account_number, double amount) {
    Account *account = find_account(account_number);
    if (account != NULL) {
        account->balance += amount;
    } else {
        printf("Account not found.\n");
    }
}

// Withdraw money from an account
void withdraw(int account_number, double amount) {
    Account *account = find_account(account_number);
    if (account != NULL) {
        if (account->balance >= amount) {
            account->balance -= amount;
        } else {
            printf("Insufficient funds.\n");
        }
    } else {
        printf("Account not found.\n");
    }
}

// Print the account details
void print_account(Account *account) {
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
}

// Print all accounts
void print_all_accounts() {
    Node *current = head;
    while (current != NULL) {
        print_account(current->account);
        current = current->next;
    }
}

// Main function
int main() {
    // Create some accounts
    Account *account1 = create_account(12345, "John Doe", 1000.0);
    insert_account(account1);

    Account *account2 = create_account(67890, "Jane Doe", 2000.0);
    insert_account(account2);

    // Deposit money into account1
    deposit(12345, 500.0);

    // Withdraw money from account2
    withdraw(67890, 1000.0);

    // Print all accounts
    print_all_accounts();

    return 0;
}