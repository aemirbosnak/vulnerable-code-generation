//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct expense {
    char *description;
    float amount;
    time_t date;
};

struct expense *expenses = NULL;
int num_expenses = 0;

void add_expense(char *description, float amount) {
    struct expense *new_expense = (struct expense *) malloc(sizeof(struct expense));
    if (new_expense == NULL) {
        printf("Error: Could not allocate memory for new expense.\n");
        return;
    }

    new_expense->description = strdup(description);
    new_expense->amount = amount;
    new_expense->date = time(NULL);

    expenses = realloc(expenses, sizeof(struct expense) * ++num_expenses);
    expenses[num_expenses - 1] = *new_expense;
    free(new_expense);
}

void print_expenses() {
    printf("Expense Tracker - %d expenses recorded:\n", num_expenses);
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f - %s\n", expenses[i].description, expenses[i].amount, ctime(&expenses[i].date));
    }
}

int main() {
    expenses = (struct expense *) malloc(sizeof(struct expense));
    if (expenses == NULL) {
        printf("Error: Could not allocate memory for expenses.\n");
        return 1;
    }

    add_expense("Groceries", 50.00);
    add_expense("Rent", 1000.00);
    add_expense("Utilities", 200.00);

    print_expenses();

    free(expenses);
    return 0;
}