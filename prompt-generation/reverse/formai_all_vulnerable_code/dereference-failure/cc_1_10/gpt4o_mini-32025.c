//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense *expenses;
    int size;
    int capacity;
} ExpenseTracker;

// Function prototypes
ExpenseTracker* createTracker();
void addExpense(ExpenseTracker *tracker, const char *description, float amount);
void viewExpenses(const ExpenseTracker *tracker);
void deleteExpense(ExpenseTracker *tracker, int index);
void freeTracker(ExpenseTracker *tracker);

int main() {
    ExpenseTracker *tracker = createTracker();
    int choice;
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;

    while (1) {
        printf("\n*** Expense Tracker ***\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline

        switch (choice) {
            case 1:
                printf("Enter description: ");
                fgets(description, MAX_DESCRIPTION_LENGTH, stdin);
                // Remove newline character from description
                description[strcspn(description, "\n")] = 0;

                printf("Enter amount: ");
                scanf("%f", &amount);
                addExpense(tracker, description, amount);
                break;

            case 2:
                viewExpenses(tracker);
                break;

            case 3:
                printf("Enter the index of expense to delete: ");
                int index;
                scanf("%d", &index);
                deleteExpense(tracker, index);
                break;

            case 4:
                freeTracker(tracker);
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

ExpenseTracker* createTracker() {
    ExpenseTracker *tracker = (ExpenseTracker *)malloc(sizeof(ExpenseTracker));
    tracker->size = 0;
    tracker->capacity = 2; // Initial capacity
    tracker->expenses = (Expense *)malloc(tracker->capacity * sizeof(Expense));
    return tracker;
}

void addExpense(ExpenseTracker *tracker, const char *description, float amount) {
    if (tracker->size == tracker->capacity) {
        tracker->capacity *= 2;  // Double the capacity
        tracker->expenses = (Expense *)realloc(tracker->expenses, tracker->capacity * sizeof(Expense));
    }
    strncpy(tracker->expenses[tracker->size].description, description, MAX_DESCRIPTION_LENGTH);
    tracker->expenses[tracker->size].amount = amount;
    tracker->size++;
    printf("Expense added: %s - $%.2f\n", description, amount);
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->size == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("\nExpenses:\n");
    for (int i = 0; i < tracker->size; i++) {
        printf("%d: %s - $%.2f\n", i, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
}

void deleteExpense(ExpenseTracker *tracker, int index) {
    if (index < 0 || index >= tracker->size) {
        printf("Invalid index. Please try again.\n");
        return;
    }
    printf("Deleting expense: %s - $%.2f\n", tracker->expenses[index].description, tracker->expenses[index].amount);
    for (int i = index; i < tracker->size - 1; i++) {
        tracker->expenses[i] = tracker->expenses[i + 1]; // Shift left
    }
    tracker->size--;
}

void freeTracker(ExpenseTracker *tracker) {
    free(tracker->expenses);
    free(tracker);
    printf("Expense Tracker freed.\n");
}