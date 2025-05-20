//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_RECORDS 100

typedef struct Record {
    int id;
    char name[MAX_NAME_LENGTH];
    struct Record* next;
} Record;

typedef struct IndexNode {
    int id;
    Record* recordPtr;
    struct IndexNode* next;
} IndexNode;

Record* records = NULL;
IndexNode* indexList = NULL;

Record* createRecord(int id, const char* name) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    newRecord->id = id;
    strcpy(newRecord->name, name);
    newRecord->next = NULL;
    return newRecord;
}

IndexNode* createIndexNode(int id, Record* recordPtr) {
    IndexNode* newNode = (IndexNode*)malloc(sizeof(IndexNode));
    newNode->id = id;
    newNode->recordPtr = recordPtr;
    newNode->next = NULL;
    return newNode;
}

void addRecord(int id, const char* name) {
    Record* newRecord = createRecord(id, name);
    newRecord->next = records;
    records = newRecord;

    IndexNode* newIndexNode = createIndexNode(id, newRecord);
    newIndexNode->next = indexList;
    indexList = newIndexNode;
    printf("Record added: ID=%d, Name=%s\n", id, name);
}

void deleteRecord(int id) {
    Record* current = records;
    Record* previous = NULL;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Record with ID=%d not found.\n", id);
        return;
    }

    if (previous == NULL) {
        records = current->next; // Deleting head
    } else {
        previous->next = current->next; // Deleting non-head
    }

    // Remove from the index
    IndexNode* indexCurrent = indexList;
    IndexNode* indexPrevious = NULL;

    while (indexCurrent != NULL && indexCurrent->id != id) {
        indexPrevious = indexCurrent;
        indexCurrent = indexCurrent->next;
    }

    if (indexPrevious == NULL) {
        indexList = indexCurrent->next; // Deleting head of index
    } else {
        indexPrevious->next = indexCurrent->next;
    }

    free(current);
    free(indexCurrent);
    printf("Record with ID=%d deleted.\n", id);
}

Record* searchRecord(int id) {
    IndexNode* indexCurrent = indexList;

    while (indexCurrent != NULL) {
        if (indexCurrent->id == id) {
            return indexCurrent->recordPtr;
        }
        indexCurrent = indexCurrent->next;
    }

    return NULL;
}

void displayRecords() {
    Record* current = records;
    printf("All Records:\n");
    while (current != NULL) {
        printf("ID=%d, Name=%s\n", current->id, current->name);
        current = current->next;
    }
}

int main() {
    int choice, id;
    char name[MAX_NAME_LENGTH];

    do {
        printf("\nDatabase Indexing System\n");
        printf("1. Add Record\n");
        printf("2. Delete Record\n");
        printf("3. Search Record\n");
        printf("4. Display All Records\n");
        printf("5. Exit\n");
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
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteRecord(id);
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Record* record = searchRecord(id);
                if (record) {
                    printf("Record found: ID=%d, Name=%s\n", record->id, record->name);
                } else {
                    printf("Record with ID=%d not found.\n", id);
                }
                break;
            case 4:
                displayRecords();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 5);

    // Clean up
    while (records != NULL) {
        deleteRecord(records->id);
    }

    while (indexList != NULL) {
        IndexNode* temp = indexList;
        indexList = indexList->next;
        free(temp);
    }

    return 0;
}