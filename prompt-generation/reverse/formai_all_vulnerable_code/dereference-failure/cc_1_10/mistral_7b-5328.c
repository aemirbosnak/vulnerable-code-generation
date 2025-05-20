//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct Expense {
    char description[50];
    float amount;
    struct Expense *next;
} Expense;

Expense *expenses_head = NULL;

void add_expense(const char *description, float amount) {
    Expense *new_expense = malloc(sizeof(Expense));
    strcpy(new_expense->description, description);
    new_expense->amount = amount;
    new_expense->next = expenses_head;
    expenses_head = new_expense;
}

void print_expenses() {
    Expense *current_expense = expenses_head;
    printf("Expenses:\n");
    while (current_expense != NULL) {
        printf("%s: %.2f\n", current_expense->description, current_expense->amount);
        current_expense = current_expense->next;
    }
}

int main() {
    int choice;
    char description[50];
    float amount;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Print Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense description: ");
                scanf("%s", description);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                add_expense(description, amount);
                break;
            case 2:
                print_expenses();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}