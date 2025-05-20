//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_CATEGORIES 100
#define MAX_EXPENSES 1000
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double total_expenses;
} Category;

typedef struct {
    char name[MAX_NAME_LENGTH];
    double amount;
    int category_index;
} Expense;

int main() {
    int num_categories;
    int num_expenses;

    printf("Enter the number of categories: ");
    scanf("%d", &num_categories);

    Category categories[num_categories];

    for (int i = 0; i < num_categories; i++) {
        printf("Enter the name of category %d: ", i + 1);
        scanf("%s", categories[i].name);
        categories[i].total_expenses = 0.0;
    }

    int num_expenses_per_category[num_categories];

    printf("\nEnter the number of expenses for each category:\n");
    for (int i = 0; i < num_categories; i++) {
        scanf("%d", &num_expenses_per_category[i]);
    }

    Expense expenses[num_categories * MAX_EXPENSES];

    int num_expenses_total = 0;

    for (int i = 0; i < num_categories; i++) {
        for (int j = 0; j < num_expenses_per_category[i]; j++) {
            printf("\nEnter the name of expense %d for category %s: ", j + 1, categories[i].name);
            scanf("%s", expenses[num_expenses_total].name);
            printf("Enter the amount of expense %s: ", expenses[num_expenses_total].name);
            scanf("%lf", &expenses[num_expenses_total].amount);
            expenses[num_expenses_total].category_index = i;
            num_expenses_total++;
        }
    }

    printf("\nCategory\tTotal Expenses\n");

    for (int i = 0; i < num_categories; i++) {
        printf("%s\t%.2lf\n", categories[i].name, categories[i].total_expenses);
    }

    return 0;
}