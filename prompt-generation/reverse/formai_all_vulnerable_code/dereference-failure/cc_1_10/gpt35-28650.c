//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include <stdio.h>
#include <stdlib.h>

//Defining the struct for expenses
struct Expense {
    char name[50];
    float amount;
};

int main() {
    int n, i;
    float total_expenses = 0;
    printf("Welcome to the Personal Finance Planner!\n\n");

    //Getting the number of expenses and allocating memory dynamically
    printf("Enter the number of expenses: ");
    scanf("%d", &n);
    struct Expense *expenses = (struct Expense *) malloc(n * sizeof(struct Expense));

    //Looping through to get the name and amount of each expense
    for(i = 0; i < n; i++) {
        printf("\nEnter expense name %d: ", i+1);
        scanf("%s", expenses[i].name);

        printf("Enter expense amount %d: ", i+1);
        scanf("%f", &expenses[i].amount);

        total_expenses += expenses[i].amount;
    }

    //Displaying a summary of expenses and total
    printf("\n-----------------------------\n");
    printf("Summary of Expenses:\n");
    for(i = 0; i < n; i++) {
        printf("%d) %s : $%.2f\n", i+1, expenses[i].name, expenses[i].amount);
    }
    printf("\nTotal Expenses: $%.2f\n", total_expenses);

    //Determining if expenses are within budget
    float budget;
    printf("\nEnter your budget: $");
    scanf("%f", &budget);
    if(total_expenses > budget) {
        printf("Your expenses are over your budget by $%.2f\n", total_expenses - budget);
    } else {
        printf("Your expenses are within your budget by $%.2f\n", budget - total_expenses);
    }

    //Freeing allocated memory
    free(expenses);
    return 0;
}