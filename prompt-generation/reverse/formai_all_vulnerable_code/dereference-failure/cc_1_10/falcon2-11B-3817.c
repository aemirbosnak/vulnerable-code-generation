//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a budget item
struct budget_item {
    char name[100];
    int amount;
};

// Define the structure for a budget plan
struct budget_plan {
    struct budget_item *items;
    int num_items;
};

// Function to add a new budget item
void add_item(struct budget_plan *plan, const char *name, int amount) {
    struct budget_item *new_item = malloc(sizeof(struct budget_item));
    strncpy(new_item->name, name, sizeof(new_item->name));
    new_item->amount = amount;
    plan->items = realloc(plan->items, (plan->num_items + 1) * sizeof(struct budget_item));
    plan->items[plan->num_items++] = *new_item;
}

// Function to print the budget plan
void print_plan(struct budget_plan *plan) {
    int i;
    printf("Budget Plan:\n");
    for (i = 0; i < plan->num_items; i++) {
        printf("%s: %d\n", plan->items[i].name, plan->items[i].amount);
    }
}

// Function to calculate the total budget
int calculate_total(struct budget_plan *plan) {
    int total = 0;
    int i;
    for (i = 0; i < plan->num_items; i++) {
        total += plan->items[i].amount;
    }
    return total;
}

int main() {
    struct budget_plan *plan = malloc(sizeof(struct budget_plan));
    plan->num_items = 0;

    // Add some budget items
    add_item(plan, "Rent", 1500);
    add_item(plan, "Groceries", 200);
    add_item(plan, "Utilities", 200);
    add_item(plan, "Transportation", 300);
    add_item(plan, "Entertainment", 100);

    // Print the budget plan
    printf("Budget Plan:\n");
    print_plan(plan);

    // Calculate the total budget
    int total = calculate_total(plan);
    printf("Total Budget: %d\n", total);

    return 0;
}