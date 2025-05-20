//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct Expense {
    char *name;
    double amount;
    struct Expense *next;
} Expense;

Expense *new_expense(char *name, double amount) {
    Expense *expense = malloc(sizeof(Expense));
    expense->name = name;
    expense->amount = amount;
    expense->next = NULL;
    return expense;
}

void add_expense(Expense **head, Expense *expense) {
    if (*head == NULL) {
        *head = expense;
    } else {
        add_expense(&(*head)->next, expense);
    }
}

void print_expenses(Expense *head) {
    if (head == NULL) {
        return;
    }
    printf("%s: %.2f\n", head->name, head->amount);
    print_expenses(head->next);
}

double total_expenses(Expense *head) {
    if (head == NULL) {
        return 0;
    }
    return head->amount + total_expenses(head->next);
}

void free_expenses(Expense *head) {
    if (head == NULL) {
        return;
    }
    free(head->name);
    free_expenses(head->next);
    free(head);
}

int main() {
    Expense *expenses = NULL;

    // Add some expenses
    add_expense(&expenses, new_expense("Rent", 1200));
    add_expense(&expenses, new_expense("Groceries", 200));
    add_expense(&expenses, new_expense("Entertainment", 100));

    // Print the expenses
    print_expenses(expenses);

    // Print the total expenses
    printf("Total expenses: %.2f\n", total_expenses(expenses));

    // Free the expenses
    free_expenses(expenses);

    return 0;
}