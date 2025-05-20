//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    double amount;
} transaction;

typedef struct {
    char name[50];
    double balance;
    transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
} category;

typedef struct {
    category categories[MAX_CATEGORIES];
    int num_categories;
} personal_finance_planner;

personal_finance_planner* create_personal_finance_planner() {
    personal_finance_planner* planner = malloc(sizeof(personal_finance_planner));
    planner->num_categories = 0;
    return planner;
}

void add_category(personal_finance_planner* planner, char* name) {
    if (planner->num_categories >= MAX_CATEGORIES) {
        printf("Error: Maximum number of categories reached.\n");
        return;
    }
    strcpy(planner->categories[planner->num_categories].name, name);
    planner->categories[planner->num_categories].balance = 0.0;
    planner->categories[planner->num_categories].num_transactions = 0;
    planner->num_categories++;
}

void add_transaction(personal_finance_planner* planner, char* category, char* name, double amount) {
    int i;
    for (i = 0; i < planner->num_categories; i++) {
        if (strcmp(planner->categories[i].name, category) == 0) {
            if (planner->categories[i].num_transactions >= MAX_TRANSACTIONS) {
                printf("Error: Maximum number of transactions reached for category %s.\n", category);
                return;
            }
            strcpy(planner->categories[i].transactions[planner->categories[i].num_transactions].name, name);
            planner->categories[i].transactions[planner->categories[i].num_transactions].amount = amount;
            planner->categories[i].balance += amount;
            planner->categories[i].num_transactions++;
            return;
        }
    }
    printf("Error: Category %s not found.\n", category);
}

void print_personal_finance_planner(personal_finance_planner* planner) {
    int i, j;
    for (i = 0; i < planner->num_categories; i++) {
        printf("Category: %s\n", planner->categories[i].name);
        printf("Balance: %.2f\n", planner->categories[i].balance);
        printf("Transactions:\n");
        for (j = 0; j < planner->categories[i].num_transactions; j++) {
            printf("  %s: %.2f\n", planner->categories[i].transactions[j].name, planner->categories[i].transactions[j].amount);
        }
    }
}

int main() {
    personal_finance_planner* planner = create_personal_finance_planner();
    add_category(planner, "Income");
    add_category(planner, "Expenses");
    add_transaction(planner, "Income", "Salary", 2000.00);
    add_transaction(planner, "Expenses", "Rent", -500.00);
    add_transaction(planner, "Expenses", "Groceries", -100.00);
    add_transaction(planner, "Expenses", "Entertainment", -50.00);
    print_personal_finance_planner(planner);
    return 0;
}