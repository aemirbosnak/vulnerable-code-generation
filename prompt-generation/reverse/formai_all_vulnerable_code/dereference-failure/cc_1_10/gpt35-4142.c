//FormAI DATASET v1.0 Category: Expense Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TITLE_SIZE 50
#define MAX_CATEGORY_SIZE 20

// a structure to hold individual expense records
struct ExpenseRecord {
    char title[MAX_TITLE_SIZE];
    char category[MAX_CATEGORY_SIZE];
    double amount;
};

// a structure to hold the expense list
struct ExpenseTracker {
    int size;
    struct ExpenseRecord *list;
};

// function prototypes
void addExpenseAsync(struct ExpenseTracker *tracker);
void displayExpensesAsync(struct ExpenseTracker *tracker);
void filterExpensesAsync(struct ExpenseTracker *tracker);

// main function
int main() {
    // create an empty expense tracker
    struct ExpenseTracker tracker = {0, NULL};
    
    while (true) {
        // print options to the user
        printf("\nWhat would you like to do?\n");
        printf("  [1] Add an Expense\n");
        printf("  [2] Display all Expenses\n");
        printf("  [3] Filter Expenses by Category\n");
        printf("  [4] Exit\n");
        printf("> ");
        
        // get user input
        int option;
        scanf("%d", &option);
        
        // perform the selected action
        switch (option) {
            case 1: // add an expense
                addExpenseAsync(&tracker);
                break;
            case 2: // display all expenses
                displayExpensesAsync(&tracker);
                break;
            case 3: // filter expenses by category
                filterExpensesAsync(&tracker);
                break;
            case 4: // exit
                printf("\nThank you for using Expense Tracker. Goodbye!\n");
                exit(0);
            default: // invalid option
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    }
}

// a function to add a new expense record to the tracker
void addExpenseAsync(struct ExpenseTracker *tracker) {
    // allocate memory for a new expense record
    struct ExpenseRecord *record = (struct ExpenseRecord *) malloc(sizeof(struct ExpenseRecord));
    
    // get user input for the record fields
    printf("\nEnter Expense Title: ");
    scanf("%s", record->title);
    printf("Enter Expense Category: ");
    scanf("%s", record->category);
    printf("Enter Expense Amount: ");
    scanf("%lf", &record->amount);
    
    // add the record to the tracker
    tracker->size++;
    tracker->list = (struct ExpenseRecord *) realloc(tracker->list, tracker->size * sizeof(struct ExpenseRecord));
    tracker->list[tracker->size-1] = *record;
    
    // free memory allocated for the new record
    free(record);
    
    printf("\nExpense added successfully.\n");
}

// a function to display all expense records in the tracker
void displayExpensesAsync(struct ExpenseTracker *tracker) {
    printf("\nExpenses:\n");
    for (int i = 0; i < tracker->size; i++) {
        printf("%d. Title: %s | Category: %s | Amount: %.2lf\n", i+1, tracker->list[i].title, tracker->list[i].category, tracker->list[i].amount);
    }
}

// a function to filter and display expense records by category
void filterExpensesAsync(struct ExpenseTracker *tracker) {
    // get user input for the category to filter by
    char category[MAX_CATEGORY_SIZE];
    printf("\nEnter Category to Filter by: ");
    scanf("%s", category);
    
    // display only expense records with matching categories
    printf("\nExpenses in Category \"%s\":\n", category);
    int count = 0;
    for (int i = 0; i < tracker->size; i++) {
        if (strcmp(tracker->list[i].category, category) == 0) {
            printf("%d. Title: %s | Category: %s | Amount: %.2lf\n", count+1, tracker->list[i].title, tracker->list[i].category, tracker->list[i].amount);
            count++;
        }
    }
    if (count == 0) {
        printf("No expenses found in Category \"%s\".\n", category);
    }
}