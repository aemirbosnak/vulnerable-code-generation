//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Data structure to store an expense
typedef struct Expense {
    char* description;
    float amount;
    char* category;
} Expense;

// Function to create a new expense
Expense* createExpense(char* description, float amount, char* category) {
    Expense* expense = (Expense*) malloc(sizeof(Expense));
    expense->description = description;
    expense->amount = amount;
    expense->category = category;
    return expense;
}

// Function to print an expense
void printExpense(Expense* expense) {
    printf("Expense: %s\n", expense->description);
    printf("Amount: %.2f\n", expense->amount);
    printf("Category: %s\n", expense->category);
}

// Function to add an expense to a list of expenses
void addExpense(Expense*** expenses, int* numExpenses, Expense* expense) {
    *expenses = (Expense**) realloc(*expenses, (*numExpenses + 1) * sizeof(Expense*));
    (*expenses)[*numExpenses] = expense;
    (*numExpenses)++;
}

// Function to print a list of expenses
void printExpenses(Expense** expenses, int numExpenses) {
    for (int i = 0; i < numExpenses; i++) {
        printExpense(expenses[i]);
        printf("\n");
    }
}

// Function to get the total amount of expenses in a list of expenses
float getTotalAmount(Expense** expenses, int numExpenses) {
    float totalAmount = 0;
    for (int i = 0; i < numExpenses; i++) {
        totalAmount += expenses[i]->amount;
    }
    return totalAmount;
}

// Function to get the average amount of expenses in a list of expenses
float getAverageAmount(Expense** expenses, int numExpenses) {
    float averageAmount = 0;
    for (int i = 0; i < numExpenses; i++) {
        averageAmount += expenses[i]->amount;
    }
    averageAmount /= numExpenses;
    return averageAmount;
}

// Function to get the most expensive expense in a list of expenses
Expense* getMostExpensiveExpense(Expense** expenses, int numExpenses) {
    Expense* mostExpensiveExpense = expenses[0];
    for (int i = 1; i < numExpenses; i++) {
        if (expenses[i]->amount > mostExpensiveExpense->amount) {
            mostExpensiveExpense = expenses[i];
        }
    }
    return mostExpensiveExpense;
}

// Function to get the least expensive expense in a list of expenses
Expense* getLeastExpensiveExpense(Expense** expenses, int numExpenses) {
    Expense* leastExpensiveExpense = expenses[0];
    for (int i = 1; i < numExpenses; i++) {
        if (expenses[i]->amount < leastExpensiveExpense->amount) {
            leastExpensiveExpense = expenses[i];
        }
    }
    return leastExpensiveExpense;
}

// Function to main
int main() {
    // Create a list of expenses
    Expense** expenses = (Expense**) malloc(0);
    int numExpenses = 0;

    // Add some expenses to the list
    addExpense(&expenses, &numExpenses, createExpense("Groceries", 100.00, "Food"));
    addExpense(&expenses, &numExpenses, createExpense("Gas", 50.00, "Transportation"));
    addExpense(&expenses, &numExpenses, createExpense("Entertainment", 25.00, "Entertainment"));

    // Print the list of expenses
    printf("Here is a list of your expenses:\n");
    printExpenses(expenses, numExpenses);

    // Get the total amount of expenses
    float totalAmount = getTotalAmount(expenses, numExpenses);
    printf("The total amount of your expenses is: %.2f\n", totalAmount);

    // Get the average amount of expenses
    float averageAmount = getAverageAmount(expenses, numExpenses);
    printf("The average amount of your expenses is: %.2f\n", averageAmount);

    // Get the most expensive expense
    Expense* mostExpensiveExpense = getMostExpensiveExpense(expenses, numExpenses);
    printf("The most expensive expense is:\n");
    printExpense(mostExpensiveExpense);

    // Get the least expensive expense
    Expense* leastExpensiveExpense = getLeastExpensiveExpense(expenses, numExpenses);
    printf("The least expensive expense is:\n");
    printExpense(leastExpensiveExpense);

    // Free the memory allocated for the expenses
    for (int i = 0; i < numExpenses; i++) {
        free(expenses[i]->description);
        free(expenses[i]->category);
        free(expenses[i]);
    }
    free(expenses);

    return 0;
}