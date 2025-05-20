//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct {
    char *name;
    double balance;
} Account;

typedef struct {
    char *name;
    double income;
    double expenses;
} Budget;

// Functions
Account* create_account(char *name, double balance);
Budget* create_budget(char *name, double income, double expenses);
void print_account(Account *account);
void print_budget(Budget *budget);
void add_transaction(Account *account, double amount, char *description);
void add_income(Budget *budget, double amount, char *source);
void add_expense(Budget *budget, double amount, char *category);
void generate_report(Account *account, Budget *budget);

// Main function
int main() {
    // Create an account
    Account *account = create_account("My Account", 1000.00);

    // Create a budget
    Budget *budget = create_budget("My Budget", 2000.00, 1500.00);

    // Add some transactions
    add_transaction(account, 500.00, "Paycheck");
    add_transaction(account, -200.00, "Rent");
    add_transaction(account, -100.00, "Groceries");

    // Add some income
    add_income(budget, 500.00, "Paycheck");
    add_income(budget, 200.00, "Side hustle");

    // Add some expenses
    add_expense(budget, 200.00, "Rent");
    add_expense(budget, 100.00, "Groceries");
    add_expense(budget, 50.00, "Entertainment");

    // Generate a report
    generate_report(account, budget);

    // Free memory
    free(account->name);
    free(account);
    free(budget->name);
    free(budget);

    return 0;
}

// Function definitions
Account* create_account(char *name, double balance) {
    Account *account = malloc(sizeof(Account));
    account->name = malloc(strlen(name) + 1);
    strcpy(account->name, name);
    account->balance = balance;
    return account;
}

Budget* create_budget(char *name, double income, double expenses) {
    Budget *budget = malloc(sizeof(Budget));
    budget->name = malloc(strlen(name) + 1);
    strcpy(budget->name, name);
    budget->income = income;
    budget->expenses = expenses;
    return budget;
}

void print_account(Account *account) {
    printf("Account: %s\n", account->name);
    printf("Balance: $%.2f\n", account->balance);
}

void print_budget(Budget *budget) {
    printf("Budget: %s\n", budget->name);
    printf("Income: $%.2f\n", budget->income);
    printf("Expenses: $%.2f\n", budget->expenses);
}

void add_transaction(Account *account, double amount, char *description) {
    account->balance += amount;
    printf("Transaction: $%.2f (%s)\n", amount, description);
}

void add_income(Budget *budget, double amount, char *source) {
    budget->income += amount;
    printf("Income: $%.2f (%s)\n", amount, source);
}

void add_expense(Budget *budget, double amount, char *category) {
    budget->expenses += amount;
    printf("Expense: $%.2f (%s)\n", amount, category);
}

void generate_report(Account *account, Budget *budget) {
    printf("\nPersonal Finance Report\n");
    print_account(account);
    print_budget(budget);
    double net_income = budget->income - budget->expenses;
    printf("Net income: $%.2f\n", net_income);
    double savings_rate = net_income / budget->income;
    printf("Savings rate: %.2f%%\n", savings_rate * 100);
}