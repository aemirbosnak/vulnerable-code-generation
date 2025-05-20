//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_INCOMES 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float amount;
} Income;

typedef struct {
    char name[MAX_NAME_LEN];
    float amount;
} Expense;

typedef struct {
    Income incomes[MAX_INCOMES];
    Expense expenses[MAX_EXPENSES];
    int income_count;
    int expense_count;
    float total_income;
    float total_expenses;
} PersonalFinance;

void initializeFinance(PersonalFinance *pf) {
    pf->income_count = 0;
    pf->expense_count = 0;
    pf->total_income = 0.0;
    pf->total_expenses = 0.0;
}

void addIncome(PersonalFinance *pf) {
    if (pf->income_count >= MAX_INCOMES) {
        printf("Maximum income entries reached!\n");
        return;
    }
    printf("Enter income source: ");
    scanf("%s", pf->incomes[pf->income_count].name);
    printf("Enter income amount: ");
    scanf("%f", &pf->incomes[pf->income_count].amount);
    pf->total_income += pf->incomes[pf->income_count].amount;
    pf->income_count++;
    printf("Income added successfully!\n");
}

void addExpense(PersonalFinance *pf) {
    if (pf->expense_count >= MAX_EXPENSES) {
        printf("Maximum expense entries reached!\n");
        return;
    }
    printf("Enter expense category: ");
    scanf("%s", pf->expenses[pf->expense_count].name);
    printf("Enter expense amount: ");
    scanf("%f", &pf->expenses[pf->expense_count].amount);
    pf->total_expenses += pf->expenses[pf->expense_count].amount;
    pf->expense_count++;
    printf("Expense added successfully!\n");
}

void displayFinance(const PersonalFinance *pf) {
    printf("\n== Personal Finance Summary ==\n");
    printf("Total Income: %.2f\n", pf->total_income);
    printf("Total Expenses: %.2f\n", pf->total_expenses);
    printf("Net Savings: %.2f\n", pf->total_income - pf->total_expenses);
    
    printf("\nIncomes:\n");
    for (int i = 0; i < pf->income_count; i++) {
        printf("%s: %.2f\n", pf->incomes[i].name, pf->incomes[i].amount);
    }
    
    printf("\nExpenses:\n");
    for (int i = 0; i < pf->expense_count; i++) {
        printf("%s: %.2f\n", pf->expenses[i].name, pf->expenses[i].amount);
    }
    printf("================================\n");
}

void printMenu() {
    printf("\n== Personal Finance Planner Menu ==\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. Display Summary\n");
    printf("4. Exit\n");
    printf("===================================\n");
}

int main() {
    PersonalFinance pf;
    initializeFinance(&pf);
    
    int choice;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addIncome(&pf);
                break;
            case 2:
                addExpense(&pf);
                break;
            case 3:
                displayFinance(&pf);
                break;
            case 4:
                printf("Exiting... Thank you for using the Personal Finance Planner!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}