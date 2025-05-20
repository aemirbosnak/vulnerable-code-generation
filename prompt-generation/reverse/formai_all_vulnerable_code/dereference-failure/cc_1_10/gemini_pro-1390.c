//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the expense structure
typedef struct expense {
    char *description;  // Description of the expense
    float amount;      // Amount of the expense
    struct expense *next;  // Pointer to the next expense in the list
} expense_t;

// Create a new expense
expense_t* create_expense(char *description, float amount) {
    expense_t *new_expense = (expense_t*)malloc(sizeof(expense_t));
    new_expense->description = description;
    new_expense->amount = amount;
    new_expense->next = NULL;
    return new_expense;
}

// Add an expense to the list
void add_expense(expense_t **head, expense_t *new_expense) {
    if (*head == NULL) {
        *head = new_expense;
    } else {
        expense_t *current_expense = *head;
        while (current_expense->next != NULL) {
            current_expense = current_expense->next;
        }
        current_expense->next = new_expense;
    }
}

// Print the list of expenses
void print_expenses(expense_t *head) {
    expense_t *current_expense = head;
    while (current_expense != NULL) {
        printf("%s: $%.2f\n", current_expense->description, current_expense->amount);
        current_expense = current_expense->next;
    }
}

// Calculate the total amount of expenses
float calculate_total(expense_t *head) {
    float total = 0;
    expense_t *current_expense = head;
    while (current_expense != NULL) {
        total += current_expense->amount;
        current_expense = current_expense->next;
    }
    return total;
}

// Free the memory allocated for the list of expenses
void free_expenses(expense_t *head) {
    expense_t *current_expense = head;
    while (current_expense != NULL) {
        expense_t *next_expense = current_expense->next;
        free(current_expense->description);
        free(current_expense);
        current_expense = next_expense;
    }
}

// Main function
int main() {
    // Create a new expense list
    expense_t *head = NULL;

    // Add some expenses to the list
    add_expense(&head, create_expense("Dinner", 20.00));
    add_expense(&head, create_expense("Movie tickets", 15.00));
    add_expense(&head, create_expense("Gas", 30.00));
    add_expense(&head, create_expense("Groceries", 50.00));

    // Print the list of expenses
    printf("Your expenses:\n");
    print_expenses(head);

    // Calculate the total amount of expenses
    float total = calculate_total(head);
    printf("\nTotal: $%.2f\n", total);

    // Free the memory allocated for the list of expenses
    free_expenses(head);

    return 0;
}