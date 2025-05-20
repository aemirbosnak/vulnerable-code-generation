//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data structures used for the program
typedef struct
{
    char *name;
    double amount;
    int year;
    int month;
    int day;
} Transaction;

typedef struct
{
    Transaction *transactions;
    int numTransactions;
    double totalIncome;
    double totalExpenses;
    double netIncome;
} Budget;

// Function to create a new budget
Budget *createBudget()
{
    Budget *budget = malloc(sizeof(Budget));
    budget->transactions = NULL;
    budget->numTransactions = 0;
    budget->totalIncome = 0;
    budget->totalExpenses = 0;
    budget->netIncome = 0;
    return budget;
}

// Function to add a new transaction to a budget
void addTransaction(Budget *budget, Transaction transaction)
{
    budget->transactions = realloc(budget->transactions, (budget->numTransactions + 1) * sizeof(Transaction));
    budget->transactions[budget->numTransactions] = transaction;
    budget->numTransactions++;
    if (transaction.amount > 0)
    {
        budget->totalIncome += transaction.amount;
    }
    else
    {
        budget->totalExpenses += transaction.amount;
    }
    budget->netIncome = budget->totalIncome - budget->totalExpenses;
}

// Function to print the details of a budget
void printBudget(Budget *budget)
{
    printf("Total Income: %.2f\n", budget->totalIncome);
    printf("Total Expenses: %.2f\n", budget->totalExpenses);
    printf("Net Income: %.2f\n", budget->netIncome);
}

// Function to free the memory allocated for a budget
void freeBudget(Budget *budget)
{
    free(budget->transactions);
    free(budget);
}

// Main function
int main()
{
    // Create a new budget
    Budget *budget = createBudget();

    // Add some transactions to the budget
    Transaction transaction1 = {"Salary", 2000, 2022, 1, 1};
    addTransaction(budget, transaction1);
    Transaction transaction2 = {"Rent", -500, 2022, 1, 1};
    addTransaction(budget, transaction2);
    Transaction transaction3 = {"Groceries", -100, 2022, 1, 2};
    addTransaction(budget, transaction3);
    Transaction transaction4 = {"Entertainment", -50, 2022, 1, 3};
    addTransaction(budget, transaction4);

    // Print the details of the budget
    printBudget(budget);

    // Free the memory allocated for the budget
    freeBudget(budget);

    return 0;
}