//FormAI DATASET v1.0 Category: Expense Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[30];
    float amount;
    char category[20];
} Expense;

// Function to prompt user for expenses
int getExpenses(Expense *expenses) {
    int num_exp = 0;
    char input[50];
    char *tok;
    float amt;

    while (1) {
        printf("Enter expense (name amount category): ");
        fgets(input, sizeof(input), stdin);

        // Check if user wants to exit
        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        // Parse input
        tok = strtok(input, " ");
        strcpy(expenses[num_exp].name, tok);

        tok = strtok(NULL, " ");
        amt = atof(tok);
        expenses[num_exp].amount = amt;

        tok = strtok(NULL, " ");
        strcpy(expenses[num_exp].category, tok);

        num_exp++;
    }

    return num_exp;
}

// Function to get total expenses
float getTotal(Expense *expenses, int num_exp) {
    float total = 0;
    for (int i = 0; i < num_exp; i++) {
        total += expenses[i].amount;
    }
    return total;
}

// Function to print expenses by category
void printByCategory(Expense *expenses, int num_exp) {
    char categories[20][20];
    int num_categories = 0;

    // Get unique categories
    for (int i = 0; i < num_exp; i++) {
        int found = 0;
        for (int j = 0; j < num_categories; j++) {
            if (strcmp(expenses[i].category, categories[j]) == 0) {
                found = 1;
            }
        }
        if (!found) {
            strcpy(categories[num_categories], expenses[i].category);
            num_categories++;
        }
    }

    // Print expenses by category
    for (int i = 0; i < num_categories; i++) {
        printf("%s expenses:\n", categories[i]);
        printf("------------------\n");
        for (int j = 0; j < num_exp; j++) {
            if (strcmp(expenses[j].category, categories[i]) == 0) {
                printf("%s: $%.2f\n", expenses[j].name, expenses[j].amount);
            }
        }
        printf("------------------\n");
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];

    int num_exp = getExpenses(expenses);

    float total = getTotal(expenses, num_exp);

    printf("Total expenses: $%.2f\n", total);

    printByCategory(expenses, num_exp);

    return 0;
}