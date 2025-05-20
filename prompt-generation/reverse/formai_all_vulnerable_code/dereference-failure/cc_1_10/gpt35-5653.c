//FormAI DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char item[50];
    float amount;
    struct Expense* next;
};

typedef struct Expense Expense;

Expense* head = NULL;

void addExpense(char item[50], float amount) {
    Expense* newExpense = (Expense*) malloc(sizeof(Expense));
    strcpy(newExpense->item, item);
    newExpense->amount = amount;

    if (head == NULL) {
        head = newExpense;
        head->next = NULL;
        printf("First expense added: %s - %.2f\n", head->item, head->amount);
    } else {
        Expense* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newExpense;
        newExpense->next = NULL;
        printf("Expense added: %s - %.2f\n", newExpense->item, newExpense->amount);
    }
}

void removeExpense(char item[50]) {
    Expense* current = head;
    Expense* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->item, item) == 0) {
            if (previous == NULL) { // remove head
                head = current->next;
                printf("Expense removed: %s - %.2f\n", current->item, current->amount);
            } else {
                previous->next = current->next;
                printf("Expense removed: %s - %.2f\n", current->item, current->amount);
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Expense not found.\n");
}

void displayExpenses() {
    if (head == NULL) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("Expenses:\n");
    Expense* current = head;
    while (current != NULL) {
        printf("%s - %.2f\n", current->item, current->amount);
        current = current->next;
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n\n");

    char choice = ' ';
    while (choice != '4') {
        printf("\nPlease choose an option:\n");
        printf("1. Add an expense\n");
        printf("2. Remove an expense\n");
        printf("3. Display all expenses\n");
        printf("4. Exit\n");

        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("\nEnter item name: ");
                char item[50];
                scanf("%s", item);
                printf("Enter amount: ");
                float amount;
                scanf("%f", &amount);
                addExpense(item, amount);
                break;
            case '2':
                printf("\nEnter item name: ");
                char itemToRemove[50];
                scanf("%s", itemToRemove);
                removeExpense(itemToRemove);
                break;
            case '3':
                displayExpenses();
                break;
            case '4':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    }

    Expense* current = head;
    while (current != NULL) {
        Expense* next = current->next;
        free(current);
        current = next;
    }
    head = NULL;

    return 0;
}