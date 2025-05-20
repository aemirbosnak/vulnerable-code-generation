//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    float amount;
    int category;
    struct Expense *next;
} Expense;

#define NUM_CATEGORIES 5
int main() {
    Expense *head = NULL;
    Expense *current = NULL;
    int choice = 0;
    int category = 0;
    char name[50];
    float amount = 0.0;

    while(true) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. List Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Search Expense\n");
        printf("5. View Expenses by Category\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter expense name: ");
                scanf("%s", name);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                printf("Enter expense category (1-Food, 2-Transport, 3-Entertainment, 4-Housing, 5-Other): ");
                scanf("%d", &category);

                current = (Expense *) malloc(sizeof(Expense));
                strcpy(current->name, name);
                current->amount = amount;
                current->category = category;
                current->next = head;
                head = current;
                break;
            // Add more cases for other options here
            // ...
            case 6:
                free(head);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}