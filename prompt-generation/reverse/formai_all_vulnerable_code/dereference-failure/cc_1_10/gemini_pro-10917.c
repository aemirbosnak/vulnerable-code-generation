//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    double amount;
    char* category;
    struct Expense* next;
} Expense;

typedef struct {
    char* name;
    double total;
    Expense* expenses;
    struct Category* next;
} Category;

Category* categories = NULL;
Expense* expenses = NULL;

void add_expense(char* name, double amount, char* category) {
    // Create a new expense
    Expense* expense = malloc(sizeof(Expense));
    expense->name = strdup(name);
    expense->amount = amount;
    expense->category = strdup(category);
    expense->next = NULL;

    // Add the expense to the list of expenses
    if (expenses == NULL) {
        expenses = expense;
    } else {
        Expense* current_expense = expenses;
        while (current_expense->next != NULL) {
            current_expense = current_expense->next;
        }
        current_expense->next = expense;
    }

    // Update the total amount for the category
    Category* current_category = categories;
    while (current_category != NULL) {
        if (strcmp(current_category->name, category) == 0) {
            current_category->total += amount;
            break;
        }
        current_category = current_category->next;
    }

    // If the category does not exist, create a new one
    if (current_category == NULL) {
        Category* new_category = malloc(sizeof(Category));
        new_category->name = strdup(category);
        new_category->total = amount;
        new_category->expenses = expense;
        new_category->next = NULL;

        if (categories == NULL) {
            categories = new_category;
        } else {
            Category* current_category = categories;
            while (current_category->next != NULL) {
                current_category = current_category->next;
            }
            current_category->next = new_category;
        }
    }
}

void print_expenses() {
    Expense* current_expense = expenses;
    while (current_expense != NULL) {
        printf("%s: $%.2f (%s)\n", current_expense->name, current_expense->amount, current_expense->category);
        current_expense = current_expense->next;
    }
}

void print_categories() {
    Category* current_category = categories;
    while (current_category != NULL) {
        printf("%s: $%.2f\n", current_category->name, current_category->total);
        current_category = current_category->next;
    }
}

int main() {
    // Add some sample expenses
    add_expense("Groceries", 50.00, "Food");
    add_expense("Gas", 25.00, "Transportation");
    add_expense("Rent", 1000.00, "Housing");
    add_expense("Entertainment", 50.00, "Entertainment");

    // Print the expenses
    printf("Expenses:\n");
    print_expenses();

    // Print the categories
    printf("\nCategories:\n");
    print_categories();

    return 0;
}