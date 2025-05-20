//FormAI DATASET v1.0 Category: Expense Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>

/* Structure to store expense details */
struct Expense {
    char category[20];
    float amount;
};

/* Function to add a new expense */
void addExpense(struct Expense *expenses, int *count) {
    char category[20];
    float amount;

    printf("Enter expense category: ");
    scanf("%s", category);

    printf("Enter expense amount: ");
    scanf("%f", &amount);

    /* Add new expense to array */
    struct Expense newExpense = { category, amount };
    expenses[*count] = newExpense;
    (*count)++;

    printf("Expense added successfully!\n\n");
}

/* Function to display all expenses */
void displayExpenses(struct Expense *expenses, int count) {
    printf("\nExpenses:\n");

    for(int i = 0; i < count; i++) {
        printf("%s: $%.2f\n", expenses[i].category, expenses[i].amount);
    }

    printf("\n");
}

/* Function to calculate total expenses */
float totalExpenses(struct Expense *expenses, int count) {
    float total = 0;

    for(int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }

    return total;
}

int main() {
    struct Expense *expenses = malloc(100 * sizeof(struct Expense));
    int count = 0;
    int choice;

    while(1) {
        printf("Expense Tracker Menu\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Total Expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addExpense(expenses, &count);
                break;

            case 2:
                displayExpenses(expenses, count);
                break;

            case 3:
                printf("\nTotal expenses: $%.2f\n\n", totalExpenses(expenses, count));
                break;

            case 4:
                printf("Exiting Expense Tracker...");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    free(expenses);
    return 0;
}