//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TRANSACTIONS 10

typedef struct Transaction {
    char name[50];
    double amount;
    struct Transaction* next;
} Transaction;

Transaction* insertTransaction(Transaction* head, char* name, double amount) {
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

double calculateTotal(Transaction* head) {
    double total = 0;

    while (head) {
        total += head->amount;
        head = head->next;
    }

    return total;
}

int main() {
    Transaction* head = NULL;

    insertTransaction(head, "Groceries", 50.0);
    insertTransaction(head, "Eating out", 25.0);
    insertTransaction(head, "Clothes", 30.0);

    double total = calculateTotal(head);

    printf("Total spending: $%.2f", total);

    return 0;
}