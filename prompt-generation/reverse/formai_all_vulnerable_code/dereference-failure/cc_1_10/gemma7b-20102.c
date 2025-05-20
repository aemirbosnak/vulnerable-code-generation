//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 10

int main()
{
    int i = 0;
    char **expenses = (char **)malloc(MAX_EXPENSES * sizeof(char *));
    for (i = 0; i < MAX_EXPENSES; i++)
    {
        expenses[i] = (char *)malloc(20 * sizeof(char));
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[0]);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[0]);

    for (i = 1; i < MAX_EXPENSES; i++)
    {
        printf("Do you want to add another expense? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'Y')
        {
            printf("Enter expense name: ");
            scanf("%s", expenses[i]);

            printf("Enter expense amount: ");
            scanf("%f", &expenses[i]);
            i++;
        }
        else
        {
            break;
        }
    }

    printf("Here is your expense list:");
    for (i = 0; i < MAX_EXPENSES; i++)
    {
        if (expenses[i] != NULL)
        {
            printf("\n%s - %.2f", expenses[i], expenses[i][0] - '0');
        }
    }

    for (i = 0; i < MAX_EXPENSES; i++)
    {
        free(expenses[i]);
    }
    free(expenses);

    return 0;
}