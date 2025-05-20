//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 10

struct Transaction {
    char name[50];
    double amount;
    char category[50];
    struct Transaction* next;
};

struct Transaction* createTransaction(char* name, double amount, char* category) {
    struct Transaction* newTransaction = (struct Transaction*)malloc(sizeof(struct Transaction));
    strcpy(newTransaction->name, name);
    newTransaction->amount = amount;
    strcpy(newTransaction->category, category);
    newTransaction->next = NULL;
    return newTransaction;
}

struct Transaction* addTransaction(struct Transaction* head, char* name, double amount, char* category) {
    struct Transaction* newTransaction = createTransaction(name, amount, category);
    if (head == NULL) {
        head = newTransaction;
    } else {
        struct Transaction* currentTransaction = head;
        while (currentTransaction->next != NULL) {
            currentTransaction = currentTransaction->next;
        }
        currentTransaction->next = newTransaction;
    }
    return head;
}

void printTransactions(struct Transaction* head) {
    struct Transaction* currentTransaction = head;
    while (currentTransaction) {
        printf("%s: $%.2lf (Category: %s)\n", currentTransaction->name, currentTransaction->amount, currentTransaction->category);
        currentTransaction = currentTransaction->next;
    }
}

int main() {
    struct Transaction* head = NULL;
    head = addTransaction(head, "Buy groceries", 50.0, "Food");
    head = addTransaction(head, "Pay rent", 100.0, "Bills");
    head = addTransaction(head, "Get a haircut", 20.0, "Services");
    printTransactions(head);
    return 0;
}