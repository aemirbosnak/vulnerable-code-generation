//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expense {
    char *name;
    float amount;
    char *date;
} expense_t;

typedef struct expense_list {
    expense_t *expenses;
    int num_expenses;
} expense_list_t;

expense_list_t *create_expense_list() {
    expense_list_t *list = malloc(sizeof(expense_list_t));
    list->expenses = NULL;
    list->num_expenses = 0;
    return list;
}

void add_expense(expense_list_t *list, expense_t *expense) {
    list->expenses = realloc(list->expenses, (list->num_expenses + 1) * sizeof(expense_t));
    list->expenses[list->num_expenses] = *expense;
    list->num_expenses++;
}

void print_expense_list(expense_list_t *list) {
    for (int i = 0; i < list->num_expenses; i++) {
        printf("%s: $%.2f (%s)\n", list->expenses[i].name, list->expenses[i].amount, list->expenses[i].date);
    }
}

void free_expense_list(expense_list_t *list) {
    for (int i = 0; i < list->num_expenses; i++) {
        free(list->expenses[i].name);
        free(list->expenses[i].date);
    }
    free(list->expenses);
    free(list);
}

int main() {
    expense_list_t *list = create_expense_list();

    expense_t expense1 = {"Coffee", 2.50, "2023-03-08"};
    add_expense(list, &expense1);

    expense_t expense2 = {"Lunch", 10.00, "2023-03-09"};
    add_expense(list, &expense2);

    expense_t expense3 = {"Dinner", 15.00, "2023-03-10"};
    add_expense(list, &expense3);

    print_expense_list(list);

    free_expense_list(list);

    return 0;
}