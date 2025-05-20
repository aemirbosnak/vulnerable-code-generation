//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

typedef struct expense {
    char category[50];
    float amount;
    struct expense *next_expense;
} Expense;

Expense *head = NULL;

void add_expense() {
    Expense *new_expense = (Expense *) malloc(sizeof(Expense));
    printf("Enter category of expense: ");
    scanf("%s", new_expense->category);
    printf("Enter amount of expense: ");
    scanf("%f", &new_expense->amount);
    new_expense->next_expense = head;
    head = new_expense;
    printf("Expense added successfully!\n");
}

void view_expenses() {
    if(head == NULL) {
        printf("No expenses to display.\n");
        return;
    }
    Expense *current_expense = head;
    printf("------------------------------------------\n");
    printf("| %-25s | %-10s |\n", "Category", "Amount");
    printf("------------------------------------------\n");
    while(current_expense != NULL) {
        printf("| %-25s | $%-9.2f |\n", current_expense->category, current_expense->amount);
        current_expense = current_expense->next_expense;
    }
    printf("------------------------------------------\n");
}

void search_expense() {
    char category[50];
    printf("Enter category to search: ");
    scanf("%s", category);
    Expense *current_expense = head;
    int found = 0;
    while(current_expense != NULL) {
        if(strcmp(current_expense->category, category) == 0) {
            printf("Category: %s\n", current_expense->category);
            printf("Amount: $%.2f\n", current_expense->amount);
            found = 1;
        }
        current_expense = current_expense->next_expense;
    }
    if(!found) {
        printf("Category not found.\n");
    }
}

void delete_expense() {
    char category[50];
    printf("Enter category to delete: ");
    scanf("%s", category);
    Expense *current_expense = head;
    Expense *prev_expense = NULL;
    int found = 0;
    while(current_expense != NULL) {
        if(strcmp(current_expense->category, category) == 0) {
            if(prev_expense == NULL) {
                head = head->next_expense;
            } else {
                prev_expense->next_expense = current_expense->next_expense;
            }
            free(current_expense);
            printf("Expense deleted successfully!\n");
            found = 1;
            break;
        }
        prev_expense = current_expense;
        current_expense = current_expense->next_expense;
    }
    if(!found) {
        printf("Category not found.\n");
    }
}

int main() {
    int choice;
    printf("C Expense Tracker\n");
    printf("=================\n\n");
    while(1) {
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Search expense\n");
        printf("4. Delete expense\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                search_expense();
                break;
            case 4:
                delete_expense();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    }
    return 0;
}