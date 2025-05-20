//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: mathematical
#include <stdio.h>

typedef struct {
    char category[30];
    double budgeted_amount;
    double actual_spend;
} Expense;

void inputExpenses(Expense expenses[], int count) {
    for(int i = 0; i < count; i++) {
        printf("Enter the category of expense %d: ", i + 1);
        scanf("%s", expenses[i].category);
        printf("Enter the budgeted amount for %s: ", expenses[i].category);
        scanf("%lf", &expenses[i].budgeted_amount);
        printf("Enter the actual spend for %s: ", expenses[i].category);
        scanf("%lf", &expenses[i].actual_spend);
    }
}

double calculateTotalBudgeted(Expense expenses[], int count) {
    double total = 0.0;
    for(int i = 0; i < count; i++) {
        total += expenses[i].budgeted_amount;
    }
    return total;
}

double calculateTotalActual(Expense expenses[], int count) {
    double total = 0.0;
    for(int i = 0; i < count; i++) {
        total += expenses[i].actual_spend;
    }
    return total;
}

void generateReport(Expense expenses[], int count) {
    double totalBudgeted = calculateTotalBudgeted(expenses, count);
    double totalActual = calculateTotalActual(expenses, count);
    
    printf("\nPersonal Finance Report\n");
    printf("-------------------------\n");
    printf("%-30s %-15s %-15s\n", "Category", "Budgeted Amount", "Actual Spend");
    for(int i = 0; i < count; i++) {
        printf("%-30s $%-14.2f $%-14.2f\n", expenses[i].category, 
               expenses[i].budgeted_amount, expenses[i].actual_spend);
    }
    printf("-------------------------\n");
    printf("Total                $%-14.2f $%-14.2f\n", totalBudgeted, totalActual);
    printf("-------------------------\n");
    
    double remaining = totalBudgeted - totalActual;
    if (remaining > 0) {
        printf("Congratulations! You are under budget by $%.2f\n", remaining);
    } else if (remaining < 0) {
        printf("Alert! You are over budget by $%.2f\n", -remaining);
    } else {
        printf("Congratulations! You are exactly on budget!\n");
    }
}

int main() {
    int numberOfExpenses;
    printf("Enter the number of expense categories you want to input: ");
    scanf("%d", &numberOfExpenses);

    Expense expenses[numberOfExpenses];

    inputExpenses(expenses, numberOfExpenses);
    generateReport(expenses, numberOfExpenses);

    return 0;
}