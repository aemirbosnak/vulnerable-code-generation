//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define the expense categories
enum expense_category {
    FUN,
    FOOD,
    RENT,
    UTILITIES,
    TRANSPORTATION,
    OTHER
};

// Define the list of expense categories
const char *expense_categories[] = {
    "Fun",
    "Food",
    "Rent",
    "Utilities",
    "Transportation",
    "Other"
};

// Define the expense structure
struct expense {
    enum expense_category category;
    float amount;
    char *description;
};

// Function to create a new expense
struct expense *create_expense(enum expense_category category, float amount, char *description) {
    struct expense *new_expense = (struct expense *)malloc(sizeof(struct expense));
    new_expense->category = category;
    new_expense->amount = amount;
    new_expense->description = description;
    return new_expense;
}

// Function to print an expense
void print_expense(struct expense *expense) {
    printf("Category: %s\n", expense_categories[expense->category]);
    printf("Amount: $%.2f\n", expense->amount);
    printf("Description: %s\n\n", expense->description);
}

// Function to add an expense to a list of expenses
void add_expense(struct expense **expenses, int *num_expenses, struct expense *new_expense) {
    expenses[*num_expenses] = new_expense;
    (*num_expenses)++;
}

// Function to sort expenses by category
void sort_expenses_by_category(struct expense **expenses, int num_expenses) {
    // Bubble sort expenses by category
    for (int i = 0; i < num_expenses - 1; i++) {
        for (int j = 0; j < num_expenses - 1 - i; j++) {
            if (expenses[j]->category > expenses[j + 1]->category) {
                struct expense *temp = expenses[j];
                expenses[j] = expenses[j + 1];
                expenses[j + 1] = temp;
            }
        }
    }
}

// Function to print a list of expenses
void print_expenses(struct expense **expenses, int num_expenses) {
    for (int i = 0; i < num_expenses; i++) {
        print_expense(expenses[i]);
    }
}

// Function to free the memory allocated for a list of expenses
void free_expenses(struct expense **expenses, int num_expenses) {
    for (int i = 0; i < num_expenses; i++) {
        free(expenses[i]);
    }
    free(expenses);
}

int main() {
    // Create a list of expenses
    struct expense *expenses[100];
    int num_expenses = 0;

    // Add some expenses to the list
    add_expense(expenses, &num_expenses, create_expense(FUN, 20.00, "Tickets to the circus"));
    add_expense(expenses, &num_expenses, create_expense(FOOD, 10.00, "Groceries for the week"));
    add_expense(expenses, &num_expenses, create_expense(RENT, 1000.00, "Monthly rent payment"));
    add_expense(expenses, &num_expenses, create_expense(UTILITIES, 150.00, "Electric, gas, and water bills"));
    add_expense(expenses, &num_expenses, create_expense(TRANSPORTATION, 50.00, "Gas for the car"));
    add_expense(expenses, &num_expenses, create_expense(OTHER, 25.00, "New shoes"));

    // Sort the expenses by category
    sort_expenses_by_category(expenses, num_expenses);

    // Print the list of expenses
    print_expenses(expenses, num_expenses);

    // Free the memory allocated for the list of expenses
    free_expenses(expenses, num_expenses);

    return 0;
}