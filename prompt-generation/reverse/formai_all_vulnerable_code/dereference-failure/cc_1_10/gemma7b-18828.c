//Gemma-7B DATASET v1.0 Category: Database querying ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_LENGTH 1024

typedef struct Record {
    char name[256];
    int age;
    struct Record* next;
} Record;

Record* insertRecord(Record* head, char* name, int age) {
    Record* newRecord = malloc(sizeof(Record));
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

void queryRecords(Record* head, char* query) {
    char* keywords[] = {"name", "age"};
    int i = 0;
    int result = 0;

    for (i = 0; i < MAX_QUERY_LENGTH; i++) {
        if (query[i] == '\0') {
            break;
        }
    }

    for (i = 0; i < 2; i++) {
        if (strstr(query, keywords[i]) != NULL) {
            result = 1;
        }
    }

    if (result) {
        printf("Results:\n");
        for (head = head; head != NULL; head = head->next) {
            printf("  %s (age: %d)\n", head->name, head->age);
        }
    } else {
        printf("No results found.\n");
    }
}

int main() {
    Record* head = NULL;
    insertRecord(head, "John Doe", 25);
    insertRecord(head, "Jane Doe", 30);
    insertRecord(head, "Peter Pan", 12);

    char query[MAX_QUERY_LENGTH] = "find name Jane Doe";

    queryRecords(head, query);

    return 0;
}