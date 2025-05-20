//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 10

typedef struct Expense {
    char name[20];
    int amount;
    struct Expense* next;
} Expense;

void addExpense(Expense** head) {
    Expense* newExpense = (Expense*)malloc(sizeof(Expense));
    printf("Enter expense name: ");
    scanf("%s", newExpense->name);
    printf("Enter expense amount: ");
    scanf("%d", &newExpense->amount);
    newExpense->next = NULL;

    if (*head == NULL) {
        *head = newExpense;
    } else {
        (*head)->next = newExpense;
    }
}

void printExpenses(Expense* head) {
    printf("List of expenses:\n");
    while (head) {
        printf("%s - %d\n", head->name, head->amount);
        head = head->next;
    }
}

int main() {
    Expense* head = NULL;
    int choice;

    do {
        printf("1. Add Expense\n");
        printf("2. Print Expenses\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&head);
                break;
            case 2:
                printExpenses(head);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}