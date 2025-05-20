//FormAI DATASET v1.0 Category: Expense Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct Expense {
    char date[11];
    char description[50];
    double amount;
} Expense;

Expense* expenses[MAX_EXPENSES];
int numExpenses = 0;

void addExpense() {
    // Prompt the user for new expense details
    printf("Enter expense date (MM/DD/YYYY): ");
    char date[11];
    fgets(date, 11, stdin);
    date[strlen(date) - 1] = '\0';

    printf("Enter expense description: ");
    char description[50];
    fgets(description, 50, stdin);
    description[strlen(description) - 1] = '\0';

    printf("Enter expense amount: $");
    double amount;
    scanf("%lf", &amount);
    getchar(); // Consume the newline character from scanf

    // Create a new expense and add it to the expenses array
    Expense* newExpense = (Expense*) malloc(sizeof(Expense));
    strcpy(newExpense->date, date);
    strcpy(newExpense->description, description);
    newExpense->amount = amount;

    expenses[numExpenses] = newExpense;
    numExpenses++;
}

void viewExpenses() {
    // Print out all expenses in the expenses array
    printf("\n Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%d. Date: %s\n Description: %s\n Amount: $%.2lf\n\n",
                i+1, expenses[i]->date, expenses[i]->description, expenses[i]->amount);
    }
}

void saveExpensesToFile(char* fileName) {
    // Open the file for writing
    FILE* fp = fopen(fileName, "w");

    // Write each expense to the file
    for (int i = 0; i < numExpenses; i++) {
        fprintf(fp, "%s,%s,%.2lf\n", expenses[i]->date, expenses[i]->description, expenses[i]->amount);
    }

    // Close the file
    fclose(fp);

    printf("\nExpenses successfully saved to %s!\n", fileName);
}

void readExpensesFromFile(char* fileName) {
    // Open the file for reading
    FILE* fp = fopen(fileName, "r");

    // Read each line of the file and create an expense from it
    char line[100];
    while (fgets(line, 100, fp) != NULL) {
        char* token;
        char* date;
        char* description;
        char* amountStr;

        // Get the date from the line
        token = strtok(line, ",");
        date = token;

        // Get the description from the line
        token = strtok(NULL, ",");
        description = token;

        // Get the amount from the line
        token = strtok(NULL, ",");
        amountStr = token;

        // Convert the amount string to a double
        double amount = atof(amountStr);

        // Create a new expense and add it to the expenses array
        Expense* newExpense = (Expense*) malloc(sizeof(Expense));
        strcpy(newExpense->date, date);
        strcpy(newExpense->description, description);
        newExpense->amount = amount;

        expenses[numExpenses] = newExpense;
        numExpenses++;
    }

    // Close the file
    fclose(fp);

    printf("\nExpenses successfully loaded from %s!\n", fileName);
}

void displayMenu() {
    printf("\n");
    printf("Expense Tracker Menu\n");
    printf("-------------------------\n");
    printf("1. Add new expense\n");
    printf("2. View all expenses\n");
    printf("3. Save expenses to file\n");
    printf("4. Load expenses from file\n");
    printf("5. Exit\n\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character from scanf

        switch(choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                // Prompt the user for a file name and save the expenses to the file
                printf("Enter file name to save expenses to: ");
                char fileName[50];
                fgets(fileName, 50, stdin);
                fileName[strlen(fileName) - 1] = '\0';

                saveExpensesToFile(fileName);
                break;
            case 4:
                // Prompt the user for a file name and load the expenses from the file
                printf("Enter file name to load expenses from: ");
                char loadFileName[50];
                fgets(loadFileName, 50, stdin);
                loadFileName[strlen(loadFileName) - 1] = '\0';

                readExpensesFromFile(loadFileName);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    } while (choice != 5);

    // Free the memory used by each expense
    for (int i = 0; i < numExpenses; i++) {
        free(expenses[i]);
    }

    return 0;
}