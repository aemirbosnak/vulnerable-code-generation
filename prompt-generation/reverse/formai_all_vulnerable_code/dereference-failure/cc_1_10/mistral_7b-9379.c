//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Expense {
    char description[100];
    float amount;
    struct Expense* next;
} Expense;

Expense* head = NULL;
Expense* current = NULL;
Expense* temp = NULL;

void addExpense() {
    if (head == NULL) {
        head = (Expense*)malloc(sizeof(Expense));
        printf("Enter Expense Description: ");
        scanf("%s", head->description);
        printf("Enter Expense Amount: ");
        scanf("%f", &head->amount);
        head->next = NULL;
        current = head;
    } else {
        temp = (Expense*)malloc(sizeof(Expense));
        printf("Enter Expense Description: ");
        scanf("%s", temp->description);
        printf("Enter Expense Amount: ");
        scanf("%f", &temp->amount);
        temp->next = NULL;

        current->next = temp;
        current = temp;
    }
}

void displayExpenses() {
    if (head == NULL) {
        printf("No Expenses Added Yet!\n");
    } else {
        printf("\nExpense List:\n");
        current = head;
        while (current != NULL) {
            printf("%s : %.2f\n", current->description, current->amount);
            current = current->next;
        }
    }
}

void searchExpense() {
    char searchDescription[100];
    bool found = false;
    if (head == NULL) {
        printf("No Expenses Added Yet!\n");
    } else {
        printf("Enter Expense Description to Search: ");
        scanf("%s", searchDescription);

        current = head;
        while (current != NULL) {
            if (strcmp(current->description, searchDescription) == 0) {
                printf("Expense Found! : %s : %.2f\n", current->description, current->amount);
                found = true;
                break;
            }
            current = current->next;
        }
        if (!found) {
            printf("Expense Not Found!\n");
        }
    }
}

int main() {
    int choice;

    while (true) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Search Expense\n");
        printf("4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                displayExpenses();
                break;
            case 3:
                searchExpense();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice! Please Try Again.\n");
        }
    }
    return 0;
}