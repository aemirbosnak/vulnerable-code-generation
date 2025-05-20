//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char *category;
    char *description;
    float amount;
    struct expense *next;
};

struct expense_list {
    struct expense *head;
    struct expense *tail;
};

struct expense *create_expense(char *category, char *description, float amount) {
    struct expense *new_expense = (struct expense *)malloc(sizeof(struct expense));
    new_expense->category = strdup(category);
    new_expense->description = strdup(description);
    new_expense->amount = amount;
    new_expense->next = NULL;
    return new_expense;
}

void add_expense(struct expense_list *list, struct expense *expense) {
    if (list->head == NULL) {
        list->head = expense;
        list->tail = expense;
    } else {
        list->tail->next = expense;
        list->tail = expense;
    }
}

void print_expense(struct expense *expense) {
    printf("%s %s %f\n", expense->category, expense->description, expense->amount);
}

void print_expense_list(struct expense_list *list) {
    struct expense *current = list->head;
    while (current != NULL) {
        print_expense(current);
        current = current->next;
    }
}

float get_total_expenses(struct expense_list *list) {
    float total = 0.0;
    struct expense *current = list->head;
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }
    return total;
}

void free_expense(struct expense *expense) {
    free(expense->category);
    free(expense->description);
    free(expense);
}

void free_expense_list(struct expense_list *list) {
    struct expense *current = list->head;
    while (current != NULL) {
        struct expense *next = current->next;
        free_expense(current);
        current = next;
    }
}

int main(void) {
    struct expense_list *list = (struct expense_list *)malloc(sizeof(struct expense_list));
    list->head = NULL;
    list->tail = NULL;

    add_expense(list, create_expense("Food", "Groceries", 100.00));
    add_expense(list, create_expense("Entertainment", "Movie tickets", 20.00));
    add_expense(list, create_expense("Transportation", "Gas", 50.00));

    print_expense_list(list);

    printf("Total expenses: %f\n", get_total_expenses(list));

    free_expense_list(list);

    return 0;
}