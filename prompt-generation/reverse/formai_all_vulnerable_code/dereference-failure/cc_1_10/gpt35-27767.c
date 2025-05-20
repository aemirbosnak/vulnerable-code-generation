//FormAI DATASET v1.0 Category: Expense Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct for Expense */
typedef struct {
    char name[30];
    char category[30];
    float cost;
} Expense;

int main() {
    int num_expenses = 0;
    Expense *expenses = NULL;

    while (1) {
        /* Printing the welcome message */
        printf("\nWelcome to the Expense Tracker Program!\n");
        printf("1 - Add an expense\n");
        printf("2 - View all expenses\n");
        printf("3 - View expenses by category\n");
        printf("4 - Exit the program\n");
        printf("Please select an option: ");

        /* Reading the option */
        int option;
        scanf("%d", &option);

        /* Switching based on the option */
        switch (option) {
            case 1:
            {
                /* Adding an expense */
                printf("\nAdding an expense\n");
                printf("Please enter the name: ");
                char name[30];
                scanf("%s", name);
                printf("Please enter the category: ");
                char category[30];
                scanf("%s", category);
                printf("Please enter the cost: ");
                float cost;
                scanf("%f", &cost);

                /* Allocating memory for a new expense */
                num_expenses++;
                expenses = realloc(expenses, num_expenses * sizeof(Expense));

                /* Adding the new expense */
                Expense expense;
                strcpy(expense.name, name);
                strcpy(expense.category, category);
                expense.cost = cost;
                expenses[num_expenses - 1] = expense;

                printf("\nExpense added successfully!\n");
                break;
            }
            case 2:
            {
                /* Viewing all expenses */
                printf("\nAll expenses:\n");
                printf("| %-30s | %-30s | %-8s |\n", "Name", "Category", "Cost");
                printf("|------------------------------|------------------------------|----------|\n");
                for (int i = 0; i < num_expenses; i++) {
                    printf("| %-30s | %-30s | $%-7.2f |\n", expenses[i].name, expenses[i].category, expenses[i].cost);
                }
                break;
            }
            case 3:
            {
                /* Viewing expenses by category */
                printf("\nViewing expenses by category\n");
                printf("Please enter the category: ");
                char category[30];
                scanf("%s", category);

                /* Filtering and printing the expenses */
                printf("\nExpenses under the category '%s':\n", category);
                printf("| %-30s | %-8s |\n", "Name", "Cost");
                printf("|------------------------------|----------|\n");
                for (int i = 0; i < num_expenses; i++) {
                    if (strcmp(expenses[i].category, category) == 0) {
                        printf("| %-30s | $%-7.2f |\n", expenses[i].name, expenses[i].cost);
                    }
                }
                break;
            }
            case 4:
            {
                /* Exiting the program */
                printf("\nThank you for using the Expense Tracker Program!\n");
                return 0;
            }
            default:
            {
                /* Handling invalid options */
                printf("\nInvalid option! Please select a valid option.\n");
            }
        }
    }
}