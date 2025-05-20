//FormAI DATASET v1.0 Category: Expense Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expense {
    int day;
    int month;
    int year;
    char category[40];
    float amount;
} Expense;

void createExpense(Expense *e) {
    printf("Enter the day, month and year of the expense (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &e->day, &e->month, &e->year);
    getchar(); // to consume the newline character
    printf("Enter the category of the expense: ");
    fgets(e->category, 40, stdin);
    e->category[strcspn(e->category, "\n")] = '\0'; // to remove the trailing newline character
    printf("Enter the amount of the expense: ");
    scanf("%f", &e->amount);
}

void printExpense(Expense e) {
    printf("%d/%d/%d - %s - $%.2f\n", e.day, e.month, e.year, e.category, e.amount);
}

float calculateTotalExpense(Expense *expenses, int numExpenses) {
    float total = 0.0;
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

int main() {
    int numExpenses;
    printf("How many expenses do you want to track? ");
    scanf("%d", &numExpenses);

    Expense *expenses = malloc(sizeof(Expense) * numExpenses);

    for (int i = 0; i < numExpenses; i++) {
        printf("\nExpense #%d:\n", i+1);
        createExpense(&expenses[i]);
    }

    printf("\nExpense Report:\n");
    for (int i = 0; i < numExpenses; i++) {
        printExpense(expenses[i]);
    }

    float totalExpense = calculateTotalExpense(expenses, numExpenses);
    printf("\nTotal Expense: $%.2f\n", totalExpense);

    free(expenses);

    return 0;
}