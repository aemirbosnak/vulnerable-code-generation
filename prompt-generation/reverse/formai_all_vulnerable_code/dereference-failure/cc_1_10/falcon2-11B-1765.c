//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

struct account {
    char name[20];
    int balance;
};

void deposit(struct account* account, double amount) {
    if (amount > 0) {
        account->balance += amount;
    } else {
        printf("Invalid deposit amount\n");
    }
}

void withdraw(struct account* account, double amount) {
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

int check_balance(struct account* account) {
    printf("Account balance: %d\n", account->balance);
    return 0;
}

void print_account_info(struct account* account) {
    printf("Account name: %s\n", account->name);
    printf("Account balance: %d\n", account->balance);
}

void calculate_interest(struct account* account, double interest_rate) {
    account->balance *= (1 + interest_rate);
}

void print_monthly_expenses_and_income(struct account* account) {
    printf("Monthly expenses:\n");
    printf("Food: $500\n");
    printf("Housing: $1000\n");
    printf("Transportation: $200\n");
    printf("Utilities: $150\n");
    printf("Entertainment: $200\n");
    printf("Total expenses: $2050\n");
    printf("Monthly income:\n");
    printf("Salary: $5000\n");
    printf("Total income: $5000\n");
}

int calculate_monthly_net_income(struct account* account) {
    double income = 5000;
    double expenses = 2050;
    double net_income = income - expenses;
    printf("Monthly net income: $%.2f\n", net_income);
    return 0;
}

int main() {
    struct account* account = (struct account*)malloc(sizeof(struct account));
    strcpy(account->name, "John Doe");
    account->balance = 1000;

    deposit(account, 2000);
    withdraw(account, 500);
    check_balance(account);
    print_account_info(account);
    calculate_interest(account, 0.05);
    print_account_info(account);
    print_monthly_expenses_and_income(account);
    calculate_monthly_net_income(account);

    free(account);

    return 0;
}