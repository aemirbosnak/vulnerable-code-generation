//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 1000

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

    newRecord->next = head;
    head = newRecord;
}

void searchRecord() {
    char searchName[50];
    printf("Enter name to search for: ");
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

void deleteRecord() {
    char deleteName[50];
    printf("Enter name to delete: ");
    scanf("%s", deleteName);

    Record* currentRecord = head;
    Record* previousRecord = NULL;

    while (currentRecord) {
        if (strcmp(currentRecord->name, deleteName) == 0) {
            if (previousRecord) {
                previousRecord->next = currentRecord->next;
            } else {
                head = currentRecord->next;
            }
            free(currentRecord);
            break;
        }
        previousRecord = currentRecord;
        currentRecord = currentRecord->next;
    }

    if (currentRecord == NULL) {
        printf("Record not found.\n");
    }
}

void displayRecords() {
    Record* currentRecord = head;
    printf("List of records:\n");
    while (currentRecord) {
        printf("Name: %s\n", currentRecord->name);
        printf("Age: %d\n", currentRecord->age);
        printf("\n");
        currentRecord = currentRecord->next;
    }
}

int main() {
    time_t t = time(NULL);
    srand(t);

    int choice;
    printf("Welcome to the Magical Database of Amazing Records!\n");
    printf("Please select an option:\n");
    printf("1. Insert Record\n");
    printf("2. Search Record\n");
    printf("3. Delete Record\n");
    printf("4. Display Records\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insertRecord();
            break;
        case 2:
            searchRecord();
            break;
        case 3:
            deleteRecord();
            break;
        case 4:
            displayRecords();
            break;
        default:
            printf("Invalid selection.\n");
            break;
    }

    return 0;
}