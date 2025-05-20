//FormAI DATASET v1.0 Category: Expense Tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size of expense description array
#define MAX_DESCRIPTION_SIZE 100

// Define structure for an expense record
struct Expense {
    char date[11];
    char description[MAX_DESCRIPTION_SIZE];
    float amount;
    struct Expense *next;
}; 

// Define function to add an expense record to the list
struct Expense *addExpenseRecord(struct Expense *list, char *date, char *desc, float amt) {
    // Create a new expense record
    struct Expense *newRecord = (struct Expense *)malloc(sizeof(struct Expense));

    // Copy data fields into new record
    strncpy(newRecord->date, date, sizeof(newRecord->date));
    strncpy(newRecord->description, desc, sizeof(newRecord->description));
    newRecord->amount = amt;

    // Set next pointer of new record to point to current head of list
    newRecord->next = list;

    // Return new node as head of list
    return newRecord;
}

// Define function to compute total expenses
float getTotalExpenses(struct Expense *list) {
    float totalExpenses = 0;
    while (list != NULL) {
        totalExpenses += list->amount;
        list = list->next;
    }
    return totalExpenses;
}

// Define function to output expense report in tabular format
void printExpenseReport(struct Expense *list) {
    printf("Date\tDescription\tAmount\n");
    while (list != NULL) {
        printf("%s\t%s\t%.2f\n", list->date, list->description, list->amount);
        list = list->next;
    }
}

// Main function
int main() {
    // Initialize list to NULL
    struct Expense *expenseList = NULL;

    // Add some dummy expense records to list
    expenseList = addExpenseRecord(expenseList, "2021/01/01", "Groceries", 75.40);
    expenseList = addExpenseRecord(expenseList, "2021/01/15", "Gasoline", 40.00);
    expenseList = addExpenseRecord(expenseList, "2021/01/23", "Dinner with friends", 80.00);

    // Output expense report and total expenses
    printExpenseReport(expenseList);
    printf("\nTotal expenses: $%.2f\n", getTotalExpenses(expenseList));

    // Free memory used by list
    struct Expense *current = expenseList;
    while (current != NULL) {
        struct Expense *next = current->next;
        free(current);
        current = next;
    }

    // Exit program
    return 0;
}