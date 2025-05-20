//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

// function to calculate the total expense
float calculateTotalExpense(float expenses[], int n) {
    float total = 0;
    for(int i=0; i<n; i++) {
        total += expenses[i];
    }
    return total;
}

// function to find the maximum expense
float findMaxExpense(float expenses[], int n) {
    float max = expenses[0];
    for(int i=1; i<n; i++) {
        if(expenses[i] > max) {
            max = expenses[i];
        }
    }
    return max;
}

// function to find the minimum expense
float findMinExpense(float expenses[], int n) {
    float min = expenses[0];
    for(int i=1; i<n; i++) {
        if(expenses[i] < min) {
            min = expenses[i];
        }
    }
    return min;
}

// function to display the report
void displayReport(float expenses[], int n, float total, float max, float min) {
    printf("\n-------------------------\n");
    printf("| Personal Finance Report |\n");
    printf("---------------------------\n\n");
    printf("Total Expenses: $%.2f\n", total);
    printf("Highest Expense: $%.2f\n", max);
    printf("Lowest Expense: $%.2f\n", min);
    printf("Average Expense: $%.2f\n", total/n);
    printf("\nExpense List:\n");
    for(int i=0; i<n; i++) {
        printf("%.2f\n", expenses[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of expenses: ");
    scanf("%d", &n);
    float expenses[n];
    printf("Enter the expenses:\n");
    for(int i=0; i<n; i++) {
        scanf("%f", &expenses[i]);
    }
    float total = calculateTotalExpense(expenses, n);
    float max = findMaxExpense(expenses, n);
    float min = findMinExpense(expenses, n);
    displayReport(expenses, n, total, max, min);
    return 0;
}