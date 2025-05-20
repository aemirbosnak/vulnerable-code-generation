//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size of strings
#define MAX_SIZE 100

// Define structure for personal finance data
typedef struct {
    char name[MAX_SIZE];
    double income;
    double expenses;
    double savings;
} PersonalFinance;

// Function to create a new personal finance data
PersonalFinance* createPersonalFinance(char* name, double income, double expenses, double savings) {
    PersonalFinance* pf = (PersonalFinance*) malloc(sizeof(PersonalFinance));
    strcpy(pf->name, name);
    pf->income = income;
    pf->expenses = expenses;
    pf->savings = savings;
    return pf;
}

// Function to print personal finance data
void printPersonalFinance(PersonalFinance* pf) {
    printf("Name: %s\n", pf->name);
    printf("Income: $%.2f\n", pf->income);
    printf("Expenses: $%.2f\n", pf->expenses);
    printf("Savings: $%.2f\n", pf->savings);
}

// Function to calculate net income
double calculateNetIncome(PersonalFinance* pf) {
    return pf->income - pf->expenses;
}

// Function to calculate savings percentage
double calculateSavingsPercentage(PersonalFinance* pf) {
    return (pf->savings / pf->income) * 100;
}

// Function to calculate average monthly expenses
double calculateAverageMonthlyExpenses(PersonalFinance* pf) {
    return pf->expenses / 12;
}

// Function to update personal finance data
void updatePersonalFinance(PersonalFinance* pf, double income, double expenses, double savings) {
    pf->income = income;
    pf->expenses = expenses;
    pf->savings = savings;
}

// Function to delete personal finance data
void deletePersonalFinance(PersonalFinance* pf) {
    free(pf);
}

// Main function
int main() {
    // Create personal finance data
    PersonalFinance* pf = createPersonalFinance("John Doe", 5000, 3500, 1500);

    // Print personal finance data
    printPersonalFinance(pf);

    // Calculate net income
    double netIncome = calculateNetIncome(pf);
    printf("Net Income: $%.2f\n", netIncome);

    // Calculate savings percentage
    double savingsPercentage = calculateSavingsPercentage(pf);
    printf("Savings Percentage: %.2f%%\n", savingsPercentage);

    // Calculate average monthly expenses
    double averageMonthlyExpenses = calculateAverageMonthlyExpenses(pf);
    printf("Average Monthly Expenses: $%.2f\n", averageMonthlyExpenses);

    // Update personal finance data
    updatePersonalFinance(pf, 5500, 4000, 2000);

    // Print updated personal finance data
    printPersonalFinance(pf);

    // Delete personal finance data
    deletePersonalFinance(pf);

    return 0;
}