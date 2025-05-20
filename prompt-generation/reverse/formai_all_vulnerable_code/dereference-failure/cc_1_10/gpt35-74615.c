//FormAI DATASET v1.0 Category: Expense Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_input_buffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

typedef struct Expense {
    char name[50];
    float amount;
    char date[11];
    char location[50];
} Expense;

int main() {
    int choice, count = 0;
    float total_expense = 0.0;
    Expense *expenses = NULL;

    printf("Welcome to your paranoid expense tracker!\n\n");

    while (1) {
        printf("Enter 1 to add an expense\n");
        printf("Enter 2 to view all expenses\n");
        printf("Enter 3 to view total expense\n");
        printf("Enter 4 to exit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);
        clear_input_buffer();   // clear input buffer to avoid unexpected behavior

        if (choice == 1) {
            expenses = (Expense *) realloc(expenses, (count + 1) * sizeof(Expense));

            printf("\nEnter expense name: ");
            fgets(expenses[count].name, 50, stdin);
            expenses[count].name[strcspn(expenses[count].name, "\n")] = '\0';  // remove newline character from input

            printf("Enter expense amount: ");
            scanf("%f", &expenses[count].amount);
            clear_input_buffer();

            printf("Enter expense date (DD/MM/YYYY): ");
            fgets(expenses[count].date, 11, stdin);
            expenses[count].date[strcspn(expenses[count].date, "\n")] = '\0';  // remove newline character from input

            printf("Enter expense location: ");
            fgets(expenses[count].location, 50, stdin);
            expenses[count].location[strcspn(expenses[count].location, "\n")] = '\0';  // remove newline character from input

            total_expense += expenses[count].amount;
            count++;
        }
        else if (choice == 2) {
            if (count == 0) {
                printf("\nNo expenses yet!\n");
                continue;  // go to next iteration of while loop to avoid printing empty expense table
            }

            printf("\nExpenses:\n");
            printf("%-5s%-30s%-10s%-20s\n", "ID", "Name", "Amount", "Date");
            printf("--------------------------------------------------------\n");
            for (int i = 0; i < count; i++) {
                printf("%-5d%-30s%-10.2f%-20s\n", i+1, expenses[i].name, expenses[i].amount, expenses[i].date);
            }
            printf("\n");
        }
        else if (choice == 3) {
            printf("\nTotal expense: $%.2f\n", total_expense);
        }
        else if (choice == 4) {
            printf("Goodbye!\n");
            break;  // exit while loop and end program
        }
        else {
            printf("\nInvalid choice. Try again.\n");
        }
    }

    free(expenses);

    return 0;
}