//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct transaction {
    char *description;
    float amount;
    int day;
    int month;
    int year;
};

struct account {
    char *name;
    float balance;
    struct transaction *transactions;
    int num_transactions;
};

struct budget {
    char *category;
    float amount;
};

int main() {
    struct account checking;
    checking.name = "Checking";
    checking.balance = 1000.00;
    checking.transactions = malloc(sizeof(struct transaction) * 10);
    checking.num_transactions = 0;

    struct account savings;
    savings.name = "Savings";
    savings.balance = 500.00;
    savings.transactions = malloc(sizeof(struct transaction) * 10);
    savings.num_transactions = 0;

    struct budget food;
    food.category = "Food";
    food.amount = 200.00;

    struct budget entertainment;
    entertainment.category = "Entertainment";
    entertainment.amount = 100.00;

    // Add a transaction to the checking account
    struct transaction transaction;
    transaction.description = "Groceries";
    transaction.amount = -50.00;
    transaction.day = 1;
    transaction.month = 1;
    transaction.year = 2023;

    checking.transactions[checking.num_transactions++] = transaction;

    // Print the checking account balance
    printf("Checking account balance: $%.2f\n", checking.balance);

    // Print the food budget
    printf("Food budget: $%.2f\n", food.amount);

    return 0;
}