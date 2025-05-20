//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Expense {
    char name[50];
    float amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;

void addExpense(char *name, float amount) {
    Expense *newExpense = (Expense *)malloc(sizeof(Expense));
    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    newExpense->next = head;
    head = newExpense;
}

void displayExpenses() {
    Expense *temp = head;
    while (temp != NULL) {
        printf("%s: %.2f\n", temp->name, temp->amount);
        temp = temp->next;
    }
}

void shiftExpenses(int numShifts) {
    Expense *temp1 = head, *temp2 = NULL;
    int i;

    for (i = 0; i < numShifts; i++) {
        if (temp1 == NULL) {
            printf("Error: Not enough expenses to shift.\n");
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = head;
    head = temp1;
}

int main() {
    addExpense("Rent", 1000.00);
    addExpense("Groceries", 200.00);
    addExpense("Utilities", 150.00);
    addExpense("Entertainment", 50.00);

    printf("Initial Expenses:\n");
    displayExpenses();

    shiftExpenses(1);
    printf("Expenses after shifting once:\n");
    displayExpenses();

    shiftExpenses(2);
    printf("Expenses after shifting twice:\n");
    displayExpenses();

    return 0;
}