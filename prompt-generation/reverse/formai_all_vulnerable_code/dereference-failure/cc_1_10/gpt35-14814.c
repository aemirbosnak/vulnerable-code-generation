//FormAI DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char category[20];
    float amount;
    struct Expense *next;
};

void addExpense(struct Expense **head, char category[], float amount) {
    struct Expense *newExpense = malloc(sizeof(struct Expense));
    strcpy(newExpense->category, category);
    newExpense->amount = amount;
    newExpense->next = *head;
    *head = newExpense;
}

void printTotalExpense(struct Expense *head) {
    float totalExpense = 0;
    struct Expense *temp = head;
    while(temp != NULL) {
        totalExpense += temp->amount;
        temp = temp->next;
    }
    printf("Total Expense: $%.2f\n", totalExpense);
}

void printExpenseByCategory(struct Expense *head, char category[]) {
    float totalExpense = 0;
    struct Expense *temp = head;
    while(temp != NULL) {
        if(strcmp(temp->category, category) == 0) {
            totalExpense += temp->amount;
        }
        temp = temp->next;
    }
    printf("%s Expense: $%.2f\n", category, totalExpense);
}

int main() {
    struct Expense *head = NULL;

    while(1) {
        printf("\nExpense Tracker Menu\n");
        printf("1. Add Expense\n");
        printf("2. View Total Expense\n");
        printf("3. View Expense by Category\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("Enter expense category: ");
                char category[20];
                scanf("%s", category);
                printf("Enter expense amount: ");
                float amount;
                scanf("%f", &amount);
                addExpense(&head, category, amount);
                printf("Expense added!\n");
                break;
            }
            case 2: {
                printTotalExpense(head);
                break;
            }
            case 3: {
                printf("Enter category to view expense: ");
                char category[20];
                scanf("%s", category);
                printExpenseByCategory(head, category);
                break;
            }
            case 4: {
                printf("Thank you for using Expense Tracker!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    }

    return 0;
}