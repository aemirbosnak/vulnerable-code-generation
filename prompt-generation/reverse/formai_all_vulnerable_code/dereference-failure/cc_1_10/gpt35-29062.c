//FormAI DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION_LENGTH 50


struct Expense {
    float amount;
    char description[MAX_DESCRIPTION_LENGTH];
    time_t date;
};

struct ExpenseTracker {
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses;
    float totalExpenses;
};

void addExpense(struct ExpenseTracker* tracker, float amount, char* description) {
    if (tracker->numExpenses == MAX_EXPENSES) {
        printf("Expense tracker is full!\n");
        return;
    }

    struct Expense* newExpense = &tracker->expenses[tracker->numExpenses];
    newExpense->amount = amount;
    strncpy(newExpense->description, description, MAX_DESCRIPTION_LENGTH);
    newExpense->date = time(NULL);

    tracker->numExpenses++;
    tracker->totalExpenses += amount;

    printf("Added expense: $%.2f - \"%s\"\n", amount, description);
}

void printExpenses(struct ExpenseTracker* tracker) {
    printf("Total expenses: $%.2f\n", tracker->totalExpenses);
    printf("Expenses:\n");
    for (int i = 0; i < tracker->numExpenses; i++) {
        struct Expense* expense = &tracker->expenses[i];
        printf("$%.2f - %s - %s", expense->amount, expense->description, asctime(localtime(&expense->date)));
    }
}

int main() {
    struct ExpenseTracker tracker = {0};

    printf("Welcome to the Expense Tracker 3000!\n");

    while (1) {
        printf("\nCommands:\n- add [amount] [description]\n- list\n- exit\n");
        printf("> ");
        char input[100];
        fgets(input, 100, stdin);

        char* command = strtok(input, " ");
        if (strncmp(command, "add", 3) == 0) {
            char* amountString = strtok(NULL, " ");
            float amount = atof(amountString);

            char* description = strtok(NULL, "\n");
            addExpense(&tracker, amount, description);
        }
        else if (strncmp(command, "list", 4) == 0) {
            printExpenses(&tracker);
        }
        else if (strncmp(command, "exit", 4) == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}