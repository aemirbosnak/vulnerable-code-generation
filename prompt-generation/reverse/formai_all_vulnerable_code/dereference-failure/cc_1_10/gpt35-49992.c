//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int option, i = 0, j = 0, num_of_months, temp1, temp2;
    float monthly_income, monthly_expense, savings = 0;

    printf("\n-----Welcome to Personal Finance Planner-----\n");

    printf("Please enter the number of months for which you want to plan: ");
    scanf("%d", &num_of_months);

    float *income = (float *) malloc(num_of_months * sizeof(float));
    float *expense = (float *) malloc(num_of_months * sizeof(float));

    while(j < num_of_months)
    {
        printf("\nMonth %d", j+1);
        printf("\nEnter monthly income: ");
        scanf("%f", &income[j]);

        printf("Enter monthly expense: ");
        scanf("%f", &expense[j]);

        savings += (income[j] - expense[j]);
        j++;
    }

    while(1)
    {
        printf("\n1. Calculate total savings\n");
        printf("2. Calculate average income and expense\n");
        printf("3. Display monthly income and expense\n");
        printf("4. Exit the program\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\nTotal savings = %.2f\n", savings);
                break;
            case 2:
                monthly_income = 0;
                monthly_expense = 0;
                for(i=0; i<num_of_months; i++)
                {
                    monthly_income += income[i];
                    monthly_expense += expense[i];
                }
                printf("\nAverage monthly income: %.2f\n", monthly_income/num_of_months);
                printf("Average monthly expense: %.2f\n", monthly_expense/num_of_months);
                break;
            case 3:
                printf("\nMonthly income and expense details:\n");
                printf("%5s %12s %12s\n", "Month", "Income", "Expense");
                for(i=0; i<num_of_months; i++)
                {
                    printf("%5d %12.2f %12.2f\n", i+1, income[i], expense[i]);
                }
                break;
            case 4:
                free(income);
                free(expense);
                printf("\nThank you for using Personal Finance Planner.\n");
                exit(0);
                break;
            default:
                printf("\nInvalid option entered! Please try again.\n");
                break;
        }
    }
    return 0;
}