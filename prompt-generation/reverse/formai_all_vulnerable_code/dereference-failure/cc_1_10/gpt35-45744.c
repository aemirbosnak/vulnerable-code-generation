//FormAI DATASET v1.0 Category: Expense Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expense {
    char date[11];
    char item[20];
    float amount;
} Expense;

void add_expense(Expense **expenses, int *num_expenses) {
    *num_expenses += 1;
    *expenses = realloc(*expenses, (*num_expenses) * sizeof(Expense));
    Expense e;

    printf("Enter the date (MM/DD/YYYY): ");
    fgets(e.date, 11, stdin);
    e.date[strcspn(e.date, "\n")] = '\0';

    printf("Enter the item (up to 20 characters): ");
    fgets(e.item, 20, stdin);
    e.item[strcspn(e.item, "\n")] = '\0';

    printf("Enter the amount: ");
    scanf("%f", &e.amount);

    (*expenses)[*num_expenses - 1] = e;

    printf("\nExpense added successfully!\n");
    fflush(stdin);
}

void view_expenses(Expense *expenses, int num_expenses) {
    if (num_expenses == 0) {
        printf("\nNo expenses added yet!\n");
        return;
    }
    printf("\n");
    printf("Date\t\tItem\t\tAmount\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%s\t\t%.2f\n", expenses[i].date, expenses[i].item, expenses[i].amount);
    }
    printf("--------------------------------------\n");
    fflush(stdin);
}

void delete_expense(Expense **expenses, int *num_expenses) {
    if (*num_expenses == 0) {
        printf("\nNo expenses added yet!\n");
        return;
    }
    char date[11];
    printf("Enter the date of the expense you want to delete (MM/DD/YYYY): ");
    fgets(date, 11, stdin);
    date[strcspn(date, "\n")] = '\0';

    int index = -1;
    for (int i = 0; i < *num_expenses; i++) {
        if (strcmp((*expenses)[i].date, date) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nExpense with the given date not found!\n");
        return;
    }
    for (int i = index; i < *num_expenses - 1; i++) {
        (*expenses)[i] = (*expenses)[i + 1];
    }
    (*num_expenses)--;
    *expenses = realloc(*expenses, (*num_expenses) * sizeof(Expense));

    printf("\nExpense deleted successfully!\n");
    fflush(stdin);
}

void save_expenses(Expense *expenses, int num_expenses) {
    FILE *f = fopen("expenses.txt", "w");
    fprintf(f, "Date\t\tItem\t\tAmount\n");
    fprintf(f, "--------------------------------------\n");
    for (int i = 0; i < num_expenses; i++) {
        fprintf(f, "%s\t%s\t\t%.2f\n", expenses[i].date, expenses[i].item, expenses[i].amount);
    }
    fclose(f);
    printf("\nExpenses saved to expenses.txt file!\n");
    fflush(stdin);
}

int main() {
    Expense *expenses = NULL;
    int num_expenses = 0;
    int choice;
    while (1) {
        printf("\nMENU\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Save Expenses\n");
        printf("5. Exit\n\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                add_expense(&expenses, &num_expenses);
                break;
            case 2:
                view_expenses(expenses, num_expenses);
                break;
            case 3:
                delete_expense(&expenses, &num_expenses);
                break;
            case 4:
                save_expenses(expenses, num_expenses);
                break;
            case 5:
                free(expenses);
                printf("\nExiting Expense Tracker. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}