//FormAI DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a structure to hold the expense information
struct Expense {
    char name[50];  // Name of the expense
    float cost;     // Cost of the expense
    char date[20];  // Date of the expense
};

// Function to add a new expense
void addExpense(struct Expense *expenses, int *n) {
    printf("\nAdding a new expense\n");

    printf("Enter the expense name: ");
    fflush(stdin);  // Clearing input buffer
    fgets(expenses[*n].name, 50, stdin);

    printf("Enter the expense cost: ");
    scanf("%f", &expenses[*n].cost);

    printf("Enter the date of the expense (dd-mm-yyyy): ");
    fflush(stdin);  // Clearing input buffer
    fgets(expenses[*n].date, 20, stdin);

    (*n)++;  // Incrementing the number of expenses
}

// Function to display all expenses
void displayExpenses(struct Expense *expenses, int n) {
    printf("\nDisplaying all expenses\n");

    for (int i = 0; i < n; i++) {
        printf("\n%s", expenses[i].name);
        printf("Cost: %.2f\n", expenses[i].cost);
        printf("Date: %s", expenses[i].date);
    }
}

// Function to find the expense with the highest cost
void findMaxExpense(struct Expense *expenses, int n) {
    printf("\nFinding the expense with the highest cost\n");

    float maxCost = 0.0;
    int maxIndex = -1;

    for (int i = 0; i < n; i++) {
        if (expenses[i].cost > maxCost) {
            maxCost = expenses[i].cost;
            maxIndex = i;
        }
    }

    if (maxIndex != -1) {
        printf("The expense with the highest cost is %s", expenses[maxIndex].name);
        printf("Cost: %.2f\n", expenses[maxIndex].cost);
        printf("Date: %s", expenses[maxIndex].date);
    } else {
        printf("No expenses found.\n");
    }
}

int main() {
    int n = 0;  // Number of expenses

    // Allocating memory for holding 10 expenses
    struct Expense *expenses = (struct Expense *)malloc(10 * sizeof(struct Expense));

    int option = 0;

    do {
        printf("\nExpense Tracker\n");
        printf("1. Add a new expense\n");
        printf("2. Display all expenses\n");
        printf("3. Find the expense with the highest cost\n");
        printf("4. Exit\n");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addExpense(expenses, &n);
                break;
            case 2:
                displayExpenses(expenses, n);
                break;
            case 3:
                findMaxExpense(expenses, n);
                break;
            case 4:
                printf("\nExiting the program...\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
        }
    } while (option != 4);

    free(expenses);  // Freeing the allocated memory

    return 0;
}