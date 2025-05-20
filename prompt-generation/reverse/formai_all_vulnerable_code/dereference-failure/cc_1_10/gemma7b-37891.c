//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSE 10

struct Expense {
    char name[50];
    int amount;
    struct Expense* next;
};

struct Expense* insertExpense(struct Expense* head, char* name, int amount) {
    struct Expense* newExpense = malloc(sizeof(struct Expense));
    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    newExpense->next = NULL;

    if (head == NULL) {
        head = newExpense;
    } else {
        head->next = newExpense;
    }

    return head;
}

int main() {

    struct Expense* head = NULL;

    insertExpense(head, "Romeo's feast", 50);
    insertExpense(head, "Juliet's dress", 20);
    insertExpense(head, "Tybalt's sword", 10);

    printf("Total expenses: $%d\n", calculateTotalExpenses(head));

    return 0;
}

int calculateTotalExpenses(struct Expense* head) {
    int totalExpenses = 0;

    struct Expense* currentExpense = head;

    while (currentExpense) {
        totalExpenses += currentExpense->amount;
        currentExpense = currentExpense->next;
    }

    return totalExpenses;
}