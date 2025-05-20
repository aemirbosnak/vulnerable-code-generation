//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

typedef struct Transaction
{
    char name[50];
    int amount;
    char type;
    struct Transaction* next;
} Transaction;

Transaction* insertTransaction(Transaction* head, char* name, int amount, char type)
{
    Transaction* newTransaction = (Transaction*)malloc(sizeof(Transaction));
    strcpy(newTransaction->name, name);
    newTransaction->amount = amount;
    newTransaction->type = type;
    newTransaction->next = NULL;

    if (head == NULL)
    {
        head = newTransaction;
    }
    else
    {
        head->next = newTransaction;
    }

    return head;
}

void printTransactions(Transaction* head)
{
    while (head)
    {
        printf("%s: %d, %c\n", head->name, head->amount, head->type);
        head = head->next;
    }
}

int main()
{
    Transaction* head = NULL;

    insertTransaction(head, "John Doe", 100, 'D');
    insertTransaction(head, "Jane Doe", 200, 'W');
    insertTransaction(head, "Bill Smith", 50, 'T');

    printTransactions(head);

    return 0;
}