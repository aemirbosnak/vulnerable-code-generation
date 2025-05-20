//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 10

typedef struct Transaction {
    char name[50];
    double amount;
    char type;
    struct Transaction* next;
} Transaction;

Transaction* insertTransaction(Transaction* head, char* name, double amount, char type) {
    Transaction* newTransaction = (Transaction*)malloc(sizeof(Transaction));
    strcpy(newTransaction->name, name);
    newTransaction->amount = amount;
    newTransaction->type = type;
    newTransaction->next = NULL;

    if (head == NULL) {
        head = newTransaction;
    } else {
        head->next = newTransaction;
    }

    return head;
}

void printTransactions(Transaction* head) {
    printf("Transactions:\n");
    while (head) {
        printf("%s - %.2lf (%c)\n", head->name, head->amount, head->type);
        head = head->next;
    }
}

int main() {
    Transaction* head = NULL;

    // Insert transactions
    insertTransaction(head, "John Doe", 50.0, 'D');
    insertTransaction(head, "Jane Doe", 25.0, 'W');
    insertTransaction(head, "Peter Pan", 10.0, 'A');

    // Print transactions
    printTransactions(head);

    return 0;
}