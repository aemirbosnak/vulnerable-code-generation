//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define expense categories
enum category {
    FOOD,
    TRANSPORTATION,
    ENTERTAINMENT,
    OTHER
};

// Define expense structure
struct expense {
    char description[50];
    enum category category;
    double amount;
};

// Create a new expense
struct expense *new_expense(char *description, enum category category, double amount) {
    struct expense *e = (struct expense *)malloc(sizeof(struct expense));
    strcpy(e->description, description);
    e->category = category;
    e->amount = amount;
    return e;
}

// Print an expense
void print_expense(struct expense *e) {
    printf("%s: %s - %.2f\n", e->description, e->category == FOOD ? "Food" : e->category == TRANSPORTATION ? "Transportation" : e->category == ENTERTAINMENT ? "Entertainment" : "Other", e->amount);
}

// Compare two expenses by amount
int compare_expenses(const void *a, const void *b) {
    struct expense *e1 = (struct expense *)a;
    struct expense *e2 = (struct expense *)b;
    return e1->amount - e2->amount;
}

// Main function
int main() {
    // Create an array of expenses
    struct expense expenses[] = {
        new_expense("Groceries", FOOD, 100),
        new_expense("Gas", TRANSPORTATION, 50),
        new_expense("Movie tickets", ENTERTAINMENT, 30),
        new_expense("Other", OTHER, 20)
    };

    // Sort the expenses by amount
    qsort(expenses, 4, sizeof(struct expense), compare_expenses);

    // Print the sorted expenses
    for (int i = 0; i < 4; i++) {
        print_expense(&expenses[i]);
    }

    return 0;
}