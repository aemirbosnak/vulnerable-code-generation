//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Sherlock Holmes Expense Tracker

    // Create an array of expenses
    char **expenses = NULL;
    int num_expenses = 0;

    // Get the expense amount
    int expense_amount;

    // Get the expense description
    char expense_description[100];

    // Loop until the user enters an expense or quits
    while (1)
    {
        // Get the expense amount
        printf("Enter the expense amount: ");
        scanf("%d", &expense_amount);

        // Get the expense description
        printf("Enter the expense description: ");
        scanf("%s", expense_description);

        // Allocate memory for the expense
        expenses = realloc(expenses, (num_expenses + 1) * sizeof(char *));
        expenses[num_expenses++] = malloc(100 * sizeof(char));
        strcpy(expenses[num_expenses - 1], expense_description);

        // Check if the user wants to quit
        printf("Do you want to quit? (Y/N): ");
        char quit_answer;
        scanf(" %c", &quit_answer);

        // If the user wants to quit, break out of the loop
        if (quit_answer == 'Y')
        {
            break;
        }
    }

    // Print the expenses
    printf("Your expenses:\n");
    for (int i = 0; i < num_expenses; i++)
    {
        printf("%s - %d\n", expenses[i], expense_amount);
    }

    // Free the memory allocated for the expenses
    for (int i = 0; i < num_expenses; i++)
    {
        free(expenses[i]);
    }
    free(expenses);

    return 0;
}