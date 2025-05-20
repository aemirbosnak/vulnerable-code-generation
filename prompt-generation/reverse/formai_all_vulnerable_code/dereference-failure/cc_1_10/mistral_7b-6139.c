//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Expense {
    char description[50];
    float amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;

void add_expense(char *desc, float amt) {
    Expense *new_expense = (Expense *) malloc(sizeof(Expense));
    strcpy(new_expense->description, desc);
    new_expense->amount = amt;
    new_expense->next = head;
    head = new_expense;
}

void display_expenses() {
    Expense *current = head;
    printf("\nCurrent Expenses:\n");
    while (current != NULL) {
        printf("Description: %s, Amount: %.2f\n", current->description, current->amount);
        current = current->next;
    }
}

void delete_expense(char *desc) {
    Expense *current = head, *prev = NULL;
    while (current != NULL && strcmp(current->description, desc) != 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Expense not found.\n");
        return;
    }
    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

int main() {
    char desc[50];
    float amt;
    int choice;

    while (true) {
        printf("\nFrugalBuddy Menu:\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense description: ");
                scanf("%s", desc);
                printf("Enter expense amount: ");
                scanf("%f", &amt);
                add_expense(desc, amt);
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                printf("Enter expense description to delete: ");
                scanf("%s", desc);
                delete_expense(desc);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}