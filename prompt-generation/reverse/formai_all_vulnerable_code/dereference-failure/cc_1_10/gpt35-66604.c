//FormAI DATASET v1.0 Category: Expense Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

struct expense {
    char category[MAX_LENGTH];
    float amount;
};

int main() {
    int num_expenses;

    printf("Welcome to the Expense Tracker!\n\n");

    printf("How many expenses would you like to enter? ");
    scanf("%d", &num_expenses);

    struct expense* expenses = (struct expense*) malloc(num_expenses * sizeof(struct expense));

    char buffer[MAX_LENGTH];
    float total_spending = 0;

    for (int i = 0; i < num_expenses; i++) {
        printf("\nEnter expense #%d category: ", i+1);
        while (fgets(buffer, MAX_LENGTH, stdin)) {
            if (buffer[0] != '\n') break;
        }
        strcpy(expenses[i].category, buffer);

        printf("Enter expense #%d amount: ", i+1);
        scanf("%f", &expenses[i].amount);

        total_spending += expenses[i].amount;
    }

    printf("\n\nHere is a summary of your expenses:\n");
    printf("------------------------------------\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("Category: %s", expenses[i].category);
        printf("Amount: $%.2f\n", expenses[i].amount);
    }

    printf("------------------------------------\n");
    printf("Total Spending: $%.2f\n", total_spending);

    free(expenses);
    return 0;
}