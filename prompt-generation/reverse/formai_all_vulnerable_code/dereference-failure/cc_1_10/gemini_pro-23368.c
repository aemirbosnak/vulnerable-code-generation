//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
    char description[50];
    float amount;
    char date[11];
} Expense;

// Define the structure of a node in the decentralized expense tracker
typedef struct Node {
    Expense expense;
    struct Node *next;
} Node;

// Define the head of the decentralized expense tracker
Node *head = NULL;

// Function to add an expense to the decentralized expense tracker
void add_expense(Expense expense) {
    // Create a new node
    Node *new_node = malloc(sizeof(Node));

    // Copy the expense into the new node
    new_node->expense = expense;

    // Set the next pointer of the new node to the current head of the list
    new_node->next = head;

    // Set the head of the list to the new node
    head = new_node;
}

// Function to print the expenses in the decentralized expense tracker
void print_expenses() {
    // If the list is empty, print a message
    if (head == NULL) {
        printf("No expenses to print.\n");
        return;
    }

    // Iterate over the list and print each expense
    Node *current = head;
    while (current != NULL) {
        printf("%s %.2f %s\n", current->expense.description, current->expense.amount, current->expense.date);
        current = current->next;
    }
}

// Function to get the total amount of expenses in the decentralized expense tracker
float get_total_amount() {
    // If the list is empty, return 0
    if (head == NULL) {
        return 0;
    }

    // Iterate over the list and calculate the total amount
    Node *current = head;
    float total_amount = 0;
    while (current != NULL) {
        total_amount += current->expense.amount;
        current = current->next;
    }

    return total_amount;
}

// Function to get the average amount of expenses in the decentralized expense tracker
float get_average_amount() {
    // If the list is empty, return 0
    if (head == NULL) {
        return 0;
    }

    // Iterate over the list and calculate the total amount and count of expenses
    Node *current = head;
    float total_amount = 0;
    int count = 0;
    while (current != NULL) {
        total_amount += current->expense.amount;
        count++;
        current = current->next;
    }

    return total_amount / count;
}

// Function to get the maximum amount of expenses in the decentralized expense tracker
float get_max_amount() {
    // If the list is empty, return 0
    if (head == NULL) {
        return 0;
    }

    // Iterate over the list and find the maximum amount
    Node *current = head;
    float max_amount = 0;
    while (current != NULL) {
        if (current->expense.amount > max_amount) {
            max_amount = current->expense.amount;
        }
        current = current->next;
    }

    return max_amount;
}

// Function to get the minimum amount of expenses in the decentralized expense tracker
float get_min_amount() {
    // If the list is empty, return 0
    if (head == NULL) {
        return 0;
    }

    // Iterate over the list and find the minimum amount
    Node *current = head;
    float min_amount = current->expense.amount;
    while (current != NULL) {
        if (current->expense.amount < min_amount) {
            min_amount = current->expense.amount;
        }
        current = current->next;
    }

    return min_amount;
}

// Main function
int main() {
    // Create some sample expenses
    Expense expenses[] = {
        {"Groceries", 100.00, "2023-01-01"},
        {"Gas", 50.00, "2023-01-02"},
        {"Entertainment", 25.00, "2023-01-03"},
        {"Rent", 1200.00, "2023-01-04"},
        {"Utilities", 150.00, "2023-01-05"},
    };

    // Add the sample expenses to the decentralized expense tracker
    for (int i = 0; i < sizeof(expenses) / sizeof(expenses[0]); i++) {
        add_expense(expenses[i]);
    }

    // Print the expenses in the decentralized expense tracker
    printf("Expenses:\n");
    print_expenses();

    // Get the total amount of expenses in the decentralized expense tracker
    float total_amount = get_total_amount();
    printf("Total amount: %.2f\n", total_amount);

    // Get the average amount of expenses in the decentralized expense tracker
    float average_amount = get_average_amount();
    printf("Average amount: %.2f\n", average_amount);

    // Get the maximum amount of expenses in the decentralized expense tracker
    float max_amount = get_max_amount();
    printf("Maximum amount: %.2f\n", max_amount);

    // Get the minimum amount of expenses in the decentralized expense tracker
    float min_amount = get_min_amount();
    printf("Minimum amount: %.2f\n", min_amount);

    return 0;
}