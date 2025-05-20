//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Structure to represent an expense
typedef struct {
    char *description;
    double amount;
    time_t date;
} Expense;

// Function to create an expense
Expense *createExpense(char *description, double amount, time_t date) {
    Expense *expense = (Expense *)malloc(sizeof(Expense));
    expense->description = (char *)malloc(strlen(description) + 1);
    strcpy(expense->description, description);
    expense->amount = amount;
    expense->date = date;
    return expense;
}

// Function to destroy an expense
void destroyExpense(Expense *expense) {
    free(expense->description);
    free(expense);
}

// Function to print an expense
void printExpense(Expense *expense) {
    printf("%s: $%.2f (%s)\n", expense->description, expense->amount, ctime(&expense->date));
}

// Function to compare two expenses by date
int compareExpensesByDate(const void *a, const void *b) {
    Expense *expense1 = (Expense *)a;
    Expense *expense2 = (Expense *)b;
    return expense1->date - expense2->date;
}

// Function to get the total amount of expenses
double getTotalAmount(Expense **expenses, int numExpenses) {
    double totalAmount = 0;
    for (int i = 0; i < numExpenses; i++) {
        totalAmount += expenses[i]->amount;
    }
    return totalAmount;
}

// Function to get the average amount of expenses
double getAverageAmount(Expense **expenses, int numExpenses) {
    double totalAmount = getTotalAmount(expenses, numExpenses);
    return totalAmount / numExpenses;
}

// Function to get the maximum amount of expenses
double getMaxAmount(Expense **expenses, int numExpenses) {
    double maxAmount = 0;
    for (int i = 0; i < numExpenses; i++) {
        if (expenses[i]->amount > maxAmount) {
            maxAmount = expenses[i]->amount;
        }
    }
    return maxAmount;
}

// Function to get the minimum amount of expenses
double getMinAmount(Expense **expenses, int numExpenses) {
    double minAmount = expenses[0]->amount;
    for (int i = 1; i < numExpenses; i++) {
        if (expenses[i]->amount < minAmount) {
            minAmount = expenses[i]->amount;
        }
    }
    return minAmount;
}

// Function to get the median amount of expenses
double getMedianAmount(Expense **expenses, int numExpenses) {
    qsort(expenses, numExpenses, sizeof(Expense *), compareExpensesByDate);
    if (numExpenses % 2 == 0) {
        return (expenses[numExpenses / 2]->amount + expenses[numExpenses / 2 - 1]->amount) / 2;
    } else {
        return expenses[numExpenses / 2]->amount;
    }
}

// Function to get the standard deviation of expenses
double getStandardDeviation(Expense **expenses, int numExpenses) {
    double totalAmount = getTotalAmount(expenses, numExpenses);
    double averageAmount = getAverageAmount(expenses, numExpenses);
    double variance = 0;
    for (int i = 0; i < numExpenses; i++) {
        variance += pow(expenses[i]->amount - averageAmount, 2);
    }
    variance /= numExpenses;
    return sqrt(variance);
}

// Function to get the covariance of expenses
double getCovariance(Expense **expenses, int numExpenses, Expense **expenses2, int numExpenses2) {
    double totalAmount = getTotalAmount(expenses, numExpenses);
    double averageAmount = getAverageAmount(expenses, numExpenses);
    double totalAmount2 = getTotalAmount(expenses2, numExpenses2);
    double averageAmount2 = getAverageAmount(expenses2, numExpenses2);
    double covariance = 0;
    for (int i = 0; i < numExpenses; i++) {
        covariance += (expenses[i]->amount - averageAmount) * (expenses2[i]->amount - averageAmount2);
    }
    covariance /= numExpenses;
    return covariance;
}

// Function to get the correlation of expenses
double getCorrelation(Expense **expenses, int numExpenses, Expense **expenses2, int numExpenses2) {
    double covariance = getCovariance(expenses, numExpenses, expenses2, numExpenses2);
    double standardDeviation = getStandardDeviation(expenses, numExpenses);
    double standardDeviation2 = getStandardDeviation(expenses2, numExpenses2);
    return covariance / (standardDeviation * standardDeviation2);
}

// Function to print a report on expenses
void printReport(Expense **expenses, int numExpenses) {
    printf("Total Amount: $%.2f\n", getTotalAmount(expenses, numExpenses));
    printf("Average Amount: $%.2f\n", getAverageAmount(expenses, numExpenses));
    printf("Maximum Amount: $%.2f\n", getMaxAmount(expenses, numExpenses));
    printf("Minimum Amount: $%.2f\n", getMinAmount(expenses, numExpenses));
    printf("Median Amount: $%.2f\n", getMedianAmount(expenses, numExpenses));
    printf("Standard Deviation: $%.2f\n", getStandardDeviation(expenses, numExpenses));
}

// Main function
int main() {
    // Create an array of expenses
    Expense *expenses[] = {
        createExpense("Rent", 1200, time(NULL)),
        createExpense("Groceries", 200, time(NULL)),
        createExpense("Utilities", 150, time(NULL)),
        createExpense("Transportation", 100, time(NULL)),
        createExpense("Entertainment", 50, time(NULL)),
    };

    // Get the number of expenses
    int numExpenses = sizeof(expenses) / sizeof(expenses[0]);

    // Print a report on expenses
    printReport(expenses, numExpenses);

    // Destroy the expenses
    for (int i = 0; i < numExpenses; i++) {
        destroyExpense(expenses[i]);
    }

    return 0;
}