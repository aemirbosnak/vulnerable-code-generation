//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Struct to hold details of an expense
typedef struct expense {
    char* description; // Description of the expense
    float amount; // Amount spent
    struct expense* next; // Pointer to next expense
} Expense;

// Function to add a new expense
void addExpense(Expense** head) {
    // Allocate memory for new expense
    Expense* newExpense = (Expense*) malloc(sizeof(Expense));

    // Ask user for details of the expense
    printf("\nEnter description of expense: ");
    char* description = (char*) malloc(sizeof(char) * 100);
    scanf("%s", description);
    newExpense->description = description;

    printf("Enter amount spent: ");
    float amount;
    scanf("%f", &amount);
    newExpense->amount = amount;

    newExpense->next = NULL;

    if (*head == NULL) { // First expense
        *head = newExpense;
    } else { // Not the first expense
        // Go to end of existing list
        Expense* current = *head;
        while(current->next != NULL) {
            current = current->next;
        }

        // Add new expense to end of existing list
        current->next = newExpense;
    }

    printf("\nExpense added successfully!\n");
}

// Function to display all expenses
void displayExpenses(Expense** head) {
    if (*head == NULL) {
        printf("\nNo expenses added yet!\n");
        return;
    }

    printf("\nList of expenses:\n\n");

    // Loop over all expenses in the list
    Expense* current = *head;
    while(current != NULL) {
        printf("%s\t%.2f\n", current->description, current->amount);
        current = current->next;
    }
}

int main() {
    Expense* head = NULL;

    while(1) {
        // Show menu options
        printf("\n---------- MENU ----------\n");
        printf("1. Add new expense\n");
        printf("2. Display all expenses\n");
        printf("3. Exit\n\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addExpense(&head); // Add new expense
                break;
            case 2:
                displayExpenses(&head); // Display all expenses
                break;
            case 3:
                printf("\nGoodbye!\n");
                exit(0); // Exit program
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}