//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EXPENSES 100

typedef struct Expense {
    char name[50];
    float amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;

void add_expense(const char *name, float amount) {
    Expense *new_expense = (Expense *)malloc(sizeof(Expense));
    strcpy(new_expense->name, name);
    new_expense->amount = amount;
    new_expense->next = head;
    head = new_expense;
}

void display_expenses() {
    Expense *current = head;
    printf("\n%-20s %-10s\n", "Expense Name", "Amount");
    while (current != NULL) {
        printf("%-20s %-10.2f\n", current->name, current->amount);
        current = current->next;
    }
}

void remove_expense(const char *name) {
    Expense *previous = NULL;
    Expense *current = head;

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Expense not found.\n");
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

int main() {
    char command[20];
    char name[50];
    float amount;

    while (true) {
        printf("\nExpense Tracker\n");
        printf("Enter command (add/display/remove/quit): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        switch (command[0]) {
        case 'a':
            printf("Enter expense name: ");
            scanf("%s", name);
            printf("Enter expense amount: ");
            scanf("%f", &amount);
            add_expense(name, amount);
            break;

        case 'd':
            display_expenses();
            break;

        case 'r':
            printf("Enter expense name to remove: ");
            scanf("%s", name);
            remove_expense(name);
            break;

        default:
            printf("Invalid command.\n");
            break;
        }
    }

    return 0;
}