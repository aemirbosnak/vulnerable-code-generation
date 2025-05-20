//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define expense categories
enum category {
    FOOD,
    RENT,
    UTILITIES,
    TRANSPORTATION,
    ENTERTAINMENT,
    OTHER
};

// Define expense structure
typedef struct expense {
    char *description;
    double amount;
    enum category category;
} expense_t;

// Define linked list node structure
typedef struct node {
    expense_t *expense;
    struct node *next;
} node_t;

// Create a new expense
expense_t *create_expense(char *description, double amount, enum category category) {
    expense_t *expense = malloc(sizeof(expense_t));
    expense->description = strdup(description);
    expense->amount = amount;
    expense->category = category;
    return expense;
}

// Add an expense to the linked list
void add_expense(node_t **head, expense_t *expense) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->expense = expense;
    new_node->next = *head;
    *head = new_node;
}

// Print the expenses in the linked list
void print_expenses(node_t *head) {
    while (head != NULL) {
        printf("%s: $%.2f (%s)\n", head->expense->description, head->expense->amount, head->expense->category == FOOD ? "Food" : head->expense->category == RENT ? "Rent" : head->expense->category == UTILITIES ? "Utilities" : head->expense->category == TRANSPORTATION ? "Transportation" : head->expense->category == ENTERTAINMENT ? "Entertainment" : "Other");
        head = head->next;
    }
}

// Free the linked list
void free_list(node_t *head) {
    while (head != NULL) {
        node_t *next = head->next;
        free(head->expense->description);
        free(head->expense);
        free(head);
        head = next;
    }
}

int main() {
    // Create a linked list to store expenses
    node_t *head = NULL;

    // Add some expenses to the linked list
    add_expense(&head, create_expense("Groceries", 100.00, FOOD));
    add_expense(&head, create_expense("Rent", 1200.00, RENT));
    add_expense(&head, create_expense("Utilities", 200.00, UTILITIES));
    add_expense(&head, create_expense("Transportation", 300.00, TRANSPORTATION));
    add_expense(&head, create_expense("Entertainment", 100.00, ENTERTAINMENT));
    add_expense(&head, create_expense("Other", 50.00, OTHER));

    // Print the expenses in the linked list
    print_expenses(head);

    // Free the linked list
    free_list(head);

    return 0;
}