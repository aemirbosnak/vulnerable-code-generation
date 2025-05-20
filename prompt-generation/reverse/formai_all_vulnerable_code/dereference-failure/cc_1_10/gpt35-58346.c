//FormAI DATASET v1.0 Category: Expense Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_EXPENSES 100  // Maximum number of expenses
#define MAX_NAME_LENGTH 30  // Maximum length of expense name

// Define a struct to represent an expense
struct Expense {
    char name[MAX_NAME_LENGTH];
    float amount;
    char date[11];  // Format "YYYY-MM-DD"
};

// Declare global variables
struct Expense expenses[MAX_EXPENSES];  // Array to store all expenses
int numExpenses = 0;  // Number of expenses

// Declare functions
void printMenu();
void addExpense();
void viewExpenses();
void saveToFile();
void readFromFile();

// Main function
int main() {
    // Load existing expenses from file (if any)
    readFromFile();

    // Display menu and get user input
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        getchar();  // Consume newline character from input buffer

        // Perform user-selected action
        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                saveToFile();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function to display main menu
void printMenu() {
    printf("\n--- Expense Tracker ---\n");
    printf("1. Add expense\n");
    printf("2. View expenses\n");
    printf("3. Save to file\n");
    printf("4. Exit\n");
    printf("Please enter your choice (1-4): ");
}

// Function to add an expense
void addExpense() {
    // Make sure there is room for another expense
    if (numExpenses == MAX_EXPENSES) {
        printf("Maximum number of expenses reached.\n");
        return;
    }

    // Get expense details from user input
    printf("\nEnter expense name: ");
    fgets(expenses[numExpenses].name, MAX_NAME_LENGTH, stdin);
    expenses[numExpenses].name[strcspn(expenses[numExpenses].name, "\n")] = 0;  // Remove newline character
    printf("Enter expense amount: $");
    scanf("%f", &expenses[numExpenses].amount);
    getchar();  // Consume newline character from input buffer
    printf("Enter expense date (YYYY-MM-DD): ");
    fgets(expenses[numExpenses].date, 11, stdin);
    expenses[numExpenses].date[strcspn(expenses[numExpenses].date, "\n")] = 0;  // Remove newline character

    // Increment number of expenses
    numExpenses++;

    // Print confirmation message
    printf("\nExpense added successfully!\n");
}

// Function to view all expenses
void viewExpenses() {
    // Make sure there are expenses to view
    if (numExpenses == 0) {
        printf("No expenses to view.\n");
        return;
    }

    // Print headers
    printf("\nExpense ID  | Expense Name                 | Amount  | Date\n");
    printf("--------------------------------------------------------------\n");

    // Print each expense's details
    for (int i = 0; i < numExpenses; i++) {
        printf("%-11d | %-29s | $%-6.2f | %s\n",
            i + 1, expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

// Function to save all expenses to file
void saveToFile() {
    // Make sure there are expenses to save
    if (numExpenses == 0) {
        printf("No expenses to save.\n");
        return;
    }

    // Get filename from user input
    printf("\nEnter filename to save to (including extension): ");
    char filename[256];
    fgets(filename, 256, stdin);
    filename[strcspn(filename, "\n")] = 0;  // Remove newline character

    // Open file for writing
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Write each expense's details to file
    for (int i = 0; i < numExpenses; i++) {
        fprintf(file, "%s,%f,%s\n",
            expenses[i].name, expenses[i].amount, expenses[i].date);
    }

    // Close file
    fclose(file);

    // Print confirmation message
    printf("\nExpenses saved to file successfully!\n");
}

// Function to read all expenses from file
void readFromFile() {
    // Get filename from user input
    printf("\nEnter filename to load from (including extension): ");
    char filename[256];
    fgets(filename, 256, stdin);
    filename[strcspn(filename, "\n")] = 0;  // Remove newline character

    // Open file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read each line from file and parse as an expense
    char line[256];
    while (fgets(line, 256, file) != NULL) {
        // Make sure there is room for another expense
        if (numExpenses == MAX_EXPENSES) {
            printf("Maximum number of expenses reached.\n");
            return;
        }

        // Parse expense details from line
        char *name = strtok(line, ",");
        float amount = atof(strtok(NULL, ","));
        char *date = strtok(NULL, "\n");

        // Assign parsed details to new expense
        strcpy(expenses[numExpenses].name, name);
        expenses[numExpenses].amount = amount;
        strcpy(expenses[numExpenses].date, date);

        // Increment number of expenses
        numExpenses++;
    }

    // Close file
    fclose(file);

    // Print confirmation message
    printf("\nExpenses loaded from file successfully!\n");
}