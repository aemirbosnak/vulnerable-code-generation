//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct expense_t {
    char *description;
    float amount;
    time_t date;
} expense_t;

typedef struct expense_list_t {
    expense_t *expenses;
    int size;
    int capacity;
} expense_list_t;

expense_list_t *expense_list_new() {
    expense_list_t *list = malloc(sizeof(expense_list_t));
    list->expenses = malloc(sizeof(expense_t) * 10);
    list->size = 0;
    list->capacity = 10;
    return list;
}

void expense_list_free(expense_list_t *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->expenses[i].description);
    }
    free(list->expenses);
    free(list);
}

void expense_list_add(expense_list_t *list, expense_t expense) {
    if (list->size == list->capacity) {
        list->expenses = realloc(list->expenses, sizeof(expense_t) * list->capacity * 2);
        list->capacity *= 2;
    }
    list->expenses[list->size] = expense;
    list->size++;
}

void expense_list_print(expense_list_t *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%s: $%.2f (%s)\n", list->expenses[i].description, list->expenses[i].amount, ctime(&list->expenses[i].date));
    }
}

int main() {
    expense_list_t *list = expense_list_new();

    expense_t expense1 = {
        .description = "Groceries",
        .amount = 100.00,
        .date = time(NULL)
    };
    expense_list_add(list, expense1);

    expense_t expense2 = {
        .description = "Rent",
        .amount = 1200.00,
        .date = time(NULL)
    };
    expense_list_add(list, expense2);

    expense_t expense3 = {
        .description = "Utilities",
        .amount = 200.00,
        .date = time(NULL)
    };
    expense_list_add(list, expense3);

    expense_list_print(list);

    expense_list_free(list);

    return 0;
}