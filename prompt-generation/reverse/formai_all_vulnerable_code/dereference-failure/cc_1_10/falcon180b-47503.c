//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float amount;
    int category;
} Expense;

void add_category(char* name, int index) {
    printf("Enter a name for category %d: ", index + 1);
    scanf("%s", name);
}

void add_expense(Expense* expenses, int* num_expenses, int category) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*num_expenses].amount);
    expenses[*num_expenses].category = category;
    (*num_expenses)++;
}

void display_categories(char* categories[], int num_categories) {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s\n", i + 1, categories[i]);
    }
}

void display_expenses(Expense* expenses, int num_expenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f (Category: %d)\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    char categories[MAX_CATEGORIES][MAX_NAME_LEN];
    int num_categories = 0;
    printf("Enter the number of expense categories (up to %d): ", MAX_CATEGORIES - 1);
    scanf("%d", &num_categories);
    for (int i = 0; i < num_categories; i++) {
        add_category(categories[i], i);
    }

    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    printf("\nEnter the number of expenses (up to %d): ", MAX_EXPENSES - 1);
    scanf("%d", &num_expenses);
    for (int i = 0; i < num_expenses; i++) {
        add_expense(expenses, &num_expenses, 0);
    }

    display_categories(categories, num_categories);
    display_expenses(expenses, num_expenses);

    return 0;
}