//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Define the structure to store expense information
struct Expense {
    char name[100];
    double amount;
    struct Expense *next;
};

// Function to initialize the head of the linked list
void init_head(struct Expense *head) {
    head->next = NULL;
}

// Function to add an expense to the linked list
void add_expense(struct Expense **head, char *name, double amount) {
    struct Expense *new_expense = malloc(sizeof(struct Expense));
    if (new_expense == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(new_expense->name, name);
    new_expense->amount = amount;
    new_expense->next = *head;
    *head = new_expense;
}

// Function to print the expenses in the linked list
void print_expenses(struct Expense *head) {
    struct Expense *current = head;
    while (current!= NULL) {
        printf("Name: %s, Amount: %f\n", current->name, current->amount);
        current = current->next;
    }
}

// Function to delete an expense from the linked list
void delete_expense(struct Expense **head, char *name) {
    struct Expense *current = *head;
    struct Expense *prev = NULL;

    while (current!= NULL && strcmp(current->name, name)!= 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Expense not found\n");
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

int main() {
    struct Expense *head = NULL;
    init_head(head);

    // Add some expenses
    add_expense(&head, "Groceries", 100.0);
    add_expense(&head, "Rent", 1000.0);
    add_expense(&head, "Utilities", 200.0);

    // Print the expenses
    print_expenses(head);

    // Delete an expense
    delete_expense(&head, "Groceries");

    // Print the expenses again
    print_expenses(head);

    return 0;
}