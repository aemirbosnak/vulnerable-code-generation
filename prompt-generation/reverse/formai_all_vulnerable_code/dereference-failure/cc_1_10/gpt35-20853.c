//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an expense node
typedef struct ExpenseNode {
    int amount;
    char category[20];
    struct ExpenseNode* next;
} ExpenseNode;

// Define the structure for the expense tracker, which contains a head node
typedef struct ExpenseTracker {
    ExpenseNode* head;
    int count;
} ExpenseTracker;

// Function to add a new expense to the tracker
void addExpense(ExpenseTracker* tracker) {
    // Get the amount and category of the expense from the user
    int amount;
    char category[20];

    printf("Enter expense amount: ");
    scanf("%d", &amount);

    printf("Enter expense category: ");
    scanf("%s", &category);

    // Create a new expense node with the input data
    ExpenseNode* newExpense = (ExpenseNode*) malloc(sizeof(ExpenseNode));
    newExpense->amount = amount;
    strcpy(newExpense->category, category);
    newExpense->next = NULL;

    // If the tracker's head is NULL, set the head to the new expense node
    if(tracker->head == NULL) {
        tracker->head = newExpense;
    }
    // Otherwise, add the new expense node to the end of the list
    else {
        ExpenseNode* current = tracker->head;

        while(current->next != NULL) {
            current = current->next;
        }

        current->next = newExpense;
    }

    // Increment the count of expenses in the tracker
    tracker->count++;

    printf("Expense added successfully!\n");
}

// Function to print all expenses in the tracker
void printExpenses(ExpenseTracker* tracker) {
    // If the tracker is empty, print a message and return
    if(tracker->head == NULL) {
        printf("No expenses to display.\n");
        return;
    }

    // Otherwise, print each expense in the tracker
    ExpenseNode* current = tracker->head;

    printf("Expenses:\n");

    while(current != NULL) {
        printf("- %d (%s)\n", current->amount, current->category);
        current = current->next;
    }
}

// Function to delete all expenses in the tracker
void clearExpenses(ExpenseTracker* tracker) {
    // If the tracker is empty, print a message and return
    if(tracker->head == NULL) {
        printf("No expenses to clear.\n");
        return;
    }

    // Otherwise, delete each expense in the tracker
    ExpenseNode* current = tracker->head;

    while(current != NULL) {
        ExpenseNode* temp = current;
        current = current->next;
        free(temp);
    }

    // Set the tracker's head to NULL and reset the count of expenses
    tracker->head = NULL;
    tracker->count = 0;

    printf("Expenses cleared successfully!\n");
}

int main() {
    // Create a new expense tracker
    ExpenseTracker* tracker = (ExpenseTracker*) malloc(sizeof(ExpenseTracker));
    tracker->head = NULL;
    tracker->count = 0;

    // Display the main menu and prompt the user for input
    int choice = 0;

    while(choice != 4) {
        printf("\nExpense Tracker\n");
        printf("---------------\n");
        printf("1. Add expense\n");
        printf("2. Print expenses\n");
        printf("3. Clear expenses\n");
        printf("4. Exit\n\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addExpense(tracker);
                break;
            case 2:
                printExpenses(tracker);
                break;
            case 3:
                clearExpenses(tracker);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    // Free the memory occupied by the tracker
    clearExpenses(tracker);
    free(tracker);

    return 0;
}