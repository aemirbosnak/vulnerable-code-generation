//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EXPENSES 10

typedef struct {
    char name[50];
    double amount;
    struct expense *next;
} expense;

expense *head = NULL;

void add_expense(char *name, double amount) {
    expense *new_expense = (expense*) malloc(sizeof(expense));
    if (!new_expense) {
        printf("Out of memory\n");
        return;
    }
    strcpy(new_expense->name, name);
    new_expense->amount = amount;
    new_expense->next = head;
    head = new_expense;
}

void remove_expense(char *name) {
    expense *current = head;
    while (current && strcmp(current->name, name)) {
        current = current->next;
    }
    if (!current) {
        printf("Expense not found\n");
        return;
    }
    if (current->next == NULL) {
        head = NULL;
    } else {
        expense *temp = current->next;
        free(current);
        current = temp;
    }
}

void print_expenses() {
    expense *current = head;
    while (current) {
        printf("%s - $%.2f\n", current->name, current->amount);
        current = current->next;
    }
}

int main() {
    srand(time(0));
    char *names[MAX_EXPENSES];
    double amounts[MAX_EXPENSES];
    int i;
    for (i = 0; i < MAX_EXPENSES; i++) {
        names[i] = (char*) malloc(sizeof(char) * 50);
        if (!names[i]) {
            printf("Out of memory\n");
            return 1;
        }
        amounts[i] = (double) rand() / RAND_MAX * 100;
    }
    for (i = 0; i < MAX_EXPENSES; i++) {
        add_expense(names[i], amounts[i]);
    }
    print_expenses();
    for (i = 0; i < MAX_EXPENSES; i++) {
        remove_expense(names[i]);
    }
    print_expenses();
    return 0;
}