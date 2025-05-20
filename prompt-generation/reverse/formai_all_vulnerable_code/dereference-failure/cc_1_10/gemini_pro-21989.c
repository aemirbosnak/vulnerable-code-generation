//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Expense type constants
#define EXPENSE_TYPE_FOOD 0
#define EXPENSE_TYPE_TRANSPORT 1
#define EXPENSE_TYPE_ENTERTAINMENT 2
#define EXPENSE_TYPE_OTHER 3

// Maintains a record of all expenses
typedef struct {
    char* description;
    double amount;
    int type;
} Expense;

// Maintains a list of all expenses
typedef struct {
    Expense* expenses;
    int num_expenses;
} ExpenseList;

// Initializes a new expense list
ExpenseList* expense_list_new() {
    ExpenseList* list = malloc(sizeof(ExpenseList));
    list->expenses = NULL;
    list->num_expenses = 0;
    return list;
}

// Frees the memory allocated for an expense list
void expense_list_free(ExpenseList* list) {
    for (int i = 0; i < list->num_expenses; i++) {
        free(list->expenses[i].description);
    }
    free(list->expenses);
    free(list);
}

// Adds an expense to an expense list
void expense_list_add(ExpenseList* list, const char* description, double amount, int type) {
    list->expenses = realloc(list->expenses, (list->num_expenses + 1) * sizeof(Expense));
    list->expenses[list->num_expenses].description = malloc(strlen(description) + 1);
    strcpy(list->expenses[list->num_expenses].description, description);
    list->expenses[list->num_expenses].amount = amount;
    list->expenses[list->num_expenses].type = type;
    list->num_expenses++;
}

// Prints the expenses in an expense list
void expense_list_print(ExpenseList* list) {
    for (int i = 0; i < list->num_expenses; i++) {
        printf("%s: $%.2f\n", list->expenses[i].description, list->expenses[i].amount);
    }
}

// Get total expenses for a given expense type
double expense_list_get_total_for_type(ExpenseList* list, int type) {
    double total = 0;
    for (int i = 0; i < list->num_expenses; i++) {
        if (list->expenses[i].type == type) {
            total += list->expenses[i].amount;
        }
    }
    return total;
}

// Main function
int main() {
    // Create a new expense list
    ExpenseList* list = expense_list_new();

    // Add some sample expenses
    expense_list_add(list, "Groceries", 100.00, EXPENSE_TYPE_FOOD);
    expense_list_add(list, "Gas", 50.00, EXPENSE_TYPE_TRANSPORT);
    expense_list_add(list, "Movie tickets", 20.00, EXPENSE_TYPE_ENTERTAINMENT);
    expense_list_add(list, "Other", 30.00, EXPENSE_TYPE_OTHER);

    // Print the expenses
    expense_list_print(list);

    // Get the total expenses for each type
    double food_total = expense_list_get_total_for_type(list, EXPENSE_TYPE_FOOD);
    double transport_total = expense_list_get_total_for_type(list, EXPENSE_TYPE_TRANSPORT);
    double entertainment_total = expense_list_get_total_for_type(list, EXPENSE_TYPE_ENTERTAINMENT);
    double other_total = expense_list_get_total_for_type(list, EXPENSE_TYPE_OTHER);

    // Print the totals
    printf("Food: $%.2f\n", food_total);
    printf("Transport: $%.2f\n", transport_total);
    printf("Entertainment: $%.2f\n", entertainment_total);
    printf("Other: $%.2f\n", other_total);

    // Free the memory allocated for the expense list
    expense_list_free(list);

    return 0;
}