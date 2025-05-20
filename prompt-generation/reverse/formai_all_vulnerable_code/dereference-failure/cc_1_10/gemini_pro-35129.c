//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char *name;
    float amount;
} Expense;

typedef struct {
    Expense *expenses;
    size_t size;
    size_t capacity;
} ExpenseList;

ExpenseList *create_expense_list(size_t capacity) {
    ExpenseList *list = malloc(sizeof(ExpenseList));
    list->expenses = malloc(sizeof(Expense) * capacity);
    list->size = 0;
    list->capacity = capacity;
    return list;
}

void add_expense(ExpenseList *list, const char *name, float amount) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->expenses = realloc(list->expenses, sizeof(Expense) * list->capacity);
    }
    strcpy(list->expenses[list->size].name, name);
    list->expenses[list->size].amount = amount;
    list->size++;
}

void print_expenses(ExpenseList *list) {
    for (size_t i = 0; i < list->size; i++) {
        printf("%s: %.2f\n", list->expenses[i].name, list->expenses[i].amount);
    }
}

void destroy_expense_list(ExpenseList *list) {
    for (size_t i = 0; i < list->size; i++) {
        free(list->expenses[i].name);
    }
    free(list->expenses);
    free(list);
}

int main() {
    ExpenseList *list = create_expense_list(10);
    add_expense(list, "Groceries", 100.0f);
    add_expense(list, "Rent", 1200.0f);
    add_expense(list, "Utilities", 150.0f);
    add_expense(list, "Transportation", 200.0f);
    print_expenses(list);
    destroy_expense_list(list);
    return 0;
}