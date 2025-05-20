//FormAI DATASET v1.0 Category: Expense Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for expense
struct expense {
    char name[50];
    float amount;
    struct expense *next;
};

// Define a function to create a new expense
struct expense *create_expense(char name[], float amount) {
    struct expense *e = (struct expense*) malloc(sizeof(struct expense));
    strcpy(e->name, name);
    e->amount = amount;
    e->next = NULL;
    return e;
}

// Define a function to add an expense recursively
void add_expense(struct expense **head, char name[], float amount) {
    if (*head == NULL) {
        *head = create_expense(name, amount);
    } else {
        add_expense(&(*head)->next, name, amount);
    }
}

// Define a function to print all expenses recursively
void print_expenses(struct expense *head) {
    if (head == NULL) {
        printf("No expenses recorded.\n");
    } else {
        printf("%s: $%.2f\n", head->name, head->amount);
        print_expenses(head->next);
    }
}

// Define a function to calculate total expenses recursively
float total_expenses(struct expense *head) {
    if (head == NULL) {
        return 0;
    } else {
        return head->amount + total_expenses(head->next);
    }
}

int main() {
    struct expense *head = NULL;

    // Add expenses
    add_expense(&head, "Grocery", 100.75);
    add_expense(&head, "Gas", 50.32);
    add_expense(&head, "Eating out", 25.50);
    add_expense(&head, "Entertainment", 30.00);

    // Print expenses
    printf("Expenses:\n");
    print_expenses(head);

    // Calculate total expenses
    printf("\nTotal expenses: $%.2f\n", total_expenses(head));

    return 0;
}