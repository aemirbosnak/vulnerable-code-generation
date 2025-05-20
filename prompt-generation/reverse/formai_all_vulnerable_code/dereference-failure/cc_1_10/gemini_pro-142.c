//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

typedef struct account {
    char *name;
    double balance;
} account_t;

typedef struct budget_item {
    char *name;
    double amount;
} budget_item_t;

typedef struct budget {
    char *name;
    double total_amount;
    budget_item_t *items;
    int num_items;
} budget_t;

typedef struct planner {
    account_t *accounts;
    int num_accounts;
    budget_t *budgets;
    int num_budgets;
} planner_t;

// Function to create a new planner
planner_t *create_planner() {
    planner_t *planner = malloc(sizeof(planner_t));
    planner->accounts = NULL;
    planner->num_accounts = 0;
    planner->budgets = NULL;
    planner->num_budgets = 0;
    return planner;
}

// Function to add an account to a planner
void add_account(planner_t *planner, char *name, double balance) {
    planner->accounts = realloc(planner->accounts, (planner->num_accounts + 1) * sizeof(account_t));
    planner->accounts[planner->num_accounts].name = name;
    planner->accounts[planner->num_accounts].balance = balance;
    planner->num_accounts++;
}

// Function to add a budget to a planner
void add_budget(planner_t *planner, char *name, double total_amount) {
    planner->budgets = realloc(planner->budgets, (planner->num_budgets + 1) * sizeof(budget_t));
    planner->budgets[planner->num_budgets].name = name;
    planner->budgets[planner->num_budgets].total_amount = total_amount;
    planner->budgets[planner->num_budgets].items = NULL;
    planner->budgets[planner->num_budgets].num_items = 0;
    planner->num_budgets++;
}

// Function to add a budget item to a budget
void add_budget_item(budget_t *budget, char *name, double amount) {
    budget->items = realloc(budget->items, (budget->num_items + 1) * sizeof(budget_item_t));
    budget->items[budget->num_items].name = name;
    budget->items[budget->num_items].amount = amount;
    budget->num_items++;
}

// Function to print a planner
void print_planner(planner_t *planner) {
    printf("Accounts:\n");
    for (int i = 0; i < planner->num_accounts; i++) {
        printf("  - %s: $%.2f\n", planner->accounts[i].name, planner->accounts[i].balance);
    }

    printf("\nBudgets:\n");
    for (int i = 0; i < planner->num_budgets; i++) {
        printf("  - %s: $%.2f\n", planner->budgets[i].name, planner->budgets[i].total_amount);
        for (int j = 0; j < planner->budgets[i].num_items; j++) {
            printf("    - %s: $%.2f\n", planner->budgets[i].items[j].name, planner->budgets[i].items[j].amount);
        }
    }
}

// Function to free the memory allocated for a planner
void free_planner(planner_t *planner) {
    for (int i = 0; i < planner->num_accounts; i++) {
        free(planner->accounts[i].name);
    }
    free(planner->accounts);

    for (int i = 0; i < planner->num_budgets; i++) {
        free(planner->budgets[i].name);
        for (int j = 0; j < planner->budgets[i].num_items; j++) {
            free(planner->budgets[i].items[j].name);
        }
        free(planner->budgets[i].items);
    }
    free(planner->budgets);

    free(planner);
}

int main() {
    // Create a new planner
    planner_t *planner = create_planner();

    // Add some accounts to the planner
    add_account(planner, "Checking", 1000.00);
    add_account(planner, "Savings", 2000.00);

    // Add some budgets to the planner
    add_budget(planner, "Groceries", 300.00);
    add_budget(planner, "Entertainment", 100.00);

    // Add some budget items to the budgets
    add_budget_item(planner->budgets, "Food", 200.00);
    add_budget_item(planner->budgets, "Toiletries", 50.00);
    add_budget_item(planner->budgets, "Movies", 75.00);
    add_budget_item(planner->budgets, "Concerts", 25.00);

    // Print the planner
    print_planner(planner);

    // Free the memory allocated for the planner
    free_planner(planner);

    return 0;
}