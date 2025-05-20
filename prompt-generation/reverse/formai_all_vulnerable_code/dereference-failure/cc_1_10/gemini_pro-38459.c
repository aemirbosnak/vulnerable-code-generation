//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store an expense
typedef struct expense {
    int id;
    char* description;
    double amount;
    char* date;
} expense;

// Array to store expenses
expense expenses[100];

// Index of the next available slot in the expenses array
int next_available_index = 0;

// Function to add an expense to the array
void add_expense(int id, char* description, double amount, char* date) {
    // Check if the array is full
    if (next_available_index >= 100) {
        printf("Error: The expense array is full.\n");
        return;
    }

    // Allocate memory for the description
    expenses[next_available_index].description = malloc(strlen(description) + 1);

    // Copy the description into the array
    strcpy(expenses[next_available_index].description, description);

    // Set the amount and date
    expenses[next_available_index].amount = amount;
    expenses[next_available_index].date = date;

    // Increment the index of the next available slot
    next_available_index++;
}

// Function to print the expenses in the array
void print_expenses() {
    // Loop through the expenses array
    for (int i = 0; i < next_available_index; i++) {
        // Print the expense
        printf("Expense %d:\n", expenses[i].id);
        printf("Description: %s\n", expenses[i].description);
        printf("Amount: %.2f\n", expenses[i].amount);
        printf("Date: %s\n\n", expenses[i].date);
    }
}

// Function to free the memory allocated for the descriptions
void free_descriptions() {
    // Loop through the expenses array
    for (int i = 0; i < next_available_index; i++) {
        // Free the memory allocated for the description
        free(expenses[i].description);
    }
}

// Main function
int main() {
    // Add some expenses to the array
    add_expense(1, "Groceries", 100.00, "2023-01-01");
    add_expense(2, "Gas", 50.00, "2023-01-05");
    add_expense(3, "Entertainment", 25.00, "2023-01-10");

    // Print the expenses in the array
    print_expenses();

    // Free the memory allocated for the descriptions
    free_descriptions();

    return 0;
}