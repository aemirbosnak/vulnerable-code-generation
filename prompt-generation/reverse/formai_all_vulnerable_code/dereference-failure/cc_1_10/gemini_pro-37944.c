//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the main structure for the personal finance planner
typedef struct personal_finance_planner {
    char *name;
    double income;
    double expenses;
    double savings;
    double net_worth;
    struct personal_finance_planner *next;
} personal_finance_planner;

// Create a new personal finance planner
personal_finance_planner *create_personal_finance_planner(char *name, double income, double expenses, double savings, double net_worth) {
    // Allocate memory for the new personal finance planner
    personal_finance_planner *new_planner = (personal_finance_planner *)malloc(sizeof(personal_finance_planner));

    // Check if the memory was allocated successfully
    if (new_planner == NULL) {
        printf("Error: Could not allocate memory for the new personal finance planner.\n");
        return NULL;
    }

    // Initialize the new personal finance planner
    new_planner->name = strdup(name);
    new_planner->income = income;
    new_planner->expenses = expenses;
    new_planner->savings = savings;
    new_planner->net_worth = net_worth;
    new_planner->next = NULL;

    // Return the new personal finance planner
    return new_planner;
}

// Add a new personal finance planner to the end of the list
void add_personal_finance_planner(personal_finance_planner **head, personal_finance_planner *new_planner) {
    // Check if the list is empty
    if (*head == NULL) {
        // If the list is empty, set the new personal finance planner as the head of the list
        *head = new_planner;
    } else {
        // If the list is not empty, add the new personal finance planner to the end of the list
        personal_finance_planner *current_planner = *head;
        while (current_planner->next != NULL) {
            current_planner = current_planner->next;
        }
        current_planner->next = new_planner;
    }
}

// Print the personal finance planner
void print_personal_finance_planner(personal_finance_planner *planner) {
    // Print the planner's name
    printf("Name: %s\n", planner->name);

    // Print the planner's income
    printf("Income: $%.2f\n", planner->income);

    // Print the planner's expenses
    printf("Expenses: $%.2f\n", planner->expenses);

    // Print the planner's savings
    printf("Savings: $%.2f\n", planner->savings);

    // Print the planner's net worth
    printf("Net worth: $%.2f\n\n", planner->net_worth);
}

// Free the memory allocated for the personal finance planner
void free_personal_finance_planner(personal_finance_planner *planner) {
    // Free the memory allocated for the planner's name
    free(planner->name);

    // Free the memory allocated for the planner
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner *planner = create_personal_finance_planner("John Doe", 50000, 30000, 20000, 100000);

    // Print the personal finance planner
    print_personal_finance_planner(planner);

    // Free the memory allocated for the personal finance planner
    free_personal_finance_planner(planner);

    return 0;
}