//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// A node in the expense linked list
typedef struct ExpenseNode {
    char* description;
    double amount;
    struct ExpenseNode* next;
} ExpenseNode;

// A function to create a new expense node
ExpenseNode* createExpenseNode(char* description, double amount) {
    ExpenseNode* node = malloc(sizeof(ExpenseNode));
    node->description = description;
    node->amount = amount;
    node->next = NULL;
    return node;
}

// A function to insert a new expense node into a linked list
ExpenseNode* insertExpenseNode(ExpenseNode* head, ExpenseNode* node) {
    if (head == NULL) {
        return node;
    } else {
        node->next = head;
        return node;
    }
}

// A function to print the expenses in a linked list
void printExpenses(ExpenseNode* head) {
    if (head == NULL) {
        printf("No expenses to print.\n");
    } else {
        printf("Description: %s\n", head->description);
        printf("Amount: %.2f\n", head->amount);
        printExpenses(head->next);
    }
}

// A function to calculate the total expenses in a linked list
double calculateTotalExpenses(ExpenseNode* head) {
    if (head == NULL) {
        return 0.0;
    } else {
        return head->amount + calculateTotalExpenses(head->next);
    }
}

// A function to free the memory allocated for a linked list of expenses
void freeExpenses(ExpenseNode* head) {
    if (head == NULL) {
        return;
    } else {
        freeExpenses(head->next);
        free(head->description);
        free(head);
    }
}

// The main function
int main() {
    // Create a new expense linked list
    ExpenseNode* head = NULL;

    // Insert some expenses into the linked list
    head = insertExpenseNode(head, createExpenseNode("Groceries", 100.00));
    head = insertExpenseNode(head, createExpenseNode("Rent", 1200.00));
    head = insertExpenseNode(head, createExpenseNode("Car payment", 500.00));
    head = insertExpenseNode(head, createExpenseNode("Utilities", 200.00));
    head = insertExpenseNode(head, createExpenseNode("Other", 100.00));

    // Print the expenses in the linked list
    printExpenses(head);

    // Calculate the total expenses in the linked list
    double totalExpenses = calculateTotalExpenses(head);
    printf("Total expenses: %.2f\n", totalExpenses);

    // Free the memory allocated for the linked list
    freeExpenses(head);

    return 0;
}