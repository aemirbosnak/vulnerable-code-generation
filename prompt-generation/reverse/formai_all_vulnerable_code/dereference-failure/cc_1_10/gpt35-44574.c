//FormAI DATASET v1.0 Category: Expense Tracker ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct expense {
    char category[20];
    float amount;
    struct expense *next;
};

void addExpense(struct expense **head, char category[20], float amount) {
    struct expense *newExpense = (struct expense*)malloc(sizeof(struct expense));
    strcpy(newExpense->category, category);
    newExpense->amount = amount;
    if(*head == NULL) {
        *head = newExpense;
        (*head)->next = NULL;
    }
    else {
        struct expense *curr = *head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newExpense;
        newExpense->next = NULL;
    }
}

void printExpense(struct expense **head) {
    printf("Category\tAmount\n");
    struct expense *curr = *head;
    while(curr != NULL) {
        printf("%s\t%.2f\n", curr->category, curr->amount);
        curr = curr->next;
    }
}

void totalExpense(struct expense **head) {
    float sum = 0.0;
    struct expense *curr = *head;
    while(curr != NULL) {
        sum += curr->amount;
        curr = curr->next;
    }
    printf("Total Expenses: $%.2f\n", sum);
}

int main() {
    struct expense *head = NULL;
    int option;
    char category[20];
    float amount;
    printf("Welcome to Expense Tracker\n");
    do {
        printf("\n1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Total Expenses\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter expense category: ");
                scanf("%s", category);
                printf("Enter expense amount: $");
                scanf("%f", &amount);
                addExpense(&head, category, amount);
                break;
            case 2:
                printf("\nExpense Details:\n");
                printExpense(&head);
                break;
            case 3:
                totalExpense(&head);
                break;
            case 4:
                printf("\nThank you for using Expense Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid option. Please try again!\n");
        }
    } while(option != 4);
    return 0;
}