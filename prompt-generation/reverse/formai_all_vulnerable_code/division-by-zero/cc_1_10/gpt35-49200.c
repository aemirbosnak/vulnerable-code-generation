//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    printf("Welcome to the Cyberpunk Personal Finance Planner!\n");

    int choice, budget, expenses, savings;
    char name[30];

    srand(time(NULL));

    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Hello %s!\n", name);
    printf("What is your monthly budget?\n");

    scanf("%d", &budget);

    printf("Great! Your monthly budget is: $%d\n", budget);
    printf("Let's start planning your monthly expenses.\n");

    expenses = rand() % (budget / 2); //randomly generate expenses between 0 and half of budget

    printf("Your monthly expenses are: $%d\n", expenses);

    savings = budget - expenses;

    printf("Your monthly savings are: $%d\n", savings);

    printf("Would you like to adjust your expenses or savings?\n");
    printf("1. Adjust expenses\n2. Adjust savings\n3. Quit\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter your new monthly expenses: ");
            scanf("%d", &expenses);
            printf("Your adjusted monthly expenses are: $%d\n", expenses);
            savings = budget - expenses;
            printf("Your adjusted monthly savings are: $%d\n", savings);
            break;

        case 2:
            printf("Enter your new monthly savings: ");
            scanf("%d", &savings);
            printf("Your adjusted monthly savings are: $%d\n", savings);
            expenses = budget - savings;
            printf("Your adjusted monthly expenses are: $%d\n", expenses);
            break;

        case 3:
            printf("Thank you for using the Cyberpunk Personal Finance Planner!\n");
            exit(0);

        default:
            printf("Invalid choice, please try again.\n");
            break;
    }

    return 0;
}