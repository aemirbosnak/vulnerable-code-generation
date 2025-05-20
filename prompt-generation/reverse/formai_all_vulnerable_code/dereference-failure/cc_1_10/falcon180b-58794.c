//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 20
#define MAX_NAME_LEN 100
#define MAX_CATEGORY_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    double cost;
} expense_t;

typedef struct {
    int num_items;
    expense_t items[MAX_ITEMS];
} expense_list_t;

expense_list_t* create_expense_list() {
    expense_list_t* list = (expense_list_t*) malloc(sizeof(expense_list_t));
    list->num_items = 0;
    return list;
}

void add_expense(expense_list_t* list, char* name, char* category, double cost) {
    if (list->num_items >= MAX_ITEMS) {
        printf("Error: Expense list is full.\n");
        return;
    }

    expense_t* new_expense = (expense_t*) malloc(sizeof(expense_t));
    strncpy(new_expense->name, name, MAX_NAME_LEN);
    strncpy(new_expense->category, category, MAX_CATEGORY_LEN);
    new_expense->cost = cost;

    list->items[list->num_items++] = *new_expense;
}

void print_expenses(expense_list_t* list) {
    for (int i = 0; i < list->num_items; i++) {
        printf("%s - %s - $%.2f\n", list->items[i].name, list->items[i].category, list->items[i].cost);
    }
}

void print_totals(expense_list_t* list) {
    double total_cost = 0;

    for (int i = 0; i < list->num_items; i++) {
        total_cost += list->items[i].cost;
    }

    printf("\nTotal Cost: $%.2f\n", total_cost);
}

int main() {
    expense_list_t* list = create_expense_list();

    add_expense(list, "Laptop", "Electronics", 1000);
    add_expense(list, "Phone", "Electronics", 500);
    add_expense(list, "Groceries", "Food", 150);
    add_expense(list, "Clothes", "Clothing", 200);

    print_expenses(list);
    print_totals(list);

    return 0;
}