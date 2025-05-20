//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
    char description[50];  // Description of the expense
    float amount;         // Amount of the expense
    char date[11];        // Date of the expense (in the format "dd/mm/yyyy")
} Expense;

// Define the structure of the expense tracker
typedef struct {
    Expense expenses[MAX_EXPENSES];  // Array of expenses
    int num_expenses;                // Number of expenses in the tracker
} ExpenseTracker;

// Create a new expense tracker
ExpenseTracker* create_expense_tracker() {
    ExpenseTracker* tracker = (ExpenseTracker*)malloc(sizeof(ExpenseTracker));
    tracker->num_expenses = 0;
    return tracker;
}

// Add an expense to the tracker
void add_expense(ExpenseTracker* tracker, Expense expense) {
    if (tracker->num_expenses < MAX_EXPENSES) {
        tracker->expenses[tracker->num_expenses] = expense;
        tracker->num_expenses++;
    }
}

// Print the expenses in the tracker
void print_expenses(ExpenseTracker* tracker) {
    for (int i = 0; i < tracker->num_expenses; i++) {
        printf("%s: $%.2f (%s)\n", tracker->expenses[i].description, tracker->expenses[i].amount, tracker->expenses[i].date);
    }
}

// Calculate the total expenses in the tracker
float calculate_total_expenses(ExpenseTracker* tracker) {
    float total = 0;
    for (int i = 0; i < tracker->num_expenses; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

// Calculate the average expense in the tracker
float calculate_average_expense(ExpenseTracker* tracker) {
    if (tracker->num_expenses == 0) {
        return 0;
    }
    return calculate_total_expenses(tracker) / tracker->num_expenses;
}

// Find the most expensive expense in the tracker
Expense find_most_expensive_expense(ExpenseTracker* tracker) {
    Expense most_expensive_expense = tracker->expenses[0];
    for (int i = 1; i < tracker->num_expenses; i++) {
        if (tracker->expenses[i].amount > most_expensive_expense.amount) {
            most_expensive_expense = tracker->expenses[i];
        }
    }
    return most_expensive_expense;
}

// Find the least expensive expense in the tracker
Expense find_least_expensive_expense(ExpenseTracker* tracker) {
    Expense least_expensive_expense = tracker->expenses[0];
    for (int i = 1; i < tracker->num_expenses; i++) {
        if (tracker->expenses[i].amount < least_expensive_expense.amount) {
            least_expensive_expense = tracker->expenses[i];
        }
    }
    return least_expensive_expense;
}

// Sort the expenses in the tracker by amount in ascending order
void sort_expenses_by_amount(ExpenseTracker* tracker) {
    for (int i = 0; i < tracker->num_expenses - 1; i++) {
        for (int j = i + 1; j < tracker->num_expenses; j++) {
            if (tracker->expenses[i].amount > tracker->expenses[j].amount) {
                Expense temp = tracker->expenses[i];
                tracker->expenses[i] = tracker->expenses[j];
                tracker->expenses[j] = temp;
            }
        }
    }
}

// Sort the expenses in the tracker by date in ascending order
void sort_expenses_by_date(ExpenseTracker* tracker) {
    for (int i = 0; i < tracker->num_expenses - 1; i++) {
        for (int j = i + 1; j < tracker->num_expenses; j++) {
            if (strcmp(tracker->expenses[i].date, tracker->expenses[j].date) > 0) {
                Expense temp = tracker->expenses[i];
                tracker->expenses[i] = tracker->expenses[j];
                tracker->expenses[j] = temp;
            }
        }
    }
}

// Free the memory allocated for the expense tracker
void free_expense_tracker(ExpenseTracker* tracker) {
    free(tracker);
}

// Main function
int main() {
    // Create an expense tracker
    ExpenseTracker* tracker = create_expense_tracker();

    // Add some expenses to the tracker
    Expense expense1 = {"Groceries", 50.00, "01/01/2023"};
    Expense expense2 = {"Rent", 1000.00, "01/02/2023"};
    Expense expense3 = {"Utilities", 150.00, "01/03/2023"};
    Expense expense4 = {"Entertainment", 50.00, "01/04/2023"};
    Expense expense5 = {"Transportation", 200.00, "01/05/2023"};
    add_expense(tracker, expense1);
    add_expense(tracker, expense2);
    add_expense(tracker, expense3);
    add_expense(tracker, expense4);
    add_expense(tracker, expense5);

    // Print the expenses in the tracker
    printf("Expenses:\n");
    print_expenses(tracker);

    // Calculate the total expenses in the tracker
    float total_expenses = calculate_total_expenses(tracker);
    printf("Total expenses: $%.2f\n", total_expenses);

    // Calculate the average expense in the tracker
    float average_expense = calculate_average_expense(tracker);
    printf("Average expense: $%.2f\n", average_expense);

    // Find the most expensive expense in the tracker
    Expense most_expensive_expense = find_most_expensive_expense(tracker);
    printf("Most expensive expense: %s: $%.2f (%s)\n", most_expensive_expense.description, most_expensive_expense.amount, most_expensive_expense.date);

    // Find the least expensive expense in the tracker
    Expense least_expensive_expense = find_least_expensive_expense(tracker);
    printf("Least expensive expense: %s: $%.2f (%s)\n", least_expensive_expense.description, least_expensive_expense.amount, least_expensive_expense.date);

    // Sort the expenses in the tracker by amount in ascending order
    sort_expenses_by_amount(tracker);
    printf("Expenses sorted by amount:\n");
    print_expenses(tracker);

    // Sort the expenses in the tracker by date in ascending order
    sort_expenses_by_date(tracker);
    printf("Expenses sorted by date:\n");
    print_expenses(tracker);

    // Free the memory allocated for the expense tracker
    free_expense_tracker(tracker);

    return 0;
}