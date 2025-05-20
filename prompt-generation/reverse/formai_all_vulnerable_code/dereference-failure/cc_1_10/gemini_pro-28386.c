//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the expense structure
typedef struct {
    char description[50];
    float amount;
    char category[20];
    char date[11];
} Expense;

// Declare the expense list structure
typedef struct {
    Expense expenses[100];
    int num_expenses;
} ExpenseList;

// Create a new expense
Expense *new_expense(char *description, float amount, char *category, char *date) {
    Expense *expense = malloc(sizeof(Expense));
    strcpy(expense->description, description);
    expense->amount = amount;
    strcpy(expense->category, category);
    strcpy(expense->date, date);
    return expense;
}

// Add an expense to the expense list
void add_expense(ExpenseList *list, Expense *expense) {
    list->expenses[list->num_expenses] = *expense;
    list->num_expenses++;
}

// Print the expense list
void print_expense_list(ExpenseList *list) {
    printf("Expense List:\n");
    for (int i = 0; i < list->num_expenses; i++) {
        printf("  %s: $%.2f (%s, %s)\n",
            list->expenses[i].description,
            list->expenses[i].amount,
            list->expenses[i].category,
            list->expenses[i].date);
    }
}

// Get the total expenses
float get_total_expenses(ExpenseList *list) {
    float total = 0;
    for (int i = 0; i < list->num_expenses; i++) {
        total += list->expenses[i].amount;
    }
    return total;
}

// Main function
int main() {
    // Create a new expense list
    ExpenseList *list = malloc(sizeof(ExpenseList));
    list->num_expenses = 0;

    // Add some expenses to the list
    add_expense(list, new_expense("Groceries", 50.00, "Food", "2023-03-08"));
    add_expense(list, new_expense("Gas", 25.00, "Transportation", "2023-03-10"));
    add_expense(list, new_expense("Entertainment", 10.00, "Entertainment", "2023-03-12"));

    // Print the expense list
    print_expense_list(list);

    // Get the total expenses
    float total = get_total_expenses(list);

    // Print the total expenses
    printf("Total expenses: $%.2f\n", total);

    return 0;
}