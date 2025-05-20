//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 10

struct Expense {
    char name[50];
    int amount;
    struct Expense* next;
};

void addExpense(struct Expense** head) {
    struct Expense* newExpense = (struct Expense*)malloc(sizeof(struct Expense));
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

void displayExpenses(struct Expense* head) {
    struct Expense* currentExpense = head;
    printf("List of expenses:\n");
    while (currentExpense) {
        printf("%s - %d\n", currentExpense->name, currentExpense->amount);
        currentExpense = currentExpense->next;
    }
}

int main() {
    struct Expense* head = NULL;
    int choice;

    while (1) {
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&head);
                break;
            case 2:
                displayExpenses(head);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Do you want to continue? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'N') {
            break;
        }
    }

    return 0;
}