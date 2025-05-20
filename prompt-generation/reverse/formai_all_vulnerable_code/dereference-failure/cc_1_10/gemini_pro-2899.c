//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some funny expense categories
#define CATEGORY_FOOD "Bellyaching and bellydancing"
#define CATEGORY_DRINK "Liquid courage and bladder expansion"
#define CATEGORY_ENTERTAINMENT "Giggles and guffaws"
#define CATEGORY_TRANSPORT "Wheeling and dealing"
#define CATEGORY_OTHER "Hocus pocus and whatnots"

// Define a struct to represent an expense
typedef struct expense {
    char *description;
    float amount;
    char *category;
} expense_t;

// Create a new expense
expense_t *new_expense(char *description, float amount, char *category) {
    expense_t *e = malloc(sizeof(expense_t));
    e->description = strdup(description);
    e->amount = amount;
    e->category = strdup(category);
    return e;
}

// Print an expense
void print_expense(expense_t *e) {
    printf("%s: $%.2f (%s)\n", e->description, e->amount, e->category);
}

// Create an expense tracker
typedef struct expense_tracker {
    expense_t **expenses;
    int num_expenses;
} expense_tracker_t;

// Create a new expense tracker
expense_tracker_t *new_expense_tracker() {
    expense_tracker_t *et = malloc(sizeof(expense_tracker_t));
    et->expenses = NULL;
    et->num_expenses = 0;
    return et;
}

// Add an expense to an expense tracker
void add_expense(expense_tracker_t *et, expense_t *e) {
    et->expenses = realloc(et->expenses, (et->num_expenses + 1) * sizeof(expense_t *));
    et->expenses[et->num_expenses++] = e;
}

// Print an expense tracker
void print_expense_tracker(expense_tracker_t *et) {
    printf("Expense Tracker:\n");
    for (int i = 0; i < et->num_expenses; i++) {
        print_expense(et->expenses[i]);
    }
}

// Free an expense tracker
void free_expense_tracker(expense_tracker_t *et) {
    for (int i = 0; i < et->num_expenses; i++) {
        free(et->expenses[i]->description);
        free(et->expenses[i]->category);
        free(et->expenses[i]);
    }
    free(et->expenses);
    free(et);
}

// Main function
int main() {
    // Create an expense tracker
    expense_tracker_t *et = new_expense_tracker();

    // Add some expenses to the expense tracker
    add_expense(et, new_expense("Pizza and beer", 20.00, CATEGORY_FOOD));
    add_expense(et, new_expense("Movie tickets", 15.00, CATEGORY_ENTERTAINMENT));
    add_expense(et, new_expense("Gas for the car", 30.00, CATEGORY_TRANSPORT));
    add_expense(et, new_expense("New shoes", 50.00, CATEGORY_OTHER));

    // Print the expense tracker
    print_expense_tracker(et);

    // Free the expense tracker
    free_expense_tracker(et);

    return 0;
}