//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 10

struct Transaction {
    char name[50];
    double amount;
    char type;
    struct Transaction* next;
};

struct Budget {
    double income;
    double expenses;
    struct Transaction* transactions;
};

void addTransaction(struct Budget* budget, char* name, double amount, char type) {
    struct Transaction* newTransaction = (struct Transaction*)malloc(sizeof(struct Transaction));

    strcpy(newTransaction->name, name);
    newTransaction->amount = amount;
    newTransaction->type = type;

    if (budget->transactions == NULL) {
        budget->transactions = newTransaction;
    } else {
        budget->transactions->next = newTransaction;
    }
}

void calculateBudget(struct Budget* budget) {
    budget->income = 0;
    budget->expenses = 0;

    struct Transaction* transaction = budget->transactions;

    while (transaction) {
        if (transaction->type == 'I') {
            budget->income += transaction->amount;
        } else if (transaction->type == 'E') {
            budget->expenses += transaction->amount;
        }
        transaction = transaction->next;
    }
}

void printBudget(struct Budget* budget) {
    printf("Income: $%.2lf\n", budget->income);
    printf("Expenses: $%.2lf\n", budget->expenses);
    printf("Balance: $%.2lf\n", budget->income - budget->expenses);

    struct Transaction* transaction = budget->transactions;

    printf("Transactions:\n");

    while (transaction) {
        printf("%s: $%.2lf (%c)\n", transaction->name, transaction->amount, transaction->type);
        transaction = transaction->next;
    }
}

int main() {
    struct Budget* budget = (struct Budget*)malloc(sizeof(struct Budget));

    addTransaction(budget, "Salary", 5000.0, 'I');
    addTransaction(budget, "Rent", 1000.0, 'E');
    addTransaction(budget, "Groceries", 500.0, 'E');
    addTransaction(budget, "Eating out", 200.0, 'E');

    calculateBudget(budget);

    printBudget(budget);

    return 0;
}