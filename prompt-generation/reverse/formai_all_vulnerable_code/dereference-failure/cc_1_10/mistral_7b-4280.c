//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: Cryptic
#define _CRYPTIC_EXPENSE_TRACKER_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _expense {
    char name[20];
    float cost;
    struct _expense *next;
} expense;

expense *head = NULL;

#define ADD_EXPENSE(name, cost) _add_expense(#name, (cost))

void _add_expense(char *name, float cost) {
    expense *new_expense = (expense *)malloc(sizeof(expense));

    strcpy(new_expense->name, name);
    new_expense->cost = cost;
    new_expense->next = head;

    head = new_expense;
}

void _print_expenses() {
    expense *expense_ptr = head;

    while (expense_ptr != NULL) {
        printf("%s: %.2f\n", expense_ptr->name, expense_ptr->cost);
        expense_ptr = expense_ptr->next;
    }
}

int main(void) {
    int choice;
    char input[30];
    float expense_amount;

    while (1) {
        printf("\n_CRYPTIC_EXPENSE_TRACKER_\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense name: ");
                scanf("%s", input);
                printf("Enter expense amount: ");
                scanf("%f", &expense_amount);
                ADD_EXPENSE(input, expense_amount);
                break;

            case 2:
                _print_expenses();
                break;

            case 3:
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

#undef ADD_EXPENSE