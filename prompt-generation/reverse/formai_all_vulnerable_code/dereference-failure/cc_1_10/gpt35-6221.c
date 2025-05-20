//FormAI DATASET v1.0 Category: Expense Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    int id;                 // unique ID for each expense
    char category[50];      // category of expense
    float amount;           // amount spent
    char date[11];          // date of expense (MM/DD/YYYY format)
    struct expense *next;
};

// function to add a new expense to the linked list
void add_expense(struct expense **head) {
    struct expense *curr = *head;
    struct expense *new_expense = malloc(sizeof(struct expense));
    memset(new_expense, 0, sizeof(struct expense));

    printf("Enter expense category: ");
    fgets(new_expense->category, 50, stdin);
    printf("Enter amount spent: ");
    scanf("%f", &new_expense->amount);
    printf("Enter date of expense (MM/DD/YYYY): ");
    scanf("%s", new_expense->date);

    // assign ID to new expense
    if (*head == NULL) {
        new_expense->id = 1;
    } else {
        while (curr->next != NULL) {
            curr = curr->next;
        }
        new_expense->id = curr->id + 1;
    }

    new_expense->next = NULL;

    if (*head == NULL) {
        *head = new_expense;
    } else {
        curr->next = new_expense;
    }
}

// function to print all expenses in the linked list
void print_expenses(struct expense *head) {
    if (head == NULL) {
        printf("No expenses found!");
    } else {
        printf("%-5s %-20s %-10s %s\n", "ID", "Category", "Amount", "Date");
        while (head != NULL) {
            printf("%-5d %-20s $%-9.2f %s\n", head->id, head->category, head->amount, head->date);
            head = head->next;
        }
    }
}

// function to delete an expense from the linked list
void delete_expense(struct expense **head, int id) {
    struct expense *curr = *head;
    struct expense *prev = NULL;

    if (*head == NULL) {
        printf("No expenses found!");
        return;
    }

    if ((*head)->id == id) {
        *head = (*head)->next;
        free(curr);
        printf("Expense with ID %d deleted successfully!\n", id);
        return;
    }

    while (curr != NULL && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Expense with ID %d not found!\n", id);
        return;
    }

    prev->next = curr->next;
    free(curr);
    printf("Expense with ID %d deleted successfully!\n", id);
}

int main() {
    struct expense *head = NULL;
    int choice, id;

    while (1) {
        printf("\n1. Add new expense\n2. Print all expenses\n3. Delete an expense\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_expense(&head);
                break;
            case 2:
                print_expenses(head);
                break;
            case 3:
                printf("Enter expense ID to delete: ");
                scanf("%d", &id);
                getchar();
                delete_expense(&head, id);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}