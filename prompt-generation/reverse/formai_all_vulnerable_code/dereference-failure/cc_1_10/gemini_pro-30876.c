//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Expense item structure
typedef struct expense_item {
    char description[50];
    float amount;
    struct expense_item *next;
} expense_item;

// Expense list structure
typedef struct expense_list {
    expense_item *head;
    expense_item *tail;
    int size;
} expense_list;

// Create a new expense item
expense_item *new_expense_item(char *description, float amount) {
    expense_item *item = malloc(sizeof(expense_item));
    strcpy(item->description, description);
    item->amount = amount;
    item->next = NULL;
    return item;
}

// Create a new expense list
expense_list *new_expense_list() {
    expense_list *list = malloc(sizeof(expense_list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Add an expense item to the list
void add_expense_item(expense_list *list, expense_item *item) {
    if (list->size == 0) {
        list->head = item;
        list->tail = item;
    } else {
        list->tail->next = item;
        list->tail = item;
    }
    list->size++;
}

// Print the expense list
void print_expense_list(expense_list *list) {
    expense_item *current = list->head;
    while (current != NULL) {
        printf("%s: %.2f\n", current->description, current->amount);
        current = current->next;
    }
}

// Free the memory allocated for the expense list
void free_expense_list(expense_list *list) {
    expense_item *current = list->head;
    while (current != NULL) {
        expense_item *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

// Main function
int main() {
    // Create a new expense list
    expense_list *list = new_expense_list();

    // Add some expense items to the list
    add_expense_item(list, new_expense_item("Food", 100.00));
    add_expense_item(list, new_expense_item("Rent", 500.00));
    add_expense_item(list, new_expense_item("Utilities", 150.00));
    add_expense_item(list, new_expense_item("Transportation", 200.00));
    add_expense_item(list, new_expense_item("Entertainment", 100.00));

    // Print the expense list
    print_expense_list(list);

    // Free the memory allocated for the expense list
    free_expense_list(list);

    return 0;
}