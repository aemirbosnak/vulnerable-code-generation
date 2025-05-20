//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Data structure to store an expense
typedef struct expense {
    char name[50];
    float amount;
    char category[50];
    time_t date;
} expense;

// Function to create a new expense
expense* create_expense(char* name, float amount, char* category, time_t date) {
    expense* new_expense = (expense*)malloc(sizeof(expense));
    strcpy(new_expense->name, name);
    new_expense->amount = amount;
    strcpy(new_expense->category, category);
    new_expense->date = date;
    return new_expense;
}

// Function to print an expense
void print_expense(expense* expense) {
    printf("Name: %s\n", expense->name);
    printf("Amount: $%.2f\n", expense->amount);
    printf("Category: %s\n", expense->category);
    printf("Date: %s\n", ctime(&expense->date));
}

// Function to add an expense to a list
void add_expense(expense*** list, int* size, expense* new_expense) {
    *list = (expense**)realloc(*list, (*size + 1) * sizeof(expense*));
    (*list)[*size] = new_expense;
    (*size)++;
}

// Function to free the memory allocated for an expense
void free_expense(expense* expense) {
    free(expense);
}

// Function to free the memory allocated for a list of expenses
void free_expenses(expense** list, int size) {
    for (int i = 0; i < size; i++) {
        free_expense(list[i]);
    }
    free(list);
}

// Function to compare two expenses by date
int compare_expenses(const void* a, const void* b) {
    expense** expense1 = (expense**)a;
    expense** expense2 = (expense**)b;
    return (*expense1)->date - (*expense2)->date;
}

//Function to generate dynamic array's directly
expense** get_expenses(int* size)
{
    int num_expenses;
    printf("How many expenses would you like to add?: ");
    scanf("%d", &num_expenses);

    *size = num_expenses;
    expense** expenses = (expense**)malloc(num_expenses * sizeof(expense*));
    
    char name[50];
    float amount;
    char category[50];
    time_t date;

    for (int i = 0; i < num_expenses; i++) {
        printf("\nEnter the expense name: ");
        scanf("%s", name);

        printf("Enter the amount: $");
        scanf("%f", &amount);

        printf("Enter the category: ");
        scanf("%s", category);

        printf("Enter the date (YYYY-MM-DD): ");
        scanf("%s", name); // dummy read
        scanf("%d-%d-%d", &date, &date, &date); 

        expenses[i] = create_expense(name, amount, category, date);
    }

    return expenses;
}

int main() {
    int size = 0;
    expense** expenses = get_expenses(&size);

    // Sort the expenses by date
    qsort(expenses, size, sizeof(expense*), compare_expenses);

    // Print the expenses
    printf("\nYour expenses:\n");
    for (int i = 0; i < size; i++) {
        print_expense(expenses[i]);
        printf("\n");
    }

    // Free the memory allocated for the expenses
    free_expenses(expenses, size);

    return 0;
}