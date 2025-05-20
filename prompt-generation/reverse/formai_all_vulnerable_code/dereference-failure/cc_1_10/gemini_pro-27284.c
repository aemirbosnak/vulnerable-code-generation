//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *description;
    int amount;
    int date;
} expense;

expense *expenses;
int num_expenses;

void add_expense(char *description, int amount, int date) {
    expenses = realloc(expenses, sizeof(expense) * (num_expenses + 1));
    expenses[num_expenses].description = strdup(description);
    expenses[num_expenses].amount = amount;
    expenses[num_expenses].date = date;
    num_expenses++;
}

void print_expenses() {
    for (int i = 0; i < num_expenses; i++) {
        printf("%s %d %d\n", expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

void sort_expenses(int field) {
    for (int i = 0; i < num_expenses - 1; i++) {
        for (int j = i + 1; j < num_expenses; j++) {
            if (field == 1 && strcmp(expenses[i].description, expenses[j].description) > 0) {
                expense temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            } else if (field == 2 && expenses[i].amount > expenses[j].amount) {
                expense temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            } else if (field == 3 && expenses[i].date > expenses[j].date) {
                expense temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            }
        }
    }
}

int main() {
    expenses = malloc(0);
    num_expenses = 0;

    add_expense("Bread", 10, 20230101);
    add_expense("Milk", 5, 20230102);
    add_expense("Eggs", 7, 20230103);
    add_expense("Cheese", 8, 20230104);
    add_expense("Meat", 12, 20230105);

    print_expenses();

    sort_expenses(1);
    printf("\nSorted by description:\n");
    print_expenses();

    sort_expenses(2);
    printf("\nSorted by amount:\n");
    print_expenses();

    sort_expenses(3);
    printf("\nSorted by date:\n");
    print_expenses();

    return 0;
}