//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define the personal finance planner structure
typedef struct PersonalFinancePlanner {
    char name[20];
    int age;
    double income;
    double expenses;
    double savings;
} PersonalFinancePlanner;

// Function to create a new personal finance planner
PersonalFinancePlanner* create_personal_finance_planner(char* name, int age, double income, double expenses, double savings) {
    PersonalFinancePlanner* planner = (PersonalFinancePlanner*)malloc(sizeof(PersonalFinancePlanner));
    strcpy(planner->name, name);
    planner->age = age;
    planner->income = income;
    planner->expenses = expenses;
    planner->savings = savings;
    return planner;
}

// Function to calculate the planner's net worth
double calculate_net_worth(PersonalFinancePlanner* planner) {
    return planner->savings + planner->income - planner->expenses;
}

// Function to display the planner's information
void display_planner_information(PersonalFinancePlanner* planner) {
    printf("Name: %s\n", planner->name);
    printf("Age: %d\n", planner->age);
    printf("Income: %.2lf\n", planner->income);
    printf("Expenses: %.2lf\n", planner->expenses);
    printf("Savings: %.2lf\n", planner->savings);
    printf("Net Worth: %.2lf\n", calculate_net_worth(planner));
}

int main() {
    // Create a new personal finance planner
    PersonalFinancePlanner* planner = create_personal_finance_planner("John Doe", 30, 50000, 20000, 10000);

    // Display the planner's information
    display_planner_information(planner);

    // Free the planner
    free(planner);

    return 0;
}