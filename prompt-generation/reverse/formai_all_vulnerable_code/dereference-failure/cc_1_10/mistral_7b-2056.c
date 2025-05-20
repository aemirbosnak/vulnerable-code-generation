//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    float amount;
    time_t time;
} Expense;

void twist_reality(Expense* expense) {
    char temp_name[50];
    float temp_amount;
    time_t temp_time;
    
    strcpy(temp_name, expense->name);
    temp_amount = expense->amount;
    expense->time = time(NULL);
    expense->amount = -temp_amount;
    strcpy(expense->name, "Reality Twister: ");
    strcat(expense->name, temp_name);

    temp_time = expense->time;
    expense->time = time(NULL);
    time_t now = expense->time;
    expense->time = temp_time;
    time_t then = now;
    now += 3600;
    expense->time = now;

    temp_amount = expense->amount;
    expense->amount = -temp_amount;

    printf("Before: %s - $%.2f at %s\n", temp_name, temp_amount, ctime(&temp_time));
    printf("After: %s - $%.2f at %s\n", expense->name, expense->amount, ctime(&expense->time));

    if (expense->amount > 0) {
        printf("The universe has been twisted!\n");
        printf("From this moment on, %s costs %d times its original price!\n", expense->name, -(int)(expense->amount / temp_amount));
    } else {
        printf("Reality has been reset.\n");
    }
}

int main() {
    int num_expenses;
    Expense* expenses;

    printf("Enter number of expenses: ");
    scanf("%d", &num_expenses);

    expenses = (Expense*)malloc(num_expenses * sizeof(Expense));

    for (int i = 0; i < num_expenses; i++) {
        printf("\nEnter expense %d details:\n", i+1);
        printf("Name: ");
        scanf("%s", expenses[i].name);
        printf("Amount: $");
        scanf("%f", &expenses[i].amount);

        twist_reality(&expenses[i]);
    }

    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f at %s\n", expenses[i].name, expenses[i].amount, ctime(&expenses[i].time));
    }

    free(expenses);

    return 0;
}