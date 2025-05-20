//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 1000
#define MAX_RECORD_LEN 255

typedef struct Record {
    char name[MAX_RECORD_LEN];
    int age;
    struct Record* next;
} Record;

Record* InsertRecord(Record* head, char* name, int age) {
    Record* new_record = malloc(sizeof(Record));
    strcpy(new_record->name, name);
    new_record->age = age;
    new_record->next = NULL;

    if (head == NULL) {
        head = new_record;
    } else {
        head->next = new_record;
    }

    return head;
}

Record* FindRecord(Record* head, char* name) {
    Record* current = head;

    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

int main() {
    Record* head = NULL;
    head = InsertRecord(head, "John Doe", 25);
    head = InsertRecord(head, "Jane Doe", 30);
    head = InsertRecord(head, "Peter Pan", 12);

    Record* found_record = FindRecord(head, "Jane Doe");

    if (found_record) {
        printf("Name: %s, Age: %d\n", found_record->name, found_record->age);
    } else {
        printf("Record not found.\n");
    }

    return 0;
}