//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Holy moly! This is the ultimate expense tracker!

// Define the expense structure
typedef struct expense {
    char *description;
    float amount;
    struct expense *next;
} expense;

// Declare the head of the expense list
expense *head = NULL;

// Insert an expense into the list
void insert_expense(char *description, float amount) {
    // Allocate memory for the new expense
    expense *new_expense = malloc(sizeof(expense));
    
    // Check if the allocation was successful
    if (new_expense == NULL) {
        printf("Oh no! I can't allocate memory for the new expense! :(\n");
        exit(1);
    }
    
    // Initialize the new expense
    new_expense->description = strdup(description);
    new_expense->amount = amount;
    new_expense->next = NULL;

    // Insert the new expense at the head of the list
    new_expense->next = head;
    head = new_expense;
}

// Print the expenses in the list
void print_expenses() {
    // Declare a pointer to traverse the list
    expense *current = head;

    // Print the header
    printf("Holy moly! Here are your expenses:\n");

    // Print each expense
    while (current != NULL) {
        printf(" - %s: $%.2f\n", current->description, current->amount);
        current = current->next;
    }
}

// Get the total amount of expenses
float get_total_expenses() {
    // Declare a variable to store the total amount
    float total = 0.0;

    // Declare a pointer to traverse the list
    expense *current = head;

    // Calculate the total amount
    while (current != NULL) {
        total += current->amount;
        current = current->next;
    }

    return total;
}

// Main function
int main() {
    // Oh my goodness! Let's add some expenses!
    insert_expense("Groceries", 50.00);
    insert_expense("Gas", 25.00);
    insert_expense("Entertainment", 10.00);
    insert_expense("Rent", 1000.00);

    // Holy moly! Let's print the expenses!
    print_expenses();

    // Wow! Let's get the total amount of expenses!
    float total = get_total_expenses();
    printf("OMG! The total amount of expenses is: $%.2f\n", total);

    return 0;
}