//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORD_SIZE 1024

typedef struct Record {
    char name[MAX_RECORD_SIZE];
    char date[MAX_RECORD_SIZE];
    char content[MAX_RECORD_SIZE];
    struct Record* next;
} Record;

Record* createRecord() {
    Record* newRecord = malloc(sizeof(Record));
    newRecord->next = NULL;

    return newRecord;
}

void addRecord(Record* head, char* name, char* date, char* content) {
    Record* newRecord = createRecord();

    strcpy(newRecord->name, name);
    strcpy(newRecord->date, date);
    strcpy(newRecord->content, content);

    if (head == NULL) {
        head = newRecord;
    } else {
        newRecord->next = head;
        head = newRecord;
    }
}

void displayRecords(Record* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Date: %s\n", head->date);
        printf("Content: %s\n", head->content);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Record* head = NULL;

    addRecord(head, "John Doe", "2023-01-01", "This is the first record.");
    addRecord(head, "Jane Doe", "2023-01-02", "This is the second record.");
    addRecord(head, "Bill Smith", "2023-01-03", "This is the third record.");

    displayRecords(head);

    return 0;
}