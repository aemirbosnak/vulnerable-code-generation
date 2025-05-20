//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double amount;
} expense_t;

int main() {
    expense_t *expenses = NULL;
    int num_expenses = 0;
    char input[100];

    while (1) {
        printf("Enter an expense (name, amount): ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "\n") == 0) {
            break;
        }

        char *name = strtok(input, ",");
        double amount = atof(strtok(NULL, ","));

        expenses = realloc(expenses, (num_expenses + 1) * sizeof(expense_t));
        expenses[num_expenses].name = strdup(name);
        expenses[num_expenses].amount = amount;
        num_expenses++;
    }

    printf("\nYour expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].amount);
    }

    double total = 0;
    for (int i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }

    printf("\nTotal: $%.2f\n", total);

    for (int i = 0; i < num_expenses; i++) {
        free(expenses[i].name);
    }
    free(expenses);

    return 0;
}