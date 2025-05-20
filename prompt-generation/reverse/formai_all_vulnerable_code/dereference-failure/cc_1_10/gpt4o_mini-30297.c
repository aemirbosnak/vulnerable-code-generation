//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct Expense {
    char description[50];
    float amount;
    struct Expense *next;
};

struct Income {
    char source[50];
    float amount;
    struct Income *next;
};

struct PersonalFinance {
    struct Expense *expenses;
    struct Income *incomes;
};

void addExpense(struct PersonalFinance *pf) {
    struct Expense *newExpense = (struct Expense *)malloc(sizeof(struct Expense));
    printf("Enter expense description: ");
    scanf("%s", newExpense->description);
    printf("Enter expense amount: ");
    scanf("%f", &newExpense->amount);
    newExpense->next = pf->expenses;
    pf->expenses = newExpense;
    printf("Expense added successfully!\n");
}

void addIncome(struct PersonalFinance *pf) {
    struct Income *newIncome = (struct Income *)malloc(sizeof(struct Income));
    printf("Enter income source: ");
    scanf("%s", newIncome->source);
    printf("Enter income amount: ");
    scanf("%f", &newIncome->amount);
    newIncome->next = pf->incomes;
    pf->incomes = newIncome;
    printf("Income added successfully!\n");
}

void viewExpenses(struct PersonalFinance *pf) {
    struct Expense *current = pf->expenses;
    float totalExpenses = 0;

    printf("\n=== Expenses ===\n");
    while (current != NULL) {
        printf("Description: %s, Amount: %.2f\n", current->description, current->amount);
        totalExpenses += current->amount;
        current = current->next;
    }
    printf("Total Expenses: %.2f\n", totalExpenses);
}

void viewIncomes(struct PersonalFinance *pf) {
    struct Income *current = pf->incomes;
    float totalIncome = 0;

    printf("\n=== Incomes ===\n");
    while (current != NULL) {
        printf("Source: %s, Amount: %.2f\n", current->source, current->amount);
        totalIncome += current->amount;
        current = current->next;
    }
    printf("Total Income: %.2f\n", totalIncome);
}

void calculateBalance(struct PersonalFinance *pf) {
    float totalIncome = 0, totalExpenses = 0;

    struct Income *incomePtr = pf->incomes;
    while (incomePtr != NULL) {
        totalIncome += incomePtr->amount;
        incomePtr = incomePtr->next;
    }

    struct Expense *expensePtr = pf->expenses;
    while (expensePtr != NULL) {
        totalExpenses += expensePtr->amount;
        expensePtr = expensePtr->next;
    }

    float balance = totalIncome - totalExpenses;
    printf("\n=== Balance Overview ===\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Balance: %.2f\n", balance);
}

void freeMemory(struct PersonalFinance *pf) {
    struct Expense *currentExpense = pf->expenses;
    struct Income *currentIncome = pf->incomes;
    
    while (currentExpense != NULL) {
        struct Expense *temp = currentExpense;
        currentExpense = currentExpense->next;
        free(temp);
    }
    
    while (currentIncome != NULL) {
        struct Income *temp = currentIncome;
        currentIncome = currentIncome->next;
        free(temp);
    }
}

int main() {
    struct PersonalFinance pf = {NULL, NULL};
    int choice;

    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Expense\n");
        printf("2. Add Income\n");
        printf("3. View Expenses\n");
        printf("4. View Incomes\n");
        printf("5. Calculate Balance\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addExpense(&pf);
                break;
            case 2:
                addIncome(&pf);
                break;
            case 3:
                viewExpenses(&pf);
                break;
            case 4:
                viewIncomes(&pf);
                break;
            case 5:
                calculateBalance(&pf);
                break;
            case 6:
                freeMemory(&pf);
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}