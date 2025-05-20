//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct expense {
    char description[100];
    float amount;
    char date[11]; // Format: "YYYY-MM-DD"
} expense_t;

// Define the structure of the expense tracker
typedef struct expense_tracker {
    expense_t expenses[MAX_EXPENSES];
    int num_expenses;
} expense_tracker_t;

// Create a new expense tracker
expense_tracker_t* create_expense_tracker() {
    expense_tracker_t* tracker = malloc(sizeof(expense_tracker_t));
    tracker->num_expenses = 0;
    return tracker;
}

// Add an expense to the tracker
void add_expense(expense_tracker_t* tracker, char* description, float amount, char* date) {
    if (tracker->num_expenses < MAX_EXPENSES) {
        strcpy(tracker->expenses[tracker->num_expenses].description, description);
        tracker->expenses[tracker->num_expenses].amount = amount;
        strcpy(tracker->expenses[tracker->num_expenses].date, date);
        tracker->num_expenses++;
    }
}

// Print the expenses in the tracker
void print_expenses(expense_tracker_t* tracker) {
    for (int i = 0; i < tracker->num_expenses; i++) {
        printf("%s: $%.2f (%s)\n", tracker->expenses[i].description, tracker->expenses[i].amount, tracker->expenses[i].date);
    }
}

// Calculate the total expenses in the tracker
float calculate_total_expenses(expense_tracker_t* tracker) {
    float total = 0;
    for (int i = 0; i < tracker->num_expenses; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

// Sort the expenses in the tracker by date
void sort_expenses_by_date(expense_tracker_t* tracker) {
    for (int i = 0; i < tracker->num_expenses - 1; i++) {
        for (int j = i + 1; j < tracker->num_expenses; j++) {
            if (strcmp(tracker->expenses[i].date, tracker->expenses[j].date) > 0) {
                expense_t temp = tracker->expenses[i];
                tracker->expenses[i] = tracker->expenses[j];
                tracker->expenses[j] = temp;
            }
        }
    }
}

// Free the memory allocated for the expense tracker
void free_expense_tracker(expense_tracker_t* tracker) {
    free(tracker);
}

int main() {
    // Create a new expense tracker
    expense_tracker_t* tracker = create_expense_tracker();

    // Add some expenses to the tracker
    add_expense(tracker, "Groceries", 100.00, "2023-03-01");
    add_expense(tracker, "Rent", 1200.00, "2023-03-05");
    add_expense(tracker, "Utilities", 150.00, "2023-03-10");
    add_expense(tracker, "Gas", 50.00, "2023-03-15");
    add_expense(tracker, "Entertainment", 100.00, "2023-03-20");

    // Print the expenses in the tracker
    printf("Expenses:\n");
    print_expenses(tracker);

    // Calculate the total expenses in the tracker
    float total_expenses = calculate_total_expenses(tracker);
    printf("Total expenses: $%.2f\n", total_expenses);

    // Sort the expenses in the tracker by date
    sort_expenses_by_date(tracker);

    // Print the sorted expenses in the tracker
    printf("Sorted expenses by date:\n");
    print_expenses(tracker);

    // Free the memory allocated for the expense tracker
    free_expense_tracker(tracker);

    return 0;
}