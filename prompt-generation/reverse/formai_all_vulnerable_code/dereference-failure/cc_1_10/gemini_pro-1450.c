//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the maximum length of an account number
#define MAX_ACCOUNT_NUMBER_LENGTH 20

// Define the maximum length of a customer name
#define MAX_CUSTOMER_NAME_LENGTH 50

// Define the maximum length of a transaction description
#define MAX_TRANSACTION_DESCRIPTION_LENGTH 100

// Define the account structure
typedef struct account {
    char account_number[MAX_ACCOUNT_NUMBER_LENGTH];
    char customer_name[MAX_CUSTOMER_NAME_LENGTH];
    double balance;
    struct transaction *transactions;
    int num_transactions;
} account;

// Define the transaction structure
typedef struct transaction {
    char description[MAX_TRANSACTION_DESCRIPTION_LENGTH];
    double amount;
    struct transaction *next;
} transaction;

// Create an array of accounts
account accounts[MAX_ACCOUNTS];

// Create a pointer to the current account
account *current_account = NULL;

// Create a pointer to the current transaction
transaction *current_transaction = NULL;

// Initialize the banking system
void init_banking_system() {
    // Create the first account
    strcpy(accounts[0].account_number, "1234567890");
    strcpy(accounts[0].customer_name, "John Doe");
    accounts[0].balance = 1000.00;
    accounts[0].transactions = NULL;
    accounts[0].num_transactions = 0;

    // Set the current account to the first account
    current_account = &accounts[0];
}

// Get the account number from the user
void get_account_number() {
    printf("Enter your account number: ");
    scanf("%s", current_account->account_number);
}

// Get the customer name from the user
void get_customer_name() {
    printf("Enter your name: ");
    scanf("%s", current_account->customer_name);
}

// Get the balance from the user
void get_balance() {
    printf("Enter your balance: ");
    scanf("%lf", &current_account->balance);
}

// Get the number of transactions from the user
void get_num_transactions() {
    printf("Enter the number of transactions: ");
    scanf("%d", &current_account->num_transactions);
}

// Get the transaction description from the user
void get_transaction_description() {
    printf("Enter the transaction description: ");
    scanf("%s", current_transaction->description);
}

// Get the transaction amount from the user
void get_transaction_amount() {
    printf("Enter the transaction amount: ");
    scanf("%lf", &current_transaction->amount);
}

// Add a transaction to the current account
void add_transaction() {
    // Create a new transaction
    transaction *new_transaction = malloc(sizeof(transaction));

    // Get the transaction description from the user
    get_transaction_description();

    // Get the transaction amount from the user
    get_transaction_amount();

    // Set the next pointer of the new transaction to NULL
    new_transaction->next = NULL;

    // If the current transaction is NULL, set the current transaction to the new transaction
    if (current_transaction == NULL) {
        current_transaction = new_transaction;
    } else {
        // Otherwise, add the new transaction to the end of the linked list of transactions
        current_transaction->next = new_transaction;
        current_transaction = new_transaction;
    }

    // Increment the number of transactions in the current account
    current_account->num_transactions++;
}

// Print the account information
void print_account_information() {
    printf("Account Number: %s\n", current_account->account_number);
    printf("Customer Name: %s\n", current_account->customer_name);
    printf("Balance: %lf\n", current_account->balance);
    printf("Number of Transactions: %d\n", current_account->num_transactions);

    // Print the transactions
    transaction *temp = current_account->transactions;
    while (temp != NULL) {
        printf("Transaction Description: %s\n", temp->description);
        printf("Transaction Amount: %lf\n", temp->amount);
        temp = temp->next;
    }
}

// Main function
int main() {
    // Initialize the banking system
    init_banking_system();

    // Get the account number from the user
    get_account_number();

    // Get the customer name from the user
    get_customer_name();

    // Get the balance from the user
    get_balance();

    // Get the number of transactions from the user
    get_num_transactions();

    // Add the transactions to the current account
    for (int i = 0; i < current_account->num_transactions; i++) {
        add_transaction();
    }

    // Print the account information
    print_account_information();

    return 0;
}