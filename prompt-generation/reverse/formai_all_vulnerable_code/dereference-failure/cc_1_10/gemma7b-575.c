//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

typedef struct Transaction {
    char name[50];
    int amount;
    struct Transaction* next;
} Transaction;

Transaction* addTransaction(Transaction* head, char* name, int amount) {
    Transaction* newTransaction = malloc(sizeof(Transaction));
    strcpy(newTransaction->name, name);
    newTransaction->amount = amount;
    newTransaction->next = NULL;

    if (head == NULL) {
        head = newTransaction;
    } else {
        head->next = newTransaction;
    }

    return head;
}

int calculateTotalAmount(Transaction* head) {
    int totalAmount = 0;

    while (head) {
        totalAmount += head->amount;
        head = head->next;
    }

    return totalAmount;
}

int main() {
    Transaction* head = NULL;

    // Add some transactions
    addTransaction(head, "Buy groceries", 50);
    addTransaction(head, "Pay rent", -20);
    addTransaction(head, "Get a refund", 10);
    addTransaction(head, "Go to the movies", 25);

    // Calculate the total amount
    int totalAmount = calculateTotalAmount(head);

    // Print the total amount
    printf("Total amount: %d\n", totalAmount);

    return 0;
}