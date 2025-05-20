//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct Record {
    int id;
    char name[NAME_LENGTH];
    struct Record* next;
} Record;

typedef struct IndexNode {
    int id;
    Record* record;
    struct IndexNode* next;
} IndexNode;

Record* head = NULL;
IndexNode* indexHead = NULL;

void addRecord(int id, const char* name) {
    // Create a new record
    Record* newRecord = (Record*)malloc(sizeof(Record));
    newRecord->id = id;
    strncpy(newRecord->name, name, NAME_LENGTH);
    newRecord->next = head;
    head = newRecord;

    // Add to index
    IndexNode* newIndexNode = (IndexNode*)malloc(sizeof(IndexNode));
    newIndexNode->id = id;
    newIndexNode->record = newRecord;
    newIndexNode->next = indexHead;
    indexHead = newIndexNode;
}

Record* searchRecordById(int id) {
    IndexNode* currentIndex = indexHead;
    while (currentIndex != NULL) {
        if (currentIndex->id == id) {
            return currentIndex->record;
        }
        currentIndex = currentIndex->next;
    }
    return NULL;
}

void displayRecords() {
    Record* current = head;
    printf("Displaying all records:\n");
    while (current != NULL) {
        printf("ID: %d, Name: %s\n", current->id, current->name);
        current = current->next;
    }
}

void freeMemory() {
    Record* currentRecord = head;
    while (currentRecord != NULL) {
        Record* tempRecord = currentRecord;
        currentRecord = currentRecord->next;
        free(tempRecord);
    }

    IndexNode* currentIndex = indexHead;
    while (currentIndex != NULL) {
        IndexNode* tempIndex = currentIndex;
        currentIndex = currentIndex->next;
        free(tempIndex);
    }
}

int main() {
    int choice, id;
    char name[NAME_LENGTH];

    while (1) {
        printf("1. Add Record\n2. Search by ID\n3. Display All Records\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                addRecord(id, name);
                break;
            case 2:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Record* foundRecord = searchRecordById(id);
                if (foundRecord != NULL) {
                    printf("Record found - ID: %d, Name: %s\n", foundRecord->id, foundRecord->name);
                } else {
                    printf("Record not found.\n");
                }
                break;
            case 3:
                displayRecords();
                break;
            case 4:
                freeMemory();
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}