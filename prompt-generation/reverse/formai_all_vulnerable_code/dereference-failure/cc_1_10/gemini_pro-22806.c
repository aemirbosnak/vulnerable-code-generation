//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for storing expenses
typedef struct Expense {
    char *description;
    float amount;
    struct Expense *next;
} Expense;

// Node structure for storing incomes
typedef struct Income {
    char *source;
    float amount;
    struct Income *next;
} Income;

// Head of the expenses linked list
Expense *expenses = NULL;

// Head of the incomes linked list
Income *incomes = NULL;

// Function to add an expense to the linked list
void addExpense(char *description, float amount) {
    // Create a new expense node
    Expense *newExpense = (Expense *) malloc(sizeof(Expense));

    // Allocate memory for the description
    newExpense->description = (char *) malloc(strlen(description) + 1);
    strcpy(newExpense->description, description);

    // Set the amount
    newExpense->amount = amount;

    // Set the next pointer to NULL
    newExpense->next = NULL;

    // If the expenses linked list is empty, set the head of the list to the new expense
    if (expenses == NULL) {
        expenses = newExpense;
    } else {
        // Otherwise, add the new expense to the end of the list
        Expense *currentExpense = expenses;
        while (currentExpense->next != NULL) {
            currentExpense = currentExpense->next;
        }
        currentExpense->next = newExpense;
    }
}

// Function to add an income to the linked list
void addIncome(char *source, float amount) {
    // Create a new income node
    Income *newIncome = (Income *) malloc(sizeof(Income));

    // Allocate memory for the source
    newIncome->source = (char *) malloc(strlen(source) + 1);
    strcpy(newIncome->source, source);

    // Set the amount
    newIncome->amount = amount;

    // Set the next pointer to NULL
    newIncome->next = NULL;

    // If the incomes linked list is empty, set the head of the list to the new income
    if (incomes == NULL) {
        incomes = newIncome;
    } else {
        // Otherwise, add the new income to the end of the list
        Income *currentIncome = incomes;
        while (currentIncome->next != NULL) {
            currentIncome = currentIncome->next;
        }
        currentIncome->next = newIncome;
    }
}

// Function to print the expenses linked list
void printExpenses() {
    // If the expenses linked list is empty, print a message
    if (expenses == NULL) {
        printf("No expenses to display.\n");
    } else {
        // Otherwise, print the expenses
        Expense *currentExpense = expenses;
        while (currentExpense != NULL) {
            printf("%s: $%.2f\n", currentExpense->description, currentExpense->amount);
            currentExpense = currentExpense->next;
        }
    }
}

// Function to print the incomes linked list
void printIncomes() {
    // If the incomes linked list is empty, print a message
    if (incomes == NULL) {
        printf("No incomes to display.\n");
    } else {
        // Otherwise, print the incomes
        Income *currentIncome = incomes;
        while (currentIncome != NULL) {
            printf("%s: $%.2f\n", currentIncome->source, currentIncome->amount);
            currentIncome = currentIncome->next;
        }
    }
}

// Function to calculate the total expenses
float calculateTotalExpenses() {
    float total = 0;

    // Iterate over the expenses linked list and add each expense to the total
    Expense *currentExpense = expenses;
    while (currentExpense != NULL) {
        total += currentExpense->amount;
        currentExpense = currentExpense->next;
    }

    return total;
}

// Function to calculate the total incomes
float calculateTotalIncomes() {
    float total = 0;

    // Iterate over the incomes linked list and add each income to the total
    Income *currentIncome = incomes;
    while (currentIncome != NULL) {
        total += currentIncome->amount;
        currentIncome = currentIncome->next;
    }

    return total;
}

// Function to calculate the net balance
float calculateNetBalance() {
    return calculateTotalIncomes() - calculateTotalExpenses();
}

// Main function
int main() {
    // Add some expenses to the linked list
    addExpense("Rent", 1000);
    addExpense("Groceries", 200);
    addExpense("Utilities", 150);
    addExpense("Entertainment", 100);

    // Add some incomes to the linked list
    addIncome("Salary", 2000);
    addIncome("Investments", 500);
    addIncome("Other", 100);

    // Print the expenses
    printf("Expenses:\n");
    printExpenses();

    // Print the incomes
    printf("Incomes:\n");
    printIncomes();

    // Calculate the total expenses
    float totalExpenses = calculateTotalExpenses();
    printf("Total expenses: $%.2f\n", totalExpenses);

    // Calculate the total incomes
    float totalIncomes = calculateTotalIncomes();
    printf("Total incomes: $%.2f\n", totalIncomes);

    // Calculate the net balance
    float netBalance = calculateNetBalance();
    printf("Net balance: $%.2f\n", netBalance);

    return 0;
}