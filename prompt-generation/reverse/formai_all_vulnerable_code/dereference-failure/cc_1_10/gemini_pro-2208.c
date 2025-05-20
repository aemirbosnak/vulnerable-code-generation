//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct to store each transaction
typedef struct transaction {
    char description[50];
    double amount;
    char type; // 'I' for income, 'E' for expense
    struct transaction *next;
} transaction;

// Define the struct to store the user's financial data
typedef struct user_data {
    char name[50];
    double balance;
    transaction *transactions;
} user_data;

// Function to create a new transaction
transaction* create_transaction(char *description, double amount, char type) {
    transaction *new_transaction = (transaction*)malloc(sizeof(transaction));
    strcpy(new_transaction->description, description);
    new_transaction->amount = amount;
    new_transaction->type = type;
    new_transaction->next = NULL;
    return new_transaction;
}

// Function to add a transaction to the user's data
void add_transaction(user_data *user, transaction *new_transaction) {
    if (user->transactions == NULL) {
        user->transactions = new_transaction;
    } else {
        transaction *current = user->transactions;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_transaction;
    }
}

// Function to print the user's financial data
void print_user_data(user_data *user) {
    printf("Name: %s\n", user->name);
    printf("Balance: %f\n", user->balance);

    transaction *current = user->transactions;
    while (current != NULL) {
        printf("Description: %s\n", current->description);
        printf("Amount: %f\n", current->amount);
        printf("Type: %c\n", current->type);
        current = current->next;
    }
}

// Function to get the user's input
void get_user_input(user_data *user) {
    char input[100];
    double amount;
    char type;

    printf("Enter a transaction description: ");
    gets(input);
    strcpy(user->name, input);

    printf("Enter the amount: ");
    scanf("%lf", &amount);
    user->balance += amount;

    printf("Enter the transaction type (I for income, E for expense): ");
    scanf(" %c", &type);
    transaction *new_transaction = create_transaction(input, amount, type);
    add_transaction(user, new_transaction);
}

// Main function
int main() {
    user_data user;
    user.balance = 0;
    user.transactions = NULL;

    get_user_input(&user);
    print_user_data(&user);

    return 0;
}