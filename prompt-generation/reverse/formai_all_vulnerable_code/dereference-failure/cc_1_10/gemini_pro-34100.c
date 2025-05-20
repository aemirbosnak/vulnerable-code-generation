//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

struct expense {
    char *description;
    float amount;
};

struct expense_list {
    struct expense *expenses;
    int num_expenses;
};

struct expense_list *create_expense_list() {
    struct expense_list *list = malloc(sizeof(struct expense_list));
    list->expenses = malloc(sizeof(struct expense));
    list->num_expenses = 0;
    return list;
}

void add_expense(struct expense_list *list, char *description, float amount) {
    list->expenses = realloc(list->expenses, sizeof(struct expense) * (list->num_expenses + 1));
    list->expenses[list->num_expenses].description = description;
    list->expenses[list->num_expenses].amount = amount;
    list->num_expenses++;
}

float get_total_expenses(struct expense_list *list) {
    float total = 0;
    for (int i = 0; i < list->num_expenses; i++) {
        total += list->expenses[i].amount;
    }
    return total;
}

void print_expenses(struct expense_list *list) {
    for (int i = 0; i < list->num_expenses; i++) {
        printf("%s: %f\n", list->expenses[i].description, list->expenses[i].amount);
    }
}

void free_expense_list(struct expense_list *list) {
    for (int i = 0; i < list->num_expenses; i++) {
        free(list->expenses[i].description);
    }
    free(list->expenses);
    free(list);
}

int main() {
    struct expense_list *list = create_expense_list();
    add_expense(list, "Rent", 1200);
    add_expense(list, "Groceries", 200);
    add_expense(list, "Utilities", 150);
    add_expense(list, "Transportation", 100);
    add_expense(list, "Entertainment", 50);

    float total_expenses = get_total_expenses(list);
    printf("Total expenses: %f\n", total_expenses);

    print_expenses(list);

    free_expense_list(list);

    return 0;
}