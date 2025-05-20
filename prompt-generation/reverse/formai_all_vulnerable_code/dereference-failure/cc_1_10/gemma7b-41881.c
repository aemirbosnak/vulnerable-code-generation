//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10

typedef struct Record {
    char name[50];
    int age;
    struct Record* next;
} Record;

Record* head = NULL;

void insertRecord() {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    printf("Enter name: ");
    scanf("%s", newRecord->name);
    printf("Enter age: ");
    scanf("%d", &newRecord->age);
    newRecord->next = NULL;

    if (head == NULL) {
        head = newRecord;
    } else {
        head->next = newRecord;
    }
}

void searchRecord() {
    char searchName[50];
    printf("Enter name: ");
    scanf("%s", searchName);

    Record* currentRecord = head;
    while (currentRecord) {
        if (strcmp(currentRecord->name, searchName) == 0) {
            printf("Name: %s\n", currentRecord->name);
            printf("Age: %d\n", currentRecord->age);
            break;
        }
        currentRecord = currentRecord->next;
    }

    if (currentRecord == NULL) {
        printf("Record not found.\n");
    }
}

int main() {
    char choice;

    printf("Welcome to the Retro Database Indexing System!\n");
    printf("Please select an option:\n");
    printf("1. Insert Record\n");
    printf("2. Search Record\n");

    scanf("%c", &choice);

    switch (choice) {
        case '1':
            insertRecord();
            break;
        case '2':
            searchRecord();
            break;
        default:
            printf("Invalid input.\n");
    }

    return 0;
}