//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define DESC_LENGTH 50

typedef struct {
    char description[DESC_LENGTH];
    float amount;
    char category[DESC_LENGTH];
} Expense;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    int count;
    float total;
} ExpenseTracker;

void initializeTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
    tracker->total = 0.0f;
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }

    Expense newExpense;
    
    printf("Enter description of the expense: ");
    scanf("%s", newExpense.description);  // Using %s for simplicity in this example

    printf("Enter amount of the expense: ");
    scanf("%f", &newExpense.amount);

    printf("Enter category of the expense: ");
    scanf("%s", newExpense.category); // Using %s for simplicity in this example

    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;
    tracker->total += newExpense.amount;

    printf("Expense added successfully!\n");
}

void displayExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n--- Expense List ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Expense %d: %s | Amount: %.2f | Category: %s\n",
            i + 1, tracker->expenses[i].description,
            tracker->expenses[i].amount, tracker->expenses[i].category);
    }
    printf("-----------------------\n");
    printf("Total Expenses: %.2f\n", tracker->total);
}

void saveExpensesToFile(const ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s %.2f %s\n", tracker->expenses[i].description,
                tracker->expenses[i].amount, tracker->expenses[i].category);
    }

    fprintf(file, "Total: %.2f\n", tracker->total);
    fclose(file);
    printf("Expenses saved to 'expenses.txt'\n");
}

void loadExpensesFromFile(ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("No previous expenses found.\n");
        return;
    }

    while (fscanf(file, "%s %f %s", tracker->expenses[tracker->count].description,
                  &tracker->expenses[tracker->count].amount,
                  tracker->expenses[tracker->count].category) != EOF) {
        tracker->total += tracker->expenses[tracker->count].amount;
        tracker->count++;
        
        if (tracker->count >= MAX_ENTRIES) {
            printf("Expense limit reached while loading.\n");
            break;
        }
    }

    fclose(file);
    printf("Expenses loaded successfully from 'expenses.txt'\n");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    loadExpensesFromFile(&tracker);

    int choice;
    do {
        printf("\n--- Expense Tracker Menu ---\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Save Expenses to File\n");
        printf("4. Load Expenses from File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                displayExpenses(&tracker);
                break;
            case 3:
                saveExpensesToFile(&tracker);
                break;
            case 4:
                loadExpensesFromFile(&tracker);
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}