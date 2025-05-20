//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#define MAX_EXPS 100

typedef struct {
    char *desc;
    float amount;
    struct exp *next;
} exp;

exp *head = NULL;
float total = 0;

void add_exp(char *desc, float amount) {
    exp *new_exp = malloc(sizeof(exp));
    new_exp->desc = desc;
    new_exp->amount = amount;
    new_exp->next = NULL;

    if (head == NULL) {
        head = new_exp;
    } else {
        exp *last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_exp;
    }

    total += amount;
}

void print_exps() {
    exp *current = head;
    while (current != NULL) {
        printf("%s: %f\n", current->desc, current->amount);
        current = current->next;
    }
}

int main() {
    add_exp("Rent", 1000);
    add_exp("Groceries", 200);
    add_exp("Utilities", 150);
    add_exp("Transportation", 250);
    add_exp("Entertainment", 100);

    print_exps();
    printf("Total: %f\n", total);

    return 0;
}