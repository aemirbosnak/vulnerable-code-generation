//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 255
#define MAX_TRANS_LEN 20

typedef struct Transaction {
    char name[MAX_NAME_LEN];
    double amount;
    char type;
    struct Transaction* next;
} Transaction;

int main() {
    // Create a linked list of transactions
    Transaction* head = NULL;
    Transaction* tail = NULL;

    // Get the user's name and create a new transaction
    char name[MAX_NAME_LEN];
    printf("What is your name? ");
    scanf("%s", name);

    Transaction* new_trans = malloc(sizeof(Transaction));
    new_trans->name[0] = '\0';
    strcpy(new_trans->name, name);

    new_trans->amount = 0.0;
    printf("What is the amount of the transaction? ");
    scanf("%lf", &new_trans->amount);

    new_trans->type = ' ';
    printf("What is the type of transaction (C/D/R)? ");
    scanf(" %c", &new_trans->type);

    // Add the new transaction to the linked list
    if (head == NULL) {
        head = new_trans;
        tail = new_trans;
    } else {
        tail->next = new_trans;
        tail = new_trans;
    }

    // Print the list of transactions
    printf("Your transactions:\n");
    for (Transaction* current = head; current; current = current->next) {
        printf("Name: %s, Amount: %.2lf, Type: %c\n", current->name, current->amount, current->type);
    }

    return 0;
}