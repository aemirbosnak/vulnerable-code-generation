//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUDGET_CATEGORIES 10
#define MAX_BUDGET_ITEMS 100

struct budget_category {
    char name[50];
    int num_items;
    struct budget_item *items[MAX_BUDGET_ITEMS];
};

struct budget_item {
    char name[50];
    double amount;
    int month;
};

struct budget_category *create_budget_category(char *name) {
    struct budget_category *category = (struct budget_category *) malloc(sizeof(struct budget_category));
    strcpy(category->name, name);
    category->num_items = 0;
    for (int i = 0; i < MAX_BUDGET_ITEMS; i++) {
        category->items[i] = NULL;
    }
    return category;
}

void add_budget_item(struct budget_category *category, char *name, double amount, int month) {
    struct budget_item *item = (struct budget_item *) malloc(sizeof(struct budget_item));
    strcpy(item->name, name);
    item->amount = amount;
    item->month = month;
    category->items[category->num_items++] = item;
}

void print_budget_category(struct budget_category *category) {
    printf("Category: %s\n", category->name);
    for (int i = 0; i < category->num_items; i++) {
        struct budget_item *item = category->items[i];
        printf("  Item: %s ($%.2f) - %d\n", item->name, item->amount, item->month);
    }
}

int main() {
    struct budget_category *budget = create_budget_category("Personal Finance");

    add_budget_item(budget, "Salary", 3000.00, 1);
    add_budget_item(budget, "Rent", 1000.00, 1);
    add_budget_item(budget, "Utilities", 200.00, 1);
    add_budget_item(budget, "Groceries", 400.00, 1);
    add_budget_item(budget, "Entertainment", 200.00, 1);

    print_budget_category(budget);

    return 0;
}