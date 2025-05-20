//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of categories and transactions
#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

// Define the transaction structure
typedef struct {
    char description[50];
    float amount;
    char category[50];
} transaction_t;

// Define the category structure
typedef struct {
    char name[50];
    float budget;
    float actual;
} category_t;

// Define the personal finance planner structure
typedef struct {
    char name[50];
    float income;
    float expenses;
    float savings;
    category_t categories[MAX_CATEGORIES];
    transaction_t transactions[MAX_TRANSACTIONS];
} personal_finance_planner_t;

// Create a new personal finance planner
personal_finance_planner_t* create_personal_finance_planner(char* name, float income) {
    personal_finance_planner_t* planner = malloc(sizeof(personal_finance_planner_t));
    strcpy(planner->name, name);
    planner->income = income;
    planner->expenses = 0;
    planner->savings = 0;
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        strcpy(planner->categories[i].name, "");
        planner->categories[i].budget = 0;
        planner->categories[i].actual = 0;
    }
    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        strcpy(planner->transactions[i].description, "");
        planner->transactions[i].amount = 0;
        strcpy(planner->transactions[i].category, "");
    }
    return planner;
}

// Add a category to the personal finance planner
void add_category(personal_finance_planner_t* planner, char* name, float budget) {
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        if (strcmp(planner->categories[i].name, "") == 0) {
            strcpy(planner->categories[i].name, name);
            planner->categories[i].budget = budget;
            planner->categories[i].actual = 0;
            break;
        }
    }
}

// Add a transaction to the personal finance planner
void add_transaction(personal_finance_planner_t* planner, char* description, float amount, char* category) {
    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        if (strcmp(planner->transactions[i].description, "") == 0) {
            strcpy(planner->transactions[i].description, description);
            planner->transactions[i].amount = amount;
            strcpy(planner->transactions[i].category, category);
            planner->expenses += amount;
            for (int j = 0; j < MAX_CATEGORIES; j++) {
                if (strcmp(planner->categories[j].name, category) == 0) {
                    planner->categories[j].actual += amount;
                    break;
                }
            }
            break;
        }
    }
}

// Calculate the savings for the personal finance planner
void calculate_savings(personal_finance_planner_t* planner) {
    planner->savings = planner->income - planner->expenses;
}

// Print the personal finance planner
void print_personal_finance_planner(personal_finance_planner_t* planner) {
    printf("Name: %s\n", planner->name);
    printf("Income: %f\n", planner->income);
    printf("Expenses: %f\n", planner->expenses);
    printf("Savings: %f\n", planner->savings);
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        if (strcmp(planner->categories[i].name, "") != 0) {
            printf("Category: %s\n", planner->categories[i].name);
            printf("Budget: %f\n", planner->categories[i].budget);
            printf("Actual: %f\n", planner->categories[i].actual);
        }
    }
    for (int i = 0; i < MAX_TRANSACTIONS; i++) {
        if (strcmp(planner->transactions[i].description, "") != 0) {
            printf("Transaction: %s\n", planner->transactions[i].description);
            printf("Amount: %f\n", planner->transactions[i].amount);
            printf("Category: %s\n", planner->transactions[i].category);
        }
    }
}

// Free the memory allocated for the personal finance planner
void free_personal_finance_planner(personal_finance_planner_t* planner) {
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner_t* planner = create_personal_finance_planner("John Doe", 5000);

    // Add some categories to the personal finance planner
    add_category(planner, "Food", 500);
    add_category(planner, "Transportation", 300);
    add_category(planner, "Entertainment", 200);

    // Add some transactions to the personal finance planner
    add_transaction(planner, "Groceries", 100, "Food");
    add_transaction(planner, "Gas", 50, "Transportation");
    add_transaction(planner, "Movie tickets", 30, "Entertainment");

    // Calculate the savings for the personal finance planner
    calculate_savings(planner);

    // Print the personal finance planner
    print_personal_finance_planner(planner);

    // Free the memory allocated for the personal finance planner
    free_personal_finance_planner(planner);

    return 0;
}