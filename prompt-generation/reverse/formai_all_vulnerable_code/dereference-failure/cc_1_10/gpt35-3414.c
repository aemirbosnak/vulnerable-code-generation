//FormAI DATASET v1.0 Category: Expense Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXP 100

typedef struct expense {
    int id;
    char date[11];
    char description[51];
    float amount;
} Expense;

int numExp = 0;
Expense *expenses[MAX_EXP];

void addExpense() {
    if (numExp >= MAX_EXP) {
        printf("\nNo more expenses can be added!\n");
        return;
    }
    Expense *newExp = (Expense*) malloc(sizeof(Expense));
    printf("\nEnter details of expense #%d:\n", numExp+1);
    newExp->id = numExp+1;
    printf("Date (dd/mm/yyyy): ");
    scanf("%s", newExp->date);
    printf("Description: ");
    scanf(" %[^\n]s", newExp->description);
    printf("Amount: ");
    scanf("%f", &newExp->amount);
    expenses[numExp++] = newExp;
}

void viewExpenses() {
    if (numExp == 0) {
        printf("\nNo expenses added yet!\n");
        return;
    }
    printf("\nID\tDate\t\tDescription\t\tAmount\n");
    printf("--\t----\t\t-----------\t\t------");
    for (int i = 0; i < numExp; i++) {
        printf("\n%d\t%s\t%s\t\t%.2f", expenses[i]->id, expenses[i]->date, expenses[i]->description, expenses[i]->amount);
    }
    printf("\n");
}

void saveExpenses() {
    FILE *fp = fopen("expenses.txt", "w");
    if (fp == NULL) {
        printf("\nError creating file!\n");
        return;
    }
    for (int i = 0; i < numExp; i++) {
        fprintf(fp, "%d,%s,%s,%.2f\n", expenses[i]->id, expenses[i]->date, expenses[i]->description, expenses[i]->amount);
    }
    fclose(fp);
    printf("\nExpenses saved to file!\n");
}

int main() {
    int choice;
    do {
        printf("\n=========== EXPENSE TRACKER ===========\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Save expenses to file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                saveExpenses();
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
                break;
        }
    } while (choice != 4);
    for (int i = 0; i < numExp; i++) {
        free(expenses[i]);
    }
    return 0;
}