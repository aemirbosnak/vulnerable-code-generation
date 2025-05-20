//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: sophisticated
// Sophisticated Personal Finance Planner in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structs for expenses, income, and user data
typedef struct {
    char* name;
    float amount;
} Expense;

typedef struct {
    char* name;
    float amount;
} Income;

typedef struct {
    char* name;
    Expense* expenses;
    int numExpenses;
    Income* incomes;
    int numIncomes;
} User;

// Function to create a new user
User* create_user(char* name) {
    User* user = malloc(sizeof(User));
    user->name = strdup(name);
    user->expenses = malloc(0);
    user->numExpenses = 0;
    user->incomes = malloc(0);
    user->numIncomes = 0;
    return user;
}

// Function to add an expense to a user
void add_expense(User* user, char* name, float amount) {
    user->expenses = realloc(user->expenses, (user->numExpenses + 1) * sizeof(Expense));
    user->expenses[user->numExpenses].name = strdup(name);
    user->expenses[user->numExpenses].amount = amount;
    user->numExpenses++;
}

// Function to add an income to a user
void add_income(User* user, char* name, float amount) {
    user->incomes = realloc(user->incomes, (user->numIncomes + 1) * sizeof(Income));
    user->incomes[user->numIncomes].name = strdup(name);
    user->incomes[user->numIncomes].amount = amount;
    user->numIncomes++;
}

// Function to print a user's financial summary
void print_summary(User* user) {
    float totalExpenses = 0;
    float totalIncomes = 0;
    float balance = 0;

    // Calculate total expenses
    for (int i = 0; i < user->numExpenses; i++) {
        totalExpenses += user->expenses[i].amount;
    }

    // Calculate total incomes
    for (int i = 0; i < user->numIncomes; i++) {
        totalIncomes += user->incomes[i].amount;
    }

    // Calculate balance
    balance = totalIncomes - totalExpenses;

    // Print summary
    printf("Financial Summary for %s:\n", user->name);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Total Incomes: $%.2f\n", totalIncomes);
    printf("Balance: $%.2f\n", balance);
}

// Main function
int main() {
    // Create a new user
    User* user = create_user("John Doe");

    // Add some expenses
    add_expense(user, "Rent", 1000);
    add_expense(user, "Utilities", 200);
    add_expense(user, "Groceries", 300);

    // Add some incomes
    add_income(user, "Salary", 5000);
    add_income(user, "Investments", 1000);

    // Print the user's financial summary
    print_summary(user);

    return 0;
}