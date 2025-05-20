//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of an expense
typedef struct {
    char *description;
    double amount;
    int category;
} Expense;

// Define the categories of expenses
#define CATEGORY_FOOD 0
#define CATEGORY_HOUSING 1
#define CATEGORY_TRANSPORTATION 2
#define CATEGORY_ENTERTAINMENT 3
#define CATEGORY_OTHER 4

// Create an array of expenses
Expense expenses[] = {
    {"Groceries", 200.00, CATEGORY_FOOD},
    {"Rent", 1000.00, CATEGORY_HOUSING},
    {"Car payment", 300.00, CATEGORY_TRANSPORTATION},
    {"Movie tickets", 50.00, CATEGORY_ENTERTAINMENT},
    {"Other", 100.00, CATEGORY_OTHER}
};

// Get the total number of expenses
int num_expenses = sizeof(expenses) / sizeof(expenses[0]);

// Function to print the expenses
void print_expenses(Expense expenses[], int num_expenses) {
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f\n", expenses[i].description, expenses[i].amount);
    }
}

// Function to get the total amount of expenses
double get_total_expenses(Expense expenses[], int num_expenses) {
    double total = 0.0;
    for (int i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

// Function to get the average amount of expenses
double get_average_expenses(Expense expenses[], int num_expenses) {
    double total = get_total_expenses(expenses, num_expenses);
    return total / num_expenses;
}

// Function to get the expenses in a given category
Expense *get_expenses_in_category(Expense expenses[], int num_expenses, int category) {
    Expense *expenses_in_category = malloc(sizeof(Expense) * num_expenses);
    int num_expenses_in_category = 0;
    for (int i = 0; i < num_expenses; i++) {
        if (expenses[i].category == category) {
            expenses_in_category[num_expenses_in_category] = expenses[i];
            num_expenses_in_category++;
        }
    }
    return expenses_in_category;
}

// Function to get the total amount of expenses in a given category
double get_total_expenses_in_category(Expense expenses[], int num_expenses, int category) {
    Expense *expenses_in_category = get_expenses_in_category(expenses, num_expenses, category);
    double total = get_total_expenses(expenses_in_category, num_expenses);
    free(expenses_in_category);
    return total;
}

// Function to get the average amount of expenses in a given category
double get_average_expenses_in_category(Expense expenses[], int num_expenses, int category) {
    Expense *expenses_in_category = get_expenses_in_category(expenses, num_expenses, category);
    double total = get_total_expenses(expenses_in_category, num_expenses);
    double average = get_average_expenses(expenses_in_category, num_expenses);
    free(expenses_in_category);
    return average;
}

// Main function
int main() {
    // Print the expenses
    printf("Expenses:\n");
    print_expenses(expenses, num_expenses);

    // Get the total amount of expenses
    double total_expenses = get_total_expenses(expenses, num_expenses);
    printf("Total expenses: $%.2f\n", total_expenses);

    // Get the average amount of expenses
    double average_expenses = get_average_expenses(expenses, num_expenses);
    printf("Average expenses: $%.2f\n", average_expenses);

    // Get the expenses in the food category
    Expense *food_expenses = get_expenses_in_category(expenses, num_expenses, CATEGORY_FOOD);
    printf("Expenses in the food category:\n");
    print_expenses(food_expenses, num_expenses);
    
    // Get the total amount of expenses in the food category
    double total_food_expenses = get_total_expenses_in_category(expenses, num_expenses, CATEGORY_FOOD);
    printf("Total expenses in the food category: $%.2f\n", total_food_expenses);
    
    // Get the average amount of expenses in the food category
    double average_food_expenses = get_average_expenses_in_category(expenses, num_expenses, CATEGORY_FOOD);
    printf("Average expenses in the food category: $%.2f\n", average_food_expenses);
    
    return 0;
}