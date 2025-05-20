//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_EXPENSES 100

struct Expense {
    char name[50];
    float amount;
};

struct Budget {
    float income;
    float totalExpenses;
    struct Expense expenses[MAX_EXPENSES];
    int expenseCount;
};

void addExpense(struct Budget *budget) {
    if (budget->expenseCount >= MAX_EXPENSES) {
        printf("Cannot add more expenses, limit reached.\n");
        return;
    }
    
    printf("Enter expense name: ");
    scanf("%s", budget->expenses[budget->expenseCount].name);
    printf("Enter expense amount: ");
    scanf("%f", &budget->expenses[budget->expenseCount].amount);
    
    budget->totalExpenses += budget->expenses[budget->expenseCount].amount;
    budget->expenseCount++;
    
    printf("Expense added successfully.\n");
}

void displaySummary(struct Budget *budget) {
    printf("\n----- Financial Summary -----\n");
    printf("Total Income: $%.2f\n", budget->income);
    printf("Total Expenses: $%.2f\n", budget->totalExpenses);
    printf("Remaining Balance: $%.2f\n", budget->income - budget->totalExpenses);
    
    printf("\nExpenses:\n");
    for (int i = 0; i < budget->expenseCount; i++) {
        printf("- %s: $%.2f\n", budget->expenses[i].name, budget->expenses[i].amount);
    }
}

void inputIncome(struct Budget *budget) {
    printf("Enter your total income: ");
    scanf("%f", &budget->income);
}

void initializeBudget(struct Budget *budget) {
    budget->income = 0.0;
    budget->totalExpenses = 0.0;
    budget->expenseCount = 0;
}

int main() {
    struct Budget myBudget;
    int choice;

    initializeBudget(&myBudget);
    
    do {
        printf("\n----- Personal Finance Planner -----\n");
        printf("1. Enter Income\n");
        printf("2. Add Expense\n");
        printf("3. Display Summary\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                inputIncome(&myBudget);
                break;
            case 2:
                addExpense(&myBudget);
                break;
            case 3:
                displaySummary(&myBudget);
                break;
            case 4:
                printf("Exiting the program. Have a great day!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}