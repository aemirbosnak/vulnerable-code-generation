//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_SIZE 50
#define DESC_SIZE 100

typedef struct {
    char name[NAME_SIZE];
    double amount;
} Income;

typedef struct {
    char description[DESC_SIZE];
    double amount;
} Expense;

typedef struct {
    char goalName[NAME_SIZE];
    double targetAmount;
    double currentAmount;
} SavingsGoal;

typedef struct {
    Income incomes[MAX_ENTRIES];
    Expense expenses[MAX_ENTRIES];
    SavingsGoal savingsGoals[MAX_ENTRIES];
    int incomeCount;
    int expenseCount;
    int savingsCount;
} FinanceTracker;

void initializeTracker(FinanceTracker *tracker) {
    tracker->incomeCount = 0;
    tracker->expenseCount = 0;
    tracker->savingsCount = 0;
}

void addIncome(FinanceTracker *tracker) {
    if (tracker->incomeCount >= MAX_ENTRIES) {
        printf("Maximum income entries reached.\n");
        return;
    }
    printf("Enter income source: ");
    scanf("%s", tracker->incomes[tracker->incomeCount].name);
    printf("Enter income amount: ");
    scanf("%lf", &tracker->incomes[tracker->incomeCount].amount);
    tracker->incomeCount++;
}

void addExpense(FinanceTracker *tracker) {
    if (tracker->expenseCount >= MAX_ENTRIES) {
        printf("Maximum expense entries reached.\n");
        return;
    }
    printf("Enter expense description: ");
    scanf("%s", tracker->expenses[tracker->expenseCount].description);
    printf("Enter expense amount: ");
    scanf("%lf", &tracker->expenses[tracker->expenseCount].amount);
    tracker->expenseCount++;
}

void addSavingsGoal(FinanceTracker *tracker) {
    if (tracker->savingsCount >= MAX_ENTRIES) {
        printf("Maximum savings goals reached.\n");
        return;
    }
    printf("Enter savings goal name: ");
    scanf("%s", tracker->savingsGoals[tracker->savingsCount].goalName);
    printf("Enter target amount: ");
    scanf("%lf", &tracker->savingsGoals[tracker->savingsCount].targetAmount);
    tracker->savingsGoals[tracker->savingsCount].currentAmount = 0; // Initialize current savings
    tracker->savingsCount++;
}

void viewSummary(FinanceTracker *tracker) {
    double totalIncome = 0, totalExpenses = 0;
    
    printf("\n--- Financial Summary ---\n");
    
    printf("Incomes:\n");
    for (int i = 0; i < tracker->incomeCount; i++) {
        printf("%s: $%.2f\n", tracker->incomes[i].name, tracker->incomes[i].amount);
        totalIncome += tracker->incomes[i].amount;
    }
    
    printf("Total Incomes: $%.2f\n", totalIncome);

    printf("\nExpenses:\n");
    for (int i = 0; i < tracker->expenseCount; i++) {
        printf("%s: $%.2f\n", tracker->expenses[i].description, tracker->expenses[i].amount);
        totalExpenses += tracker->expenses[i].amount;
    }
    
    printf("Total Expenses: $%.2f\n", totalExpenses);

    double netIncome = totalIncome - totalExpenses;
    printf("Net Income: $%.2f\n", netIncome);

    printf("\nSavings Goals:\n");
    for (int i = 0; i < tracker->savingsCount; i++) {
        printf("%s: Target: $%.2f, Current: $%.2f\n",
               tracker->savingsGoals[i].goalName,
               tracker->savingsGoals[i].targetAmount,
               tracker->savingsGoals[i].currentAmount);
    }
}

void updateSavingsGoal(FinanceTracker *tracker) {
    char goalName[NAME_SIZE];
    double amount;
    
    printf("Enter savings goal name to update: ");
    scanf("%s", goalName);
    printf("Enter amount to add to the goal: ");
    scanf("%lf", &amount);
    
    for (int i = 0; i < tracker->savingsCount; i++) {
        if (strcmp(tracker->savingsGoals[i].goalName, goalName) == 0) {
            tracker->savingsGoals[i].currentAmount += amount;
            printf("Updated %s: Current amount: $%.2f\n", tracker->savingsGoals[i].goalName, tracker->savingsGoals[i].currentAmount);
            return;
        }
    }
    printf("Savings goal not found.\n");
}

int main() {
    FinanceTracker tracker;
    initializeTracker(&tracker);
    
    int choice;
    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Add Savings Goal\n");
        printf("4. View Summary\n");
        printf("5. Update Savings Goal\n");
        printf("0. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addIncome(&tracker);
                break;
            case 2:
                addExpense(&tracker);
                break;
            case 3:
                addSavingsGoal(&tracker);
                break;
            case 4:
                viewSummary(&tracker);
                break;
            case 5:
                updateSavingsGoal(&tracker);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}