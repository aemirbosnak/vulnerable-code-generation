//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: real-life
#include <stdio.h>

#define MAX_EXPENSES 10

int main() 
{ 
    int expenses[MAX_EXPENSES]; // Declare an array to store expenses
    
    int total_expenses = 0; // Initialize total expenses variable to zero
    
    int i; // Loop counter variable
    
    for (i = 0; i < MAX_EXPENSES; i++) { // Loop through all the expenses
        expenses[i] = 0; // Initialize each expense to zero
    }
    
    printf("Enter the name of the expense and its category: "); // Prompt user to enter expense information
    
    char name[50]; // Declare a string variable to store the name of the expense
    
    char category[20]; // Declare a string variable to store the category of the expense
    
    scanf("%s %s", name, category); // Read the name and category of the expense
    
    int expense_index = -1; // Initialize index variable to -1
    
    for (i = 0; i < MAX_EXPENSES; i++) { // Loop through all the expenses
        if (strcmp(name, expenses[i]) == 0) { // If the expense already exists
            expense_index = i; // Update the index variable to the current position of the expense
            break;
        }
    }
    
    if (expense_index == -1) { // If the expense doesn't exist
        expenses[i] = 1; // Add the expense to the end of the array
        total_expenses++; // Increment total expenses
    }
    
    printf("Expense added!\n"); // Print a message to indicate that the expense has been added
    
    for (i = 0; i < MAX_EXPENSES; i++) { // Loop through all the expenses
        if (expenses[i] == 1) { // If the expense exists
            printf("Expense Name: %s\n", name); // Print the name of the expense
            printf("Expense Category: %s\n", category); // Print the category of the expense
        }
    }
    
    printf("Total expenses: %d\n", total_expenses); // Print the total number of expenses
    
    return 0; // Return 0 to indicate successful execution
}