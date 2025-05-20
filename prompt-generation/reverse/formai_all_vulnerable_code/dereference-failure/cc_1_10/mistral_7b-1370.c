//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[50];
    float amount;
    struct expense* next;
} expense;

expense* expenses = NULL;

void add_expense(char* desc, float amt) {
    expense* new_expense = (expense*) malloc(sizeof(expense));
    strcpy(new_expense->description, desc);
    new_expense->amount = amt;
    new_expense->next = expenses;
    expenses = new_expense;
}

void display_expenses() {
    expense* curr_expense = expenses;
    printf("\n---- SHERLOCK HOLMES'S EXPENSE TRACKER ----\n");
    while (curr_expense != NULL) {
        printf("%s: %.2f\n", curr_expense->description, curr_expense->amount);
        curr_expense = curr_expense->next;
    }
}

int main() {
    char input_str[100];
    float amount;
    int more_expenses = 1;

    while (more_expenses) {
        printf("Enter expense description: ");
        fgets(input_str, sizeof(input_str), stdin);
        input_str[strcspn(input_str, "\n")] = '\0'; // Remove newline character

        printf("Enter expense amount: ");
        scanf("%f", &amount);

        add_expense(input_str, amount);

        printf("Do you want to add another expense? (y/n): ");
        scanf("%s", input_str);
        if (strcmp(input_str, "n") == 0) {
            more_expenses = 0;
        }
    }

    display_expenses();

    expense* curr_expense = expenses;
    while (curr_expense != NULL) {
        expense* temp = curr_expense;
        curr_expense = curr_expense->next;
        free(temp);
    }

    return 0;
}