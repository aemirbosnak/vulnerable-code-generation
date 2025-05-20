//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of categories and transactions
#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

// Define the category structure
typedef struct {
    char name[50];
    double amount;
} Category;

// Define the transaction structure
typedef struct {
    char date[20];
    char description[100];
    double amount;
    Category* category;
} Transaction;

// Define the personal finance planner structure
typedef struct {
    Category categories[MAX_CATEGORIES];
    Transaction transactions[MAX_TRANSACTIONS];
    int numCategories;
    int numTransactions;
} PersonalFinancePlanner;

// Create a new personal finance planner
PersonalFinancePlanner* createPersonalFinancePlanner() {
    PersonalFinancePlanner* planner = (PersonalFinancePlanner*) malloc(sizeof(PersonalFinancePlanner));
    planner->numCategories = 0;
    planner->numTransactions = 0;
    return planner;
}

// Add a new category to the personal finance planner
void addCategory(PersonalFinancePlanner* planner, char* name) {
    if (planner->numCategories >= MAX_CATEGORIES) {
        printf("Error: Maximum number of categories reached.\n");
        return;
    }
    strcpy(planner->categories[planner->numCategories].name, name);
    planner->categories[planner->numCategories].amount = 0.0;
    planner->numCategories++;
}

// Add a new transaction to the personal finance planner
void addTransaction(PersonalFinancePlanner* planner, char* date, char* description, double amount, Category* category) {
    if (planner->numTransactions >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }
    strcpy(planner->transactions[planner->numTransactions].date, date);
    strcpy(planner->transactions[planner->numTransactions].description, description);
    planner->transactions[planner->numTransactions].amount = amount;
    planner->transactions[planner->numTransactions].category = category;
    planner->numTransactions++;
}

// Print the personal finance planner
void printPersonalFinancePlanner(PersonalFinancePlanner* planner) {
    printf("Categories:\n");
    for (int i = 0; i < planner->numCategories; i++) {
        printf("  %s: $%.2f\n", planner->categories[i].name, planner->categories[i].amount);
    }
    printf("Transactions:\n");
    for (int i = 0; i < planner->numTransactions; i++) {
        printf("  %s: %s: $%.2f\n", planner->transactions[i].date, planner->transactions[i].description, planner->transactions[i].amount);
    }
}

// Free the memory allocated for the personal finance planner
void freePersonalFinancePlanner(PersonalFinancePlanner* planner) {
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    PersonalFinancePlanner* planner = createPersonalFinancePlanner();

    // Add some categories to the planner
    addCategory(planner, "Income");
    addCategory(planner, "Expenses");

    // Add some transactions to the planner
    addTransaction(planner, "2023-01-01", "Salary", 2000.00, &planner->categories[0]);
    addTransaction(planner, "2023-01-05", "Groceries", -100.00, &planner->categories[1]);
    addTransaction(planner, "2023-01-10", "Rent", -500.00, &planner->categories[1]);
    addTransaction(planner, "2023-01-15", "Utilities", -150.00, &planner->categories[1]);

    // Print the personal finance planner
    printPersonalFinancePlanner(planner);

    // Free the memory allocated for the personal finance planner
    freePersonalFinancePlanner(planner);

    return 0;
}