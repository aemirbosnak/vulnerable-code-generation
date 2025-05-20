//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *description;
    float amount;
    time_t date;
} Expense;

static Expense *expenses; // Array of expenses
static int num_expenses;   // Number of expenses

void add_expense(char *description, float amount) {
    expenses = realloc(expenses, sizeof(Expense) * (num_expenses + 1));
    expenses[num_expenses].description = malloc(strlen(description) + 1);
    strcpy(expenses[num_expenses].description, description);
    expenses[num_expenses].amount = amount;
    expenses[num_expenses].date = time(NULL);
    num_expenses++;
}

void print_expenses() {
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f\n", expenses[i].description, expenses[i].amount);
    }
}

void free_expenses() {
    for (int i = 0; i < num_expenses; i++) {
        free(expenses[i].description);
    }
    free(expenses);
}

int main() {
    // Add some sample expenses
    add_expense("Groceries", 100);
    add_expense("Rent", 1200);
    add_expense("Utilities", 200);
    add_expense("Entertainment", 100);

    // Print the expenses
    print_expenses();

    // Free the memory
    free_expenses();

    return 0;
}