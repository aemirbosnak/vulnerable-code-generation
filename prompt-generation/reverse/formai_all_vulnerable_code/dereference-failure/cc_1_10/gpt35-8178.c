//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold financial data
struct finance {
    char date[10];
    float income;
    float expenses;
    char category[30];
};

// Function to display menu and get user input
int menu() {
    int choice;
    printf("Personal Finance Planner\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add expense
void add_expense(struct finance *ptr, int *count) {
    printf("Enter date (mm/dd/yyyy): ");
    scanf("%s", ptr[*count].date);
    printf("Enter amount: ");
    scanf("%f", &ptr[*count].expenses);
    printf("Enter category: ");
    scanf("%s", ptr[*count].category);
    ptr[*count].income = 0;
    (*count)++;
    printf("Expense added successfully!\n\n");
}

// Function to view expenses
void view_expenses(struct finance *ptr, int count) {
    float total_expenses = 0;
    printf("Date    \tIncome\tExpenses\tCategory\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%.2f\t%.2f\t%s\n", ptr[i].date, ptr[i].income, ptr[i].expenses, ptr[i].category);
        total_expenses += ptr[i].expenses;
    }
    printf("Total Expenses: $%.2f\n\n", total_expenses);
}

// Main function
int main() {
    int count = 0;
    struct finance *ptr = malloc(sizeof(struct finance));
    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1:
                add_expense(ptr, &count);
                ptr = realloc(ptr, (count + 1) * sizeof(struct finance));
                break;
            case 2:
                if (count == 0) {
                    printf("No expenses added yet.\n\n");
                } else {
                    view_expenses(ptr, count);
                }
                break;
            case 3:
                printf("Exiting Personal Finance Planner. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while (choice != 3);
    free(ptr);
    return 0;
}