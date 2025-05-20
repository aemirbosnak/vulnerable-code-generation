//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EXPENSES 1000

typedef struct Expense {
    char name[MAX_NAME_LENGTH];
    float amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;
Expense *current = NULL;
Expense *prev = NULL;
int num_expenses = 0;

void add_expense() {
    Expense *new_expense = (Expense *)malloc(sizeof(Expense));

    printf("Enter expense name: ");
    scanf("%s", new_expense->name);

    printf("Enter expense amount: ");
    scanf("%f", &new_expense->amount);

    new_expense->next = NULL;

    if (head == NULL) {
        head = new_expense;
        current = head;
    } else {
        current->next = new_expense;
        current = new_expense;
    }

    num_expenses++;
}

void edit_expense() {
    int index;
    Expense *temp;

    printf("Enter expense index to edit: ");
    scanf("%d", &index);

    temp = head;

    for (int i = 0; i < index && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid index.\n");
        return;
    }

    printf("Enter new expense name: ");
    scanf("%s", temp->name);

    printf("Enter new expense amount: ");
    scanf("%f", &temp->amount);
}

void delete_expense() {
    int index;
    Expense *temp, *prev;

    printf("Enter expense index to delete: ");
    scanf("%d", &index);

    temp = head;

    for (int i = 0; i < index && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid index.\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    num_expenses--;
}

void display_expenses() {
    Expense *temp = head;
    float total = 0;

    printf("\nExpenses:\n");

    while (temp != NULL) {
        printf("%s: %.2f\n", temp->name, temp->amount);
        total += temp->amount;
        temp = temp->next;
    }

    printf("\nTotal expenses: %.2f\n", total);
    printf("Average expense: %.2f\n", total / num_expenses);
}

int main() {
    int choice;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. Edit expense\n");
        printf("3. Delete expense\n");
        printf("4. Display expenses\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                edit_expense();
                break;
            case 3:
                delete_expense();
                break;
            case 4:
                display_expenses();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}