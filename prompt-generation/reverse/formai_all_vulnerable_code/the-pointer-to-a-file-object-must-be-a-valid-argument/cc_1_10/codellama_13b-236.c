//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXPENSES_FILE "expenses.txt"

typedef struct {
    char category[100];
    float amount;
} Expense;

void add_expense(Expense expense);
void print_expenses();

int main() {
    Expense expense;

    printf("Enter the category: ");
    scanf("%s", expense.category);
    printf("Enter the amount: ");
    scanf("%f", &expense.amount);

    add_expense(expense);
    print_expenses();

    return 0;
}

void add_expense(Expense expense) {
    FILE *fp;
    fp = fopen(EXPENSES_FILE, "a");
    fprintf(fp, "%s,%.2f\n", expense.category, expense.amount);
    fclose(fp);
}

void print_expenses() {
    FILE *fp;
    char line[100];
    float total = 0;

    fp = fopen(EXPENSES_FILE, "r");
    while (fgets(line, 100, fp) != NULL) {
        char *category = strtok(line, ",");
        float amount = atof(strtok(NULL, ","));
        total += amount;
        printf("%s - %.2f\n", category, amount);
    }
    fclose(fp);
    printf("Total: %.2f\n", total);
}