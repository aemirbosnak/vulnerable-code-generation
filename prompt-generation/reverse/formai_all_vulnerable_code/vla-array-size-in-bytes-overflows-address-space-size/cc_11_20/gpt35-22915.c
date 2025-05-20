//FormAI DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

struct expense {
    char category[20];
    float amount;
};

typedef struct expense Expense;

int main() {
    int n, i, j;
    printf("Enter the number of expenses to be tracked: ");
    scanf("%d", &n);

    Expense *expenses = (Expense*) malloc(n * sizeof(Expense));

    // Input expenses
    for (i = 0; i < n; i++) {
        printf("\n----Expense %d----\n", i+1);
        printf("Enter the category: ");
        scanf("%s", expenses[i].category);
        printf("Enter the amount: ");
        scanf("%f", &expenses[i].amount);
    }

    // Display expenses
    printf("\n---Expenses---\n");
    printf("%-15s %-10s\n", "Category", "Amount");
    for (i = 0; i < n; i++) {
        printf("%-15s %-10.2f\n", expenses[i].category, expenses[i].amount);
    }

    // Display total amount spent for each category
    printf("\n---Total Amount Spent per Category---\n");
    float total_amount = 0;
    for (i = 0; i < n; i++) {
        total_amount += expenses[i].amount;
    }
    printf("%-15s %-10.2f\n", "Total", total_amount);

    char unique_categories[n][20];
    int unique_count = 0;
    for (i = 0; i < n; i++) {
        int is_unique = 1;
        for (j = i+1; j < n; j++) {
            if (strcmp(expenses[i].category, expenses[j].category) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            strcpy(unique_categories[unique_count], expenses[i].category);
            unique_count++;
        }
    }

    for (i = 0; i < unique_count; i++) {
        printf("%-15s ", unique_categories[i]);
        float category_total = 0;
        for (j = 0; j < n; j++) {
            if (strcmp(expenses[j].category, unique_categories[i]) == 0) {
                category_total += expenses[j].amount;
            }
        }
        printf("%-10.2f\n", category_total);
    }

    free(expenses);

    return 0;
}