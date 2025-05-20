//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store bank account information
struct bank_account {
    char name[50];
    int account_number;
    double balance;
    struct bank_account* next;
};

// Function to insert a new bank account into the linked list
void insert_account(struct bank_account** head, char* name, int account_number, double balance) {
    struct bank_account* new_account = (struct bank_account*)malloc(sizeof(struct bank_account));
    strcpy(new_account->name, name);
    new_account->account_number = account_number;
    new_account->balance = balance;
    new_account->next = NULL;

    if (*head == NULL) {
        *head = new_account;
    } else {
        (*head)->next = new_account;
    }
}

// Function to search for a bank account by account number
struct bank_account* search_account(struct bank_account* head, int account_number) {
    while (head) {
        if (head->account_number == account_number) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the balance of a bank account
void update_balance(struct bank_account* account, double new_balance) {
    account->balance = new_balance;
}

// Main function
int main() {
    struct bank_account* head = NULL;

    // Insert some sample accounts
    insert_account(&head, "John Doe", 123456, 1000);
    insert_account(&head, "Jane Doe", 654912, 2000);
    insert_account(&head, "Peter Pan", 987631, 3000);

    // Search for an account by account number and update its balance
    struct bank_account* account = search_account(head, 123456);
    if (account) {
        update_balance(account, 1500);
    }

    // Print the updated account balance
    account = search_account(head, 123456);
    if (account) {
        printf("Account name: %s\n", account->name);
        printf("Account number: %d\n", account->account_number);
        printf("Balance: %f\n", account->balance);
    }

    return 0;
}