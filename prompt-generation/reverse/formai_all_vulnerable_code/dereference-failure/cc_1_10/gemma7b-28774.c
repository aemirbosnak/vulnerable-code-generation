//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 10

// Define the transaction structure
typedef struct Transaction {
    char name[50];
    double amount;
    struct Transaction* next;
} Transaction;

// Function to insert a transaction
void insertTransaction(Transaction** head, char* name, double amount) {
    // Allocate memory for the new transaction
    Transaction* newTransaction = (Transaction*)malloc(sizeof(Transaction));

    // Copy the transaction name and amount
    strcpy(newTransaction->name, name);
    newTransaction->amount = amount;

    // If the head of the list is null, make it the new head
    if (*head == NULL) {
        *head = newTransaction;
    } else {
        // Traverse the list to the end
        Transaction* currentTransaction = *head;
        while (currentTransaction->next != NULL) {
            currentTransaction = currentTransaction->next;
        }

        // Insert the new transaction at the end
        currentTransaction->next = newTransaction;
    }
}

// Function to print the transactions
void printTransactions(Transaction* head) {
    // Traverse the list of transactions
    Transaction* currentTransaction = head;
    while (currentTransaction) {
        // Print the transaction name and amount
        printf("%s: %.2lf\n", currentTransaction->name, currentTransaction->amount);
        currentTransaction = currentTransaction->next;
    }
}

int main() {
    // Create a linked list of transactions
    Transaction* head = NULL;

    // Insert some transactions
    insertTransaction(&head, "Groceries", 50.0);
    insertTransaction(&head, "Eating out", 25.0);
    insertTransaction(&head, "Clothes", 75.0);

    // Print the transactions
    printTransactions(head);

    return 0;
}