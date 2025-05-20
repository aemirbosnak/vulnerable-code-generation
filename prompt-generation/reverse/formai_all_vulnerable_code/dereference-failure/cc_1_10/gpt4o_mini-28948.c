//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10

typedef struct {
    char name[30];
    float spending;
} ExpenseCategory;

typedef struct {
    float income;
    ExpenseCategory categories[MAX_CATEGORIES];
    int categoryCount;
} FinancialPlan;

void addCategory(FinancialPlan *plan) {
    if (plan->categoryCount < MAX_CATEGORIES) {
        ExpenseCategory category;
        printf("Enter expense category name: ");
        scanf("%s", category.name);
        printf("Enter the amount spent in %s: ", category.name);
        scanf("%f", &category.spending);
        plan->categories[plan->categoryCount] = category;
        plan->categoryCount++;
    } else {
        printf("Maximum categories reached.\n");
    }
}

void displaySummary(FinancialPlan plan) {
    float totalExpenses = 0;
    printf("\n--- Financial Summary ---\n");
    printf("Total Income: $%.2f\n", plan.income);
    printf("Expenses Breakdown:\n");

    for (int i = 0; i < plan.categoryCount; i++) {
        printf("Category: %s, Amount Spent: $%.2f\n", plan.categories[i].name, plan.categories[i].spending);
        totalExpenses += plan.categories[i].spending;
    }

    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Remaining Balance: $%.2f\n", plan.income - totalExpenses);
}

void displayMenu() {
    printf("\n--- Personal Finance Planner Menu ---\n");
    printf("1. Add Expense Category\n");
    printf("2. Display Summary\n");
    printf("3. Exit\n");
}

int main() {
    FinancialPlan plan;
    plan.categoryCount = 0;
    plan.income = 0.0;

    printf("Enter your total monthly income: ");
    scanf("%f", &plan.income);

    int choice;
    do {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCategory(&plan);
                break;
            case 2:
                displaySummary(plan);
                break;
            case 3:
                printf("Thank you for using the Personal Finance Planner!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}