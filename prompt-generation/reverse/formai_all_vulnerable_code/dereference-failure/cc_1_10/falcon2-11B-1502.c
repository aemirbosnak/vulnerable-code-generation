//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

struct Expense {
    char* name;
    int cost;
    struct Expense* next;
};

void addExpense(struct Expense** expenses, char* name, int cost) {
    struct Expense* newExpense = (struct Expense*)malloc(sizeof(struct Expense));
    if (!newExpense) {
        printf("Memory allocation failed.\n");
        return;
    }
    newExpense->name = strdup(name);
    newExpense->cost = cost;
    newExpense->next = NULL;

    struct Expense* current = *expenses;
    while (current->next) {
        current = current->next;
    }
    current->next = newExpense;
}

void displayExpenses(struct Expense* expenses) {
    struct Expense* current = expenses;
    while (current) {
        printf("Name: %s, Cost: %d\n", current->name, current->cost);
        current = current->next;
    }
}

int main() {
    struct Expense* expenses = NULL;

    while (1) {
        printf("Enter expense name: ");
        char name[100];
        scanf("%s", name);

        printf("Enter expense cost: ");
        int cost;
        scanf("%d", &cost);

        addExpense(&expenses, name, cost);

        printf("\nExpenses:\n");
        displayExpenses(expenses);

        printf("\nPress any key to continue, or 'q' to quit.\n");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'q') {
            break;
        }
    }

    return 0;
}