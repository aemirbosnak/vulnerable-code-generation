//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the income and expense categories
enum category {
    INCOME,
    EXPENSE
};

// Define the income and expense subcategories
enum subcategory {
    SALARY,
    INVESTMENTS,
    RENT,
    UTILITIES,
    FOOD,
    TRANSPORTATION,
    ENTERTAINMENT,
    OTHER
};

// Declare the struct for each transaction
typedef struct {
    char description[50];
    double amount;
    enum category category;
    enum subcategory subcategory;
} transaction;

// Declare the struct for the personal finance planner
typedef struct {
    char name[50];
    double balance;
    transaction transactions[100];
    int num_transactions;
} personal_finance_planner;

// Function to create a new personal finance planner
personal_finance_planner* create_planner(char* name) {
    personal_finance_planner* planner = (personal_finance_planner*)malloc(sizeof(personal_finance_planner));
    strcpy(planner->name, name);
    planner->balance = 0.0;
    planner->num_transactions = 0;
    return planner;
}

// Function to add a transaction to the personal finance planner
void add_transaction(personal_finance_planner* planner, transaction* transaction) {
    planner->transactions[planner->num_transactions] = *transaction;
    planner->num_transactions++;
    planner->balance += (transaction->category == INCOME) ? transaction->amount : -transaction->amount;
}

// Function to print the personal finance planner
void print_planner(personal_finance_planner* planner) {
    printf("Personal Finance Planner for %s\n", planner->name);
    printf("Balance: $%.2f\n", planner->balance);
    printf("Transactions:\n");
    for (int i = 0; i < planner->num_transactions; i++) {
        printf("  %s: $%.2f\n", planner->transactions[i].description, planner->transactions[i].amount);
    }
}

// Function to free the memory allocated for the personal finance planner
void free_planner(personal_finance_planner* planner) {
    free(planner);
}

// Main function
int main() {
    // Create a new personal finance planner
    personal_finance_planner* planner = create_planner("John Doe");

    // Add some transactions to the personal finance planner
    transaction salary = {"Salary", 2000.00, INCOME, SALARY};
    add_transaction(planner, &salary);

    transaction rent = {"Rent", -1000.00, EXPENSE, RENT};
    add_transaction(planner, &rent);

    transaction utilities = {"Utilities", -200.00, EXPENSE, UTILITIES};
    add_transaction(planner, &utilities);

    transaction food = {"Food", -300.00, EXPENSE, FOOD};
    add_transaction(planner, &food);

    transaction transportation = {"Transportation", -200.00, EXPENSE, TRANSPORTATION};
    add_transaction(planner, &transportation);

    transaction entertainment = {"Entertainment", -100.00, EXPENSE, ENTERTAINMENT};
    add_transaction(planner, &entertainment);

    transaction other = {"Other", -100.00, EXPENSE, OTHER};
    add_transaction(planner, &other);

    // Print the personal finance planner
    print_planner(planner);

    // Free the memory allocated for the personal finance planner
    free_planner(planner);

    return 0;
}