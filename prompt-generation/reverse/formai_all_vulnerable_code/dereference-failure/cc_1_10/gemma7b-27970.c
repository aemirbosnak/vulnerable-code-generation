//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RECORDS 100

typedef struct Record {
    char name[20];
    int age;
    struct Record* next;
} Record;

Record* insertRecord(Record* head, char* name, int age) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    newRecord->age = age;
    newRecord->next = NULL;

    if (head == NULL) {
        head = newRecord;
    } else {
        head->next = newRecord;
    }

    return head;
}

int searchRecord(Record* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

int main() {
    Record* head = NULL;

    insertRecord(head, "John Doe", 25);
    insertRecord(head, "Jane Doe", 30);
    insertRecord(head, "Peter Pan", 12);

    if (searchRecord(head, "Jane Doe") == 1) {
        printf("Jane Doe found!");
    } else {
        printf("Jane Doe not found!");
    }

    return 0;
}