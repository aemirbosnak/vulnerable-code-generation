//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct Expense {
    char *description;
    float amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;

void add_expense(char *description, float amount) {
    Expense *new_expense = malloc(sizeof(Expense));
    new_expense->description = description;
    new_expense->amount = amount;
    new_expense->next = NULL;

    if (head == NULL) {
        head = new_expense;
    } else {
        Expense *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_expense;
    }

    printf("Thank you for sharing your generosity, %f for %s\n", amount, description);
}

void print_expenses() {
    Expense *current = head;
    printf("Here are your blessings: \n");
    while (current != NULL) {
        printf(" - %s: %f\n", current->description, current->amount);
        current = current->next;
    }
}

void free_expenses() {
    Expense *current = head;
    while (current != NULL) {
        Expense *next = current->next;
        free(current->description);
        free(current);
        current = next;
    }
}

int main() {
    add_expense("Medical expenses", 100.00);
    add_expense("Groceries", 200.00);
    add_expense("Entertainment", 50.00);
    add_expense("Clothing", 100.00);
    add_expense("Transportation", 200.00);
    add_expense("Education", 100.00);
    add_expense("Savings", 500.00);

    print_expenses();
    free_expenses();

    return 0;
}