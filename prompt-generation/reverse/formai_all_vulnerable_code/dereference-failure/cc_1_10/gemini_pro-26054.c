//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store expense details
typedef struct expense {
    char *category;
    float amount;
    char *description;
    struct expense *next;
} expense_t;

// Function to create a new expense
expense_t *create_expense(char *category, float amount, char *description) {
    expense_t *new_expense = (expense_t *)malloc(sizeof(expense_t));
    new_expense->category = strdup(category);
    new_expense->amount = amount;
    new_expense->description = strdup(description);
    new_expense->next = NULL;
    return new_expense;
}

// Function to add an expense to the list
void add_expense(expense_t **head, expense_t *new_expense) {
    if (*head == NULL) {
        *head = new_expense;
    } else {
        expense_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_expense;
    }
}

// Function to print the list of expenses
void print_expenses(expense_t *head) {
    expense_t *current = head;
    while (current != NULL) {
        printf("%s: $%.2f - %s\n", current->category, current->amount, current->description);
        current = current->next;
    }
}

// Function to calculate the total expenses
float calculate_total_expenses(expense_t *head) {
    float total = 0;
    expense_t *current = head;
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }
    return total;
}

// Function to calculate the average expenses
float calculate_average_expenses(expense_t *head) {
    float total = calculate_total_expenses(head);
    int count = 0;
    expense_t *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return total / count;
}

// Function to find the most expensive category
char *find_most_expensive_category(expense_t *head) {
    char *most_expensive_category = NULL;
    float max_amount = 0;
    expense_t *current = head;
    while (current != NULL) {
        if (current->amount > max_amount) {
            max_amount = current->amount;
            most_expensive_category = current->category;
        }
        current = current->next;
    }
    return most_expensive_category;
}

// Function to free the memory allocated for the list of expenses
void free_expenses(expense_t *head) {
    expense_t *current = head;
    while (current != NULL) {
        expense_t *next = current->next;
        free(current->category);
        free(current->description);
        free(current);
        current = next;
    }
}

int main() {
    // Create the head of the linked list
    expense_t *head = NULL;

    // Add some expenses to the list
    add_expense(&head, create_expense("Food", 100.0, "Groceries and eating out"));
    add_expense(&head, create_expense("Transportation", 50.0, "Gas, public transportation, and car repairs"));
    add_expense(&head, create_expense("Entertainment", 25.0, "Movies, concerts, and other forms of entertainment"));
    add_expense(&head, create_expense("Shopping", 100.0, "Clothing, electronics, and other purchases"));
    add_expense(&head, create_expense("Utilities", 150.0, "Electricity, gas, and water"));
    add_expense(&head, create_expense("Other", 50.0, "Miscellaneous expenses"));

    // Print the list of expenses
    printf("Expenses:\n");
    print_expenses(head);

    // Calculate the total expenses
    float total_expenses = calculate_total_expenses(head);
    printf("Total expenses: $%.2f\n", total_expenses);

    // Calculate the average expenses
    float average_expenses = calculate_average_expenses(head);
    printf("Average expenses: $%.2f\n", average_expenses);

    // Find the most expensive category
    char *most_expensive_category = find_most_expensive_category(head);
    printf("Most expensive category: %s\n", most_expensive_category);

    // Free the memory allocated for the list of expenses
    free_expenses(head);

    return 0;
}