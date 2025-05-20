//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char *name;
    int quantity;
    double price;
};

struct Inventory {
    struct Item *items;
    int count;
};

struct Expense {
    char *date;
    char *description;
    double amount;
};

struct ExpenseTracker {
    struct Expense *expenses;
    int count;
};

void add_item(struct Inventory *inventory, char *name, int quantity, double price) {
    inventory->items = realloc(inventory->items, (inventory->count + 1) * sizeof(struct Item));
    inventory->items[inventory->count].name = strdup(name);
    inventory->items[inventory->count].quantity = quantity;
    inventory->items[inventory->count].price = price;
    inventory->count++;
}

void add_expense(struct ExpenseTracker *tracker, char *date, char *description, double amount) {
    tracker->expenses = realloc(tracker->expenses, (tracker->count + 1) * sizeof(struct Expense));
    tracker->expenses[tracker->count].date = strdup(date);
    tracker->expenses[tracker->count].description = strdup(description);
    tracker->expenses[tracker->count].amount = amount;
    tracker->count++;
}

void print_inventory(struct Inventory *inventory) {
    printf("Inventory:\n");
    for (int i = 0; i < inventory->count; i++) {
        printf("%s: %d units at $%.2f each\n", inventory->items[i].name, inventory->items[i].quantity, inventory->items[i].price);
    }
}

void print_expenses(struct ExpenseTracker *tracker) {
    printf("Expenses:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%s: %s for $%.2f\n", tracker->expenses[i].date, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
}

int main() {
    // Initialize the inventory.
    struct Inventory inventory;
    inventory.items = NULL;
    inventory.count = 0;

    // Add some items to the inventory.
    add_item(&inventory, "Food", 10, 10.0);
    add_item(&inventory, "Water", 5, 5.0);
    add_item(&inventory, "Ammunition", 20, 20.0);

    // Initialize the expense tracker.
    struct ExpenseTracker tracker;
    tracker.expenses = NULL;
    tracker.count = 0;

    // Add some expenses to the tracker.
    add_expense(&tracker, "2023-03-01", "Food", 10.0);
    add_expense(&tracker, "2023-03-02", "Water", 5.0);
    add_expense(&tracker, "2023-03-03", "Ammunition", 20.0);

    // Print the inventory and expense tracker.
    print_inventory(&inventory);
    print_expenses(&tracker);

    // Clean up the memory allocated for the inventory and expense tracker.
    for (int i = 0; i < inventory.count; i++) {
        free(inventory.items[i].name);
    }
    free(inventory.items);

    for (int i = 0; i < tracker.count; i++) {
        free(tracker.expenses[i].date);
        free(tracker.expenses[i].description);
    }
    free(tracker.expenses);

    return 0;
}