//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expense {
    char name[50];
    float cost;
    struct expense* next;
} Expense;

Expense* createExpense(char* name, float cost) {
    Expense* exp = (Expense*)malloc(sizeof(Expense));
    strcpy(exp->name, name);
    exp->cost = cost;
    exp->next = NULL;
    return exp;
}

void addExpense(Expense** head, Expense* exp) {
    if (*head == NULL) {
        *head = exp;
    } else {
        Expense* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = exp;
    }
}

void printExpenses(Expense* head) {
    Expense* current = head;
    while (current != NULL) {
        printf("%s: $%.2f\n", current->name, current->cost);
        current = current->next;
    }
}

float getTotal(Expense* head) {
    float total = 0.0;
    Expense* current = head;
    while (current != NULL) {
        total += current->cost;
        current = current->next;
    }
    return total;
}

int main() {
    Expense* head = NULL;
    int choice;
    char name[50];
    float cost;
    do {
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Get total\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Name: ");
                scanf("%s", name);
                printf("Cost: ");
                scanf("%f", &cost);
                addExpense(&head, createExpense(name, cost));
                printf("Expense added!\n");
                break;
            case 2:
                printExpenses(head);
                break;
            case 3:
                printf("Total: $%.2f\n", getTotal(head));
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}