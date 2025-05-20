//FormAI DATASET v1.0 Category: Expense Tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define maximum number of expenses allowed
#define MAX_EXPENSES 50

// define structure for expense
typedef struct Expense {
    char date[20];
    char category[30];
    float amount;
} Expense;

// function declarations
void displayMenu();
void addExpense(Expense expenses[], int *numExpenses);
void viewExpenses(Expense expenses[], int numExpenses);
void saveExpenses(Expense expenses[], int numExpenses);
void loadExpenses(Expense expenses[], int *numExpenses);

// main function
int main() {
    // variable declarations
    int choice;
    int numExpenses = 0;
    Expense expenses[MAX_EXPENSES];

    // load saved expenses on startup
    loadExpenses(expenses, &numExpenses);

    // display menu and get user choice
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                viewExpenses(expenses, numExpenses);
                break;
            case 3:
                saveExpenses(expenses, numExpenses);
                printf("Expenses saved successfully!\n");
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

// function to display menu options
void displayMenu() {
    printf("\nExpense Tracker Menu\n");
    printf("--------------------\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Save Expenses\n");
    printf("4. Exit\n");
}

// function to add a new expense
void addExpense(Expense expenses[], int *numExpenses) {
    // check if maximum number of expenses has been reached
    if(*numExpenses == MAX_EXPENSES) {
        printf("Maximum number of expenses reached.\n");
        return;
    }

    // get expense details from user
    printf("Enter date of expense (MM/DD/YYYY): ");
    scanf("%s", expenses[*numExpenses].date);
    printf("Enter category of expense: ");
    scanf("%s", expenses[*numExpenses].category);
    printf("Enter amount of expense: ");
    scanf("%f", &expenses[*numExpenses].amount);

    // increment number of expenses counter
    (*numExpenses)++;

    printf("Expense added successfully!\n");
}

// function to view all expenses
void viewExpenses(Expense expenses[], int numExpenses) {
    // check if expenses list is empty
    if(numExpenses == 0) {
        printf("No expenses found.\n");
        return;
    }

    // print table header
    printf("Date\t\tCategory\tAmount\n");
    printf("------------------------------------------\n");

    // iterate through expenses and print each one
    for(int i = 0; i < numExpenses; i++) {
        printf("%s\t%s\t\t$%.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
    }
}

// function to save expenses to file
void saveExpenses(Expense expenses[], int numExpenses) {
    // create file pointer and open file for writing
    FILE *fp;
    fp = fopen("expenses.txt", "w");

    // iterate through expenses and write each one to file
    for(int i = 0; i < numExpenses; i++) {
        fprintf(fp, "%s,%s,%.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
    }

    // close file
    fclose(fp);
}

// function to load expenses from file
void loadExpenses(Expense expenses[], int *numExpenses) {
    // create file pointer and open file for reading
    FILE *fp;
    fp = fopen("expenses.txt", "r");

    // check if file exists
    if(fp == NULL) {
        printf("No saved expenses found.\n");
        return;
    }

    // read each line from file and store in expenses array
    char buffer[100];
    while(fgets(buffer, 100, fp)) {
        char *token = strtok(buffer, ",");
        strcpy(expenses[*numExpenses].date, token);
        token = strtok(NULL, ",");
        strcpy(expenses[*numExpenses].category, token);
        token = strtok(NULL, ",");
        expenses[*numExpenses].amount = atof(token);
        (*numExpenses)++;
    }

    // close file
    fclose(fp);
}