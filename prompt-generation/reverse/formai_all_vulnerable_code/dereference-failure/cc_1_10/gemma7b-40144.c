//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: innovative
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

PersonalFinanceRecord* insertPersonalFinanceRecord(PersonalFinanceRecord* head, char* name, int age, double income, double expenses) {
    PersonalFinanceRecord* newRecord = (PersonalFinanceRecord*)malloc(sizeof(PersonalFinanceRecord));
    strcpy(newRecord->name, name);
    newRecord->age = age;
    newRecord->income = income;
    newRecord->expenses = expenses;
    newRecord->next = NULL;

    if (head == NULL) {
        head = newRecord;
    } else {
        PersonalFinanceRecord* currentRecord = head;
        while (currentRecord->next != NULL) {
            currentRecord = currentRecord->next;
        }
        currentRecord->next = newRecord;
    }

    return head;
}

void printPersonalFinanceRecords(PersonalFinanceRecord* head) {
    PersonalFinanceRecord* currentRecord = head;
    while (currentRecord) {
        printf("Name: %s, Age: %d, Income: %.2lf, Expenses: %.2lf\n", currentRecord->name, currentRecord->age, currentRecord->income, currentRecord->expenses);
        currentRecord = currentRecord->next;
    }
}

int main() {
    PersonalFinanceRecord* head = NULL;

    insertPersonalFinanceRecord(head, "John Doe", 25, 50000, 20000);
    insertPersonalFinanceRecord(head, "Jane Doe", 30, 60000, 30000);
    insertPersonalFinanceRecord(head, "Peter Pan", 12, 40000, 10000);

    printPersonalFinanceRecords(head);

    return 0;
}