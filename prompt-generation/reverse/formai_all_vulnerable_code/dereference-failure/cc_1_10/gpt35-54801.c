//FormAI DATASET v1.0 Category: Expense Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char date[11];
    float amount;
    char description[50];
} Expense;

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void print_menu() {
    printf("\n1. Add an expense\n2. View All Expenses\n3. View Expense by Date Range\n4. Exit\n");
}

void add_expense(Expense *expenses, int *num_expenses) {
    char date_input[11];
    char amount_input[MAX_LINE_LENGTH];
    char description_input[50];
    float amount;
    char *endptr;

    printf("Enter the date (MM/DD/YYYY): ");
    fgets(date_input, sizeof(date_input), stdin);
    date_input[strcspn(date_input, "\n")] = '\0';

    printf("Enter the amount: ");
    fgets(amount_input, sizeof(amount_input), stdin);
    amount_input[strcspn(amount_input, "\n")] = '\0';

    printf("Enter the description: ");
    fgets(description_input, sizeof(description_input), stdin);
    description_input[strcspn(description_input, "\n")] = '\0';

    amount = strtod(amount_input, &endptr);
    if (*endptr || amount < 0) {
        printf("Invalid amount\n");
        return;
    }

    strcpy(expenses[*num_expenses].date, date_input);
    expenses[*num_expenses].amount = amount;
    strcpy(expenses[*num_expenses].description, description_input);
    (*num_expenses)++;

    printf("Expense Added!\n");
}

void view_all_expenses(Expense *expenses, int num_expenses) {
    if (num_expenses == 0) {
        printf("No expenses have been added\n");
        return;
    }

    printf("%-12s%-10s%s\n", "Date", "Amount", "Description");
    for (int i = 0; i < num_expenses; i++) {
        printf("%-12s$%-9.2f%s\n", expenses[i].date, expenses[i].amount, expenses[i].description);
    }
}

void view_expenses_by_date_range(Expense *expenses, int num_expenses) {
    if (num_expenses == 0) {
        printf("No expenses have been added\n");
        return;
    }

    char start_date_input[11];
    char end_date_input[11];
    printf("Enter the start date (MM/DD/YYYY): ");
    fgets(start_date_input, sizeof(start_date_input), stdin);
    start_date_input[strcspn(start_date_input, "\n")] = '\0';

    printf("Enter the end date (MM/DD/YYYY): ");
    fgets(end_date_input, sizeof(end_date_input), stdin);
    end_date_input[strcspn(end_date_input, "\n")] = '\0';

    int num_matching_expenses = 0;
    float total_amount = 0;
    printf("%-12s%-10s%s\n", "Date", "Amount", "Description");
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].date, start_date_input) >= 0 && strcmp(expenses[i].date, end_date_input) <= 0) {
            printf("%-12s$%-9.2f%s\n", expenses[i].date, expenses[i].amount, expenses[i].description);
            num_matching_expenses++;
            total_amount += expenses[i].amount;
        }
    }

    if (num_matching_expenses == 0) {
        printf("No matching expenses found\n");
        return;
    }

    printf("%d expenses found, total amount: $%.2f\n", num_matching_expenses, total_amount);
}

int main() {
    printf("---Expense Tracker---\n");

    Expense expenses[100];
    int num_expenses = 0;

    int menu_choice = 0;
    do {
        print_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &menu_choice) != 1) {
            printf("Invalid input\n");
            clear_input_buffer();
            continue;
        }

        switch (menu_choice) {
            case 1:
                add_expense(expenses, &num_expenses);
                break;
            case 2:
                view_all_expenses(expenses, num_expenses);
                break;
            case 3:
                view_expenses_by_date_range(expenses, num_expenses);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (menu_choice != 4);

    return 0;
}