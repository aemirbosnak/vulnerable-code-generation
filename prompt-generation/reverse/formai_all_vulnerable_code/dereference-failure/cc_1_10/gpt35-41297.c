//FormAI DATASET v1.0 Category: Expense Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char category[20];
    double amount;
} Expense;

typedef struct {
    int month;
    int year;
    Expense *expenses;
} MonthExpense;

typedef struct {
    int num_months;
    MonthExpense *month_expenses;
} ExpenseTracker;

void add_expense(ExpenseTracker *tracker, int month, int year, char *category, double amount) {
    MonthExpense *current_month = NULL;
    for (int i = 0; i < tracker->num_months; i++) {
        if (tracker->month_expenses[i].month == month && tracker->month_expenses[i].year == year) {
            current_month = &tracker->month_expenses[i];
        }
    }
    if (current_month == NULL) {
        tracker->num_months++;
        tracker->month_expenses = realloc(tracker->month_expenses, tracker->num_months * sizeof(MonthExpense));
        current_month = &tracker->month_expenses[tracker->num_months - 1];
        current_month->expenses = NULL;
        current_month->month = month;
        current_month->year = year;
    }
    int num_expenses = 0;
    if (current_month->expenses != NULL) {
        for (int i = 0; current_month->expenses[i].category[0] != '\0'; i++) {
            num_expenses++;
        }
    } else {
        current_month->expenses = malloc(sizeof(Expense));
    }
    current_month->expenses = realloc(current_month->expenses, (num_expenses + 2) * sizeof(Expense));
    strcpy(current_month->expenses[num_expenses].category, category);
    current_month->expenses[num_expenses].amount = amount;
    current_month->expenses[num_expenses + 1].category[0] = '\0';
}

void display_expenses(ExpenseTracker *tracker, int month, int year) {
    MonthExpense *current_month = NULL;
    for (int i = 0; i < tracker->num_months; i++) {
        if (tracker->month_expenses[i].month == month && tracker->month_expenses[i].year == year) {
            current_month = &tracker->month_expenses[i];
        }
    }
    if (current_month == NULL) {
        printf("No expenses found for this month and year.\n");
    } else {
        printf("Expenses for %d/%d:\n", month, year);
        for (int i = 0; current_month->expenses[i].category[0] != '\0'; i++) {
            printf("%s: %.2f\n", current_month->expenses[i].category, current_month->expenses[i].amount);
        }
    }
}

int main() {
    ExpenseTracker tracker = {0, NULL};
    add_expense(&tracker, 1, 2022, "Food", 50.75);
    add_expense(&tracker, 1, 2022, "Transportation", 12.30);
    add_expense(&tracker, 2, 2022, "Rent", 800.00);
    add_expense(&tracker, 2, 2022, "Utilities", 96.50);
    add_expense(&tracker, 3, 2022, "Entertainment", 25.60);
    display_expenses(&tracker, 1, 2022);
    display_expenses(&tracker, 2, 2022);
    display_expenses(&tracker, 3, 2022);
    return 0;
}