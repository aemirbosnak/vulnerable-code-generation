//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
// Expense Tracker Program in C by Ken Thompson

#include <stdio.h>
#include <stdlib.h>

// Structure to hold the expense details
typedef struct Expense {
    int day;
    int month;
    int year;
    char description[50];
    float amount;
    struct Expense* next;
} Expense;

// Function to add new expense record to the linked list
void addExpense(Expense** head, int day, int month, int year, char* description, float amount) {
    Expense* newExpense = (Expense*)malloc(sizeof(Expense));
    newExpense->day = day;
    newExpense->month = month;
    newExpense->year = year;
    strcpy(newExpense->description, description);
    newExpense->amount = amount;
    newExpense->next = NULL;

    if(*head == NULL) {
        *head = newExpense;
        return;
    }

    Expense* last = *head;
    while(last->next != NULL) {
        last = last->next;
    }
    last->next = newExpense;
}

// Function to display all the expense records
void displayExpenses(Expense* head) {
    printf("Expenses List:\n");
    printf("Day\tMonth\tYear\tDescription\tAmount\n");
    printf("----------------------------------------------\n");

    while(head != NULL) {
        printf("%d\t%d\t%d\t%s\t%.2f\n", head->day, head->month, head->year, head->description, head->amount);
        head = head->next;
    }
}

int main() {
    Expense* head = NULL;

    // Adding sample expense records
    addExpense(&head, 22, 9, 2021, "Grocery Shopping", 45.67);
    addExpense(&head, 23, 9, 2021, "Fuel", 30.00);
    addExpense(&head, 24, 9, 2021, "Dinner with Friends", 75.89);

    displayExpenses(head);

    return 0;
}