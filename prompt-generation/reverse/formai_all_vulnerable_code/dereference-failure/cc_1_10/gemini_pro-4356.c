//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Transaction {
    char description[100];
    float amount;
    char type;  // 'I' for income, 'E' for expense
    struct Transaction *next;
};

struct Account {
    char name[100];
    float balance;
    struct Transaction *transactions;
};

struct PersonalFinancePlanner {
    struct Account accounts[10];
    int numAccounts;
    float totalIncome;
    float totalExpense;
};

struct PersonalFinancePlanner *createPersonalFinancePlanner() {
    struct PersonalFinancePlanner *planner = malloc(sizeof(struct PersonalFinancePlanner));
    planner->numAccounts = 0;
    planner->totalIncome = 0;
    planner->totalExpense = 0;
    return planner;
}

void addAccount(struct PersonalFinancePlanner *planner, char *name) {
    if (planner->numAccounts == 10) {
        printf("Error: Maximum number of accounts reached.\n");
        return;
    }
    strcpy(planner->accounts[planner->numAccounts].name, name);
    planner->accounts[planner->numAccounts].balance = 0;
    planner->accounts[planner->numAccounts].transactions = NULL;
    planner->numAccounts++;
}

void addTransaction(struct PersonalFinancePlanner *planner, char *accountName, char description[100], float amount, char type) {
    int i;
    for (i = 0; i < planner->numAccounts; i++) {
        if (strcmp(planner->accounts[i].name, accountName) == 0) {
            struct Transaction *newTransaction = malloc(sizeof(struct Transaction));
            strcpy(newTransaction->description, description);
            newTransaction->amount = amount;
            newTransaction->type = type;
            newTransaction->next = planner->accounts[i].transactions;
            planner->accounts[i].transactions = newTransaction;
            if (type == 'I') {
                planner->totalIncome += amount;
                planner->accounts[i].balance += amount;
            } else if (type == 'E') {
                planner->totalExpense += amount;
                planner->accounts[i].balance -= amount;
            }
            return;
        }
    }
    printf("Error: Account not found.\n");
}

void printPersonalFinancePlanner(struct PersonalFinancePlanner *planner) {
    int i;
    for (i = 0; i < planner->numAccounts; i++) {
        printf("Account: %s\n", planner->accounts[i].name);
        printf("  Balance: %.2f\n", planner->accounts[i].balance);
        struct Transaction *transaction = planner->accounts[i].transactions;
        while (transaction != NULL) {
            printf("    %s: %.2f\n", transaction->description, transaction->amount);
            transaction = transaction->next;
        }
    }
    printf("Total Income: %.2f\n", planner->totalIncome);
    printf("Total Expense: %.2f\n", planner->totalExpense);
}

int main() {
    struct PersonalFinancePlanner *planner = createPersonalFinancePlanner();
    addAccount(planner, "Checking");
    addAccount(planner, "Savings");
    addTransaction(planner, "Checking", "Salary", 2000, 'I');
    addTransaction(planner, "Checking", "Groceries", -100, 'E');
    addTransaction(planner, "Savings", "Interest", 20, 'I');
    addTransaction(planner, "Savings", "Transfer to Checking", -500, 'E');
    printPersonalFinancePlanner(planner);
    return 0;
}