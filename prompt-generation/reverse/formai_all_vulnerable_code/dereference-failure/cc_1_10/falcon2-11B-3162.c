//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char name[50];
    float amount;
    struct expense* next;
};

typedef struct expense expense;

expense* create_expense(const char* name, float amount) {
    expense* new_expense = (expense*) malloc(sizeof(expense));
    strcpy(new_expense->name, name);
    new_expense->amount = amount;
    new_expense->next = NULL;
    return new_expense;
}

void add_expense(expense* list, const char* name, float amount) {
    expense* new_expense = create_expense(name, amount);
    if (list == NULL) {
        list = new_expense;
    } else {
        expense* current = list;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_expense;
    }
}

void print_expenses(expense* list) {
    if (list == NULL) {
        printf("No expenses found.\n");
        return;
    }
    expense* current = list;
    while (current!= NULL) {
        printf("%s - $%.2f\n", current->name, current->amount);
        current = current->next;
    }
}

int main() {
    expense* list = NULL;
    add_expense(list, "Coffee", 3.50);
    add_expense(list, "Lunch", 12.00);
    add_expense(list, "Groceries", 25.00);
    print_expenses(list);
    return 0;
}