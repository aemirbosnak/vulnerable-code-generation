//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define INDEX_MAX 100

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

// Function to create a new record
Record* createRecord(int id, const char* name) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    newRecord->id = id;
    strncpy(newRecord->name, name, NAME_LENGTH);
    newRecord->next = NULL;
    return newRecord;
}

// Function to add a record to the database
void addRecord(int id, const char* name) {
    Record* newRecord = createRecord(id, name);
    newRecord->next = head;
    head = newRecord;

    // Adding to index
    IndexNode* newIndexNode = (IndexNode*)malloc(sizeof(IndexNode));
    newIndexNode->id = id;
    newIndexNode->record = newRecord;
    newIndexNode->next = indexHead;
    indexHead = newIndexNode;

    printf("Record added: ID = %d, Name = %s\n", id, name);
}

// Function to display all records
void displayRecords() {
    Record* current = head;
    printf("\nAll Records:\n");
    while (current != NULL) {
        printf("ID: %d, Name: %s\n", current->id, current->name);
        current = current->next;
    }
}

// Function to search for a record by ID
void searchRecord(int id) {
    IndexNode* currentIndex = indexHead;
    while (currentIndex != NULL) {
        if (currentIndex->id == id) {
            printf("Found record: ID = %d, Name = %s\n", currentIndex->record->id, currentIndex->record->name);
            return;
        }
        currentIndex = currentIndex->next;
    }
    printf("Record with ID = %d not found!\n", id);
}

// Function to clean up memory
void cleanup() {
    while (head != NULL) {
        Record* temp = head;
        head = head->next;
        free(temp);
    }

    while (indexHead != NULL) {
        IndexNode* tempIndex = indexHead;
        indexHead = indexHead->next;
        free(tempIndex);
    }
}

// Main program
int main() {
    int choice, id;
    char name[NAME_LENGTH];

    printf("Welcome to the C Database Indexing System!\n");
    printf("1. Add Record\n2. Display Records\n3. Search Record\n4. Exit\n");

    while (1) {
        printf("\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Record ID: ");
                scanf("%d", &id);
                printf("Enter Record Name: ");
                scanf("%s", name);
                addRecord(id, name);
                break;

            case 2:
                displayRecords();
                break;

            case 3:
                printf("Enter Record ID to search: ");
                scanf("%d", &id);
                searchRecord(id);
                break;

            case 4:
                printf("Exiting the system. Thank you!\n");
                cleanup();
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}