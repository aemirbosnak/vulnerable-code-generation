//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LENGTH 100

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void initTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense list is full!\n");
        return;
    }

    printf("Enter expense description: ");
    scanf("%s", tracker->expenses[tracker->count].description);
    printf("Enter expense amount: ");
    scanf("%f", &tracker->expenses[tracker->count].amount);
    tracker->count++;
    printf("Expense added successfully!\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("Expenses:\n");
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
        total += tracker->expenses[i].amount;
    }
    printf("Total expenses: $%.2f\n", total);
}

void deleteExpense(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses to delete.\n");
        return;
    }

    int index;
    printf("Enter the number of the expense to delete (1 to %d): ", tracker->count);
    scanf("%d", &index);
    
    if (index < 1 || index > tracker->count) {
        printf("Invalid expense number.\n");
        return;
    }

    for (int i = index - 1; i < tracker->count - 1; i++) {
        tracker->expenses[i] = tracker->expenses[i + 1];
    }
    tracker->count--;
    printf("Expense deleted successfully!\n");
}

void saveExpenses(const ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "w");
    if (file == NULL) {
        printf("Failed to save expenses.\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s %.2f\n", tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    fclose(file);
    printf("Expenses saved successfully!\n");
}

void loadExpenses(ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("No expense record found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%s %f", tracker->expenses[tracker->count].description, &tracker->expenses[tracker->count].amount) != EOF) {
        tracker->count++;
        if (tracker->count >= MAX_EXPENSES) {
            printf("Maximum expense limit reached while loading.\n");
            break;
        }
    }
    fclose(file);
    printf("Expenses loaded successfully!\n");
}

void displayMenu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Save Expenses\n");
    printf("5. Load Expenses\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    ExpenseTracker tracker;
    initTracker(&tracker);
    loadExpenses(&tracker);

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                deleteExpense(&tracker);
                break;
            case 4:
                saveExpenses(&tracker);
                break;
            case 5:
                loadExpenses(&tracker);
                break;
            case 6:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}