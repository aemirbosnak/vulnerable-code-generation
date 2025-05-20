//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define surrealistic data structures
typedef struct {
    char *name;
    int amount;
    int date;
} Expense;

typedef struct {
    int capacity;
    int size;
    Expense **data;
} ExpenseList;

// Initialize an empty expense list
ExpenseList *initExpenseList(int capacity) {
    ExpenseList *list = (ExpenseList *) malloc(sizeof(ExpenseList));
    list->capacity = capacity;
    list->size = 0;
    list->data = (Expense **) malloc(capacity * sizeof(Expense *));
    return list;
}

// Add an expense to the list
void addExpense(ExpenseList *list, char *name, int amount, int date) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (Expense **) realloc(list->data, list->capacity * sizeof(Expense *));
    }
    list->data[list->size] = (Expense *) malloc(sizeof(Expense));
    list->data[list->size]->name = strdup(name);
    list->data[list->size]->amount = amount;
    list->data[list->size]->date = date;
    list->size++;
}

// Print the expense list
void printExpenseList(ExpenseList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%s - %d - %d\n", list->data[i]->name, list->data[i]->amount, list->data[i]->date);
    }
}

// Free the expense list
void freeExpenseList(ExpenseList *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->data[i]->name);
        free(list->data[i]);
    }
    free(list->data);
    free(list);
}

// Define surrealistic main function
int main() {
    srand(time(NULL));
    ExpenseList *list = initExpenseList(10);
    for (int i = 0; i < 20; i++) {
        char *name = (char *) malloc(10 * sizeof(char));
        sprintf(name, "Expense %d", i);
        int amount = rand() % 1000;
        int date = rand() % 1000000000;
        addExpense(list, name, amount, date);
    }
    printExpenseList(list);
    freeExpenseList(list);
    return 0;
}