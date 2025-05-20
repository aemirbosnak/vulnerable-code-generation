//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSE 100

struct Expense {
    char name[50];
    int amount;
    struct Expense *next;
};

struct Expense *head = NULL;

void addExpense(struct Expense *newExpense) {
    struct Expense *temp = head;

    if (head == NULL) {
        head = newExpense;
        return;
    }

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = newExpense;
}

void printExpenses() {
    struct Expense *temp = head;

    while (temp!= NULL) {
        printf("%s - $%.2f\n", temp->name, temp->amount);
        temp = temp->next;
    }
}

int main() {
    struct Expense *newExpense;
    int choice;

    while (1) {
        printf("1. Add Expense\n2. Print Expenses\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense name: ");
                scanf("%s", newExpense->name);
                printf("Enter expense amount: $");
                scanf("%d", &newExpense->amount);

                newExpense->next = NULL;
                addExpense(newExpense);
                break;

            case 2:
                printExpenses();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}