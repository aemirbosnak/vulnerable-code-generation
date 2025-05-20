//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100

typedef struct Record {
    char name[50];
    int age;
    double salary;
    struct Record* next;
} Record;

Record* insertRecord(Record* head) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    printf("Enter name: ");
    scanf("%s", newRecord->name);
    printf("Enter age: ");
    scanf("%d", &newRecord->age);
    printf("Enter salary: ");
    scanf("%lf", &newRecord->salary);
    newRecord->next = NULL;

    if (head == NULL) {
        head = newRecord;
    } else {
        head->next = newRecord;
    }

    return head;
}

void searchRecord(Record* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            printf("Name: %s\n", head->name);
            printf("Age: %d\n", head->age);
            printf("Salary: %.2lf\n", head->salary);
            return;
        }
        head = head->next;
    }

    printf("Record not found.\n");
}

int main() {
    Record* head = NULL;

    // Insert records
    head = insertRecord(head);
    insertRecord(head);
    insertRecord(head);

    // Search for a record
    searchRecord(head, "John Doe");

    return 0;
}