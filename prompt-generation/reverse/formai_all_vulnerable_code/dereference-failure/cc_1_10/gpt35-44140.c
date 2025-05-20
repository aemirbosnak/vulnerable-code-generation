//FormAI DATASET v1.0 Category: Expense Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Expense {
    char* name;
    float cost;
} Expense;

int main() {
    int numExpenses = 0;
    Expense* expenses = malloc(numExpenses * sizeof(Expense));

    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        int choice = 0;
        printf("\nMenu\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Clear input buffer
        while ((getchar()) != '\n');

        if (choice == 1) {
            printf("\nEnter the name of the expense: ");
            char* name = malloc(50 * sizeof(char));
            scanf("%[^\n]", name);

            printf("Enter the cost of the expense: ");
            float cost = 0.0;
            scanf("%f", &cost);

            // Clear input buffer
            while ((getchar()) != '\n');

            numExpenses++;
            expenses = realloc(expenses, numExpenses * sizeof(Expense));
            expenses[numExpenses-1].name = malloc(strlen(name) * sizeof(char));
            strncpy(expenses[numExpenses-1].name, name, strlen(name));
            expenses[numExpenses-1].cost = cost;

            printf("\nExpense added successfully!\n");

            free(name);
        }
        else if (choice == 2) {
            printf("\nExpenses\n");
            printf("%-30s%-10s\n", "Name", "Cost");
            printf("----------------------------------------\n");
            float totalCost = 0.0;
            for (int i = 0; i < numExpenses; i++) {
                printf("%-30s%-10.2f\n", expenses[i].name, expenses[i].cost);
                totalCost += expenses[i].cost;
            }
            printf("----------------------------------------\n");
            printf("%-30s%-10.2f\n", "Total Cost:", totalCost);
        }
        else if (choice == 3) {
            printf("\nThank you for using the Expense Tracker!\n");
            break;
        }
        else {
            printf("\nInvalid Choice!\n");
        }
    }

    for (int i = 0; i < numExpenses; i++) {
        free(expenses[i].name);
    }
    free(expenses);

    return 0;
}