//FormAI DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expense {
    char category[50];
    char date[50];
    float amount;
}Expense;

int main() {
    int numExpenses = 0;
    int option;
    float totalExpense = 0;
    Expense *expenses = NULL;

    while(1) {
        printf("\nEXPENSE TRACKER\n\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d",&option);

        if(option == 1) {
            Expense newExpense;

            printf("\nEnter Category: ");
            scanf("%s",newExpense.category);
            printf("Enter Date (MM/DD/YYYY): ");
            scanf("%s",newExpense.date);
            printf("Enter Amount: $");
            scanf("%f",&newExpense.amount);

            totalExpense += newExpense.amount;
            numExpenses++;
            expenses = (Expense*)realloc(expenses,numExpenses*sizeof(Expense));
            expenses[numExpenses-1] = newExpense;
            printf("\nExpense Successfully Added!\n");
        }
        else if(option == 2) {
            if(numExpenses == 0) {
                printf("\nNo expenses yet.\n");
                continue;
            }

            char filter[50];
            printf("\nEnter 'all' to show all expenses.\n");
            printf("Enter a category to filter (e.g. 'food'): ");
            scanf("%s",filter);

            printf("\n");
            printf("| %3s | %-15s | %-12s | %11s |\n","ID","CATEGORY","DATE","AMOUNT");
            printf("|-----|-----------------|--------------|-------------|\n");

            for(int i = 0; i < numExpenses; i++) {
                if(strcmp(filter,"all") == 0 || strcmp(expenses[i].category,filter) == 0) {
                    printf("| %3d | %-15s | %-12s | $%10.2f |\n",i+1,expenses[i].category,expenses[i].date,expenses[i].amount);
                }
            }

            printf("|-----|-----------------|--------------|-------------|\n");
            printf("|     | TOTAL EXPENSES              |        $%10.2f |\n",totalExpense);
            printf("|-----|-----------------|--------------|-------------|\n");
        }
        else if(option == 3) {
            printf("\nGoodbye!\n");
            break;
        }
        else {
            printf("\nInvalid Option.\n");
        }
    }

    free(expenses);
    return 0;
}