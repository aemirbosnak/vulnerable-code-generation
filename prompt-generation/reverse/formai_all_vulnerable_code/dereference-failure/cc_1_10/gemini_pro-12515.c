//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char *description;
    float amount;
    char *date;
};

struct expense_tracker {
    struct expense *expenses;
    int num_expenses;
    float total_expenses;
};

void add_expense(struct expense_tracker *tracker, char *description, float amount, char *date) {
    tracker->expenses = realloc(tracker->expenses, (tracker->num_expenses + 1) * sizeof(struct expense));
    tracker->expenses[tracker->num_expenses].description = malloc(strlen(description) + 1);
    strcpy(tracker->expenses[tracker->num_expenses].description, description);
    tracker->expenses[tracker->num_expenses].amount = amount;
    tracker->expenses[tracker->num_expenses].date = malloc(strlen(date) + 1);
    strcpy(tracker->expenses[tracker->num_expenses].date, date);
    tracker->num_expenses++;
    tracker->total_expenses += amount;
}

void print_expenses(struct expense_tracker *tracker) {
    int i;
    for (i = 0; i < tracker->num_expenses; i++) {
        printf("%s\t%.2f\t%s\n", tracker->expenses[i].description, tracker->expenses[i].amount, tracker->expenses[i].date);
    }
}

int main() {
    struct expense_tracker tracker;
    tracker.expenses = NULL;
    tracker.num_expenses = 0;
    tracker.total_expenses = 0;

    add_expense(&tracker, "Flowers for my darling", 25.00, "2023-02-14");
    add_expense(&tracker, "Dinner at our favorite restaurant", 100.00, "2023-02-14");
    add_expense(&tracker, "Movie tickets for a romantic evening", 20.00, "2023-02-14");

    print_expenses(&tracker);

    printf("\nTotal expenses: %.2f\n", tracker.total_expenses);

    return 0;
}