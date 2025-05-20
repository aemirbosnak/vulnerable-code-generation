//FormAI DATASET v1.0 Category: Expense Tracker ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

// defining the structure for expense
struct Expense {
    char name[50];
    float amount;
    char category[20];
};

// function to add expenses
void addExpense(struct Expense *expenses, int n) {
    printf("Enter the details of the new expense:\n");
    printf("Name: ");
    scanf("%s", (expenses+n)->name);
    printf("Amount: ");
    scanf("%f", &(expenses+n)->amount);
    printf("Category: ");
    scanf("%s", (expenses+n)->category);
}

// function to display all expenses
void displayExpenses(struct Expense *expenses, int n) {
    printf("\nAll expenses:\n");
    printf("Name\t\tAmount\t\tCategory\n");
    for(int i=0; i<n; i++) {
        printf("%s\t\t%.2f\t\t%s\n", (expenses+i)->name, (expenses+i)->amount, (expenses+i)->category);
    }
}

// function to display expenses by category
void displayExpensesByCategory(struct Expense *expenses, int n) {
    char category[20];
    printf("\nEnter the category to display expenses: ");
    scanf("%s", category);
    printf("\nExpenses in category %s:\n", category);
    printf("Name\t\tAmount\t\tCategory\n");
    for(int i=0; i<n; i++) {
        if(strcmp((expenses+i)->category, category) == 0) {
            printf("%s\t\t%.2f\t\t%s\n", (expenses+i)->name, (expenses+i)->amount, (expenses+i)->category);
        }
    }
}

int main() {
    int n, choice;
    printf("Welcome to the Expense Tracker program!\n");
    printf("Enter the number of expenses: ");
    scanf("%d", &n);

    // dynamically allocating memory for expenses
    struct Expense *expenses = (struct Expense*) malloc(n * sizeof(struct Expense));
    if(expenses == NULL) {
        printf("Memory allocation failed!\n");
        exit(0);
    }

    // loop to display menu and handle choices
    while(1) {
        printf("\nChoose an option:\n");
        printf("1. Add an expense\n");
        printf("2. Display all expenses\n");
        printf("3. Display expenses by category\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addExpense(expenses, n);
                break;
            case 2:
                displayExpenses(expenses, n);
                break;
            case 3:
                displayExpensesByCategory(expenses, n);
                break;
            case 4:
                printf("Exiting the program. Thank you for using our Expense Tracker!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    free(expenses); // freeing the memory allocated for expenses
    return 0;
}