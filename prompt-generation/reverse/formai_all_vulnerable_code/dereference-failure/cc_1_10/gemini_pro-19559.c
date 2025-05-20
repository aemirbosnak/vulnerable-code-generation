//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Data structure to store expenses
typedef struct {
    char* category;
    float amount;
    struct expense* next;
} expense;

// Create a new expense
expense* create_expense(char* category, float amount) {
    expense* new_expense = malloc(sizeof(expense));
    new_expense->category = category;
    new_expense->amount = amount;
    new_expense->next = NULL;
    return new_expense;
}

// Add a new expense to the list
void add_expense(expense** head, char* category, float amount) {
    expense* new_expense = create_expense(category, amount);
    if (*head == NULL) {
        *head = new_expense;
    } else {
        expense* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_expense;
    }
}

// Print the list of expenses
void print_expenses(expense* head) {
    expense* current = head;
    while (current != NULL) {
        printf("%s: $%.2f\n", current->category, current->amount);
        current = current->next;
    }
}

// Calculate the total expenses
float calculate_total(expense* head) {
    float total = 0;
    expense* current = head;
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }
    return total;
}

// Main function
int main() {
    printf("Welcome to the Happy Personal Finance Planner!\n");

    // Create a linked list to store expenses
    expense* head = NULL;

    // Add some sample expenses
    add_expense(&head, "Groceries", 100);
    add_expense(&head, "Entertainment", 50);
    add_expense(&head, "Transportation", 150);

    // Print the list of expenses
    printf("Your expenses:\n");
    print_expenses(head);

    // Calculate the total expenses
    float total = calculate_total(head);
    printf("Your total expenses: $%.2f\n", total);

    return 0;
}