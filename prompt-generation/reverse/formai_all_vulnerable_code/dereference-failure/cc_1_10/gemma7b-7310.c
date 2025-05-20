//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 10

struct Expense {
    char name[20];
    int amount;
    struct Expense* next;
};

struct Expense* createExpense(char* name, int amount) {
    struct Expense* newExpense = (struct Expense*)malloc(sizeof(struct Expense));
    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    newExpense->next = NULL;
    return newExpense;
}

void addExpense(struct Expense* head, char* name, int amount) {
    struct Expense* newExpense = createExpense(name, amount);
    if (head == NULL) {
        head = newExpense;
    } else {
        struct Expense* currentExpense = head;
        while (currentExpense->next) {
            currentExpense = currentExpense->next;
        }
        currentExpense->next = newExpense;
    }
}

void displayExpenses(struct Expense* head) {
    struct Expense* currentExpense = head;
    printf("Expenses:\n");
    while (currentExpense) {
        printf("%s: %d\n", currentExpense->name, currentExpense->amount);
        currentExpense = currentExpense->next;
    }
}

int main() {
    struct Expense* head = NULL;
    addExpense(head, "Groceries", 50);
    addExpense(head, "Electronics", 200);
    addExpense(head, "Clothing", 25);
    displayExpenses(head);

    return 0;
}