//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float amount;
    struct account *next;
} account;

typedef struct {
    char title[50];
    float balance;
    account *head;
} budget;

void createAccount(account **head, char name[], float amount) {
    account *newAccount = (account *) malloc(sizeof(account));
    strcpy(newAccount->name, name);
    newAccount->amount = amount;
    newAccount->next = *head;
    *head = newAccount;
}

void printAccounts(account *head) {
    account *current = head;
    while (current != NULL) {
        printf("%s: %.2f\n", current->name, current->amount);
        current = current->next;
    }
}

void calculateBudget(budget *budget, char title[], float amount) {
    budget->balance += amount;
    createAccount(&(budget->head), title, amount);
}

void printBudget(budget *budget) {
    printf("\nBudget:\nTitle\tAmount\n--------------------\n");
    printAccounts(budget->head);
    printf("\nTotal Balance: %.2f\n", budget->balance);
}

int main() {
    budget myBudget = { .title = "My Budget", .balance = 0.0 };

    calculateBudget(&myBudget, "Groceries", 100.50);
    calculateBudget(&myBudget, "Gas", 50.00);
    calculateBudget(&myBudget, "Rent", 1000.00);

    printBudget(&myBudget);

    return 0;
}