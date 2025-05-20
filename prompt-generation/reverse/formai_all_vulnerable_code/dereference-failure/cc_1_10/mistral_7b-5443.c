//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct Expense {
    char description[50];
    float amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;
Expense *current = NULL;
Expense newExpense;

void addExpense() {
    if (head == NULL) {
        head = (Expense *) malloc(sizeof(Expense));
        printf("Enter expense description: ");
        fgets(head->description, sizeof(head->description), stdin);
        strtok(head->description, "\n");
        printf("Enter expense amount: ");
        scanf("%f", &head->amount);
        head->next = NULL;
        current = head;
    } else {
        current->next = (Expense *) malloc(sizeof(Expense));
        current = current->next;
        printf("Enter expense description: ");
        fgets(current->description, sizeof(current->description), stdin);
        strtok(current->description, "\n");
        printf("Enter expense amount: ");
        scanf("%f", &current->amount);
        current->next = NULL;
    }
}

void removeExpense(char *description) {
    Expense *previous = head;
    Expense *temp;

    if (head == NULL) {
        printf("No expenses to remove.\n");
        return;
    }

    if (strcmp(head->description, description) == 0) {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    while (previous->next != NULL && strcmp(previous->next->description, description) != 0) {
        previous = previous->next;
    }

    if (previous->next == NULL) {
        printf("Expense not found.\n");
        return;
    }

    temp = previous->next;
    previous->next = temp->next;
    free(temp);
}

void displayExpenses() {
    Expense *temp = head;

    if (head == NULL) {
        printf("No expenses to display.\n");
        return;
    }

    printf("Expenses:\n");
    while (temp != NULL) {
        printf("Description: %s, Amount: %.2f\n", temp->description, temp->amount);
        temp = temp->next;
    }
}

int main() {
    int choice;
    char description[50];

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Remove Expense\n");
        printf("3. Display Expenses\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                printf("Enter expense description to remove: ");
                fgets(description, sizeof(description), stdin);
                strtok(description, "\n");
                removeExpense(description);
                break;
            case 3:
                displayExpenses();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}