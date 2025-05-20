//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

struct PersonalFinancePlanner {
    char name[50];
    int age;
    double income;
    double expenses;
    double networth;
    double savings;
    double investments;
    double debt;
    struct PersonalFinancePlanner *next;
};

void createPersonalFinancePlanner(struct PersonalFinancePlanner *planner) {
    planner = (struct PersonalFinancePlanner *)malloc(sizeof(struct PersonalFinancePlanner));
    planner->next = NULL;
    return;
}

void addPersonalFinancePlanner(struct PersonalFinancePlanner *planner, char *name, int age, double income, double expenses, double networth, double savings, double investments, double debt) {
    createPersonalFinancePlanner(planner);
    strcpy(planner->name, name);
    planner->age = age;
    planner->income = income;
    planner->expenses = expenses;
    planner->networth = networth;
    planner->savings = savings;
    planner->investments = investments;
    planner->debt = debt;
}

void printPersonalFinancePlanner(struct PersonalFinancePlanner *planner) {
    while (planner) {
        printf("Name: %s\n", planner->name);
        printf("Age: %d\n", planner->age);
        printf("Income: %.2lf\n", planner->income);
        printf("Expenses: %.2lf\n", planner->expenses);
        printf("Net Worth: %.2lf\n", planner->networth);
        printf("Savings: %.2lf\n", planner->savings);
        printf("Investments: %.2lf\n", planner->investments);
        printf("Debt: %.2lf\n", planner->debt);
        printf("\n");
        planner = planner->next;
    }
}

int main() {
    struct PersonalFinancePlanner *planner = NULL;

    addPersonalFinancePlanner(planner, "John Doe", 30, 50000, 20000, 100000, 20000, 50000, 10000);
    addPersonalFinancePlanner(planner, "Jane Doe", 25, 60000, 30000, 150000, 30000, 60000, 5000);

    printPersonalFinancePlanner(planner);

    return 0;
}