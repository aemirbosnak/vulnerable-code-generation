//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 10

struct Expense {
    char name[50];
    int amount;
    struct Expense* next;
};

struct Expense* head = NULL;

void addExpense(char* name, int amount) {
    struct Expense* newExpense = (struct Expense*)malloc(sizeof(struct Expense));
    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    newExpense->next = NULL;

    if (head == NULL) {
        head = newExpense;
    } else {
        struct Expense* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newExpense;
    }
}

void displayExpenses() {
    struct Expense* temp = head;
    printf("Expenses:\n");
    while (temp) {
        printf("%s - %d\n", temp->name, temp->amount);
        temp = temp->next;
    }
}

int main() {
    addExpense("Groceries", 50);
    addExpense("Eating Out", 20);
    addExpense("Electronics", 100);
    addExpense("Clothing", 30);
    addExpense("Transportation", 25);

    displayExpenses();

    return 0;
}