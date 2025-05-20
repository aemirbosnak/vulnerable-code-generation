//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: complex
#include <stdio.h>
#include <stdlib.h>

struct Budget {
    char name[20];
    int income;
    int expenses[5];
    int savings;
    struct Budget* next;
};

void createBudget(struct Budget** head) {
    *head = (struct Budget*)malloc(sizeof(struct Budget));
    (*head)->name[0] = '\0';
    (*head)->income = 0;
    for (int i = 0; i < 5; i++) {
        (*head)->expenses[i] = 0;
    }
    (*head)->savings = 0;
    (*head)->next = NULL;
}

void addBudget(struct Budget** head) {
    struct Budget* newBudget = (struct Budget*)malloc(sizeof(struct Budget));
    newBudget->name[0] = '\0';
    newBudget->income = 0;
    for (int i = 0; i < 5; i++) {
        newBudget->expenses[i] = 0;
    }
    newBudget->savings = 0;
    newBudget->next = NULL;

    struct Budget* temp = *head;
    if (*head == NULL) {
        *head = newBudget;
    } else {
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newBudget;
    }
}

void printBudget(struct Budget* head) {
    printf("Name: %s\n", head->name);
    printf("Income: %d\n", head->income);
    printf("Expenses:");
    for (int i = 0; i < 5; i++) {
        printf(", %d", head->expenses[i]);
    }
    printf("\nSavings: %d\n", head->savings);
}

int main() {
    struct Budget* head = NULL;
    createBudget(&head);
    addBudget(&head);
    addBudget(&head);
    printBudget(head);

    return 0;
}