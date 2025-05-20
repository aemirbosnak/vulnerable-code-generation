//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;

void createExpense(char *name, float amount) {
    Expense *newExpense = (Expense *) malloc(sizeof(Expense));

    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    newExpense->next = head;
    head = newExpense;
}

void displayExpenses() {
    Expense *current = head;
    printf("\n-----------\n| Expenses |\n-----------\n");

    while (current != NULL) {
        printf("| %-40s | %10.2f |\n", current->name, current->amount);
        current = current->next;
    }
}

void searchExpense(char *name) {
    Expense *current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("\n-----------\n| Found   |\n-----------\n| Expense | %-40s |\n-----------\n| Amount | %10.2f |\n-----------\n", current->name, current->amount);
            return;
        }
        current = current->next;
    }

    printf("\n-----------\n| Not found|\n-----------\n");
}

int main() {
    createExpense("Capulet's Ball", 100.0);
    createExpense("Juliet's Dress", 50.0);
    createExpense("Romeo's Poison", -50.0);
    createExpense("Friar Laurence's Wedding Gifts", 50.0);
    createExpense("Mercutio's Funeral", 50.0);
    createExpense("Tybalt's Funeral", 30.0);

    displayExpenses();

    searchExpense("Capulet's Ball");
    searchExpense("Montague's Funeral"); // This should print "Not found"

    return 0;
}