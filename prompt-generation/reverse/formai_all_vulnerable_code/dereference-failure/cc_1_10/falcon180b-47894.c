//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 1000

typedef struct {
    char name[50];
    float amount;
    time_t date;
} expense;

int num_expenses = 0;
expense expenses[MAX_EXPENSES];

void add_expense(char *name, float amount) {
    time_t now = time(NULL);
    strftime(expenses[num_expenses].date, 50, "%Y-%m-%d %H:%M:%S", localtime(&now));
    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].amount = amount;
    num_expenses++;
}

void print_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

void delete_expense(int index) {
    for (int i = index; i < num_expenses - 1; i++) {
        strcpy(expenses[i].name, expenses[i + 1].name);
        expenses[i].amount = expenses[i + 1].amount;
        strcpy(expenses[i].date, expenses[i + 1].date);
    }
    num_expenses--;
}

int main() {
    add_expense("Lunch", 10.99);
    add_expense("Gas", 25.45);
    add_expense("Coffee", 3.50);

    print_expenses();

    delete_expense(1);

    print_expenses();

    return 0;
}