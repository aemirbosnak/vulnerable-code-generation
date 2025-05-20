//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
    char description[50];
    float amount;
    char category[50];
    char date[20];
} expense_t;

// Function to print the menu
void print_menu() {
    printf("\nExpense Tracker\n");
    printf("1. Add an expense\n");
    printf("2. View expenses\n");
    printf("3. Search expenses\n");
    printf("4. Delete an expense\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
}

// Function to add an expense
void add_expense(expense_t expenses[], int *num_expenses) {
    // Get the expense details from the user
    printf("Enter the expense description: ");
    scanf(" %[^\n]%*c", expenses[*num_expenses].description);
    printf("Enter the expense amount: ");
    scanf("%f", &expenses[*num_expenses].amount);
    printf("Enter the expense category: ");
    scanf(" %[^\n]%*c", expenses[*num_expenses].category);
    printf("Enter the expense date (YYYY-MM-DD): ");
    scanf(" %[^\n]%*c", expenses[*num_expenses].date);

    // Increment the number of expenses
    (*num_expenses)++;
}

// Function to view expenses
void view_expenses(expense_t expenses[], int num_expenses) {
    // Print the header
    printf("\n%-5s  %-50s  %-10s  %-10s  %-10s\n", "ID", "Description", "Amount", "Category", "Date");

    // Print each expense
    for (int i = 0; i < num_expenses; i++) {
        printf("%-5d  %-50s  %-10.2f  %-10s  %-10s\n", i + 1, expenses[i].description, expenses[i].amount, expenses[i].category, expenses[i].date);
    }
}

// Function to search expenses
void search_expenses(expense_t expenses[], int num_expenses) {
    // Get the search term from the user
    char search_term[50];
    printf("Enter the search term: ");
    scanf(" %[^\n]%*c", search_term);

    // Search for the expense
    int found = 0;
    for (int i = 0; i < num_expenses; i++) {
        if (strstr(expenses[i].description, search_term) != NULL || strstr(expenses[i].category, search_term) != NULL || strstr(expenses[i].date, search_term) != NULL) {
            // Print the expense
            printf("\n%-5s  %-50s  %-10s  %-10s  %-10s\n", "ID", "Description", "Amount", "Category", "Date");
            printf("%-5d  %-50s  %-10.2f  %-10s  %-10s\n", i + 1, expenses[i].description, expenses[i].amount, expenses[i].category, expenses[i].date);
            found = 1;
        }
    }

    // If no expenses were found, print a message
    if (!found) {
        printf("No expenses found matching the search term.\n");
    }
}

// Function to delete an expense
void delete_expense(expense_t expenses[], int *num_expenses) {
    // Get the ID of the expense to be deleted
    int id;
    printf("Enter the ID of the expense to be deleted: ");
    scanf("%d", &id);

    // Delete the expense
    for (int i = id - 1; i < *num_expenses - 1; i++) {
        expenses[i] = expenses[i + 1];
    }

    // Decrement the number of expenses
    (*num_expenses)--;
}

// Main function
int main() {
    // Define the array of expenses
    expense_t expenses[MAX_EXPENSES];

    // Initialize the number of expenses to 0
    int num_expenses = 0;

    // Main loop
    while (1) {
        // Print the menu
        print_menu();

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                add_expense(expenses, &num_expenses);
                break;
            case 2:
                view_expenses(expenses, num_expenses);
                break;
            case 3:
                search_expenses(expenses, num_expenses);
                break;
            case 4:
                delete_expense(expenses, &num_expenses);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}