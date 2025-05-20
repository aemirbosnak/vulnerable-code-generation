//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

// Define an expense struct
typedef struct expense {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
    struct expense *next;
} expense;

// Define a linked list of expenses
struct expense *head = NULL;

// Function to add an expense to the linked list
void add_expense(char *name, char *description, float amount) {
    // Check if the linked list is empty
    if (head == NULL) {
        // Create a new expense and add it to the linked list
        head = malloc(sizeof(expense));
        strcpy(head->name, name);
        strcpy(head->description, description);
        head->amount = amount;
        head->next = NULL;
    } else {
        // Add the new expense to the end of the linked list
        struct expense *current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        // Create a new expense and add it to the end of the linked list
        current->next = malloc(sizeof(expense));
        strcpy(current->next->name, name);
        strcpy(current->next->description, description);
        current->next->amount = amount;
        current->next->next = NULL;
    }
}

// Function to print the linked list of expenses
void print_expenses() {
    // Check if the linked list is empty
    if (head == NULL) {
        printf("No expenses to print.\n");
    } else {
        // Print the expenses
        struct expense *current = head;
        while (current != NULL) {
            printf("Name: %s\n", current->name);
            printf("Description: %s\n", current->description);
            printf("Amount: %.2f\n\n", current->amount);
            current = current->next;
        }
    }
}

// Function to free the linked list of expenses
void free_expenses() {
    // Check if the linked list is empty
    if (head == NULL) {
        return;
    } else {
        // Free the expenses
        struct expense *current = head;
        while (current != NULL) {
            struct expense *next = current->next;
            free(current);
            current = next;
        }

        head = NULL;
    }
}

// Main function
int main() {
    // Add some expenses to the linked list
    add_expense("Groceries", "Bought food for the week", 100.00);
    add_expense("Gas", "Filled up the car", 50.00);
    add_expense("Entertainment", "Went to the movies", 20.00);

    // Print the expenses
    printf("Current expenses:\n");
    print_expenses();

    // Free the expenses
    free_expenses();

    return 0;
}