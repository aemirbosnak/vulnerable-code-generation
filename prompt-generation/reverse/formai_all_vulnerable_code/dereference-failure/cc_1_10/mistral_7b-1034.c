//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORIES 5

struct S_Expense {
    char name[MAX_NAME_LEN];
    int category;
    float amount;
    struct S_Expense* next;
};

typedef struct S_Expense Expense;

Expense* expenses = NULL;

int categories[MAX_CATEGORIES] = {1, 2, 3, 4, 5}; // Food: 1, Transport: 2, Entertainment: 3, Rent: 4, Utilities: 5
int num_categories = sizeof(categories) / sizeof(categories[0]);

int random_category() {
    return categories[rand() % num_categories];
}

void new_expense(char* name, float amount) {
    Expense* new_expense = (Expense*)malloc(sizeof(Expense));
    strcpy(new_expense->name, name);
    new_expense->category = random_category();
    new_expense->amount = amount;
    new_expense->next = expenses;
    expenses = new_expense;
}

void print_expenses() {
    Expense* current = expenses;
    int i = 1;
    printf("Expenses Report for the Enigmatic Accountant's Conundrum:\n");
    while (current != NULL) {
        printf("%d. %s: %s - Category: %d, Amount: %.2f\n", i++, current->name, current->name, current->category, current->amount);
        current = current->next;
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    int num_expenses = 10;
    for (int i = 0; i < num_expenses; i++) {
        char name[MAX_NAME_LEN];
        float amount;
        printf("Enter expense %d name: ", i + 1);
        scanf("%s", name);
        printf("Enter expense %d amount: ", i + 1);
        scanf("%f", &amount);
        new_expense(name, amount);
    }
    print_expenses();
    return 0;
}