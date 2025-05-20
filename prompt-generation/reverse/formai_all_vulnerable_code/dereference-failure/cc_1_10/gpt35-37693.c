//FormAI DATASET v1.0 Category: Expense Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

typedef struct expense_tracker {
    char item[MAX_LEN];
    float cost;
    struct expense_tracker *next;
} expense_tracker;

void print_menu() {
    printf("Welcome to Expense Tracker!\n");
    printf("1. Add an expense\n");
    printf("2. View all expenses\n");
    printf("3. View total expenses\n");
    printf("4. Exit\n");
}

expense_tracker *create_expense() {
    expense_tracker *expense = (expense_tracker*)malloc(sizeof(expense_tracker));
    printf("Enter expense item: ");
    scanf("%s", expense->item);
    printf("Enter expense cost: ");
    scanf("%f", &expense->cost);
    expense->next = NULL;
    return expense;
}

void insert_expense(expense_tracker **head_ptr, expense_tracker **tail_ptr, expense_tracker *expense) {
    if (*head_ptr == NULL) {
        *head_ptr = expense;
        *tail_ptr = expense;
    }
    else {
        (*tail_ptr)->next = expense;
        *tail_ptr = expense;
    }
    printf("Expense added successfully!\n");
}

void print_expenses(expense_tracker *head) {
    if (head == NULL) {
        printf("No expenses found.\n");
    }
    else {
        printf("Item\tCost\n");
        printf("----------------\n");
        while(head != NULL) {
            printf("%s\t%.2f\n", head->item, head->cost);
            head = head->next;
        }
    }
}

void print_total(expense_tracker *head) {
    float total = 0.0;
    while(head != NULL) {
        total += head->cost;
        head = head->next;
    }
    printf("Total expenses: %.2f\n", total);
}

int main() {
    int choice;
    expense_tracker *head = NULL;
    expense_tracker *tail = NULL;
    do {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                expense_tracker *expense = create_expense();
                insert_expense(&head, &tail, expense);
                break;
            }
            case 2: {
                print_expenses(head);
                break;
            }
            case 3: {
                print_total(head);
                break;
            }
            case 4: {
                printf("Exiting Expense Tracker. Goodbye!\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    } while(choice != 4);
    return 0;
}