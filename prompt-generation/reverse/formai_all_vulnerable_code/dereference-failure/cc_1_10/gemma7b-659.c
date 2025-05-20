//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 20

typedef struct Record {
    char name[MAX_NAME_LENGTH];
    int age;
    struct Record* next;
} Record;

Record* insertRecord(Record* head) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    printf("Enter name: ");
    scanf("%s", newRecord->name);
    printf("Enter age: ");
    scanf("%d", &newRecord->age);

    newRecord->next = head;
    head = newRecord;

    return head;
}

void searchRecord(Record* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            printf("Name: %s\n", head->name);
            printf("Age: %d\n", head->age);
            break;
        } else {
            head = head->next;
        }
    }

    if (head == NULL) {
        printf("Record not found.\n");
    }
}

int main() {
    Record* head = NULL;
    char name[MAX_NAME_LENGTH];

    // Insert records
    head = insertRecord(head);
    insertRecord(head);
    insertRecord(head);

    // Search for a record
    printf("Enter name: ");
    scanf("%s", name);
    searchRecord(head, name);

    return 0;
}