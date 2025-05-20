//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUDGET_CATEGORIES 10
#define MAX_BUDGET_ITEMS 100

typedef struct {
    char name[50];
    float amount;
} BudgetItem;

typedef struct {
    char name[50];
    BudgetItem items[MAX_BUDGET_ITEMS];
    int numItems;
} BudgetCategory;

typedef struct {
    char name[50];
    BudgetCategory categories[MAX_BUDGET_CATEGORIES];
    int numCategories;
} BudgetPlan;

void addBudgetCategory(BudgetPlan* plan) {
    printf("Enter a budget category name: ");
    scanf("%s", plan->categories[plan->numCategories].name);
    plan->categories[plan->numCategories].numItems = 0;
    plan->numCategories++;
}

void addBudgetItem(BudgetPlan* plan, int categoryIndex) {
    printf("Enter a budget item name: ");
    scanf("%s", &(plan->categories[categoryIndex].items[plan->categories[categoryIndex].numItems].name));
    printf("Enter a budget item amount: ");
    scanf("%f", &(plan->categories[categoryIndex].items[plan->categories[categoryIndex].numItems].amount));
    plan->categories[categoryIndex].numItems++;
}

void printBudgetPlan(BudgetPlan* plan) {
    printf("Budget Plan:\n");
    printf("--------------------\n");
    for(int i=0; i<plan->numCategories; i++) {
        printf("Category: %s\n", plan->categories[i].name);
        for(int j=0; j<plan->categories[i].numItems; j++) {
            printf("\tItem: %s\tAmount: $%.2f\n", plan->categories[i].items[j].name, plan->categories[i].items[j].amount);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    BudgetPlan plan;
    plan.numCategories = 0;

    addBudgetCategory(&plan);
    addBudgetCategory(&plan);
    addBudgetCategory(&plan);

    int categoryIndex = rand() % plan.numCategories;
    addBudgetItem(&plan, categoryIndex);
    addBudgetItem(&plan, categoryIndex);

    printBudgetPlan(&plan);

    return 0;
}