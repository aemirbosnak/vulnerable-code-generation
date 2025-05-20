//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 255

typedef struct PersonalFinance {
    char name[MAX_NAME_LEN];
    double income;
    double expenses;
    double net_worth;
    struct PersonalFinance* next;
} PersonalFinance;

PersonalFinance* createPersonalFinance() {
    PersonalFinance* new_person = malloc(sizeof(PersonalFinance));
    new_person->name[0] = '\0';
    new_person->income = 0.0;
    new_person->expenses = 0.0;
    new_person->net_worth = 0.0;
    new_person->next = NULL;
    return new_person;
}

void addPersonalFinance(PersonalFinance* head, char* name, double income, double expenses) {
    PersonalFinance* new_person = createPersonalFinance();
    strcpy(new_person->name, name);
    new_person->income = income;
    new_person->expenses = expenses;
    new_person->next = head;
    head = new_person;
}

void calculateNetWorth(PersonalFinance* head) {
    while (head) {
        head->net_worth = head->income - head->expenses;
        head = head->next;
    }
}

int main() {
    PersonalFinance* head = NULL;
    addPersonalFinance(head, "John Doe", 50000, 20000);
    addPersonalFinance(head, "Jane Doe", 60000, 30000);
    addPersonalFinance(head, "Peter Pan", 70000, 40000);

    calculateNetWorth(head);

    for (PersonalFinance* current = head; current; current = current->next) {
        printf("%s has a net worth of $%.2lf\n", current->name, current->net_worth);
    }

    return 0;
}