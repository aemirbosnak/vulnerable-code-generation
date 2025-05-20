//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Expense {
    char description[50];
    float amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;

void addExpense() {
    Expense *newExpense = (Expense *)malloc(sizeof(Expense));

    printf("Enter expense description: ");
    fgets(newExpense->description, sizeof(newExpense->description), stdin);
    newExpense->description[strcspn(newExpense->description, "\n")] = '\0';

    printf("Enter expense amount: ");
    scanf("%f", &newExpense->amount);

    if (head == NULL) {
        head = newExpense;
        newExpense->next = NULL;
    } else {
        Expense *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newExpense;
        newExpense->next = NULL;
    }

    printf("Expense added successfully!\n");
}

void listExpenses() {
    Expense *temp = head;
    if (head == NULL) {
        printf("No expenses to display.\n");
        return;
    }

    printf("\nExpense List:\n");
    while (temp != NULL) {
        printf("%s: %.2f\n", temp->description, temp->amount);
        temp = temp->next;
    }
}

void deleteExpense() {
    char description[50];
    Expense *current = head, *previous = NULL;

    printf("Enter expense description to delete: ");
    fgets(description, sizeof(description), stdin);
    description[strcspn(description, "\n")] = '\0';

    while (current != NULL && strcmp(current->description, description) != 0) {
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

    printf("Expense deleted successfully!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nMoneyMentor\n");
        printf("1. Add Expense\n");
        printf("2. List Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                listExpenses();
                break;
            case 3:
                deleteExpense();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}