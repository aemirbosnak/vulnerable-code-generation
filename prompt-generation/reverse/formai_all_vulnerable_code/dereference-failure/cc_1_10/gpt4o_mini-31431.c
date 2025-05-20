//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char description[50];
    float amount;
} Expense;

void addExpense(Expense **expenses, int *count);
void viewExpenses(Expense *expenses, int count);
void saveExpensesToFile(Expense *expenses, int count);
void freeExpenses(Expense *expenses);

int main() {
    Expense *expenses = NULL;
    int expenseCount = 0;
    int choice;

    do {
        printf("\n----- Expense Tracker -----\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Save Expenses to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character

        switch (choice) {
            case 1:
                addExpense(&expenses, &expenseCount);
                break;
            case 2:
                viewExpenses(expenses, expenseCount);
                break;
            case 3:
                saveExpensesToFile(expenses, expenseCount);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    freeExpenses(expenses);
    return 0;
}

void addExpense(Expense **expenses, int *count) {
    *expenses = realloc(*expenses, (*count + 1) * sizeof(Expense));
    if (*expenses == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter description: ");
    fgets((*expenses)[*count].description, 50, stdin);
    (*expenses)[*count].description[strcspn((*expenses)[*count].description, "\n")] = 0; // Remove newline
    printf("Enter amount: ");
    scanf("%f", &(*expenses)[*count].amount);
    (*count)++;
    getchar(); // To consume newline character
    printf("Expense added successfully!\n");
}

void viewExpenses(Expense *expenses, int count) {
    if (count == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("\n----- List of Expenses -----\n");
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        printf("Description: %s, Amount: %.2f\n", expenses[i].description, expenses[i].amount);
        total += expenses[i].amount;
    }
    printf("Total Expenses: %.2f\n", total);
}

void saveExpensesToFile(Expense *expenses, int count) {
    FILE *file = fopen("expenses.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for writing!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "Description: %s, Amount: %.2f\n", expenses[i].description, expenses[i].amount);
    }
    fprintf(file, "Total Expenses: %.2f\n", (count > 0) ? (expenses[count-1].amount) : 0);
    fclose(file);
    printf("Expenses saved to expenses.txt.\n");
}

void freeExpenses(Expense *expenses) {
    free(expenses);
}