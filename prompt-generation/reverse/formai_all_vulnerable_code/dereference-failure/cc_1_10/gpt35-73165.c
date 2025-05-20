//FormAI DATASET v1.0 Category: Expense Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    int day;
    int month;
    int year;
    char *description;
    double amount;
};

void printHeader() {
    printf("%-5s %-10s %-20s %s\n", "Day", "Month", "Year", "Description", "Amount");
    printf("--------------------------------------------------------------\n");
}

void printExpense(struct Expense expense) {
    printf("%-5d %-10d %-20d %-20s %.2f\n", expense.day, expense.month, expense.year, expense.description, expense.amount);
}

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    char input[1000];

    while (1) {
        printf("Enter command (add, list, quit): ");
        fgets(input, 1000, stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "quit") == 0) {
            break;
        }

        else if (strcmp(input, "add") == 0) {
            struct Expense newExpense;

            printf("Enter day (1-31): ");
            fgets(input, 1000, stdin);
            newExpense.day = atoi(input);

            printf("Enter month (1-12): ");
            fgets(input, 1000, stdin);
            newExpense.month = atoi(input);

            printf("Enter year: ");
            fgets(input, 1000, stdin);
            newExpense.year = atoi(input);

            printf("Enter description: ");
            fgets(input, 1000, stdin);
            newExpense.description = malloc(strlen(input) + 1);
            strcpy(newExpense.description, input);

            printf("Enter amount: ");
            fgets(input, 1000, stdin);
            newExpense.amount = atof(input);

            expenses[numExpenses] = newExpense;
            numExpenses++;
        }

        else if (strcmp(input, "list") == 0) {
            if (numExpenses == 0) {
                printf("No expenses to display.\n");
            }
            else {
                printHeader();
                for (int i = 0; i < numExpenses; i++) {
                    printExpense(expenses[i]);
                }
            }
        }

        else {
            printf("Invalid command.\n");
        }
    }

    for (int i = 0; i < numExpenses; i++) {
        free(expenses[i].description);
    }

    return 0;
}