//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    double amount;
    char category[MAX_CATEGORIES];
} expense;

int main() {
    int num_categories, num_expenses;
    char input[100];
    expense expenses[MAX_EXPENSES];
    char categories[MAX_CATEGORIES][MAX_CATEGORIES];
    int category_lengths[MAX_CATEGORIES];
    int i, j, k, category_index;
    double total_expenses = 0;

    printf("Enter the number of expense categories: ");
    scanf("%d", &num_categories);

    for (i = 0; i < num_categories; i++) {
        printf("Enter the name of category %d: ", i + 1);
        scanf("%s", categories[i]);
        category_lengths[i] = strlen(categories[i]);
    }

    printf("Enter the number of expenses: ");
    scanf("%d", &num_expenses);

    for (i = 0; i < num_expenses; i++) {
        printf("Enter the name of expense %d: ", i + 1);
        scanf("%s", expenses[i].name);
        printf("Enter the description of expense %d: ", i + 1);
        scanf("%s", expenses[i].description);
        printf("Enter the amount of expense %d: ", i + 1);
        scanf("%lf", &expenses[i].amount);
        printf("Enter the category of expense %d (1-%d): ", i + 1, num_categories);
        scanf("%d", &category_index);
        strcpy(expenses[i].category, categories[category_index - 1]);
        total_expenses += expenses[i].amount;
    }

    printf("Category\tExpense\tAmount\n");
    for (i = 0; i < num_categories; i++) {
        printf("%s\t", categories[i]);
        for (j = 0; j < num_expenses; j++) {
            if (strcmp(expenses[j].category, categories[i]) == 0) {
                printf("%s\t%.2lf\n", expenses[j].name, expenses[j].amount);
                total_expenses += expenses[j].amount;
            }
        }
        if (i == num_categories - 1) {
            printf("%.2lf\n", total_expenses);
        }
    }

    return 0;
}