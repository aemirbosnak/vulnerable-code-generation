//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50
#define MAX_INCOME 10
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    int income;
    int expenses[MAX_EXPENSES];
    int num_expenses;
    int num_categories;
    char categories[MAX_CATEGORIES][50];
} PersonalFinance;

void add_expense(PersonalFinance* pf, char* category, int amount) {
    int i;
    for (i = 0; i < pf->num_categories; i++) {
        if (strcmp(category, pf->categories[i]) == 0) {
            pf->expenses[pf->num_expenses++] = amount;
            return;
        }
    }
    strcpy(pf->categories[pf->num_categories++], category);
    pf->expenses[pf->num_expenses++] = amount;
}

void print_expenses(PersonalFinance* pf) {
    int i;
    printf("Expenses:\n");
    for (i = 0; i < pf->num_categories; i++) {
        printf("%s: ", pf->categories[i]);
        int total = 0;
        while (pf->expenses[pf->num_expenses - 1]!= 0) {
            total += pf->expenses[--pf->num_expenses];
        }
        printf("%d\n", total);
    }
}

void print_income(PersonalFinance* pf) {
    printf("Income: %d\n", pf->income);
}

int main() {
    PersonalFinance pf;
    int choice;
    do {
        printf("1. Add expense\n2. Add income\n3. Print expenses\n4. Print income\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char category[50];
                int amount;
                printf("Enter expense category: ");
                scanf("%s", category);
                printf("Enter expense amount: ");
                scanf("%d", &amount);
                add_expense(&pf, category, amount);
                break;
            }
            case 2: {
                int income;
                printf("Enter income: ");
                scanf("%d", &income);
                pf.income += income;
                break;
            }
            case 3: {
                print_expenses(&pf);
                break;
            }
            case 4: {
                print_income(&pf);
                break;
            }
            case 5: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    } while (choice!= 5);
    return 0;
}