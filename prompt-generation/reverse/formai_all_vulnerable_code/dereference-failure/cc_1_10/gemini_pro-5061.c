//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of an expense
typedef struct {
    char *description;
    float amount;
    int day;
    int month;
    int year;
} expense;

// Define the structure of a budget
typedef struct {
    float income;
    float expenses;
    float savings;
} budget;

// Create a new expense
expense *create_expense(char *description, float amount, int day, int month, int year) {
    expense *new_expense = (expense *)malloc(sizeof(expense));
    new_expense->description = (char *)malloc(strlen(description) + 1);
    strcpy(new_expense->description, description);
    new_expense->amount = amount;
    new_expense->day = day;
    new_expense->month = month;
    new_expense->year = year;
    return new_expense;
}

// Create a new budget
budget *create_budget(float income, float expenses, float savings) {
    budget *new_budget = (budget *)malloc(sizeof(budget));
    new_budget->income = income;
    new_budget->expenses = expenses;
    new_budget->savings = savings;
    return new_budget;
}

// Print an expense
void print_expense(expense *e) {
    printf("Description: %s\n", e->description);
    printf("Amount: %f\n", e->amount);
    printf("Date: %d/%d/%d\n", e->day, e->month, e->year);
}

// Print a budget
void print_budget(budget *b) {
    printf("Income: %f\n", b->income);
    printf("Expenses: %f\n", b->expenses);
    printf("Savings: %f\n", b->savings);
}

// Main function
int main() {
    // Create a few expenses
    expense *e1 = create_expense("Rent", 1000, 1, 1, 2023);
    expense *e2 = create_expense("Groceries", 200, 15, 1, 2023);
    expense *e3 = create_expense("Entertainment", 100, 20, 1, 2023);

    // Create a budget
    budget *b = create_budget(3000, 1300, 1700);

    // Print the expenses and budget
    printf("Expenses:\n");
    print_expense(e1);
    print_expense(e2);
    print_expense(e3);
    printf("\nBudget:\n");
    print_budget(b);

    // Free the memory allocated for the expenses and budget
    free(e1->description);
    free(e1);
    free(e2->description);
    free(e2);
    free(e3->description);
    free(e3);
    free(b);

    return 0;
}