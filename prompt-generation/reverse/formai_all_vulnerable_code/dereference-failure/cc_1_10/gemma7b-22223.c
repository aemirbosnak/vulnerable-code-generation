//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct PersonalFinanceRecord {
    char name[MAX_NAME_LENGTH];
    int age;
    double income;
    double expenses;
    struct PersonalFinanceRecord* next;
} PersonalFinanceRecord;

PersonalFinanceRecord* insertRecord(PersonalFinanceRecord* head, char* name, int age, double income, double expenses) {
    PersonalFinanceRecord* newRecord = malloc(sizeof(PersonalFinanceRecord));

    strcpy(newRecord->name, name);
    newRecord->age = age;
    newRecord->income = income;
    newRecord->expenses = expenses;
    newRecord->next = NULL;

    if (head == NULL) {
        head = newRecord;
    } else {
        head->next = newRecord;
    }

    return head;
}

void printRecords(PersonalFinanceRecord* head) {
    PersonalFinanceRecord* currentRecord = head;

    while (currentRecord) {
        printf("Name: %s, Age: %d, Income: %.2lf, Expenses: %.2lf\n", currentRecord->name, currentRecord->age, currentRecord->income, currentRecord->expenses);
        currentRecord = currentRecord->next;
    }
}

int main() {
    PersonalFinanceRecord* head = NULL;

    insertRecord(head, "John Doe", 25, 50000, 20000);
    insertRecord(head, "Jane Doe", 30, 60000, 25000);
    insertRecord(head, "Bill Smith", 40, 40000, 15000);

    printRecords(head);

    return 0;
}