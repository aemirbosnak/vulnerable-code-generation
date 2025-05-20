//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item represents a single expense item
typedef struct Item {
    char description[50];
    float amount;
    struct Item *next;
} Item;

// Expense represents a collection of expense items
typedef struct Expense {
    Item *head;
    Item *tail;
} Expense;

// create a new expense item
Item *createItem(char *description, float amount) {
    Item *item = (Item *)malloc(sizeof(Item));
    strcpy(item->description, description);
    item->amount = amount;
    item->next = NULL;
    return item;
}

// add an item to the expense
void addItem(Expense *expense, Item *item) {
    if (expense->head == NULL) {
        expense->head = item;
        expense->tail = item;
    } else {
        expense->tail->next = item;
        expense->tail = item;
    }
}

// print the expense
void printExpense(Expense *expense) {
    Item *current = expense->head;
    while (current != NULL) {
        printf("%s: $%.2f\n", current->description, current->amount);
        current = current->next;
    }
}

// calculate the total expense
float calculateTotal(Expense *expense) {
    float total = 0;
    Item *current = expense->head;
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }
    return total;
}

// main function
int main() {
    // create an expense
    Expense expense;
    expense.head = NULL;
    expense.tail = NULL;

    // add some items to the expense
    addItem(&expense, createItem("Groceries", 100.00));
    addItem(&expense, createItem("Gas", 50.00));
    addItem(&expense, createItem("Entertainment", 25.00));

    // print the expense
    printf("Expense:\n");
    printExpense(&expense);

    // calculate the total expense
    float total = calculateTotal(&expense);
    printf("Total: $%.2f\n", total);

    return 0;
}