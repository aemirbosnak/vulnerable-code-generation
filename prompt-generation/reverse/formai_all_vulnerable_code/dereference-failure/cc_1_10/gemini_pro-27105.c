//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double income;
    double expenses;
    double savings;
} budget;

budget* create_budget(double income, double expenses, double savings) {
    budget* b = malloc(sizeof(budget));
    b->income = income;
    b->expenses = expenses;
    b->savings = savings;
    return b;
}

void print_budget(budget* b) {
    printf("Income: $%.2f\n", b->income);
    printf("Expenses: $%.2f\n", b->expenses);
    printf("Savings: $%.2f\n", b->savings);
}

double calculate_net_worth(budget* b) {
    return b->income - b->expenses + b->savings;
}

void update_budget(budget* b, double new_income, double new_expenses, double new_savings) {
    b->income = new_income;
    b->expenses = new_expenses;
    b->savings = new_savings;
}

int main() {
    // Create a sample budget
    budget* my_budget = create_budget(5000, 3000, 2000);

    // Print the original budget
    printf("Original budget:\n");
    print_budget(my_budget);

    // Update the budget
    update_budget(my_budget, 5500, 3200, 2300);

    // Print the updated budget
    printf("\nUpdated budget:\n");
    print_budget(my_budget);

    // Calculate the net worth
    double net_worth = calculate_net_worth(my_budget);
    printf("\nNet worth: $%.2f\n", net_worth);

    // Free the memory allocated for the budget
    free(my_budget);

    return 0;
}